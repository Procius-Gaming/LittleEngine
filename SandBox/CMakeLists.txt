cmake_minimum_required(VERSION 3.2)
set(CMAKE_CXX_STANDARD 14)

project(SandBox)

file(GLOB SOURCES src/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

add_subdirectory(../Little ../build/Little)

if(UNIX)
add_compile_definitions( LE_PLATFORM_LINUX LE_BUILD_DLL)
endif(UNIX)

if(WIN32)
add_compile_definitions( LE_PLATFORM_LINUX LE_BUILD_DLL)
endif(WIN32)

add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD 
    COMMAND ${CMAKE_COMMAND} -E copy "../build/Little/libLittle.dll" "../build"
    COMMENT "Copying dll to build directory"
)


target_include_directories(${PROJECT_NAME}
				PUBLIC ../Little/include
				)

target_link_directories(${PROJECT_NAME}
				PUBLIC ../Little/src
				)

target_link_libraries(${PROJECT_NAME}
				Little
				)
