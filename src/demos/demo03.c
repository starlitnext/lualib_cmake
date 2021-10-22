#include <lua_utils.hpp>

#define MAX_COLOR   255

// assume that table is on the top of the stack
int getcolorfield(lua_State *L, const char *key) {
    int result, isnum;
    lua_pushstring(L, key); // push key
    lua_gettable(L, -2); // pop key, push background[key]
    result = (int)(lua_tonumberx(L, -1, &isnum) * MAX_COLOR);
    if (!isnum)
        error(L, "invalid component '%s' in color", key);
    lua_pop(L, 1); // remove number
    return result;
}

int getglobint(lua_State *L, const char *var) {
    int isnum, result;
    lua_getglobal(L, var);
    result = (int)lua_tointegerx(L, -1, &isnum);
    if (!isnum)
        error(L, "'%s' should be a number\n", var);
    lua_pop(L, 1);  // remove result from stack
    return result;
}

void load(lua_State *L, const char *fname, int *w, int *h) {
    if (luaL_loadfile(L, fname) || lua_pcall(L, 0, 0, 0))
        error(L, "cannot run config. file: %s", lua_tostring(L, -1));
    *w = getglobint(L, "width");
    *h = getglobint(L, "height");
}

int main(int argv, char* argc[]) {
    if (argv != 2) {
        printf("Usage: %s configfilepath\n", argc[0]);
        return 0;
    }
    lua_State *L = luaL_newstate();
    int width, height;
    load(L, argc[1], &width, &height);
    printf("width: %d\nheight: %d\n", width, height);

    lua_getglobal(L, "background");
    if (!lua_istable(L, -1))
        error(L, "'background' is not a table");
    int red, green, blue;
    red = getcolorfield(L, "red");
    green = getcolorfield(L, "green");
    blue = getcolorfield(L, "blue");
    printf("background<rgb>: <%d, %d, %d>\n", red, green, blue);
    return 0;
}