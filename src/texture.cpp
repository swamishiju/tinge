#include "texture.h"
#include "util.h"
#include <vector>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image/stb_image.h>

Texture::Texture(const std::string &fname) {

    unsigned char *read_data = stbi_load(fname.data(), &width, &height, &n, 3);

    if (read_data) {
        data =
            std::vector<std::vector<Vec3>>(height, std::vector<Vec3>(width, 0));

        for (int i = 0; i < height; i++)
            for (int j = 0; j < width; j++)
                data[i][j] = Vec3(read_data[3 * (width * i + j)],
                                  read_data[3 * (width * i + j) + 1],
                                  read_data[3 * (width * i + j) + 2]) /
                             255;
        stbi_image_free(read_data);
    } else {
        width = 3;
        height = 3;

        data.push_back(
            std::vector({Vec3(0, 0, 0), Vec3(1, 0, 0.86), Vec3(0, 0, 0)}));
        data.push_back(
            std::vector({Vec3(1, 0, 0.86), Vec3(0, 0, 0), Vec3(1, 0, 0.86)}));
        data.push_back(
            std::vector({Vec3(0, 0, 0), Vec3(1, 0, 0.86), Vec3(0, 0, 0)}));
    }
}

Vec3 Texture::uv(float u, float v) {
    int x = clamp(u * width, 0, width - 1);
    int y = clamp(v * height, 0, height - 1);
    return data.at(y).at(x);
}
