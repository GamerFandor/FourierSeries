#include <iostream>
#include "Platform.h"
#include "Core/Application.h"


#ifdef PLATFORM_WINDOWS

#include <Windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    Application app;
    app.Run();

    return EXIT_SUCCESS;
}

#else

int main(void)
{
    Application app;
    app.Run();

    return EXIT_SUCCESS;
}

#endif