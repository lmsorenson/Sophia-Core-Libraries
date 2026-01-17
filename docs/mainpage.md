# Sophia Decision Engine

> **σοφία** - *Wisdom in Computational Decision-Making*

## Overview

**Sophia Decision Engine** is a high-performance C++ framework that provides the computational core for intelligent decision-making systems. Built around advanced tree search algorithms like Monte Carlo Tree Search (MCTS), it serves as the engine that powers AI agents, game-playing systems, and optimization applications.

## Key Features

### 🚀 **High-Performance Engine**
- Template-based design for compile-time optimization
- C++23 features for maximum performance
- Extensible architecture for custom algorithms

### 🧠 **Decision-Making Algorithms**
- **Monte Carlo Tree Search (MCTS)**: Probabilistic tree search for optimal decisions
- **Extensible Framework**: Plugin architecture for additional algorithms
- **Tree Search Foundation**: Base classes for various decision strategies

### 🛠️ **Developer-Friendly**
- Modern CMake build system
- Comprehensive unit testing
- Cross-platform support (Windows, macOS, Linux)
- Extensive documentation with diagrams

## Quick Start

```cpp
#include <sophia/monte_carlo/tree_search_algorithm.h>
#include <memory>

// Create your game state (implementing Node interface)
auto rootNode = std::make_shared<YourGameState>();

// Run MCTS for optimal decision-making
auto bestAction = sophia::monte_carlo::MonteCarloTreeSearch::run(rootNode, 1000);

// Execute the best action
bestAction->Execute();
```

## Architecture

### Core Components

| Component | Description |
|-----------|-------------|
| **Node** | Represents decision states with MCTS statistics |
| **Action** | Represents moves/transitions between states |
| **RolloutStrategy** | Defines how to evaluate leaf nodes |
| **MonteCarloTreeSearch** | Main algorithm implementation |

### Design Patterns

- **Template Method**: Extensible base classes for customization
- **Strategy Pattern**: Pluggable evaluation and selection strategies
- **Factory Pattern**: Object creation for different game types
- **Observer Pattern**: Event-driven game state management

## Use Cases

### 🎮 **Game AI**
- Chess, Go, and other strategic games
- Real-time strategy games
- Board games and puzzles

### 🤖 **Robotics & Planning**
- Motion planning
- Path optimization
- Decision-making under uncertainty

### 📊 **Optimization**
- Combinatorial optimization
- Resource allocation
- Decision support systems

## Examples

Explore our comprehensive examples:

- **Tic-Tac-Toe**: Complete game implementation with MCTS AI
- **Custom Games**: Framework for implementing your own games
- **Algorithm Comparison**: Performance analysis of different strategies

## Getting Started

1. **Clone the repository**:
   ```bash
   git clone https://github.com/lmsorenson/Sophia-Decision-Engine.git
   cd Sophia-Decision-Engine
   ```

2. **Build the project**:
   ```bash
   mkdir build && cd build
   cmake .. -DCMAKE_BUILD_TYPE=Release
   cmake --build . --config Release
   ```

3. **Run the examples**:
   ```bash
   ./examples/monte_carlo/tic_tac_toe/tic_tac_toe_example
   ```

## Documentation Structure

- **📚 [API Reference](namespaces.html)**: Complete class and function documentation
- **💡 [Examples](examples.html)**: Working code samples
- **🔧 [Getting Started](md_README.html)**: Installation and setup guide
- **📖 [Architecture](md_docs_2mainpage.html)**: Detailed technical overview

## Contributing

We welcome contributions! See our [Contributing Guide](md_README.html#autotoc_md22) for details.

## License

This project is licensed under the MIT License - see the [LICENSE](md_README.html#autotoc_md25) file for details.

---

*"The function of wisdom is to discriminate between good and evil."*
— Cicero