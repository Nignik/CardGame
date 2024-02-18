#pragma once

#include <windows.h>
#include <string>
#include <CsvHandler.h>
#include <fstream>
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

inline std::string getDefaultPath()
{
	char cwd[MAX_PATH];
	GetCurrentDirectory(MAX_PATH, cwd);
	std::string folderPath = std::string(cwd) + "/../quizzes/";

	return folderPath;
}

inline std::ifstream getCsvFile(const std::string& filePath)
{
	std::ifstream file(filePath);

	if (!file)
	{
		std::cerr << "Incorrect filename:" << getDefaultPath() << "\nTry again." << std::endl;
	}

	return file;
}

inline std::vector<std::pair<std::string, std::string>> extractCards(std::ifstream file)
{
	std::vector<std::pair<std::string, std::string>> cards;
	for (auto& row : CSVRange(file))
	{
		cards.emplace_back(row[0], row[1]);
	}

	return cards;
}

inline std::vector<std::string> getFolderContent(const std::string& folderPath)
{
	std::vector<std::string> files;

	try
	{
		if (fs::is_directory(folderPath))
		{
			for (const auto& entry : fs::directory_iterator(folderPath))
			{
				files.push_back(entry.path().filename().string());
			}
		}
		else
		{
			std::cerr << "Error: Specified path is not a directory." << std::endl;
		}
	}
	catch (const fs::filesystem_error& e)
	{
		std::cerr << "Filesystem error: " << e.what() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "General error: " << e.what() << std::endl;
	}

	return files;
}