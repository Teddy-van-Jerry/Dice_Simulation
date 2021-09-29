# `ext`

There are external dependency libraries for Dice Simulation.

## qscintilla
[QScintilla](https://riverbankcomputing.com/software/qscintilla) is used to provide syntax highlight in the code editor.

Building the `pro` file is needed.

> Version 2.13.0 downloaded at https://riverbankcomputing.com/software/qscintilla/download.

## reactphysics3d
[ReactPhysics3D](https://www.reactphysics3d.com) is used as the physics engine.

> Version 0.8.0 from [reactphysics3d](https://github.com/DanielChappuis/reactphysics3d) with last commit c1d6146291cca3d4af8724a4f15005ea8fcd8331.

## astyle
[AStyle](https://sourceforge.net/projects/astyle) is used to format the generated `cpp` code.

Windows, Mac and Linux versions are in folder `win`, `mac`, `linux` respectively.
Windows version has an official build version and Mac has my build version on Apple chip M1.
On theory, for Mac and Linux versions, astyle should be built manually.
I prefer using `cmake`.

> Version 3.1
