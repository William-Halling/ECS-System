#pragma once
#include <cstdint>
#include <functional>

namespace ecs 
{
  struct Entity 
  {
    uint64_t id = 0;

    constexpr Entity() noexcept = default;
    constexpr explicit Entity(uint64_t val) noexcept : id(val) {}
    
    constexpr Entity(uint32_t index, uint32_t generation) noexcept 
      : id((static_cast<uint64_t>(generation) << 32) | index) {}
  
    
    [[nodiscard]] constexpr uint32_t index() const noexcept 
    { 
      return static_cast<uint32_t>(id); 
    }

    [[nodiscard]] constexpr uint32_t generation() const noexcept 
    { 
      return static_cast<uint32_t>(id >> 32); 
    }

      
    constexpr bool operator==(Entity other) const noexcept 
    {
        return id == other.id;
    }

    constexpr bool operator!=(Entity other) const noexcept { return id != other.id; }
  };

  inline constexpr Entity ENTITY_NULL = { ~0u, 0u };
}


namespace std 
{
  template<> struct hash<ecs::Entity> 
  {
      size_t operator()(ecs::Entity e) const noexcept 
      {
          return std::hash<uint64_t>{}(e.id);
      }
  };
}
