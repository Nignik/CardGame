#pragma once

#include <string>

struct QuizCard
{
	std::string answer;
	std::string question;

	QuizCard(std::string answer, std::string question) : answer(std::move(answer)), question(std::move(question)) {}
};