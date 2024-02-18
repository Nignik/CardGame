#pragma once

#include <windows.h>
#include <string>
#include <FilesHandler.h>

class UserInterface
{
public:
	UserInterface();
	explicit UserInterface(std::string folderPath);

	void ShowAvailableFiles() const;
	void ShowQuestion(const std::string& question) const;
	void ShowResult(const std::string& correctAnswer, const bool correct = true) const;
	void ClearConsole() const;

private:
	HANDLE m_HConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	std::string m_FolderPath;
};