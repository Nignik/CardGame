#include "Quiz.h"

Quiz::Quiz(std::vector<QuizCard> deck, std::function<void(std::vector<QuizCard>&)> shuffleFunction) :
	m_Shuffle(std::move(shuffleFunction)), m_Deck(std::move(deck))
{
	m_CurrentCard = m_Deck.begin();
}

std::string& Quiz::GetCurrentQuestion() const
{
	return m_CurrentCard->question;
}

std::string& Quiz::GetCurrentAnswer() const
{
	return m_CurrentCard->answer;
}


void Quiz::NextCard()
{
	if (m_CurrentCard == m_Deck.end())
	{
		ShuffleDeck();
		m_CurrentCard = m_Deck.begin();
	}

	++m_CurrentCard;
}

void Quiz::ShuffleDeck()
{
	m_Shuffle(m_Deck);
}

