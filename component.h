// component.h
#pragma once
#include <cstddef>
#include <cstdint>
#include <type_traits>
#include <functional>

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
  
  
  // Type-erased component traits
  struct ComponentTraits 
  {
      size_t size;
      size_t alignment;
      void (*move_construct)(void* dst, void* src);
      void (*copy_construct)(void* dst, const void* src);
      void (*destruct)(void* ptr);
  };
  
  
  // Helper to create traits for a concrete component type
  template<typename T>
  ComponentTraits make_component_traits() 
  {
    return ComponentTraits
    {
      .size = sizeof(T),
      .alignment = alignof(T),
      .move_construct = [](void* dst, void* src) 
      {
        new (dst) T(std::move(*static_cast<T*>(src)));
      },
      .copy_construct = [](void* dst, const void* src)
      {
        new (dst) T(*static_cast<const T*>(src));
      },
      .destruct = [](void* ptr)
      {
        static_cast<T*>(ptr)->~T();
      }
    };
  }
}
