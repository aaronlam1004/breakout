#pragma once

#include <Constants.hpp>
#include <Entity.hpp>
#include <Shader.hpp>

const float TRIANGLE_VERTICES[] = {
     // aPos (xyz)      // aColor (RGB)
    -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
     0.0f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f,
     0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f
};

const VertexAttributes TRIANGLE_ATTRS[] = {
    { 0, 3, 6 * sizeof(float), 0 }, // aPos
    { 1, 3, 6 * sizeof(float), 3 * sizeof(float) } // aColor
};
