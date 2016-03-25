#include "stdafx.h"
#include "ShaderCompilator.h"

using namespace std;

template <class ShaderClass>
string GetLatestProfile(ID3D11Device *d3dDevice);

template<>
string GetLatestProfile<ID3D11VertexShader>(ID3D11Device *d3dDevice)
{
	assert(d3dDevice);

	D3D_FEATURE_LEVEL FeatureLevel = d3dDevice->GetFeatureLevel();

	switch (FeatureLevel)
	{
	case D3D_FEATURE_LEVEL_11_1:
	case D3D_FEATURE_LEVEL_11_0:
		return "vs_5_0";
	case D3D_FEATURE_LEVEL_10_1:
		return "vs_4_1";
	case D3D_FEATURE_LEVEL_10_0:
		return "vs_4_0";
	case D3D_FEATURE_LEVEL_9_3:
		return "vs_4_0_level_9_3";
	case D3D_FEATURE_LEVEL_9_2:
	case D3D_FEATURE_LEVEL_9_1:
		return "vs_4_0_level_9_1";
	default:
		return "";
	}
}

template <>
string GetLatestProfile<ID3D11PixelShader>(ID3D11Device *d3dDevice)
{
	assert(d3dDevice);

	D3D_FEATURE_LEVEL FeatureLevel = d3dDevice->GetFeatureLevel();

	switch (FeatureLevel)
	{
	case D3D_FEATURE_LEVEL_11_1:
	case D3D_FEATURE_LEVEL_11_0:
		return "ps_5_0";
	case D3D_FEATURE_LEVEL_10_1:
		return "ps_4_1";
	case D3D_FEATURE_LEVEL_10_0:
		return "ps_4_0";
	case D3D_FEATURE_LEVEL_9_3:
		return "ps_4_0_level_9_3";
	case D3D_FEATURE_LEVEL_9_2:
	case D3D_FEATURE_LEVEL_9_1:
		return "ps_4_0_level_9_1";
	default:
		return "";
	}
}

template< class ShaderClass >
ShaderClass* CreateShader(ID3D11Device* d3dDevice, ID3DBlob* pShaderBlob, ID3D11ClassLinkage* pClassLinkage);

template<>
ID3D11VertexShader* CreateShader<ID3D11VertexShader>(ID3D11Device* d3dDevice, ID3DBlob* pShaderBlob, ID3D11ClassLinkage* pClassLinkage)
{
	assert(d3dDevice);
	assert(pShaderBlob);

	ID3D11VertexShader* pVertexShader = nullptr;
	d3dDevice->CreateVertexShader(pShaderBlob->GetBufferPointer(), pShaderBlob->GetBufferSize(), pClassLinkage, &pVertexShader);

	return pVertexShader;
}

template<>
ID3D11PixelShader* CreateShader<ID3D11PixelShader>(ID3D11Device* d3dDevice, ID3DBlob* pShaderBlob, ID3D11ClassLinkage* pClassLinkage)
{
	assert(d3dDevice);
	assert(pShaderBlob);

	ID3D11PixelShader* pPixelShader = nullptr;
	d3dDevice->CreatePixelShader(pShaderBlob->GetBufferPointer(), pShaderBlob->GetBufferSize(), pClassLinkage,  &pPixelShader);

	return pPixelShader;
}


template< class ShaderClass >
ShaderClass* LoadShader(ID3D11Device* d3dDevice, const std::wstring& fileName, const std::string& entryPoint, const std::string& _profile)
{
	ID3DBlob* pShaderBlob = nullptr;
	ID3DBlob* pErrorBlob = nullptr;

	string profile = _profile;
	if (profile == "latest")
		profile = GetLatestProfile<ShaderClass>();

	UINT flags = D3DCOMPILE_ENABLE_STRICTNESS;
#ifdef _DEBUG
	flags |= D3DCOMPILE_DEBUG;
#endif

	// No macros used
	HRESULT hResult = D3DCompileFromFile(fileName, nullptr, D3D_COMPILE_STANDARD_FILE_INCLUDE, entryPoint.c_str(), profile.c_str(), flags, 0, *pShaderBlob, *pErrorBlob);
	if (FAILED(hResult))
	{
		if (pErrorBlob)
		{
			string error = (char *)pErrorBlob->GetBufferPointer();
			OutputDebugStringA(error.c_str());

			SafeRelease(pErrorBlob);
			SafeRelease(pShaderBlob);
		}

		return nullptr;
	}

	ShaderClass pShader = CreateShader<ShaderClass>(d3dDevice, pShaderBlob, nullptr);
	SafeRelease(pShaderBlob);
	SafeRelease(pErrorBlob);

	return pShader;
}