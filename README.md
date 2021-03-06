# Dice Simulation

![Dice Simulation Logo](src/img/icon/ds-banner.png)

This is script-based software to enable different kinds of dice simulation in a visual way.

This software is based on [Qt](https://qt.io), [ReactPhysics3D](https://github.com/DanielChappuis/reactphysics3d) and [AStyle](https://sourceforge.net/projects/astyle).

## Current Version

|  Component  | Version | Description |
| :---------: | :-----: | :---------: |
|   Project   |  0.1.1  | Main project. |
| ds-convert  |  0.1.1  | Convert `ds` code to standard `cpp` code. |
| ds-compile  |  0.0.1  | Compile the converted `cpp` code. |
|   ds-help   |    -    |             |
| ds-maintain |    -    |             |
|   ds-gui    |    -    |             |
| [ds-vsc](https://github.com/Teddy-van-Jerry/Dice_Simulation_VSC) |  0.0.3  | Visual Studio Code Extension for DS. |

> Documentation version will follow the project version.

In this version, basic functions of ds-convert are achieved but tests have not been done.

## Installation
### Mac
- Option 1: Download Release
  - The release build is universal, for both Apple Silicon and Intel Silicon.
  - Need to have `qtbase` or full Qt 6 (Best to be 6.2.0). You can install `qtbase` using MacPort with `sudo port install qt6-qtbase`. However this is not tested.
- Option 2: Build from Source *(Recommended)*
  - First build AStyle with CMake or XCode.
  - Build Dice Simulation `pro` file.

### Windows
- Option 1: Download Release *(Recommended)*
- Option 2: Build from Source
  - You can try using the `AStyle.exe`. If it fails, build it with CMake.
  - Build Dice Simulation `pro` file.

### Linux
You have no choice but to build it yourself currently.
But it has been tested on Ubuntu 20, with Qt 6.2.2.

## Project Schedule

### Version 0.x

In version 0.x, Dice Simulation will be able to convert `ds`(`ds-cpp`) file to standard `cpp` file for simulation.
During this time, a visual studio code extension will be developed in addition to the GUI tool.

Here the task is split into four components:
- **ds-convert**: Convert `ds`(`ds-cpp`) file to standard `cpp` file linked to ReactPhysics3D library.
- **ds-compile**: Use C++ compilers (GCC/Clang/MSVC) to compile the converted `cpp` file. Error information is also needed to be stored to a `ds-err` (in the format of `json`) file and log information into a `ds-log` file.
- **ds-gui**: A Qt-based GUI tool for the language `ds`. Components include *Editor*, *Terminal*, *Snippet*, etc.

### Version 1.x

Offer visual simulation using OpenGL.

## Documentation

Documentation is published at https://dice.teddy-van-jerry and is in the repo [Teddy-van-Jerry/Dice_Simulation_Online_Doc](https://github.com/Teddy-van-Jerry/Dice_Simulation_Online_Doc) or [Dice-Simulation/Dice_Simulation_Online_Doc](https://github.com/Teddy-van-Jerry/Dice_Simulation_Online_Doc).

## VS Code Extension

- Repo: [Teddy-van-Jerry/Dice_Simulation_VSC](https://github.com/Teddy-van-Jerry/Dice_Simulation_VSC)
- Market Place: https://marketplace.visualstudio.com/items?itemName=Teddy-van-Jerry.dice-simulation
