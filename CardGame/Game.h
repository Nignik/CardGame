#pragma once

#include <mutex>
#include <condition_variable>

#include "Quiz.h"

class Game
{
public:
	void Init(const std::vector<QuizCard>& cards);
	void Play();
	void End();

	void ProcessUserAnswer() const;

private:
	std::unique_ptr<Quiz> m_Quiz;
	bool m_IsGameOn = false;
	std::mutex m_Mutex;
	std::string m_UserAnswer;

	bool IsGameOn()
	{
		std::lock_guard<std::mutex> lock(m_Mutex);
		return m_IsGameOn;
	}
};