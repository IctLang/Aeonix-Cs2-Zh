#pragma once
#include "..\OS-ImGui\imgui\imgui.h"
#include "..\MenuConfig.hpp"

namespace CheatList
{
	static inline void CheatText(const char* Cheat, bool config)
	{
		if (config)
			ImGui::Text(Cheat);
	}

	inline void Render() noexcept
	{
		if (MenuConfig::CheatList) {

			ImGuiWindowFlags windowFlags = ImGuiWindowFlags_NoCollapse;
			ImGui::SetNextWindowBgAlpha(0.3f);
			ImGui::SetNextWindowSize(ImVec2(200, 0));
			ImGui::Begin(u8"功能", nullptr, windowFlags);

			CheatText(u8"自动瞄准", MenuConfig::AimBot);
			CheatText(u8"自动开火", MenuConfig::TriggerBot);
			CheatText(u8"地图雷达", MenuConfig::ShowRadar);
			CheatText(u8"骨骼绘制", MenuConfig::ShowBoneESP);
			CheatText(u8"方框绘制", MenuConfig::ShowBoxESP);
			CheatText(u8"血条绘制", MenuConfig::ShowHealthBar);
			CheatText(u8"血量绘制", MenuConfig::HealthText);
			CheatText(u8"武器名绘制", MenuConfig::ShowWeaponESP);
			CheatText(u8"距离绘制", MenuConfig::ShowDistance);
			CheatText(u8"敌方视线", MenuConfig::ShowEyeRay);
			CheatText(u8"名称绘制", MenuConfig::ShowPlayerName);
			CheatText(u8"观战绘制", MenuConfig::SpectateEsp);
			CheatText(u8"自瞄范围显示", MenuConfig::ShowAimFovRange);
			CheatText(u8"掩体不瞄", MenuConfig::VisibleCheck);
			CheatText(u8"不绘制队友", MenuConfig::TeamCheck);
			CheatText(u8"敌人连线", MenuConfig::ShowLineToEnemy);

			CheatText(u8"准心", MenuConfig::ShowCrossHair);
			CheatText(u8"准心中心点", CrosshairConfig::drawDot);
			CheatText(u8"准心T形样式", CrosshairConfig::tStyle);
			CheatText(u8"准心描边", CrosshairConfig::drawOutLine);
			CheatText(u8"准心爆头线", MenuConfig::ShowHeadShootLine);
			CheatText(u8"水印显示", MenuConfig::WaterMark);
			CheatText(u8"绕过录屏", MenuConfig::OBSBypass);
		}
		ImGui::End();
	}
}