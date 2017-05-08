#pragma once
#include "vertex_buffer.h"
#include "vertex_array.h"
#include "shader.h"
#include "shader_program.h"
#include "texture.h"
#include "framebuffer.h"
#include "context.h"
#include "window.h"

#define GLSL(version, shader)  "#version " #version "\n" #shader