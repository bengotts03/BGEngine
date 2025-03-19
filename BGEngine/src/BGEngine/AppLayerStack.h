#pragma once
#include "AppLayer.h"

namespace BGEngine {
	class BG_API AppLayerStack
	{
	public:
		AppLayerStack();
		~AppLayerStack();

		void PushLayer(AppLayer* layer);
		void PopLayer(AppLayer* layer);
		void PushOverlay(AppLayer* layer);
		void PopOverlay(AppLayer* layer);

		std::vector<AppLayer*>::iterator begin() { return layers.begin(); }
		std::vector<AppLayer*>::iterator end() { return layers.end(); }
		std::vector<AppLayer*>::reverse_iterator rbegin() { return layers.rbegin(); }
		std::vector<AppLayer*>::reverse_iterator rend() { return layers.rend(); }

		std::vector<AppLayer*>::const_iterator begin() const { return layers.begin(); }
		std::vector<AppLayer*>::const_iterator end()	const { return layers.end(); }
		std::vector<AppLayer*>::const_reverse_iterator rbegin() const { return layers.rbegin(); }
		std::vector<AppLayer*>::const_reverse_iterator rend() const { return layers.rend(); }
	private:
		std::vector<AppLayer*> layers;
		std::vector<AppLayer*>::iterator layerInsert;
	};
}
