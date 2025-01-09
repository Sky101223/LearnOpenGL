#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "VertexArray.h"
#include "LoadShader.h"

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

    GLFWwindow *window = glfwCreateWindow(800, 600, "Tirangle", NULL, NULL);
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
        GLfloat vertices[] = {
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f,  0.5f, 0.0f
        };

        std::vector<const GLchar*> paths;
        paths.push_back("media/shaders/triangles/triangle.vert");
        paths.push_back("media/shaders/triangles/triangle.frag");

        Shader shaders(paths);
        VertexBuffer VBO(vertices, sizeof(vertices));
        VertexArray VAO;
        VertexBufferLayout layout;

        layout.push(TYPE::FLAOT, 3);
        VAO.addBuffer(VBO, layout);

        VAO.unbind();
        VBO.unbind();
        shaders.unbind();

        Viewport(window);

        while (!glfwWindowShouldClose(window))
        {
            processInput(window);

            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            shaders.bind();
            VAO.bind();

            glDrawArrays(GL_TRIANGLES, 0, 3);

            glfwSwapBuffers(window);
            glfwPollEvents();
        }
    }

    glfwTerminate();
    return 0;
}
