#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;

class QuizType
{
public:
	virtual ~QuizType() = default;
	QuizType(const QuizType& other) = default;
	QuizType& operator=(const QuizType& other) = default;
	QuizType(QuizType&& other) noexcept = default;
	QuizType& operator=(QuizType&& other) noexcept = default;

	virtual void ShuffleDeck(vector<std::pair<string, string>>& cards) = 0;
	virtual void NextCard(vector<std::pair<string, string>>& cards, vector<std::pair<string, string>>::iterator& cardIterator) = 0;

protected:
	QuizType() = default;
};