// entity.h
#pragma once
#include <cstdint>
#include <functional>

namespace ecs 
{
  
  struct Entity 
  {
      uint32_t index;
      uint32_t generation;
  
      bool operator==(Entity other) const noexcept 
      {
          return index == other.index && generation == other.generation;
      }

      bool operator!=(Entity other) const noexcept { return !(*this == other); }
  };

  constexpr Entity ENTITY_NULL = { ~0u, 0u };

} // namespace ecs


// Specialize std::hash for use in unordered containers
namespace std 
{
  template<> struct hash<ecs::Entity> 
  {
      size_t operator()(ecs::Entity e) const noexcept 
      {
          // Combine into a 64‑bit value first, then hash that if needed.
          uint64_t combined = (uint64_t(e.index) << 32) | e.generation;
          
          return std::hash<uint64_t>{}(combined);
      }
  };
}
