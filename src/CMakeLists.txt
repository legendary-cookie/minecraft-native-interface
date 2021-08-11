FILE(GLOB_RECURSE SRC CONFIGURE_DEPENDS
	*.cpp
	*.hpp
	*.h
	*.c
)

SET(CMAKE_CXX_STANDARD 17)

# JNI
find_package(JNI REQUIRED)
include_directories(${JNI_INCLUDE_DIRS} ${PROJECT_SOURCE_DIR}/discord-rpc/include)

# Building/Linking
add_library(${PROJECT_NAME} SHARED ${SRC})
target_link_libraries(${PROJECT_NAME} ${JNI_LIBRARIES} discord-rpc)
