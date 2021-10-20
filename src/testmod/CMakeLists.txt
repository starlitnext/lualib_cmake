
# specify the c++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(testmod SHARED ltestmod.cpp)
target_include_directories(testmod PRIVATE "${PROJECT_SOURCE_DIR}/src/lua")
target_include_directories(testmod PRIVATE "${PROJECT_SOURCE_DIR}/src")
target_link_libraries(testmod PRIVATE Lua53)
target_compile_definitions(testmod PRIVATE "LUA_BUILD_AS_DLL")

install(TARGETS testmod DESTINATION)