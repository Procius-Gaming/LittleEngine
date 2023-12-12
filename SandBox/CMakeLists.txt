cmake_minimum_required(VERSION 3.2)
set(CMAKE_CXX_STANDARD 17)

project(SandBox)

file(GLOB SOURCES src/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

add_subdirectory(../Little ../build/Little)

if(UNIX)
	add_compile_definitions( LE_PLATFORM_LINUX LE_BUILD_DLL LE_ENABLE_ASSERTS)
endif(UNIX)

if(WIN32)
	add_compile_definitions( LE_PLATFORM_WINDOWS LE_BUILD_DLL LE_ENABLE_ASSERTS)
endif(WIN32)

#if(WIN32)
#add_custom_command(
#    TARGET ${PROJECT_NAME} POST_BUILD 
#    COMMAND ${CMAKE_COMMAND} -E copy "../build/Little/libLittle.dll" "../build"
#    COMMENT "Copying dll to build directory"
#)
#endif(WIN32)

if (CMAKE_GENERATOR MATCHES "Visual Studio")
add_custom_command(
	TARGET ${PROJECT_NAME} POST_BUILD 
    COMMAND ${CMAKE_COMMAND} -E copy "../build/Little/libLittle.dll" "test"
    COMMENT "Copying dll to build directory vstudio"
)
endif()


target_include_directories(${PROJECT_NAME}
				PUBLIC ../Little/include
				)

target_link_directories(${PROJECT_NAME}
				PUBLIC ../Little/src
				)

target_link_libraries(${PROJECT_NAME}
				Little
				)
