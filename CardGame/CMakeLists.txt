set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
set(BUILD_SHARED_LIBS OFF)
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable (CardGame "QuizApp.cpp" "QuizApp.h" "Quiz.h" "BasicQuiz.h" "BasicQuiz.cpp" "Quiz.cpp" "QuizType.h"   "UserInterface.h" "UserInterface.cpp" "../includes/FilesHandler.h" "Game.h" "Game.cpp" "Card.h")

include_directories(${CMAKE_SOURCE_DIR}/includes)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CardGame PROPERTY CXX_STANDARD 20)
endif()
