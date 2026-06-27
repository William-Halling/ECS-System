#pragma once
#include <vector>
#include <unordered_map>
#include <cstdint>

using Entity = std::uint32_t;

class EntityManager
{
private:
  Entity nextEntity = 0;

public: 
  Entity createEntity()
  {
    return nextEntity++;
  }
};
