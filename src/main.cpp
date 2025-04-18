#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>
#include <filesystem>
#include <imgui.h>
#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include <core.hpp>
#include <stb_image.h>

int main()
{
    if (!glfwInit())
        return -1;

    GLFWwindow *window = glfwCreateWindow(1280, 720, "Hello, world!", nullptr, nullptr);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    std::cout << "Running Iori Engine version: " << Iori::Core::getVersion() << std::endl;

    glfwMaximizeWindow(window);

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    (void)io;

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 130");

    const auto cwd = std::filesystem::current_path();

    std::string icons_path[3] = {(cwd / "resources" / "icon_128.png").string(),
                                 (cwd / "resources" / "icon_64.png").string(),
                                 (cwd / "resources" / "icon_32.png").string()};

    GLFWimage icons[3];
    for (int i = 0; i < 3; i++)
    {
        int width, height, channels;
        unsigned char *data = stbi_load(icons_path[i].c_str(), &width, &height, &channels, 0);
        if (data)
        {
            icons[i].pixels = data;
            icons[i].width = width;
            icons[i].height = height;
        }
        else
        {
            std::cerr << "Failed to load " << icons_path[i] << std::endl;
        }
    }

    glfwSetWindowIcon(window, 3, icons);

    ImGui::StyleColorsDark();

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        glfwSetWindowCloseCallback(window, [](GLFWwindow *window) { glfwSetWindowShouldClose(window, true); });

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();

        ImGui::NewFrame();

        ImGui::Begin("Some window");
        ImGui::Text("Hello, world!");

        // Setup a counter
        static int counter = 0;
        ImGui::Text("Counter: %d", counter);
        ImGui::SameLine();
        if (ImGui::Button("Increment"))
            counter++;
        ImGui::SameLine();
        if (ImGui::Button("Decrement"))
            counter--;
        ImGui::SameLine();

        if (ImGui::Button("Quit"))
        {
            glfwSetWindowShouldClose(window, true);
        }

        ImGui::End();

        ImGui::Begin("Another winodw");
        ImGui::Text("This is another window");

        if (ImGui::Button("Quit"))
        {
            glfwSetWindowShouldClose(window, true);
        }
        ImGui::End();

        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
