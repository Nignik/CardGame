#include "Game.h"

#include "BasicQuiz.h"

void Game::Init()
{
	std::string filePath;
	std::cout << "Quiz file name: ";
	std::getline(std::cin, filePath);

	while (!getCsvFile(filePath))
	{
		std::getline(std::cin, filePath);
	}

	m_UserInterface->ClearConsole();

	const auto cards = extractCards(getCsvFile(filePath));

	BasicQuiz type;
	m_Quiz = std::make_unique<Quiz>(std::make_unique<BasicQuiz>(), cards);

	m_Quiz->ShuffleDeck();
}

void Game::TakeUserAnswer()
{
	std::getline(std::cin, m_UserAnswer);
}

void Game::ProcessUserAnswer()
{
	if (m_UserAnswer == "quit")
	{
		m_Is_GameOn = false;
	}
	else if (m_UserAnswer == m_Quiz->GetCurrentAnswer())
	{
		m_UserInterface->ShowResult(m_Quiz->GetCurrentAnswer(), true);
	}
	else
	{
		m_UserInterface->ShowResult(m_Quiz->GetCurrentAnswer(), false);
	}
}

void Game::Play()
{
	while (m_Is_GameOn)
	{
		m_UserInterface->ShowQuestion(m_Quiz->GetCurrentQuestion());
		TakeUserAnswer();
		ProcessUserAnswer();
		m_Quiz->NextCard();
	}
}


