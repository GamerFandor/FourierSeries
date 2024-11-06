cmake_minimum_required(VERSION 3.27)

project(TemplateCPP)

# If you want to use C instead of C++, comment out the line below and uncomment the line below that.
file(GLOB_RECURSE SOURCE "Source/*.cpp" "Source/**/*.cpp")
#file(GLOB_RECURSE SOURCE "Source/*.c" "Source/**/*.c")

add_executable(${PROJECT_NAME} ${SOURCE})
