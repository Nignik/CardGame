#pragma once

#include <string>
#include <FilesHandler.h>

namespace UI
{
	void RenderFileSelector(const std::string& title, std::string& currentPath, std::string& selectedFile);
	void ShowAvailableFiles();
	void ClearConsole();
};