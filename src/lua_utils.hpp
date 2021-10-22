#pragma once
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "platform.hpp"

#ifdef __cplusplus
extern "C" {
#endif

#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

EXPORT_API void error(lua_State *L, const char *fmt, ...);

#ifdef __cplusplus
}
#endif


