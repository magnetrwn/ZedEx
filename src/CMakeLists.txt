file(GLOB_RECURSE SOURCE_FILES *.cpp)
add_library(libzedex ${SOURCE_FILES})

target_include_directories(libzedex PUBLIC 
    ${PROJECT_SOURCE_DIR}/src
    ${PROJECT_SOURCE_DIR}/extern/toml11/include
)

add_executable(ZedEx main.cpp)
target_link_libraries(ZedEx PRIVATE libzedex toml11)
