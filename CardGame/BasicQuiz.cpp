#include "BasicQuiz.h"

void BasicQuiz::ShuffleDeck(std::vector<std::pair<std::string, std::string>>& cards)
{
	std::ranges::shuffle(cards, m_G);
}

void BasicQuiz::NextCard(std::vector<std::pair<std::string, std::string>>& cards, std::vector<std::pair<std::string, std::string>>::iterator& cardIterator)
{
	++cardIterator;

	if (cardIterator == cards.end())
	{
		ShuffleDeck(cards);
		cardIterator = cards.begin();
	}
}
