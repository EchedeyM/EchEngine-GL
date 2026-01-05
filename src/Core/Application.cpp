#include "Application.h"
#include <iostream>

Application::Application()
    : m_Running(true)
{
    std::cout << "EchEngine Application created" << std::endl;
}

Application::~Application()
{
    std::cout << "EchEngine Application destroyed" << std::endl;
}

void Application::Run()
{
    while (m_Running)
    {
        // TODO: update, render, events
        std::cout << "Running..." << std::endl;
        m_Running = false; // TEMP: exit after one loop
    }
}