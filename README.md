# ECS-System
# C++ Entity Component System (ECS)

A lightweight, educational Entity Component System (ECS) implementation written in modern C++.

This project demonstrates core systems programming concepts commonly used in game engines and high-performance simulations:
- Data-oriented design
- Separation of data and logic
- Component-based architecture
- Efficient system updates

- ---

## Overview

This project implements ECS architecture consisting of:

- **Entities** – Unique identifiers (IDs)
- **Components** – Pure data structures
- **Systems** – Logic that operates on components

The goal is to provide a minimal but expandable foundation for learning engine architecture and simulation design.

---



# Structure
- ecs-core/
- ├── CMakeLists.txt
- ├── README.md
- ├── LICENSE
- ├── include/
- │   └── ecs/
- │       ├── ecs.h                  # Main umbrella header
- │       ├── entity.h
- │       ├── component.h
- │       ├── chunk.h
- │       ├── archetype.h
- │       ├── world.h
- │       ├── query.h
- │       ├── system.h
- │       ├── scheduler.h
- │       ├── job_system.h
- │       ├── reflection.h            # Optional reflection macros
- │       ├── serialization.h
- │       └── debug.h
- ├── src/
- │   ├── world.cpp
- │   ├── chunk.cpp
- │   ├── archetype.cpp
- │   ├── query.cpp
- │   ├── scheduler.cpp
- │   ├── job_system.cpp
- │   ├── serialization.cpp
- │   └── debug.cpp
- ├── tests/
- │   ├── CMakeLists.txt
- │   ├── test_entity.cpp
- │   ├── test_archetype.cpp
- │   ├── test_world.cpp
- │   ├── test_query.cpp
- │   ├── test_scheduler.cpp
- │   └── benchmark/
- │       └── perf_iteration.cpp
- ├── examples/
- │   ├── hello_ecs.cpp
│   └── movement_system.cpp
└── docs/                           # Doxygen configuration
