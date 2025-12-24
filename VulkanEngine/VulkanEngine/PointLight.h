#pragma once
#include "Camera.h"
#include "Device.h"
#include "FrameInfo.h"
#include "GameObject.h"
#include "Pipeline.h"

#include <memory>
#include <vector>

namespace HN
{
	class PointLight
	{
	public:

		PointLight(Device& HDevice, VkRenderPass renderPass, VkDescriptorSetLayout globalSetLayout);
		~PointLight();

		PointLight(const PointLight&) = delete;
		PointLight& operator=(const PointLight&) = delete;
		
		void update(FrameInfo& frameInfo, GlobalUbo& ubo);
		void render(FrameInfo& frameInfo);

	private:
		void createPipelineLayout(VkDescriptorSetLayout globalSetLayout);
		void createPipeline(VkRenderPass renderPass);

		Device& device;

		std::unique_ptr<Pipeline> pipeline;
		VkPipelineLayout pipelineLayout;
	};
}
