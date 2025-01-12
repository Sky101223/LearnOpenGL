#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <array>

#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "LoadShader.h"
#include "Texture.h"

#include "Renderer.h"

static void framebuffer_size_callback(GLFWwindow *window, int width, int height);
static void processInput(GLFWwindow *window);

int main()
{
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

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

        std::array<const char*, 2> paths {
            "media/shaders/textures/texture.vert",
            "media/shaders/textures/texture.frag"
        };

        VertexBuffer vb(vertices, sizeof(vertices));
        VertexArray va;

        VertexBufferLayout layout;
        layout.push(TYPE::FLAOT, 3);
        layout.push(TYPE::FLAOT, 3);
        layout.push(TYPE::FLAOT, 2);
        va.addBuffer(vb, layout);

        IndexBuffer ib(indices, sizeof(indices));

        Shader ourShader(paths);

        Texture texture1("media/container.jpg", Level::RGB);
        Texture texture2("media/awesomeface.png", Level::RGBA);

        ourShader.bind();
        ourShader.setInt("texture1", 0);
        ourShader.setInt("texture2", 1);

        va.unbind();
        vb.unbind();
        ib.unbind();
        ourShader.unbind();

        Renderer renderer;

        glViewport(0, 0, 800, 600);
        glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

        while (!glfwWindowShouldClose(window))
        {
            processInput(window);

            renderer.clear();

            texture1.bind(0);
            texture2.bind(1);
            renderer.draw(va, ib, ourShader);

            glfwSwapBuffers(window);
            glfwPollEvents();
        }
    }

    glfwTerminate();
    return 0;
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GL_TRUE)
        glfwSetWindowShouldClose(window, GL_TRUE);
}
