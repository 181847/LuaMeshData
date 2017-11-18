#pragma once
#include "DLLTools.h"

#include "lib\MyTools\MyAssert.h"

#ifdef __cplusplus
extern "C"
{
#endif
#include "lib\lua\lua.h"
#include "lib\lua\lauxlib.h"
#include "lib\lua\lualib.h"

#ifdef __cplusplus
}
#endif
#include "lib\DirectX12\Common\GeometryGenerator.h"

#include "lib\MyTools\Cleaner.h"
#pragma comment(lib, "lua.lib")

#define checkMeshData(L) \
	reinterpret_cast<LuaPointerContainer<Lua::MeshData>*>\
	(luaL_checkudata(L, 1, "LoadAssets.MeshData"))->pointer

template<typename T>
struct LuaPointerContainer
{
	T * pointer;
	// using the cleaner to free the memeroy in the pointer.
	std::function<void(void)> cleaner;
	LuaPointerContainer()
	{
		cleaner = [&this]() {
			delete this->pointer; 
			printf("Mesh Data has been cleaned."); 
		};
	}
	~LuaPointerContainer()
	{
		cleaner(pointer);
	}

	// reload '->'
	T* operator->() const
	{
		return pointer;
	}
	
	void setPointer(T * p)
	{
		pointer = p;
	}
};

#ifdef __cplusplus
extern "C"
{
#endif
	int DLL_API luaopen_MeshData(lua_State * L);
#ifdef __cplusplus
}
#endif


// create a new MeshData.
static int lua_newMeshData(lua_State * L);

// just show the data for test
static int lua_showMeshData(lua_State * L);

// add positioni to the buffer 
static int lua_addPosition(lua_State * L);

// add normal to the buffer
static int lua_addNormal(lua_State * L);

// add tangentU to the buffer
static int lua_addTangentU(lua_State * L);

// add textureCoord to the buffer
static int lua_addTexC(lua_State * L);

// add a vertex using the index of the previous added positions/normals.....
// here we can just pass 
static int lua_addVertex(lua_State * L);

// show some help message.
static int lua_help(lua_State * L);

static const struct luaL_Reg MeshDataLib[] =
{
	{"new", lua_newMeshData},
	{NULL, NULL}
};

static const struct luaL_Reg MeshDataLib_m[] =
{
	{"show", lua_showMeshData},
	{ "addPosition", lua_addPosition },
	{ "addNormal", lua_addNormal },
	{ "addTangentU", lua_addTangentU },
	{ "addTexC", lua_addTexC },
	{ "addVertex", lua_addVertex},
	{ "help", lua_help },
	
	{NULL, NULL}
};
