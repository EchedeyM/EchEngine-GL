#include "Application.h"
#include <GLFW/glfw3.h>
#include <iostream>

Application::Application()
    : m_Running(true), m_Window(nullptr)
{
    std::cout << "EchEngine Application created" << std::endl;
    if(!Init())
    {
        std::cerr << "Failed to initialize Application" << std::endl;
        m_Running = false;
    }
}

Application::~Application()
{
    if(m_Window)
        glfwDestroyWindow(m_Window);
    glfwTerminate();

    std::cout << "EchEngine Application destroyed" << std::endl;
}

bool Application::Init()
{
    if(!glfwInit())
        return false;

    // Configuración OpenGL mínima
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_Window = glfwCreateWindow(800, 600, "EchEngine Window", nullptr, nullptr);
    if(!m_Window)
        return false;

    glfwMakeContextCurrent(m_Window);
    return true;
}

void Application::ProcessInput()
{
    if(glfwGetKey(m_Window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        m_Running = false;
}

void Application::MainLoop()
{
    while(m_Running && !glfwWindowShouldClose(m_Window))
    {
        ProcessInput();

        // Clear screen
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(m_Window);
        glfwPollEvents();
    }
}

void Application::Run()
{
    MainLoop();
}
