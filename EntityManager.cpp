#include "EntityManager.h"

namespace ecs 
{
  EntityManager EntityManager::createEntity()
  {
    uint32_t target_index;
    uint32_t current_generation = 0;
  
    if (!free_indices.empty()) 
    {
        target_index = free_indices.back();
        free_indices.pop_back();
        current_generation = generations[target_index];
    } 
    else 
    {
        target_index = next_index++;
        generations.push_back(0);
    }
  
    return Entity(target_index, current_generation);
  }

  bool EntityManager::destroyEntity(Entity entity) 
  {
    const uint32_t idx = entity.index();

    
    if (!isAlive(entity)) 
    {
        return false; 
    }

    generations[idx]++;
      
    // Push the index back to the pool for a future createEntity() call
    free_indices.push_back(idx);
    return true;
  }
  
  // High-performance validation check: O(1) time complexity
  [[nodiscard]] bool EntityManager::isAlive(Entity entity) const noexcept 
  {
      const uint32_t idx = entity.index();
    
      return idx < generations.size() && generations[idx] == entity.generation();
  }

  [[nodiscard]] size_t EntityManager::capacity() const noexcept
  { 
    return generations.size(); 
  }
}
