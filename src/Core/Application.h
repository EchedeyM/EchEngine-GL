#pragma once

struct GLFWwindow;

class Application
{
public:
    Application();
    ~Application();

    void Run();

private:
    bool Init();
    void ProcessInput();
    void MainLoop();

private:
    bool m_Running;
    GLFWwindow* m_Window;
};