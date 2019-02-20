#ifndef CAMERA_H
#define CAMERA_H

#include "GL/glew.h"
#include "math3d.h"

struct Camera
{
    Vector3 position;
    Vector3 target;
    Vector3 up;
    GLfloat speed;
    bool enable;
};

#endif // CAMERA_H
