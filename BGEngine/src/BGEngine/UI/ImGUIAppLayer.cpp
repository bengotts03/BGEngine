// ImGUIAppLayer.cpp refactoring
#include "BGPCH.h"
#include "ImGUIAppLayer.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "BGEngine/Core/Application.h"

namespace BGEngine::UI {

    ImGUIAppLayer::ImGUIAppLayer() : AppLayer("ImGUIAppLayer") {
        layerName = "ImGUIAppLayer";
    }

    ImGUIAppLayer::~ImGUIAppLayer() {
        // Destructor implementation
    }

    void ImGUIAppLayer::OnStart() {
        // Initialize ImGui context and setup
        BG_ENGINE_LOG_INFO("ImGui Layer Started");

        // Setup ImGui context
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO(); (void)io;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
        
        // Set style
        ImGui::StyleColorsDark();
        
        // Init platform/renderer backends - ensure we're not initializing twice
        GLFWwindow* window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        
        // Check if backend is already initialized to avoid the assertion
        if (io.BackendPlatformUserData == nullptr) {
            ImGui_ImplGlfw_InitForOpenGL(window, true);
        } else {
            BG_ENGINE_LOG_WARN("ImGui GLFW backend already initialized!");
        }
        
        // Check if renderer backend is already initialized
        if (io.BackendRendererUserData == nullptr) {
            ImGui_ImplOpenGL3_Init("#version 410");
        } else {
            BG_ENGINE_LOG_WARN("ImGui OpenGL backend already initialized!");
        }
    }

    void ImGUIAppLayer::OnShutdown() {
        // Cleanup ImGui context
        BG_ENGINE_LOG_INFO("ImGui Layer Shutdown");

        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
    }

    void ImGUIAppLayer::OnUpdate() {

    }

    void ImGUIAppLayer::OnGUI() {
    }

    void ImGUIAppLayer::Begin() {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
    }

    void ImGUIAppLayer::End() {
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }
}