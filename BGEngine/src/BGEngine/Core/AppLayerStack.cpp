#include "BGPCH.h"
#include "AppLayerStack.h"

namespace BGEngine {
	AppLayerStack::AppLayerStack() {
		layerInsert = layers.begin();
	}

	AppLayerStack::~AppLayerStack() {
		for (AppLayer* layer : layers) {
			delete layer;
		}
	}

	void AppLayerStack::PushLayer(AppLayer* layer) {
		layerInsert = layers.emplace(layerInsert, layer);
	}

	void AppLayerStack::PopLayer(AppLayer* layer) {
		auto it = std::find(layers.begin(), layers.end(), layer);
		if (it != layers.end()) {
			layers.erase(it);
			layerInsert--;
		}
	}

	void AppLayerStack::PushOverlay(AppLayer* layer) {
		layers.emplace_back(layer);
	}

	void AppLayerStack::PopOverlay(AppLayer* layer) {
		auto it = std::find(layers.begin(), layers.end(), layer);
		if (it != layers.end()) {
			layers.erase(it);
		}
	}
}