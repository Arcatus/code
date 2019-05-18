#ifndef BODY_H
#define BODY_H

#include "math3d.h"

struct Body {
	GLuint vao;
	Vector3 position;
	Vector3 velocity;
	float mass;
};

#endif // BODY_H