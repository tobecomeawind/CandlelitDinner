set(LIBRARY_NAME candle)

add_library(${LIBRARY_NAME} STATIC)


target_sources(${LIBRARY_NAME} 
	PRIVATE
		${CMAKE_CURRENT_LIST_DIR}/candle.cpp
	PUBLIC
		${CMAKE_CURRENT_LIST_DIR}/candle.h
)

target_include_directories(${LIBRARY_NAME}
	PUBLIC
		${CMAKE_CURRENT_LIST_DIR}
)
