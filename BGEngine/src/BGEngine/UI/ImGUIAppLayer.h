//
// Created by Ben Gotts on 10/05/2025.
//

#ifndef BGENGINE_APPLAYER_IMGUI_H
#define BGENGINE_APPLAYER_IMGUI_H

#include "BGPCH.h"
#include "BGEngine/Core/AppLayer.h"

namespace BGEngine::UI {
    class ImGUIAppLayer : public AppLayer {
    public:
        ImGUIAppLayer();
        ~ImGUIAppLayer() override;

        void OnStart() override;
        void OnShutdown() override;
        void OnUpdate() override;
        void OnGUI() override;

        void Begin();
        void End();

        const std::string& GetName() const { return layerName; }
    private:
        std::string layerName; // For debugging purposes
    };
}

#endif //BGENGINE_APPLAYER_IMGUI_H
