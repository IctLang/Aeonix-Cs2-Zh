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
			ImGui::Begin(u8"����", nullptr, windowFlags);

			CheatText(u8"�Զ���׼", MenuConfig::AimBot);
			CheatText(u8"�Զ�����", MenuConfig::TriggerBot);
			CheatText(u8"��ͼ�״�", MenuConfig::ShowRadar);
			CheatText(u8"��������", MenuConfig::ShowBoneESP);
			CheatText(u8"�������", MenuConfig::ShowBoxESP);
			CheatText(u8"Ѫ������", MenuConfig::ShowHealthBar);
			CheatText(u8"Ѫ������", MenuConfig::HealthText);
			CheatText(u8"����������", MenuConfig::ShowWeaponESP);
			CheatText(u8"�������", MenuConfig::ShowDistance);
			CheatText(u8"�з�����", MenuConfig::ShowEyeRay);
			CheatText(u8"���ƻ���", MenuConfig::ShowPlayerName);
			CheatText(u8"��ս����", MenuConfig::SpectateEsp);
			CheatText(u8"���鷶Χ��ʾ", MenuConfig::ShowAimFovRange);
			CheatText(u8"���岻��", MenuConfig::VisibleCheck);
			CheatText(u8"�����ƶ���", MenuConfig::TeamCheck);
			CheatText(u8"��������", MenuConfig::ShowLineToEnemy);

			CheatText(u8"׼��", MenuConfig::ShowCrossHair);
			CheatText(u8"׼�����ĵ�", CrosshairConfig::drawDot);
			CheatText(u8"׼��T����ʽ", CrosshairConfig::tStyle);
			CheatText(u8"׼�����", CrosshairConfig::drawOutLine);
			CheatText(u8"׼�ı�ͷ��", MenuConfig::ShowHeadShootLine);
			CheatText(u8"ˮӡ��ʾ", MenuConfig::WaterMark);
			CheatText(u8"�ƹ�¼��", MenuConfig::OBSBypass);
		}
		ImGui::End();
	}
}