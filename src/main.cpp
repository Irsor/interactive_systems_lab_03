#include "imgui.h"
#include "imgui_internal.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define STB_IMAGE_IMPLEMENTATION
#include "../external/stb/stb_image.h"

#include <iostream>

int main(void)
{
    GLFWwindow *window;

    /* Initialize the library */
    if (!glfwInit())
    {
        return -1;
    }

    float width = 640;
    float height = 480;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(width, height, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Initialize GLAD */
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        return -1;
    }

    /* Initialize ImGui */
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 460 core");

    bool checkBoxValue = false;

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* ImGui Frame */
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // Get GLFW window size
        int fb_width, fb_height;
        glfwGetFramebufferSize(window, &fb_width, &fb_height);

// Файл
// В пункт меню «Файл» (File) кроме операций по работе с файлами (обычно открытие, сохранение, а также создание нового документа) размещают функции печати, обмена по сети. В Windows в этом меню также принято располагать пункт «выход» для закрытия программы. Также в этом меню принято размещать список недавно открытых документов.
// Правка
// В меню «Правка» (Edit) принято размещать команды для работы с буфером обмена, с выделенными фрагментами, а также команды отмены действий. При отсутствии отдельного пункта меню здесь же располагаются команды поиска.
// Вид
// В меню «Вид» (View) обычно вносятся функции управления отображением содержимого: включение линеек, сеток и панелей инструментов; изменение шрифта и цвета интерфейса; изменение масштаба и способа постраничного отображения документа.
// Окно
// В меню «Окно» (Window) вносятся средства управления окнами отдельно открытых документов, при условии, что программа поддерживает многодокументный интерфейс.
// Справка
// Кроме руководства пользователя в раздел «Справка» (Help) также помещают контактную информацию производителя, а также способы регистрации и оплаты. 


        if (ImGui::BeginMainMenuBar())
        {
            if (ImGui::BeginMenu("File"))
            {
                if (ImGui::MenuItem("Open", "Ctrl+O")) 
                {
                // Действия при выборе пункта "Open"
                }
                if (ImGui::MenuItem("Save", "Ctrl+S")) 
                {
            // Действия при выборе пункта "Save"
                }
                ImGui::EndMenu();
            }
            if (ImGui::BeginMenu("Edit"))
            {
                if (ImGui::MenuItem("Copy", "Ctrl+C")) 
                {
                    // Действия при выборе пункта "Copy"
                }
                if (ImGui::MenuItem("Paste", "Ctrl+V")) 
                {
                    // Действия при выборе пункта "Paste"
                }
                ImGui::EndMenu();
            }
            if (ImGui::BeginMenu("View"))
            {
                if (ImGui::BeginMenu("Zoom"))
                {
                    if (ImGui::MenuItem("In"))
                    {
                        addLogMessage("Log message 1");
                    }
                    if (ImGui::MenuItem("Out"))
                    {

                    }
                    ImGui::EndMenu();
                }
                if (ImGui::BeginMenu("Themes", ""))
                {
                    if (ImGui::MenuItem("Light"))
                    {

                    }
                    if (ImGui::MenuItem("Dark"))
                    {

                    }
                    ImGui::EndMenu();
                }
                ImGui::EndMenu();  
            }
            if (ImGui::BeginMenu("Window"))
            {
                if (ImGui::MenuItem("New Window"))
                {
                    /* code */
                }
                if (ImGui::MenuItem("Close Window"))
                {
                    /* code */
                }
                ImGui::EndMenu();
            }
            if (ImGui::BeginMenu("Help"))
            {
                if (ImGui::MenuItem("Welcome"))
                {

                }
                if (ImGui::MenuItem("About"))
                {

                }
                ImGui::EndMenu();
            }
            
            ImGui::EndMainMenuBar();
        }

        // Ширина и длинна предыдущего виджета.
        auto previousWidgetSize = ImGui::GetItemRectSize();

        // Set ImGui window position and size
        ImGui::SetNextWindowPos(ImVec2(0, previousWidgetSize.y));
        ImGui::SetNextWindowSize(ImVec2(fb_width, fb_height - previousWidgetSize.y));
        ImGui::Begin("My Fullscreen Window", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
       
        ImGui::End();
        ImGui::Render();

        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.0f, 1.0f, 0.0f, 1.0f);

        /* ImGui Render */
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
