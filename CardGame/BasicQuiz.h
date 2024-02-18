#pragma once

#include "QuizType.h"
#include <random>
#include <algorithm>

class BasicQuiz final : public QuizType {
public:
	void ShuffleDeck(std::vector<std::pair<std::string, std::string>>& cards) override;
	void NextCard(std::vector<std::pair<std::string, std::string>>& cards, std::vector<std::pair<std::string, std::string>>::iterator& cardIterator) override;


private:
	std::random_device m_Rd;
	std::mt19937 m_G{m_Rd()};
};