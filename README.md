# urfu-gl-lab
OpenGL labs

Author: Saveliy Pototskiy

Website: savalione.com

Completed as part of the laboratory works on the subject: "Technologies of parallel programming on GPU"

## Libraries
1. OpenGL
2. GLFW
3. spdlog

## Compile
### Windows
#### MinGW
1. ```cmake -G"MinGW Makefiles" ..```
    * To support the ```clangd``` tool, you need to add the parameter ```-DCMAKE_EXPORT_COMPILE_COMMANDS=1```
2. ```mingw32-make```

Example of CMake command: ``cmake -G"MinGW Makefiles" -DCMAKE_EXPORT_COMPILE_COMMANDS=1 ..``

#### Ninja
1. ```cmake -G"Ninja" -DCMAKE_EXPORT_COMPILE_COMMANDS=1 ..```
2. ```ninja```

Example of CMake command: ``cmake -G"Ninja" -DCMAKE_EXPORT_COMPILE_COMMANDS=1 ..``

#### LLVM Clang (ninja)
An example of building a project using the ```LLVM Clang``` compiler and the ```ninja```, tool, if there are several compilers on the system:
1. ```cmake.exe -G"Ninja" -DCMAKE_C_COMPILER="C:/bin/mingw64/bin/clang.exe" -DCMAKE_CXX_COMPILER="C:/bin/mingw64/bin/clang++.exe" ..```
2. ```ninja```

Example of CMake command: ``cmake.exe -G"Ninja" -DCMAKE_C_COMPILER="C:/bin/mingw64/bin/clang.exe" -DCMAKE_CXX_COMPILER="C:/bin/mingw64/bin/clang++.exe" -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -DCMAKE_BUILD_TYPE=Release ..``

### Linux
1. ```git clone --recursive-submodules https://github.com/SavaLione/urfu-gl-lab```
2. ```cd urfu-tspn-lab```
3. ```mkdir build```
4. ```cd build```
5. ```cmake ..```
    * To support the ```clangd``` tool, you need to add the parameter ```-DCMAKE_EXPORT_COMPILE_COMMANDS=1```
6. ```make```

Example of CMake command: ``cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 ..``

## etc.
### OpenGL
```
.vert - a vertex shader
.tesc - a tessellation control shader
.tese - a tessellation evaluation shader
.geom - a geometry shader
.frag - a fragment shader
.comp - a compute shader
```

Also we have ``.glsl`` file extension.

And also we have this:
```
.vert
.frag
.comp
.geom
.tesc
.tese
.mesh
.task
.rgen
.rchit
.rmiss
```

#### SPIR-V
The Standard, Portable Intermediate Representation - V (SPIR-V) is an intermediate language for defining shaders.

Compile:
```sh
git clone https://github.com/KhronosGroup/SPIRV-Tools.git spirv-tools
cd spirv-tools
python3 utils/git-sync-deps
mkdir build
cd build
cmake.exe -G"Ninja" -DCMAKE_C_COMPILER="C:/bin/mingw64/bin/clang.exe" -DCMAKE_CXX_COMPILER="C:/bin/mingw64/bin/clang++.exe" -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -DSPIRV_SKIP_TESTS=ON ..
```

```
cmake.exe -G"Ninja" -DCMAKE_C_COMPILER="C:/LLVM/bin/clang.exe" -DCMAKE_CXX_COMPILER="C:/LLVM/bin/clang++.exe" -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -DCMAKE_BUILD_TYPE=Release ..
```