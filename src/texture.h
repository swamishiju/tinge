#pragma once
#include "math.h"
#include <memory>
#include <vector>

struct Texture {
    std::vector<std::vector<Vec3>> data;
    int width, height, n;

    Texture(const std::string &fname);
    Vec3 uv(float u, float v);
};

using tex_pointer = std::shared_ptr<Texture>;
