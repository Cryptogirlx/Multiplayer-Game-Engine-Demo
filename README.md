# Multiplayer-Game-Engine-Demo

# 🎮 Mini Game Engine Demo - Quantum Runner

Quantum Runner is a fast-paced, top-down endless runner game where players navigate a constantly shifting world filled with obstacles and collectible quantum tokens. The player must dodge obstacles, collect tokens for points, and survive as long as possible while the game progressively speeds up and the environment “quantum jumps” every few seconds, keeping the challenge dynamic and unpredictable.

Built in C++ using a custom game engine, Quantum Runner demonstrates modular engine design, a real-time game loop, player input handling, and procedural world generation.

- **Game Engine Development (C++)**
- **Systems Programming & Security**
- **Multiplayer Networking (Go + C++)**
- **AI/Gameplay Engineering**

---

## ✨ Features

- ⚙️ **Core Engine Loop** (C++): fixed timestep update & render cycle
- 🧩 **Entity System**: simple player + NPCs with movement
- 🎨 **2D Graphics**: rendering with [SFML](https://www.sfml-dev.org/)
- 🌐 **Multiplayer Networking**: Go server + C++ clients syncing player positions
- 🤖 **AI NPC**: autonomous movement using pathfinding / finite state machines
- 🔐 **Security-Aware Code**: memory safety, input validation, secure networking

---

## 🖼 Demo

👉 _(Insert GIFs or screenshots here — can record with OBS or asciinema)_

![Demo Screenshot](assets/demo-screenshot.png)

---

## 🚀 Getting Started

### Prerequisites

- C++17 or newer
- [CMake](https://cmake.org/)
- [SFML](https://www.sfml-dev.org/) (for rendering)
- [Go](https://go.dev/dl/) (for multiplayer server)

### Build & Run (C++ Client)

```bash
cd cpp-graphics
mkdir build && cd build
cmake ..
make
./game_demo
```
