#include "Offsets.h"
#include "Cheats.h"
#include "Utils/Format.hpp"
#include <iostream>
#include <iomanip>
#include <Shlobj.h>
#include <filesystem>
#include <Windows.h>

int main()
{

	auto ProcessStatus = ProcessMgr.Attach("cs2.exe");

	TCHAR documentsPath[MAX_PATH];
	if (SHGetFolderPath(NULL, CSIDL_MYDOCUMENTS, NULL, 0, documentsPath) != S_OK) {
		return 0;
	}
	char narrowPath[MAX_PATH];
	if (WideCharToMultiByte(CP_UTF8, 0, documentsPath, -1, narrowPath, sizeof(narrowPath), NULL, NULL) == 0) {
		return 0;
	}
	std::string documentsDir(narrowPath);
	std::string configFilePath = documentsDir + "\\.Aeonix\\";
	namespace fs = std::filesystem;
	if (!fs::is_directory(configFilePath)) {
		if (fs::create_directory(configFilePath)) {
			std::cout << "[Success] 配置目录已创建:：" << configFilePath << std::endl;
		}
		else {
			std::cerr << "[Error] 无法创建配置目录。" << std::endl;
		}
	}
	else {
		std::cout << "[Success] 配置目录已存在：" << configFilePath << std::endl;
	}

	
	if (ProcessStatus != StatusCode::SUCCEED)
	{
		std::cout << "[ERROR] 无法附加进程，状态代码：" << ProcessStatus << std::endl;
		goto END;
	}

	if (!Offset::UpdateOffsets())
	{
		std::cout << "[ERROR] 无法更新偏移量。" << std::endl;
		goto END;
	}

	if (!gGame.InitAddress())
	{
		std::cout << "[ERROR] 调用 Init Address() 失败。" << std::endl;
		goto END;
	}

	std::cout << Format("[Game] Pid:%d\n", ProcessMgr.ProcessID);
	std::cout << Format("[Game] Client:%llX\n", gGame.GetClientDLLAddress());

	std::cout << Format("[Offset] EntityList:%llX\n", Offset::EntityList);
	std::cout << Format("[Offset] Matrix:%llX\n", Offset::Matrix);
	std::cout << Format("[Offset] LocalPlayerController:%llX\n", Offset::LocalPlayerController);
	std::cout << Format("[Offset] ViewAngles:%llX\n", Offset::ViewAngle);
	std::cout << Format("[Offset] LocalPlayerPawn:%llX\n", Offset::LocalPlayerPawn);
	std::cout << Format("[Offset] ForceJump:%llX\n", Offset::ForceJump);

	std::cout << "[Success] 正在运行..." << std::endl;
	std::cout << "[提示] 注入国服输入c,国际服按任意键。" << std::endl;

	try
	{
		if (getchar() == 'c')
			Gui.AttachAnotherWindow("反恐精英：全球攻势", "SDL_app", Cheats::Run);
		else
			Gui.AttachAnotherWindow("Counter-Strike 2", "SDL_app", Cheats::Run);
	}
	catch (OSImGui::OSException& e)
	{
		std::cout << e.what() << std::endl;
	}

END:
	system("pause");
	return 0;
}
