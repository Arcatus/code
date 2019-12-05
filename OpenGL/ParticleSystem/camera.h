#ifndef CAMERAINFO_H
#define CAMERAINFO_H

#include "math3d.h"

struct Camera
{
    Vector3 position = { 0.0f, 0.0f, 0.0f };
    Vector3 target   = { 0.0f, 0.0f, 0.0f };
    Vector3 up       = { 0.0f, 0.0f, 0.0f };

    float  speed     = 10.0f;
    double mouseX    = 0.0;
    double mouseY    = 0.0;
    bool   mouseInit = true;
};

#endif // CAMERAINFO_H
