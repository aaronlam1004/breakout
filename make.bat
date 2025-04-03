@echo off

rem SOURCES
set SOURCES=../main.cpp
set SOURCES=%SOURCES% ../src/Logger.cpp
set SOURCES=%SOURCES% ../src/Shader.cpp
set SOURCES=%SOURCES% ../src/Mesh.cpp
set SOURCES=%SOURCES% ../src/Scene.cpp

rem SOURCES (3rd party)
set SOURCES=%SOURCES% ../3rdparty/glad/glad.c

rem LIBS
set LIBS=opengl32.lib ../3rdparty/GLFW/lib/glfw3dll.lib

mkdir build
pushd build
cl -Zi /EHsc %SOURCES% /I ../3rdparty /I ../include/ /link %LIBS%
xcopy ..\3rdparty\GLFW\lib\glfw3.dll . /d
popd build
