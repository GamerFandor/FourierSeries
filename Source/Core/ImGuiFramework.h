#pragma once

#include "imgui.h"
#include "implot.h"
#include "imgui_internal.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <stdio.h>
#define GL_SILENCE_DEPRECATION
#if defined(IMGUI_IMPL_OPENGL_ES2)
    #include <GLES2/gl2.h>
#endif
#include <GLFW/glfw3.h>

static void glfw_error_callback(int error, const char* description)
{
    fprintf(stderr, "GLFW Error %d: %s\n", error, description);
}

class ImGuiFramework
{
public:
    ImGuiFramework();
    virtual ~ImGuiFramework();
    void Run();
    virtual void StartUp() = 0;
    virtual void Update() = 0;

private:
    GLFWwindow* window;
    ImGuiIO* io;
    ImVec4 clear_color = ImVec4(0.10f, 0.10f, 0.10f, 1.00f);
};