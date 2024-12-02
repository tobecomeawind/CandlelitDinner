set(LIBRARY_NAME tests)

add_library(${LIBRARY_NAME} STATIC)


target_sources(${LIBRARY_NAME} 
	PRIVATE
		${CMAKE_CURRENT_LIST_DIR}/tests.cpp
	PUBLIC
		${CMAKE_CURRENT_LIST_DIR}/tests.h
)

target_include_directories(${LIBRARY_NAME}
	PUBLIC
		${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(${LIBRARY_NAME}
	PRIVATE
		candle
)
