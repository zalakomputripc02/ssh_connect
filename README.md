# SSH Connect (Console Tool)

A simple C++ console application for connecting to remote systems using SSH or PuTTY.  
The program uses a menu-based interface for easy navigation.

---

## Features

- Menu-driven console interface
- Connect using native SSH
- Optional PuTTY support
  - SSH
  - Telnet
  - Raw
  - Serial
- Options and Help menus
- Automatic screen clearing (Windows / Linux)

---

## Requirements

### Windows
- C++ compiler (MinGW or MSVC)
- OpenSSH installed
- PuTTY (optional)

### Linux
- g++
- OpenSSH

---

## Build

```bash
g++ main.cpp -o ssh_connect
