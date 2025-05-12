#include "GameLayer.h"
#include <BGEngine.h>
#include <imgui.h>

using namespace BGEngine;
using namespace BGEngine::Components;
using namespace BGEngine::Graphics;
using namespace BGEngine::Maths;

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
    auto currentPos = gameObject->GetTransform()->GetPosition();

    if(BGEngine::Input::IsKeyDown(BGEngine::Keycode::W))
        gameObject->GetTransform()->SetPosition(currentPos + Vector3(0.0f, 0.1f, 0.0f));

    if(BGEngine::Input::IsKeyDown(BGEngine::Keycode::S))
        gameObject->GetTransform()->SetPosition(currentPos + Vector3(0.0f, -0.1f, 0.0f));

    if(BGEngine::Input::IsKeyDown(BGEngine::Keycode::A))
        gameObject->GetTransform()->SetPosition(currentPos + Vector3(-0.1f, 0.0f, 0.0f));

    if(BGEngine::Input::IsKeyDown(BGEngine::Keycode::D))
        gameObject->GetTransform()->SetPosition(currentPos + Vector3(0.1f, 0.0f, 0.0f));

    Renderer2D::DrawQuad(gameObject->GetTransform()->GetPosition().ToVector2(), gameObject->GetTransform()->GetScale().ToVector2(), Vector3(1.0f, 0.0f, 0.0f));
}

void GameLayer::OnGUI() {
    ImGui::Begin("Debug Inspector");

    auto stats = Graphics::Renderer2D::GetRendererStats();
    ImGui::Text("Renderer2D Stats:");
    ImGui::Text("Draw Calls: %d", stats.DrawCalls);
    ImGui::Text("Quads: %d", stats.QuadCount);

    ImGui::Separator();

    vector<shared_ptr<GameObject>> objects = Application::Get().GetRegistry().GetAllGameObjects();
    ImGui::Text("Object Registry (%d):", objects.size());
    ImGui::Spacing();
    for (const auto &object: objects) {
        if (ImGui::TreeNode(object->GetName().c_str())) {
            if(ImGui::TreeNode("Transform:")){
                ImGui::Text("Position: %s", object->GetTransform()->GetPosition().ToString().c_str());
                ImGui::Text("Rotation: %s", object->GetTransform()->GetRotation().ToString().c_str());
                ImGui::Text("Scale: %s", object->GetTransform()->GetScale().ToString().c_str());
                ImGui::TreePop();
            }
            ImGui::TreePop();
        }
        ImGui::Spacing();
    }
    ImGui::End();
}