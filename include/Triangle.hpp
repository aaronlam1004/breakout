#pragma once

#include <Entity.hpp>
#include <Shader.hpp>
#include <Constants.hpp>

const float TRIANGLE_VERTICES[] = {
     // aPos (xyz)      // aColor (RGB)
    -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
     0.0f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f,
     0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f
};

const int TRIANGLE_ATTRIBUTE_SLICES[] = {
    3, 3
};


const VertexAttributes TRIANGLE_ATTRIBUTES = {
    2, 6, (unsigned int*) TRIANGLE_ATTRIBUTE_SLICES
};
