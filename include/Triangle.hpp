#pragma once

#include <Entity.hpp>
#include <Shader.hpp>

const float TRIANGLE_VERTICES[] = {
     // aPos (xyz)      // aColor (RGB)
    -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
     0.0f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f,
     0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f
};

const int TRIANGLE_ATTR_COUNT[] = {
    3, 3
};
