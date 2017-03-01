#pragma once
#include "vertex_buffer.h"
#include "vertex_array.h"
#include "shader.h"
#include "shader_program.h"
#include "texture.h"
#include "context.h"

#define GLSL(version, shader)  "#version " #version "\n" #shader