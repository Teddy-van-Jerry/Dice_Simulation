# Dice Simulation

This is script-based software to enable different kinds of dice simulation in a visual way.

## Current Version

| Component  | Version | Description |
| :--------: | :-----: | :---------: |
|  Project   |  0.0.1  |             |
| ds-convert |    -    |             |
| ds-compile |    -    |             |
|   ds-gui   |    -    |             |
|   ds-vsc   |    -    |             |

> Documentation version will follow the project version.

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
