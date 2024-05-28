set(CMAKE_FIND_LIBRARY_SUFFIXES ".lib")
set(BUILD_SHARED_LIBS OFF)
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable (CardGame "QuizApp.cpp" "QuizApp.h" "Quiz.h"   "Quiz.cpp"    "UserInterface.h" "UserInterface.cpp" "../includes/FilesHandler.h" "Game.h" "Game.cpp"         "Main.cpp" "GameInterface.h" "GameInterface.cpp" "SharedResources.h"                                        "imgui_impl_glfw.cpp" "imgui_impl_opengl3.cpp")

include_directories(${CMAKE_SOURCE_DIR}/includes)

find_package(glad CONFIG REQUIRED)
target_link_libraries(CardGame PRIVATE glad::glad)

find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(CardGame PRIVATE glfw)

find_package(imgui CONFIG REQUIRED)
target_link_libraries(CardGame PRIVATE imgui::imgui)

find_package(OpenGL REQUIRED)
target_link_libraries(CardGame PRIVATE OpenGL::GL)


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CardGame PROPERTY CXX_STANDARD 20)
endif()
