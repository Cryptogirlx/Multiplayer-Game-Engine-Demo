# Multiplayer-Game-Engine-Demo

# 🎮 Mini Game Engine Demo

A lightweight **C++ game engine demo** showcasing **low-level systems programming**, **multiplayer networking**, and **basic AI agents**.

This project demonstrates skills relevant for:

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
