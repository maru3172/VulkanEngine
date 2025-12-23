#pragma once
#include "Camera.h"
#include "Device.h"
#include "GameObject.h"
#include "Pipeline.h"

#include <memory>
#include <vector>

namespace HN
{
	class RendererSystem
	{
	public:
		RendererSystem(Device& Hdevice, VkRenderPass renderPass);
		~RendererSystem();

		RendererSystem(const RendererSystem&) = delete;
		RendererSystem& operator=(const RendererSystem&) = delete;

		void renderGameObjects(VkCommandBuffer commandBuffer, std::vector<GameObject>& gameObjects,const Camera& camera);
	private:
		void createPipelineLayout();
		void createPipeline(VkRenderPass renderPass);

		Device& device;

		std::unique_ptr<Pipeline> pipeline;
		VkPipelineLayout pipelineLayout;
	};
}
