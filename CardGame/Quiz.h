#pragma once

#include <memory>

#include "QuizType.h"
#include <vector>
#include <string>
#include <utility>

class Quiz
{
public:
	[[nodiscard]] std::string& GetCurrentQuestion() const;
	[[nodiscard]] std::string& GetCurrentAnswer() const;

	void NextCard();
	void ShuffleDeck();

	Quiz(std::unique_ptr<QuizType> type, std::vector<std::pair<std::string, std::string>> cards);

private:
	std::unique_ptr<QuizType> m_Type;
	std::vector<std::pair<std::string, std::string>> m_Cards;
	std::vector<std::pair<std::string, std::string>>::iterator m_CurrentCard;
};