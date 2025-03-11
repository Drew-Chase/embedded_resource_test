cmake_minimum_required(VERSION 3.30)
project(embedded_resource_test)
set(CMAKE_CXX_STANDARD 20)

add_executable(${CMAKE_PROJECT_NAME}
        main.cpp
)

target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE -DB_PRODUCTION_MODE=ON -Oz)

# Add resources
include(FetchContent)
FetchContent_Declare(
        battery-embed
        GIT_REPOSITORY https://github.com/batterycenter/embed.git
        GIT_TAG v1.2.19
)
set(B_PRODUCTION_MODE ON CACHE BOOL "Enable production mode for Battery Embed")
FetchContent_MakeAvailable(battery-embed)

file(GLOB_RECURSE RESOURCES "res/*")
file(RELATIVE_PATH RESOURCES_RELATIVE_TO_SOURCE "${CMAKE_SOURCE_DIR}" "${RESOURCES}")
b_embed(${CMAKE_PROJECT_NAME} ${RESOURCES_RELATIVE_TO_SOURCE})