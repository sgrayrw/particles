# particles

Implements particle systems using openGL

## Unique demo

A "Snake Game" made with a square particle travelling horizontally and vertically. Up/down/left/right keys are used
to control the direction the snake is heading. The snake leaves a trail and can wrap around the window!

https://user-images.githubusercontent.com/43045651/116641250-58ec2380-a93a-11eb-97b7-ee4aab78d94e.mov

## How to build

*Windows*

Open git bash to the directory containing this repository.

```
particles $ mkdir build
particles $ cd build
particles/build $ cmake -G "Visual Studio 16 2019" ..
particles/build $ start CS312-Particles.sln
```

Your solution file should contain two projects: `pixmap_art` and `pixmap_test`.
To run from the git bash command shell, 

```
particles/build $ ../bin/Debug/billboard
particles/build $ ../bin/Debug/confetti
particles/build $ ../bin/Debug/demo
```

*macOS*

Open terminal to the directory containing this repository.

```
particles $ mkdir build
particles $ cd build
particles/build $ cmake ..
particles/build $ make
```

To run each program from build, you would type

```
particles/build $ ../bin/billboard
particles/build $ ../bin/confetti
particles/build $ ../bin/demo
```

## Results

TODO: Show your work
