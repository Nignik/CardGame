#include "Game.h"

#include <iostream>
#include <Shuffles.h>

#include "GameInterface.h"

void Game::Init(const std::vector<QuizCard>& cards)
{
	m_IsGameOn = true;

	std::function passFunction = shuffleRandom<QuizCard>;
	m_Quiz = std::make_unique<Quiz>(cards, passFunction);
	std::cout << "Initialized" << '\n';
}

void Game::Play()
{
	while (IsGameOn())
	{
		GI::DisplayQuestion(m_Quiz->GetCurrentQuestion());

		std::cin >> m_UserAnswer;
		ProcessUserAnswer();
	}

	std::cout << "Play stopped" << '\n';
}

void Game::End()
{
	std::lock_guard<std::mutex> lock(m_Mutex);
	m_IsGameOn = false;
	std::cout << "Ended" << '\n';
}

void Game::ProcessUserAnswer() const
{
	if (m_UserAnswer == m_Quiz->GetCurrentAnswer())
	{
		GI::DisplayResult(m_Quiz->GetCurrentAnswer(), true);
	}
	else
	{
		GI::DisplayResult(m_Quiz->GetCurrentAnswer(), false);
	}
}


