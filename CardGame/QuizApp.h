#pragma once

#include <GLFW/glfw3.h>
#include "Game.h"

class QuizApp
{
public:
	QuizApp();
	~QuizApp();

	void Run();

private:
	GLFWwindow* m_Window;
	Game m_Game;
	std::thread m_GameThread;

	void InitWindow();
	void InitImGui() const;
	void MainLoop();
	void Cleanup() const;
};

