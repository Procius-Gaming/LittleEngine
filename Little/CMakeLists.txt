cmake_minimum_required(VERSION 3.2)

set(CMAKE_CXX_STANDARD 14)

project(Little)

set(HEADER_FILES
    include/lepch.h)

file(GLOB SOURCES src/**.cpp src/Platform/OpenGL/**.cpp)

add_library(${PROJECT_NAME} SHARED ${SOURCES})

target_precompile_headers(${PROJECT_NAME} PRIVATE ${HEADER_FILES})


#if(UNIX)
add_compile_definitions(UNICODE
#LE_PLATFORM_LINUX LE_BUILD_DLL
)
#endif(UNIX)

#if(WIN32)
#add_compile_definitions(UNICODE LE_PLATFORM_LINUX LE_BUILD_DLL)
#endif(WIN32)

add_subdirectory(../vendor/glad glad)
add_subdirectory(../vendor/glfw glfw)
add_subdirectory(../vendor/imgui imgui)


target_include_directories(${PROJECT_NAME}
				PUBLIC include
				PUBLIC include/Events
				PUBLIC inlcude/Platform
				PUBLIC ../vendor/glad/include
				PUBLIC ../vendor/glfw/include
				PUBLIC ../vendor/spdlog/include
				PUBLIC ../vendor/imgui
				)

target_link_libraries(${PROJECT_NAME}
				glad
				${OPENGL_LIBRARIES}
				glfw
				imgui
				#glm
				#assimp
				)