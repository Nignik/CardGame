#include "UserInterface.h"

UserInterface::UserInterface()
{
	m_FolderPath = getDefaultPath();
}

UserInterface::UserInterface(std::string folderPath) : m_FolderPath(std::move(folderPath)) {}

void UserInterface::ShowAvailableFiles() const
{
	for (auto& file : getFolderContent(m_FolderPath))
	{
		SetConsoleTextAttribute(m_HConsole, 11);
		std::cout << file << std::endl;
		SetConsoleTextAttribute(m_HConsole, 15);
	}
}

void UserInterface::ShowQuestion(const std::string& question) const
{
	SetConsoleTextAttribute(m_HConsole, 11);
	std::cout << question << std::endl;
	SetConsoleTextAttribute(m_HConsole, 15);
}

void UserInterface::ShowResult(const std::string& correctAnswer, const bool correct) const
{
	if (correct)
	{
		SetConsoleTextAttribute(m_HConsole, 10);
		std::cout << "Correct: ";
		SetConsoleTextAttribute(m_HConsole, 14);
		std::cout << correctAnswer << "\n\n";
		SetConsoleTextAttribute(m_HConsole, 15);
	}
	else
	{
		SetConsoleTextAttribute(m_HConsole, 12);
		std::cout << "Incorrect: ";
		SetConsoleTextAttribute(m_HConsole, 14);
		std::cout << correctAnswer << "\n\n";
		SetConsoleTextAttribute(m_HConsole, 15);
	}
}

void UserInterface::ClearConsole() const
{
	constexpr COORD topLeft = { 0, 0 };
	DWORD written;
	CONSOLE_SCREEN_BUFFER_INFO info;

	if (!GetConsoleScreenBufferInfo(m_HConsole, &info))
	{
		std::cerr << "Something went wrong with clearing the console!!!" << std::endl;
	}
	const DWORD cells = info.dwSize.X * info.dwSize.Y;

	FillConsoleOutputCharacter(m_HConsole, ' ', cells, topLeft, &written);
	FillConsoleOutputAttribute(m_HConsole, info.wAttributes, cells, topLeft, &written);
	SetConsoleCursorPosition(m_HConsole, topLeft);
}
