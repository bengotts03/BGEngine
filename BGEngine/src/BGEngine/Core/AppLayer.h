#pragma once

namespace BGEngine
{
	class BG_API AppLayer
	{
	public:
		AppLayer(const std::string& name = "Layer");
		virtual ~AppLayer();

		virtual void OnStart() = 0;
		virtual void OnShutdown() = 0;
		virtual void OnUpdate() = 0;

		const std::string& GetName() const { return layerName; }
	private:
		std::string layerName; // For debugging purposes
	};
}
