#include "LuaMeshData.h"
#include "MyMeshData.h"

#ifdef __cplusplus
extern "C"
{
#endif
int DLL_API luaopen_MeshData(lua_State * L)
{
	luaL_newmetatable(L, "LoadAssets.MeshData");
	lua_pushvalue(L, -1);
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
	auto *pContainer = reinterpret_cast<LuaPointerContainer<Lua::MeshData>*>
		(lua_newuserdata(L, sizeof(LuaPointerContainer<Lua::MeshData>)));

	auto * pMeshData = new Lua::MeshData();
	pContainer->setPointer(pMeshData);

	luaL_getmetatable(L, "LoadAssets.MeshData");
	lua_setmetatable(L, -2);
	
	return 1;
}

int lua_showMeshData(lua_State * L)
{
	// check and get mesh data
	auto *pMeshData = checkMeshData(L);
	printf("Vertex count:\t\t%d\n", pMeshData->Vertices.size());
	printf("Index count:\t\t%d\n", pMeshData->Indices32.size());
	printf("Position count:\t\t%d\n", pMeshData->Positions.size());
	printf("Normal count:\t\t%d\n", pMeshData->Normals.size());
	printf("TangentU count:\t\t%d\n", pMeshData->TangentUs.size());
	printf("TextureCoord count:\t\t%d\n", pMeshData->Texcoords.size());
	return 0;
}

int lua_addPosition(lua_State * L)
{
	auto * pMeshData = checkMeshData(L);
	auto px = static_cast<float>(luaL_checknumber(L, 2));
	auto py = static_cast<float>(luaL_checknumber(L, 3));
	auto pz = static_cast<float>(luaL_checknumber(L, 4));


	pMeshData->Positions.push_back(DirectX::XMFLOAT3(px, py, pz));
	DEBUG_MESSAGE("position added: %f, %f, %f\n", px, py, pz);
	return 0;
}

int lua_addNormal(lua_State * L)
{
	auto * pMeshData = checkMeshData(L);
	auto px = static_cast<float>(luaL_checknumber(L, 2));
	auto py = static_cast<float>(luaL_checknumber(L, 3));
	auto pz = static_cast<float>(luaL_checknumber(L, 4));


	pMeshData->Normals.push_back(DirectX::XMFLOAT3(px, py, pz));
	DEBUG_MESSAGE("normal added: %f, %f, %f\n", px, py, pz);
	return 0;
}

int lua_addTangentU(lua_State * L)
{
	auto * pMeshData = checkMeshData(L);
	auto px = static_cast<float>(luaL_checknumber(L, 2));
	auto py = static_cast<float>(luaL_checknumber(L, 3));
	auto pz = static_cast<float>(luaL_checknumber(L, 4));


	pMeshData->TangentUs.push_back(DirectX::XMFLOAT3(px, py, pz));
	DEBUG_MESSAGE("tangentU added: %f, %f, %f\n", px, py, pz);
	return 0;
}

int lua_addTexC(lua_State * L)
{
	auto * pMeshData = checkMeshData(L);
	auto pu = static_cast<float>(luaL_checknumber(L, 2));
	auto pv = static_cast<float>(luaL_checknumber(L, 3));


	pMeshData->Texcoords.push_back(DirectX::XMFLOAT2(pu, pv));
	DEBUG_MESSAGE("textureCoord added: %f, %f\n", pu, pv);
	return 0;
}

int lua_addVertex(lua_State * L)
{
	auto * pMeshData = checkMeshData(L);
	auto positionIndex = OBJ_INDEX_TO_C_INDEX(luaL_checkinteger(L, 2));
	auto normalIndex = OBJ_INDEX_TO_C_INDEX(luaL_checkinteger(L, 3));
	auto tangentUIndex = OBJ_INDEX_TO_C_INDEX(luaL_checkinteger(L, 4));
	auto texCIndex = OBJ_INDEX_TO_C_INDEX(luaL_checkinteger(L, 5));

	auto posCount = pMeshData->Positions.size();
	auto nmlCount = pMeshData->Normals.size();
	auto tguCount = pMeshData->TangentUs.size();
	auto texCount = pMeshData->Texcoords.size();

	if (positionIndex > )
	
	return 0;
}

int lua_help(lua_State * L)
{

	printf("\n****** HELP MESH DATA *****\n");
	fprintf(stderr, ":show: show the statics of the mesh.\n");
	fprintf(stderr, ":addPosition: add one position to the buffer, please pass 3 number.\n");
	fprintf(stderr, ":addNormal: add one normal to the buffer, please pass 3 number.\n");
	fprintf(stderr, ":addTangentU: add one tangentU to the buffer, please pass 3 number.\n");
	fprintf(stderr, ":addTexC: add one textureCoord to the buffer, please pass 2 number.\n");
	fprintf(stderr, ":addVertex: add one Vertex to the Vertices, must pass 4 integer, and the index just start from 1(same as in the .obj file).\n");
	fprintf(stderr, "            the module will convert the index to the in the C.\n");
	fprintf(stderr, ":help: show this information.\n");
	printf("\n****** HELP MESH DATA *****\n");

	return 0;
}
