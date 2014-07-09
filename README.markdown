# Demo app for packager
This is just a simple app to demonstrate how to work with my proposal CVRA package manager.
It simply searches for a c++ style comment (`// asd`) and exits when there is a match.

## Preparing for build
Preparing for build is done in two steps :

1. Download all dependencies
2. Generate build files

To do both of those steps, supposing the "package manager" is somewhere in your path, simply run `packager.py` from the root of the project.

It will download all dependencies into the `dependencies/` subfolder and generate a CMakeList (used for tests) and a Makefile (used for application build).
I could have put both targets in the `CMakeLists.txt` but the goal here was to show the features of template inheritance and the support of Makefile, which will be useful when we want to create the ARM binary.

## Building app
Simply run `make` and a binary named "app" will be created in the root folder.

## Building tests

```
mkdir build; cd build
cmake ..
make
./tests
```



