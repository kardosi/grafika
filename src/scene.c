#include "scene.h"

#include <GL/glut.h>

#include <obj/load.h>
#include <obj/draw.h>

 double angle [2] = {0,0};
 double angle2[2] ={50,50};
 double angle3[2]={-50,-50};

void init_scene(Scene* scene)
{
    
	load_model(&(scene->model[0]), "obj/porsche.obj");
	load_model(&(scene->model[1]), "obj/gomb.obj");
	load_model(&(scene->model[2]), "obj/duck.obj");
	load_model(&(scene->model[3]), "obj/hare.obj");
	scene->texture_id[0] = load_texture("images/piros.jpg");
    scene->texture_id[1] = load_texture("images/hatter.jpg");
	scene->texture_id[2] = load_texture("images/fold.jpg");
	scene->texture_id[3] = load_texture("images/hold.jpg");
	scene->texture_id[4] = load_texture("images/duck.jpg");
	scene->texture_id[5] = load_texture("images/hare.jpg");
	scene->texture_id[6] = load_texture("images/sugo.jpg");

    glBindTexture(GL_TEXTURE_2D, scene->texture_id);

    scene->material[0].ambient.red = 0.25;
    scene->material[0].ambient.green = 0.25;
    scene->material[0].ambient.blue = 0.25;
	
    scene->material[0].diffuse.red = 0.4;
    scene->material[0].diffuse.green = 0.4;
    scene->material[0].diffuse.blue = 0.4;
	
    scene->material[0].specular.red = 0.774597;
    scene->material[0].specular.green = 0.774597;
    scene->material[0].specular.blue = 0.774597;
	
    scene->material[0].shininess = 0.8;
}

void set_lighting()
{
    float ambient_light[] = { 0.2, 0.2, 0.2, 1.0 };
    float diffuse_light[] = { 1.0, 1.0, 1.0, 1.0 };
    float specular_light[] = { 1.0, 1.0, 1.0, 1.0 };
    float position[] = { 1.0, 1.0, 1.0, 0.0 };
	float spot_direction[] = { -1.0, -1.0, 0.0 };

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 45.0);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_direction);
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 2.0);
}

void set_material(const Material* material)
{
    float ambient_material_color[] = {
        material->ambient.red,
        material->ambient.green,
        material->ambient.blue
    };

    float diffuse_material_color[] = {
        material->diffuse.red,
        material->diffuse.green,
        material->diffuse.blue
    };

    float specular_material_color[] = {
        material->specular.red,
        material->specular.green,
        material->specular.blue
    };

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular_material_color);

    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &(material->shininess));
}

void draw_scene(const Scene* scene)
{
    angle[0]+=2;
    angle[1]+=3;
	angle2[0]-=0.5;
	angle2[1]+=0.5;
	angle3[0]+=0.7;
	angle3[1]-=0.7;
	set_material(&(scene->material));
    set_lighting();
	glPushMatrix();
                glRotatef(-270,1,0,0);
				if(angle2[0]>=-50)
				{
					glTranslatef(10,-5,angle2[0]);
					angle2[1]=50;
				}
				else if(angle2[0]<-50)
				{
					glTranslatef(10,-5,angle2[1]);
					angle2[0]=50;
				}

				glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);
				glBindTexture(GL_TEXTURE_2D, scene->texture_id[0]);
				glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
				draw_model(&(scene->model[0]));
    glPopMatrix();
	glPushMatrix();
				glScalef(500,500,500);
				glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);
				glBindTexture(GL_TEXTURE_2D, scene->texture_id[1]);
				glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
                draw_model(&(scene->model[1]));
    glPopMatrix();
	glPushMatrix();
				glScalef(20,20,20);
				glTranslatef(3,-1,0.5);
				glRotatef(angle[1],1,0,0);
				glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);
				glBindTexture(GL_TEXTURE_2D, scene->texture_id[2]);
				glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
                draw_model(&(scene->model[1]));
    glPopMatrix();
	glPushMatrix();
				glScalef(1,1,1);
				glTranslatef(3,-7,1);
				glRotatef(angle[0],1,0,0);
				glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);
				glBindTexture(GL_TEXTURE_2D, scene->texture_id[3]);
				glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
                draw_model(&(scene->model[1]));
    glPopMatrix();
    glPushMatrix();
				glScalef(0.3,0.3,0.3);
				glRotatef(-270,0,0,1);
				if(angle3[0]<=50)
				{
					glTranslatef(angle3[0],-6,-6);
					angle3[1]=-50;
				}
				else if(angle3[0]>50)
				{
					glTranslatef(angle3[1],-6,-6);
					angle3[0]=-50;
				}
				glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);
				glBindTexture(GL_TEXTURE_2D, scene->texture_id[4]);
				glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
                draw_model(&(scene->model[2]));
    glPopMatrix();
	glPushMatrix();
				glScalef(0.3,0.3,0.3);
				glTranslatef(0,6,1);
				glRotatef(angle[1],0,0,1);
				glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);
				glBindTexture(GL_TEXTURE_2D, scene->texture_id[5]);
				glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
                draw_model(&(scene->model[3]));
    glPopMatrix();
	
	
}


