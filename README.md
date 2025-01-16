# Installation and Compilation Instructions

## 1. Installing the Clang Toolchain

To install the Clang toolchain for your project, follow these steps:

1. Open your terminal and navigate to the `scripts` directory.

```bash
cd scripts
```
2. Run the following command to begin the setup:

```bash
python Setup.py
```
3. Follow the on-screen instructions. You'll just need to hit `y` when prompted to continue.

> **Disclaimer**: The `Setup.py` script is only available on Windows.  
> Linux users should install a C++ compiler of their choice (e.g., Clang or GCC) and set up the required dependencies manually.

---

## 2. Compiling the Dino Game Example

Once you've set up the Clang toolchain (on Windows), compile the Dino game by following these steps:

1. Navigate to the `game` directory:

```bash
cd game
```

2. Run the following command to compile the game using Clang:

```bash
clang++ dino.cpp -o dino_game.exe -Iinclude -Llib -lraylib -lopengl32 -lgdi32 -lwinmm
```

Here's what each part does:
- `dino.cpp` — The source file for the Dino game.
- `-o dino_game.exe` — Specifies the output executable file name.
- `-Iinclude` — Includes the header files from the `include` directory.
- `-Llib` — Links the libraries from the `lib` directory.
- `-lraylib -lopengl32 -lgdi32 -lwinmm` — Links the necessary libraries for Raylib and OpenGL.

> **Disclaimer**: The Raylib libraries (`libraylib`, `opengl32`, `lgdi32`, and `winmm`) are **only available for Windows**.  
> Linux users will need to use appropriate libraries for their platform and modify the compile command accordingly.

3. After compiling, run the game by executing:

```bash
./dino_game.exe
```

---

With these steps, you should have everything set up and ready to play the example Dino game, as well as continue developing C++ on a more higher level.
The setup script not only installs the compiler, but also the industry standard buildsystem **CMake** and **Ninja**, which work well in tandem to compile larger scale C++ projects.
