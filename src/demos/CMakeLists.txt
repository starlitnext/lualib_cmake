
add_executable(demo01 demo01.c)
target_include_directories(demo01 PRIVATE "${PROJECT_SOURCE_DIR}/src/lua")
target_include_directories(demo01 PRIVATE "${PROJECT_SOURCE_DIR}/src")
target_link_libraries(demo01 PRIVATE Lua53)