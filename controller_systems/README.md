# Running
The projects in this repository require Conan to be built and run successfully. Unless stated otherwise,
building (and testing) can be accomplished with
```sh
cd lab_##
conan build . 

# For testing
./build/Release/test_suite

# For running 
./build/Release/lab_##
```

Building for debugging can be accomplished with
```sh
cd lab_##
conan build . --settings=build_type=Debug
gdb ./build/Debug/lab_##
```
