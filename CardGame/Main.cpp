#include <iostream>

#include "QuizApp.h"

int main()
{
	try
	{
		QuizApp app;
		std::cout << "App started" << '\n';
		app.Run();
	}
	catch (const std::exception& e)
	{
		std::cerr << "An error occurred: " << e.what() << "\n";
		return -1;
	}
	return 0;
}