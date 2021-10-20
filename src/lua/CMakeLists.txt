
set(SRCS)
file(GLOB SRCS ${SRC_DIR}/lua/*.c)

list(FILTER SRCS EXCLUDE REGEX ".*luac*\.c$")

add_library(Lua53 SHARED ${SRCS})
target_compile_definitions(Lua53 PRIVATE "LUA_BUILD_AS_DLL")

add_executable(lua ${SRC_DIR}/lua/lua.c)

target_link_libraries(lua PUBLIC Lua53)
