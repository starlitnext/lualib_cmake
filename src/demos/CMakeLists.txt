
add_executable(demo01 demo01.c)
target_include_directories(demo01 PRIVATE "${PROJECT_SOURCE_DIR}/src/lua")
target_include_directories(demo01 PRIVATE "${PROJECT_SOURCE_DIR}/src")
target_link_libraries(demo01 PRIVATE Lua53)

add_executable(demo02 demo02.c)
target_include_directories(demo02 PRIVATE "${PROJECT_SOURCE_DIR}/src/lua")
target_include_directories(demo02 PRIVATE "${PROJECT_SOURCE_DIR}/src")
target_link_libraries(demo02 PRIVATE Lua53)

add_executable(demo03 demo03.c)
target_include_directories(demo03 PRIVATE "${PROJECT_SOURCE_DIR}/src/lua")
target_include_directories(demo03 PRIVATE "${PROJECT_SOURCE_DIR}/src")
target_link_libraries(demo03 PRIVATE Lua53 luaext)