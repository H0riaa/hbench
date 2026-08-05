# hbench

**hbench** is a lightweight C++ profiling and benchmarking library designed to measure code execution time. It provides a simple API for function benchmarking, manual profiling, and RAII-based scoped timers.

It uses `std::chrono` high-resolution clocks for accurate measurements and provides execution statistics such as minimum, maximum, average, and median times.

## Features

* Function benchmarking (`HBENCH()`)
* Manual profiling (`HSTART()` / `HSTOP()`)
* RAII scoped timer
* High-resolution timing using `std::chrono`
* Execution statistics:
  * Minimum
  * Maximum
  * Average
  * Median

## Requirements

* C++17
* CMake 3.20+

## Usage

Include the library header:

```cpp
#include "hbench.h"
```

Then use one of the available profiling methods:

* Function benchmarking with `HBENCH()`
* Manual profiling with `HSTART()` / `HSTOP()`
* RAII scoped timer

## Building

hbench uses **CMake** for building.

1. Create a build directory:
```
mkdir build
cd build
```

2. Configure the project:
```
cmake ..
```

3. Build the library:
```
cmake --build .
```
## Run

### Windows

.\Debug\hbench.exe

### Linux

./hbench

## Cross-platform Support

* Windows (MSVC)
* Linux (GCC/g++)

## Tools

* CMake
* clang-format