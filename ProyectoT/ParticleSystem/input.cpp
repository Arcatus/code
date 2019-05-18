#include "input.h"

void poll_keyboard(GLFWwindow* window, Camera* camera, GLfloat deltaTime)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }

    if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
    {
        Vector3 sideVector;
        Vector3CrossProduct(&camera->target, &camera->up, &sideVector);
        Vector3Normalize(&sideVector);

        camera->position = camera->position -
            camera->speed * deltaTime * sideVector;
    }

    if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
    {
        Vector3 sideVector;
        Vector3CrossProduct(&camera->target, &camera->up, &sideVector);
        Vector3Normalize(&sideVector);

        camera->position = camera->position +
            camera->speed * deltaTime * sideVector;
    }

    if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
    {
        camera->position = camera->position +
            camera->speed * deltaTime * camera->target;
    }

    if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
    {
        camera->position = camera->position -
            camera->speed * deltaTime * camera->target;
    }
}

void poll_mouse(GLFWwindow* window, Camera* camera)
{
    GLdouble cursorX, cursorY;
    glfwGetCursorPos(window, &cursorX, &cursorY);

    if(camera->mouseInit)
    {
        camera->mouseX = cursorX;
        camera->mouseY = cursorY;
        camera->mouseInit = GL_FALSE;
    }

    GLfloat deltaX = (GLfloat)(camera->mouseX - cursorX);
    GLfloat deltaY = (GLfloat)(camera->mouseY - cursorY);

    camera->mouseX = cursorX;
    camera->mouseY = cursorY;

    GLfloat hAngle = deltaX / 5.0f;
    GLfloat vAngle = deltaY / 5.0f;

    Matrix3x3 rotation;
    Matrix3x3MakeRotation(&camera->up, hAngle, &rotation);
    Vector3 newTarget;
    Matrix3x3MultiplicationByVector(&rotation, &camera->target, &newTarget);

    camera->target.x = newTarget.x;
    camera->target.y = newTarget.y;
    camera->target.z = newTarget.z;

    Vector3 hAxis;
    Vector3CrossProduct(&camera->up, &newTarget, &hAxis);
    Vector3Normalize(&hAxis);
    Matrix3x3MakeRotation(&hAxis, vAngle, &rotation);
    Matrix3x3MultiplicationByVector(&rotation, &camera->target, &newTarget);

    camera->target.x = newTarget.x;
    camera->target.y = newTarget.y;
    camera->target.z = newTarget.z;
}
