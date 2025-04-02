@echo off

rem SOURCES
set SOURCES=../main.cpp
set SOURCES=%SOURCES% ../glad/glad.c
set SOURCES=%SOURCES% ../src/Shader.cpp
set SOURCES=%SOURCES% ../src/Entity.cpp
set SOURCES=%SOURCES% ../src/Sprite.cpp

rem LIBS
set LIBS=opengl32.lib ../GLFW/lib/glfw3dll.lib

mkdir build
pushd build
cl -Zi /EHsc %SOURCES% /I ../ /I ../include/ /link %LIBS%
xcopy ..\GLFW\lib\glfw3.dll . /d
popd build
