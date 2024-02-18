#pragma once

#include "UserInterface.h"
#include "Quiz.h"

class Game
{
public:
	void Init();
	void TakeUserAnswer();
	void ProcessUserAnswer();
	void Play();

private:
	std::unique_ptr<UserInterface> m_UserInterface = std::make_unique<UserInterface>();
	std::unique_ptr<Quiz> m_Quiz;

	bool m_Is_GameOn = true;

	std::string m_UserAnswer;
};