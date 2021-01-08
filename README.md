# Steps to Reproduce

```
git clone https://github.com/automata172/polyhook-veh-crash.git
cd polyhook-veh-crash/
vcpkg install polyhook2:x64-windows
mkdir build/
cd build/
cmake -DCMAKE_GENERATOR_PLATFORM=x64 -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE=C:\libs\vcpkg\scripts\buildsystems\vcpkg.cmake ..
cmake --build .
../bin/polyhook-veh-crash.exe
```
