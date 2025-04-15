#include "scene_generator.h"
#include "frame.h"
#include "material.h"
#include "math.h"
#include "objects.h"
#include "texture.h"
#include <memory>

void generate_scene(std::vector<obj_pointer> &shapes) {

    float root3 = std::sqrt(3);
    float root3_ = 1 / root3;
    float root2 = std::sqrt(2);

    mat_pointer diffuse_white =
        std::make_shared<MaterialDiffuse>(Vec3(1, 1, 1));

    obj_pointer t1 = std::make_shared<Triangle>(
        Vec3(0, 0, -4 * root3_), Vec3(-2, 0, 2 * root3_),
        Vec3(2, 0, 2 * root3_), diffuse_white);
    obj_pointer t2 = std::make_shared<Triangle>(
        Vec3(0, 0, -4 * root3_), Vec3(-2, 0, 2 * root3_),
        Vec3(0, -4 * root2 * root3_, 0), diffuse_white);
    obj_pointer t3 = std::make_shared<Triangle>(
        Vec3(0, 0, -4 * root3_), Vec3(0, -4 * root2 * root3_, 0),
        Vec3(2, 0, 2 * root3_), diffuse_white);
    obj_pointer t4 = std::make_shared<Triangle>(
        Vec3(0, -4 * root2 * root3_, 0), Vec3(-2, 0, 2 * root3_),
        Vec3(2, 0, 2 * root3_), diffuse_white);

    t1->frame.origin.z = -8;
    t2->frame.origin.z = -8;
    t3->frame.origin.z = -8;
    t4->frame.origin.z = -8;

    t1->frame.lockFrame();
    t2->frame.lockFrame();
    t3->frame.lockFrame();
    t4->frame.lockFrame();

    tex_pointer b = std::make_shared<Texture>("pre-uv.png");

    t4->set_texture(b);

    shapes.push_back(t1);
    shapes.push_back(t2);
    shapes.push_back(t3);
    shapes.push_back(t4);
}
