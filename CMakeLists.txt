cmake_minimum_required(VERSION 3.24.2)

project(testproj CXX)

add_subdirectory(candle)
add_subdirectory(tests)


add_executable(${PROJECT_NAME} main.cpp)


target_link_libraries(${PROJECT_NAME}
	PRIVATE
		tests
		candle
)	
