#include "Offsets.h"
#include "Cheats.h"
#include "Utils/Format.hpp"
#include <iostream>
#include <iomanip>
#include <Shlobj.h>
#include <filesystem>
#include <KnownFolders.h>
#include <Windows.h>

int main()
{
	namespace fs = std::filesystem;

	auto ProcessStatus = ProcessMgr.Attach("cs2.exe");

	char documentsPath[MAX_PATH];
	if (SHGetFolderPathA(NULL, CSIDL_PERSONAL, NULL, 0, documentsPath) != S_OK) {
		std::cerr << "[Error] 无法获取文档路径。" << std::endl;
		goto END;
	}

	MenuConfig::path = documentsPath;
	MenuConfig::path += "\\.Aeonix";

	if (!fs::is_directory(MenuConfig::path)) {

		if (fs::create_directory(MenuConfig::path)) {

			std::cout << "[Success] 创建的配置目录：" << MenuConfig::path << std::endl;
		}
		else {

			std::cerr << "[Error] 无法创建配置目录。" << std::endl;
		}
	}
	else {

		std::cout << "[Success] 配置目录已经存在：" << MenuConfig::path << std::endl;
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
