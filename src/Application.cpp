#include "Application.h"

#include <iostream>

namespace wot {
    Application::Application() {

    }

    void Application::PreInit() {
        std::cout << "PreInit:" << std::endl;
    }

    void Application::Init() {
        std::cout << "Init:" << std::endl;
    }

    void Application::Run() {
        std::cout << "Run:" << std::endl;
    }

    void Application::Close() {
        std::cout << "Close:" << std::endl;
    }

    void Application::Start() {
        PreInit();
        Init();
        Run();
        Close();
    }
} /* wot */
