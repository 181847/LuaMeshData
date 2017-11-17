#pragma once
#include "DLLTools.h"

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
	reinterpret_cast<LuaPointerContainer<GeometryGenerator::MeshData>*>\
	(luaL_checkudata(L, 1, "LoadAssets.MeshData"))

template<typename T>
struct LuaPointerContainer
{
	T * pointer;
	// using the cleaner to free the memeroy in the pointer.
	std::function<void(void)> cleaner;
	LuaPointerContainer()
	{
		cleaner = [&this]() {delete this->pointer; };
	}
	~LuaPointerContainer()
	{
		cleaner(pointer);
	}

	// reload '->'
	T * operator ->()
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

static const struct luaL_Reg MeshDataLib[] =
{
	{"new", lua_newMeshData},
	{NULL, NULL}
};

static const struct luaL_Reg MeshDataLib_m[] =
{
	{"show", lua_showMeshData},
	{NULL, NULL}
};
