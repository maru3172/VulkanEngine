#pragma once
#include "Device.h"
#include "GameObject.h"
#include "Renderer.h"
#include "HWindow.h"

#include <memory>
#include <vector>

namespace HN {
	class App {
	public:
		static constexpr int WIDTH = 800;
		static constexpr int HEIGHT = 600;

		App();
		~App();

		App(const App&) = delete;
		App& operator=(const App&) = delete;

		void run();

	private:
		void loadGameObjects();

		HWindow hWindow{ WIDTH, HEIGHT, "Vulkan Engine" };
		Device device{ hWindow };
		Renderer renderer{ hWindow, device };
		std::vector<GameObject> gameObjects;
	};
}
