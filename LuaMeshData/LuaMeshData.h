#pragma once
#include "DLLTools.h"
#include "lib\lua\lua.h"
#include "lib\DirectX12\Common\GeometryGenerator.h"

int DLL_API luaopen_MeshData(lua_State * L);

// create a new MeshData.
int lua_newMeshData(lua_State * L);
