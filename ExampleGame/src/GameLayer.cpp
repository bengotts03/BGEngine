#include "GameLayer.h"
#include <BGEngine.h>
#include <imgui.h>

using namespace BGEngine;
using namespace BGEngine::Components;
using namespace BGEngine::Graphics;
using namespace BGEngine::Maths;

void GameLayer::OnStart() {
	BG_ENGINE_LOG_INFO("GameLayer Start");

    // Without batching: 28 fps
    // With batching: 119 fps FUCK YEAH
    Renderer2D::BeginDraw(*Application::Get().GetMainCamera());

    int width = 50, height = 100;
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            GameObject *obj = new GameObject();
            obj->SetName("Obj" + std::to_string(x + y));
            obj->GetTransform()->SetPosition(Vector3(x * 2.0f, y * 2.0f, 0));
            obj->GetTransform()->SetScale(Vector3(0.5f, 0.5f, 0.5f));
            obj->AddComponent<SpriteRendererComponent>()->SetColour(Colour::White());
        }
    }

    Renderer2D::EndDraw();
}

void GameLayer::OnShutdown() {
    BG_ENGINE_LOG_INFO("GameLayer Shutdown");
}

void GameLayer::OnUpdate() {
}

void GameLayer::OnGUI() {
    ImGui::Begin("Debug Inspector");

    auto stats = Graphics::Renderer2D::GetRendererStats();
    ImGui::Text("Renderer2D Stats:");
    ImGui::Text("Draw Calls: %d", stats.DrawCalls);
    ImGui::Text("Quads: %d", stats.QuadCount);

    ImGui::Separator();

    ImGui::Text("Performance Inspector:");

    ImGui::Text("FPS: %f", Application::Get().GetWindow().GetFPS());
    ImGui::Text("Delta Time: %f", Time::DeltaTime);

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
            if (object->GetComponent<CameraComponent>() != nullptr) {
                auto camera = object->GetComponent<CameraComponent>();
                if(ImGui::TreeNode("Camera")){
                    ImGui::Text("Orthographic Size: %d", camera->GetOrthographicSize());
                    ImGui::TreePop();
                }
            }
            ImGui::TreePop();
        }
        ImGui::Spacing();
    }
    ImGui::End();
}