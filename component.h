// component.h
#pragma once
#include <cstddef>
#include <cstdint>
#include <type_traits>
#include <utility>

namespace ecs 
{
  using ComponentTypeId = uint32_t;
  
    // Unique ID generator for component types
  inline ComponentTypeId next_component_type_id() noexcept 
  {
      static ComponentTypeId counter = 0;
    
      return counter++;
  }
  
  template<typename T>
  ComponentTypeId component_type_id() noexcept 
  {
      static ComponentTypeId id = next_component_type_id();
      
      return id;
  }


  struct ComponentTraits 
  {
    size_t size;
    size_t alignment;
    void (*move_construct)(void* dst, void* src);
    void (*copy_construct)(void* dst, const void* src);
    void (*destruct)(void* ptr);
    bool is_trivially_copyable;
  };


  template<typename T>
  ComponentTraits make_component_traits() 
  {
    return ComponentTraits
    {
      sizeof(T),
      alignof(T),
      
      std::is_trivially_move_constructible_v<T> ? nullptr : [](void* dst, void* src) 
      {
          new (dst) T(std::move(*static_cast<T*>(src)));
      },
      
      std::is_trivially_copy_constructible_v<T> ? nullptr : [](void* dst, const void* src)
      {
          new (dst) T(*static_cast<const T*>(src));
      },
      
      std::is_trivially_destructible_v<T> ? nullptr : [](void* ptr)
      {
          static_cast<T*>(ptr)->~T();
      },

      std::is_trivially_copyable_v<T>
    };
  }
}
