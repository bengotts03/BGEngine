#include "GameLayer.h"
#include <BGEngine.h>
#include <imgui.h>

using namespace BGEngine;
using namespace BGEngine::Components;
GameObject* gameObject = nullptr;

void GameLayer::OnStart() {
	BG_ENGINE_LOG_INFO("GameLayer Attached");

    gameObject = new GameObject();
    gameObject->SetName("Player");
}

void GameLayer::OnShutdown() {
	BG_ENGINE_LOG_INFO("GameLayer Detached");
}

void GameLayer::OnUpdate() {
    if(BGEngine::Input::IsKeyPressed(BGEngine::Keycode::SPACE))
        BG_LOG_INFO("Space key pressed");
}

void GameLayer::OnGUI() {
    ImGui::Begin("Debug Inspector");

    auto stats = Graphics::Renderer2D::GetRendererStats();
    ImGui::Text("Renderer2D Stats:");
    ImGui::Text("Draw Calls: %d", stats.DrawCalls);
    ImGui::Text("Quads: %d", stats.QuadCount);

    ImGui::Separator();

    ImGui::Text("Object Registry");
    vector<shared_ptr<GameObject>> objects = Application::Get().GetRegistry().GetAllGameObjects();
    for (auto& object : objects) {
        ImGui::Text(object->GetName().c_str());
        ImGui::Separator();
    }

    ImGui::End();
}