#include <cmath>
#include <lua.hpp>
#include <platform.hpp>

static int l_sin(lua_State *L) {
    double d = luaL_checknumber(L, 1);
    lua_pushnumber(L, std::sin(d));
    return 1;
}

static int l_sqrt(lua_State *L) {
    double d = luaL_checknumber(L, 1);
    lua_pushnumber(L, std::sqrt(d));
    return 1;
}

static const struct luaL_Reg mylib[] = {
    {"sin", l_sin},
    {"sqrt", l_sqrt},
    {NULL, NULL}
};

extern "C" EXPORT_API int luaopen_testmod(lua_State *L) {
    luaL_newlib(L, mylib);
    return 1;
}