#pragma once

#include "lib\DirectX12\Common\d3dUtil.h"
#define OBJ_INDEX_TO_C_INDEX(index) (index - 1)

namespace Lua 
{
	using uint16 = std::uint16_t;
	using uint32 = std::uint32_t;
	struct Vertex 
	{
		DirectX::XMFLOAT3 Position;
		DirectX::XMFLOAT3 Normal;
		DirectX::XMFLOAT3 TangentU;
		DirectX::XMFLOAT2 TexC;
	};

	struct MeshData
	{
		std::vector<Vertex> Vertices;
		std::vector<uint32> Indices32;

		// for read object,
		// here we save the component seperately.
		std::vector<DirectX::XMFLOAT3> Positions;
		std::vector<DirectX::XMFLOAT3> Normals;
		std::vector<DirectX::XMFLOAT3> TangentUs;
		std::vector<DirectX::XMFLOAT2> Texcoords;

	private:
		std::vector<uint16> mIndices16;

	public:
		std::vector<uint16>& GetIndices16()
		{
			if (mIndices16.empty())
			{
				mIndices16.resize(Indices32.size());
				for (size_t i = 0; i < Indices32.size(); ++i)
				{
					mIndices16[i] = static_cast<uint16>(Indices32[i]);
				}
			}
		}
	};
}