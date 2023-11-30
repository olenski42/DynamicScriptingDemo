# DynamicScriptingDemo
This project is primarily a learning exercise, providing a simple example to explore the development of a dynamically linked scripting system in C++ on the Unix platform.

## build (cmake)
- clone the repository
```command
git clone https://github.com/olenski42/DynamicScriptingDemo.git
```
- create the build folders
```command
mkdir DynamicScriptingDemo/src/base/build/
```
```command
mkdir DynamicScriptingDemo/src/script/build/
```
- compile the script
```command
cd DynamicScriptingDemo/src/script/build/
```
```command
cmake .. && make
```

- compile the base
```command
cd ../../base/build
```
```command
cmake .. && make
```

## usage
- run the base
```command
./base
```
- run the MyScript::OnUpdate function with 'a'
- edit the MyScript::OnUpdate function in src/script/MyScript.hpp
- compile the script (from src/script/build/)
```command
cmake .. && make
```
- reload the script with 'r'
- rerun the OnUpdate function with 'a'
- quit with 'q'
