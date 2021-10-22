#include <stdio.h>
#include <string.h>
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

static void stackDump(lua_State *L) {
    int i;
    int top = lua_gettop(L); // 获取栈的大小
    printf("top------------------------\n");
    for (i = 1; i <= top; ++i) {
        int index = top - i + 1;
        int t = lua_type(L, index);     // 获取栈中元素的类型
        printf("%d %d\t\t", index, -i);
        switch (t)
        {
        case LUA_TSTRING: {
            printf("'%s'", lua_tostring(L, index));
            break;
        }
        case LUA_TBOOLEAN: {
            printf(lua_toboolean(L, index) ? "true" : "false");
            break;
        }
        case LUA_TNUMBER: {
            if (lua_isinteger(L, index)) 
                printf("%lld", lua_tointeger(L, index));
            else
                printf("%g", lua_tonumber(L, index));
            break;
        }
        
        default:
            printf("%s", lua_typename(L, t));
            break;
        }
        printf("\n");
    }
    printf("bottom------------------------\n");
}

int main(int argc, char* argv[]) {
    lua_State *L = luaL_newstate();

    lua_pushboolean(L, 1);
    lua_pushnumber(L, 10);
    lua_pushnil(L);
    lua_pushstring(L, "Hello");

    stackDump(L);

    lua_pushvalue(L, -4); // 在栈顶push一个-4位置处的值
    stackDump(L);

    lua_replace(L, 3); // 从栈顶pop一个值，并把位置3的值设置为这个pop出来的值
    stackDump(L);

    lua_settop(L, 6);
    stackDump(L);

    lua_rotate(L, 3, 1); // 从位置3往栈顶旋转一个元素，也就是说，栈顶元素到了3，3到了4，4到了5 等。。
    stackDump(L);

    lua_rotate(L, 3, -1); // 往相反的方向旋转，从栈顶往下旋转
    stackDump(L);

    return 0;
}