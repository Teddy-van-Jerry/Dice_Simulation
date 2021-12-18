# Brief Information

<img alt="Dice Simulation Logo" src="https://dice.teddy-van-jerry.org/wp-content/uploads/2021/12/ds-banner.png" style="max-height: 80pt;"/>

This is script-based software to enable different kinds of dice simulation in a visual way.

## Current Version

|  Component  | Version | Description |
| :---------: | :-----: | :---------: |
|   Project   |  0.1.0  | Main project. |
| ds-convert  |  0.1.0  | Convert `ds` code to standard `cpp` code. |
| ds-compile  |    -    | Compile the converted `cpp` code. |
|   ds-help   |    -    |             |
| ds-maintain |    -    |             |
|   ds-gui    |    -    |             |
|   ds-vsc    |  0.0.1  | Visual Studio Code Extension for DS. |

> Documentation version will follow the project version.

In this version, basic functions of ds-convert are achieved but tests have not been done.

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
