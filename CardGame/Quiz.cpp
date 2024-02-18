#include "Quiz.h"

Quiz::Quiz(std::unique_ptr<QuizType> type, std::vector<std::pair<std::string, std::string>> cards) : m_Type(std::move(type)), m_Cards(std::move(cards))
{
	this->m_CurrentCard = this->m_Cards.begin();
}

std::string& Quiz::GetCurrentQuestion() const
{
	return m_CurrentCard->first;
}

std::string& Quiz::GetCurrentAnswer() const
{
	return m_CurrentCard->second;
}


void Quiz::NextCard()
{
	m_Type->NextCard(m_Cards, m_CurrentCard);
}

void Quiz::ShuffleDeck()
{
	m_Type->ShuffleDeck(m_Cards);
}

