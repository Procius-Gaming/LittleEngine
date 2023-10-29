cmake_minimum_required(VERSION 3.2)
set(CMAKE_CXX_STANDARD 14)

project(SandBox)

file(GLOB SOURCES src/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

add_subdirectory(../Little ../build/Little)

add_compile_definitions(LE_PLATFORM_LINUX)

target_include_directories(${PROJECT_NAME}
				PUBLIC ../Little/include
				)

target_link_directories(${PROJECT_NAME}
				PUBLIC ../Little/src
				)

target_link_libraries(${PROJECT_NAME}
				Little
				)
