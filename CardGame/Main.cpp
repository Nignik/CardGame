#include <iostream>

#include "QuizApp.h"

int main()
{
	try
	{
		QuizApp app;
		app.Run();
	}
	catch (const std::exception& e)
	{
		std::cerr << "An error occurred: " << e.what() << "\n";
		return -1;
	}
	return 0;
}