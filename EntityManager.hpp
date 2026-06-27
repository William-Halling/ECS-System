#pragma once
#include <vector>
#include <unordered_map>
#include <cstdint>

using Entity = std::uint32_t;
namespace ecs 
{
  class EntityManager
  {
    private:
      uint32_t next_index = 0;
      std::vector<uint32_t> generations;
      std::vector<uint32_t> free_indices;
  
    public:
      EntityManager() = default;
      ~EntityManager() = default;

      Entity createEntity();
      bool destroyEntity(Entity entity);
      [[nodiscard]] bool isAlive(Entity entity) const noexcept;
  };
}
