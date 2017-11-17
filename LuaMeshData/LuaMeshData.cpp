#include "LuaMeshData.h"

#ifdef __cplusplus
extern "C"
{
#endif
int DLL_API luaopen_LuaMeshData(lua_State * L)
{
	luaL_newmetatable(L, "LoadAssets.MeshData");
	lua_pushvalue(L, 1);
	lua_setfield(L, -2, "__index");
	luaL_setfuncs(L, MeshDataLib_m, 0);
	luaL_newlib(L, MeshDataLib);
	return 1;
}
#ifdef __cplusplus
}
#endif

int lua_newMeshData(lua_State * L)
{
	// convert the user data,
	// using a lambda of the struct to automatically free the object.
	auto *pContainer = reinterpret_cast<LuaPointerContainer<GeometryGenerator::MeshData>*>
		(lua_newuserdata(L, sizeof(LuaPointerContainer<GeometryGenerator::MeshData>)));

	auto * pMeshData = new GeometryGenerator::MeshData();
	pContainer->setPointer(pMeshData);

	luaL_getmetatable(L, "LoadAssets.MeshData");
	lua_setmetatable(L, -2);
	
	return 1;
}

int lua_showMeshData(lua_State * L)
{
	// check and get mesh data
	auto *pMeshData = checkMeshData(L);
	fprintf(stdout, "This is a MeshData.");
	return 0;
}
