#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "texture.h"

#include <obj/model.h>

typedef struct Scene
{
	Model model[20];
    Material material[20];
    GLuint texture_id[20];
} Scene;

/**
 * Initialize the scene by loading models.
 */
void init_scene(Scene* scene);

/**
 * Set the lighting of the scene.
 */
void set_lighting();


/**
 * Set the current material.
 */
void set_material(const Material* material);

/**
 * Draw the scene objects.
 */
void draw_scene(const Scene* scene);

/**
 * Draw the origin of the world coordinate system.
 */

#endif /* SCENE_H */
