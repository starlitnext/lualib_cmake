
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(luaext SHARED lua_utils.cpp)
target_include_directories(luaext PRIVATE "${PROJECT_SOURCE_DIR}/src/lua")
target_include_directories(luaext INTERFACE "${PROJECT_SOURCE_DIR}/src")
target_link_libraries(luaext PRIVATE Lua53)

add_subdirectory(lua)
add_subdirectory(testmod)
add_subdirectory(demos)