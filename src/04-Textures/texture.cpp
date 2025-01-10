#include <iostream>
#include <cmath>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Renderer.h"

#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "LoadShader.h"
#include "Texture.h"

static void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

static void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GL_TRUE)
    {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
}

static void Initialize()
{
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#if __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif   
}

static void Viewport(GLFWwindow *window)
{
    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
}

int main()
{
    Initialize();

    GLFWwindow *window = glfwCreateWindow(800, 600, "Texture", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    {
        float vertices[] = {
             0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,
             0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,
            -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,
            -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f
        };

        unsigned int indices[] = {
            0, 1, 3,
            1, 2, 3
        };

        std::vector<const char*> paths;
        paths.push_back("media/shaders/triangles/others/textures/texture.vert");
        paths.push_back("media/shaders/triangles/others/textures/texture.frag");

        VertexBuffer vb(vertices, sizeof(vertices));
        VertexArray va;

        VertexBufferLayout layout;
        layout.push(TYPE::FLAOT, 3);
        layout.push(TYPE::FLAOT, 3);
        layout.push(TYPE::FLAOT, 2);
        va.addBuffer(vb, layout);

        IndexBuffer ib(indices, sizeof(indices));

        Shader ourShader(paths);

        Texture texture("media/container.jpg");

        va.unbind();
        vb.unbind();
        ib.unbind();
        ourShader.unbind();

        Renderer renderer;

        Viewport(window);

        while (!glfwWindowShouldClose(window))
        {
            processInput(window);

            // glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            renderer.clear();

            ourShader.bind();

            GLdouble timeValue = glfwGetTime();
            float redValue = static_cast<float>(std::sin(timeValue) / 2.0 + 0.3);
            float greenValue = static_cast<float>(std::sin(timeValue) / 2.0 + 0.4);
            float buleValue = static_cast<float>(std::sin(timeValue) / 2.0 + 0.8);
            float alphaValue = static_cast<float>(std::sin(timeValue) / 2.0 + 0.5);

            ourShader.setFloat("ourColor", redValue, greenValue, buleValue, alphaValue);
            renderer.draw(va, ib, ourShader);

            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

            glfwSwapBuffers(window);
            glfwPollEvents();
        }
    }

    glfwTerminate();
    return 0;
}
