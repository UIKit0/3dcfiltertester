#include "D3DHelper.h"
#include "Exception.h"
#include "Engine.h"

#include <D3DX10core.h>
#include <fstream>

#include "../Misc/mmgr.h"

namespace engine
{
	std::wstring GetD3D10Error(HRESULT hresult)
	{
		switch(hresult)
		{
		case D3DERR_INVALIDCALL:
			return L"D3DERR_INVALIDCALL";
		case D3DERR_WASSTILLDRAWING:
			return L"D3DERR_WASSTILLDRAWING";
		case D3D10_ERROR_TOO_MANY_UNIQUE_STATE_OBJECTS:
			return L"D3D10_ERROR_TOO_MANY_UNIQUE_STATE_OBJECTS: ";
		case D3D10_ERROR_FILE_NOT_FOUND:
			return L"D3D10_ERROR_FILE_NOT_FOUND";
		case S_FALSE:
			return L"S_FALSE";
		case E_OUTOFMEMORY:
			return L"E_OUTOFMEMORY";
		case E_INVALIDARG:
			return L"E_INVALIDARG";
		case E_FAIL:
			return L"E_FAIL";
		}		

		return L"Unknown Error";
	}

	std::string GetDXGIFormatString(DXGI_FORMAT format)
	{
		switch(format) {			
			case DXGI_FORMAT_R32G32B32A32_TYPELESS: return "R32G32B32A32_TYPELESS";
			case DXGI_FORMAT_R32G32B32A32_FLOAT: return "R32G32B32A32_FLOAT";
			case DXGI_FORMAT_R32G32B32A32_UINT: return "R32G32B32A32_UINT";
			case DXGI_FORMAT_R32G32B32A32_SINT: return "R32G32B32A32_SINT";
			case DXGI_FORMAT_R32G32B32_TYPELESS: return "R32G32B32_TYPELESS";
			case DXGI_FORMAT_R32G32B32_FLOAT: return "R32G32B32_FLOAT";
			case DXGI_FORMAT_R32G32B32_UINT: return "R32G32B32_UINT";
			case DXGI_FORMAT_R32G32B32_SINT: return "R32G32B32_SINT";
			case DXGI_FORMAT_R16G16B16A16_TYPELESS: return "R16G16B16A16_TYPELESS";
			case DXGI_FORMAT_R16G16B16A16_FLOAT: return "R16G16B16A16_FLOAT";
			case DXGI_FORMAT_R16G16B16A16_UNORM: return "R16G16B16A16_UNORM";
			case DXGI_FORMAT_R16G16B16A16_UINT: return "R16G16B16A16_UINT";
			case DXGI_FORMAT_R16G16B16A16_SNORM: return "R16G16B16A16_SNORM";
			case DXGI_FORMAT_R16G16B16A16_SINT: return "R16G16B16A16_SINT";
			case DXGI_FORMAT_R32G32_TYPELESS: return "R32G32_TYPELESS";
			case DXGI_FORMAT_R32G32_FLOAT: return "R32G32_FLOAT";
			case DXGI_FORMAT_R32G32_UINT: return "R32G32_UINT";
			case DXGI_FORMAT_R32G32_SINT: return "R32G32_SINT";
			case DXGI_FORMAT_R32G8X24_TYPELESS: return "R32G8X24_TYPELESS";
			case DXGI_FORMAT_D32_FLOAT_S8X24_UINT: return "D32_FLOAT_S8X24_UINT";
			case DXGI_FORMAT_R32_FLOAT_X8X24_TYPELESS: return "R32_FLOAT_X8X24_TYPELESS";
			case DXGI_FORMAT_X32_TYPELESS_G8X24_UINT: return "X32_TYPELESS_G8X24_UINT";
			case DXGI_FORMAT_R10G10B10A2_TYPELESS: return "R10G10B10A2_TYPELESS";
			case DXGI_FORMAT_R10G10B10A2_UNORM: return "R10G10B10A2_UNORM";
			case DXGI_FORMAT_R10G10B10A2_UINT: return "R10G10B10A2_UINT";
			case DXGI_FORMAT_R11G11B10_FLOAT: return "R11G11B10_FLOAT";
			case DXGI_FORMAT_R8G8B8A8_TYPELESS: return "R8G8B8A8_TYPELESS";
			case DXGI_FORMAT_R8G8B8A8_UNORM: return "R8G8B8A8_UNORM";
			case DXGI_FORMAT_R8G8B8A8_UNORM_SRGB: return "R8G8B8A8_UNORM_SRGB";
			case DXGI_FORMAT_R8G8B8A8_UINT: return "R8G8B8A8_UINT";
			case DXGI_FORMAT_R8G8B8A8_SNORM: return "R8G8B8A8_SNORM";
			case DXGI_FORMAT_R8G8B8A8_SINT: return "R8G8B8A8_SINT";
			case DXGI_FORMAT_R16G16_TYPELESS: return "R16G16_TYPELESS";
			case DXGI_FORMAT_R16G16_FLOAT: return "R16G16_FLOAT";
			case DXGI_FORMAT_R16G16_UNORM: return "R16G16_UNORM";
			case DXGI_FORMAT_R16G16_UINT: return "R16G16_UINT";
			case DXGI_FORMAT_R16G16_SNORM: return "R16G16_SNORM";
			case DXGI_FORMAT_R16G16_SINT: return "R16G16_SINT";
			case DXGI_FORMAT_R32_TYPELESS: return "R32_TYPELESS";
			case DXGI_FORMAT_D32_FLOAT: return "D32_FLOAT";
			case DXGI_FORMAT_R32_FLOAT: return "R32_FLOAT";
			case DXGI_FORMAT_R32_UINT: return "R32_UINT";
			case DXGI_FORMAT_R32_SINT: return "R32_SINT";
			case DXGI_FORMAT_R24G8_TYPELESS: return "R24G8_TYPELESS";
			case DXGI_FORMAT_D24_UNORM_S8_UINT: return "D24_UNORM_S8_UINT";
			case DXGI_FORMAT_R24_UNORM_X8_TYPELESS: return "R24_UNORM_X8_TYPELESS";
			case DXGI_FORMAT_X24_TYPELESS_G8_UINT: return "X24_TYPELESS_G8_UINT";
			case DXGI_FORMAT_R8G8_TYPELESS: return "R8G8_TYPELESS";
			case DXGI_FORMAT_R8G8_UNORM: return "R8G8_UNORM";
			case DXGI_FORMAT_R8G8_UINT: return "R8G8_UINT";
			case DXGI_FORMAT_R8G8_SNORM: return "R8G8_SNORM";
			case DXGI_FORMAT_R8G8_SINT: return "R8G8_SINT";
			case DXGI_FORMAT_R16_TYPELESS: return "R16_TYPELESS";
			case DXGI_FORMAT_R16_FLOAT: return "R16_FLOAT";
			case DXGI_FORMAT_D16_UNORM: return "D16_UNORM";
			case DXGI_FORMAT_R16_UNORM: return "R16_UNORM";
			case DXGI_FORMAT_R16_UINT: return "R16_UINT";
			case DXGI_FORMAT_R16_SNORM: return "R16_SNORM";
			case DXGI_FORMAT_R16_SINT: return "R16_SINT";
			case DXGI_FORMAT_R8_TYPELESS: return "R8_TYPELESS";
			case DXGI_FORMAT_R8_UNORM: return "R8_UNORM";
			case DXGI_FORMAT_R8_UINT: return "R8_UINT";
			case DXGI_FORMAT_R8_SNORM: return "R8_SNORM";
			case DXGI_FORMAT_R8_SINT: return "R8_SINT";
			case DXGI_FORMAT_A8_UNORM: return "A8_UNORM";
			case DXGI_FORMAT_R1_UNORM: return "R1_UNORM";
			case DXGI_FORMAT_R9G9B9E5_SHAREDEXP: return "R9G9B9E5_SHAREDEXP";
			case DXGI_FORMAT_R8G8_B8G8_UNORM: return "R8G8_B8G8_UNORM";
			case DXGI_FORMAT_G8R8_G8B8_UNORM: return "G8R8_G8B8_UNORM";
			case DXGI_FORMAT_BC1_TYPELESS: return "BC1_TYPELESS";
			case DXGI_FORMAT_BC1_UNORM: return "BC1_UNORM";
			case DXGI_FORMAT_BC1_UNORM_SRGB: return "BC1_UNORM_SRGB";
			case DXGI_FORMAT_BC2_TYPELESS: return "BC2_TYPELESS";
			case DXGI_FORMAT_BC2_UNORM: return "BC2_UNORM";
			case DXGI_FORMAT_BC2_UNORM_SRGB: return "BC2_UNORM_SRGB";
			case DXGI_FORMAT_BC3_TYPELESS: return "BC3_TYPELESS";
			case DXGI_FORMAT_BC3_UNORM: return "BC3_UNORM";
			case DXGI_FORMAT_BC3_UNORM_SRGB: return "BC3_UNORM_SRGB";
			case DXGI_FORMAT_BC4_TYPELESS: return "BC4_TYPELESS";
			case DXGI_FORMAT_BC4_UNORM: return "BC4_UNORM";
			case DXGI_FORMAT_BC4_SNORM: return "BC4_SNORM";
			case DXGI_FORMAT_BC5_TYPELESS: return "BC5_TYPELESS";
			case DXGI_FORMAT_BC5_UNORM: return "BC5_UNORM";
			case DXGI_FORMAT_BC5_SNORM: return "BC5_SNORM";
			case DXGI_FORMAT_B5G6R5_UNORM: return "B5G6R5_UNORM";
			case DXGI_FORMAT_B5G5R5A1_UNORM: return "B5G5R5A1_UNORM";
			case DXGI_FORMAT_B8G8R8A8_UNORM: return "B8G8R8A8_UNORM";
			case DXGI_FORMAT_B8G8R8X8_UNORM: return "B8G8R8X8_UNORM";
		}

		return "Unknown";
	}

	unsigned int GetDXGIFormatSize(DXGI_FORMAT format)
	{
		switch(format) {			
			case DXGI_FORMAT_R32G32B32A32_TYPELESS: return 16;
			case DXGI_FORMAT_R32G32B32A32_FLOAT: return 16;
			case DXGI_FORMAT_R32G32B32A32_UINT: return 16;
			case DXGI_FORMAT_R32G32B32A32_SINT: return 16;
			case DXGI_FORMAT_R32G32B32_TYPELESS: return 12;
			case DXGI_FORMAT_R32G32B32_FLOAT: return 12;
			case DXGI_FORMAT_R32G32B32_UINT: return 12;
			case DXGI_FORMAT_R32G32B32_SINT: return 12;
			case DXGI_FORMAT_R16G16B16A16_TYPELESS: return 8;
			case DXGI_FORMAT_R16G16B16A16_FLOAT: return 8;
			case DXGI_FORMAT_R16G16B16A16_UNORM: return 8;
			case DXGI_FORMAT_R16G16B16A16_UINT: return 8;
			case DXGI_FORMAT_R16G16B16A16_SNORM: return 8;
			case DXGI_FORMAT_R16G16B16A16_SINT: return 8;
			case DXGI_FORMAT_R32G32_TYPELESS: return 8;
			case DXGI_FORMAT_R32G32_FLOAT: return 8;
			case DXGI_FORMAT_R32G32_UINT: return 8;
			case DXGI_FORMAT_R32G32_SINT: return 8;
			case DXGI_FORMAT_R32G8X24_TYPELESS: return 8;
			case DXGI_FORMAT_D32_FLOAT_S8X24_UINT: return 8;
			case DXGI_FORMAT_R32_FLOAT_X8X24_TYPELESS: return 8;
			case DXGI_FORMAT_X32_TYPELESS_G8X24_UINT: return 8;
			case DXGI_FORMAT_R10G10B10A2_TYPELESS: return 4;
			case DXGI_FORMAT_R10G10B10A2_UNORM: return 4;
			case DXGI_FORMAT_R10G10B10A2_UINT: return 4;
			case DXGI_FORMAT_R11G11B10_FLOAT: return 4;
			case DXGI_FORMAT_R8G8B8A8_TYPELESS: return 4;
			case DXGI_FORMAT_R8G8B8A8_UNORM: return 4;
			case DXGI_FORMAT_R8G8B8A8_UNORM_SRGB: return 4;
			case DXGI_FORMAT_R8G8B8A8_UINT: return 4;
			case DXGI_FORMAT_R8G8B8A8_SNORM: return 4;
			case DXGI_FORMAT_R8G8B8A8_SINT: return 4;
			case DXGI_FORMAT_R16G16_TYPELESS: return 4;
			case DXGI_FORMAT_R16G16_FLOAT: return 4;
			case DXGI_FORMAT_R16G16_UNORM: return 4;
			case DXGI_FORMAT_R16G16_UINT: return 4;
			case DXGI_FORMAT_R16G16_SNORM: return 4;
			case DXGI_FORMAT_R16G16_SINT: return 4;
			case DXGI_FORMAT_R32_TYPELESS: return 4;
			case DXGI_FORMAT_D32_FLOAT: return 4;
			case DXGI_FORMAT_R32_FLOAT: return 4;
			case DXGI_FORMAT_R32_UINT: return 4;
			case DXGI_FORMAT_R32_SINT: return 4;
			case DXGI_FORMAT_R24G8_TYPELESS: return 4;
			case DXGI_FORMAT_D24_UNORM_S8_UINT: return 4;
			case DXGI_FORMAT_R24_UNORM_X8_TYPELESS: return 4;
			case DXGI_FORMAT_X24_TYPELESS_G8_UINT: return 4;
			case DXGI_FORMAT_R8G8_TYPELESS: return 2;
			case DXGI_FORMAT_R8G8_UNORM: return 2;
			case DXGI_FORMAT_R8G8_UINT: return 2;
			case DXGI_FORMAT_R8G8_SNORM: return 2;
			case DXGI_FORMAT_R8G8_SINT: return 2;
			case DXGI_FORMAT_R16_TYPELESS:  return 2;
			case DXGI_FORMAT_R16_FLOAT: return 2;
			case DXGI_FORMAT_D16_UNORM: return 2;
			case DXGI_FORMAT_R16_UNORM: return 2;
			case DXGI_FORMAT_R16_UINT: return 2;
			case DXGI_FORMAT_R16_SNORM: return 2;
			case DXGI_FORMAT_R16_SINT: return 2;
			case DXGI_FORMAT_R8_TYPELESS: return 1;
			case DXGI_FORMAT_R8_UNORM: return 1;
			case DXGI_FORMAT_R8_UINT: return 1;
			case DXGI_FORMAT_R8_SNORM: return 1;
			case DXGI_FORMAT_R8_SINT: return 1;
			case DXGI_FORMAT_A8_UNORM: return 1;			
			case DXGI_FORMAT_R9G9B9E5_SHAREDEXP: return 4;
			case DXGI_FORMAT_R8G8_B8G8_UNORM: return 4;
			case DXGI_FORMAT_G8R8_G8B8_UNORM: return 4;
			case DXGI_FORMAT_BC1_TYPELESS: return 8;
			case DXGI_FORMAT_BC1_UNORM: return 8;
			case DXGI_FORMAT_BC1_UNORM_SRGB: return 8;
			case DXGI_FORMAT_BC2_TYPELESS: return 16;
			case DXGI_FORMAT_BC2_UNORM: return 16;
			case DXGI_FORMAT_BC2_UNORM_SRGB: return 16;
			case DXGI_FORMAT_BC3_TYPELESS: return 16;
			case DXGI_FORMAT_BC3_UNORM: return 16;
			case DXGI_FORMAT_BC3_UNORM_SRGB: return 16;
			case DXGI_FORMAT_BC4_TYPELESS: return 8;
			case DXGI_FORMAT_BC4_UNORM: return 8;
			case DXGI_FORMAT_BC4_SNORM: return 8;
			case DXGI_FORMAT_BC5_TYPELESS: return 16;
			case DXGI_FORMAT_BC5_UNORM: return 16;
			case DXGI_FORMAT_BC5_SNORM: return 16;
			case DXGI_FORMAT_B5G6R5_UNORM: return 2;
			case DXGI_FORMAT_B5G5R5A1_UNORM: return 2;
			case DXGI_FORMAT_B8G8R8A8_UNORM: return 4;
			case DXGI_FORMAT_B8G8R8X8_UNORM: return 4;
		}

		throw Exception(L"GetDXGIFormatSize: Invalid format");		
	}

	ID3D10VertexShader *CreateVertexShaderFromFile(std::string name, char *&buffer, unsigned int &size)
	{
		HRESULT hresult;
		ID3D10Device *d3d10_device = engine.GetDevice();

		DWORD dwShaderFlags = 0;		
#ifdef _DEBUG
		dwShaderFlags |= D3D10_SHADER_DEBUG;
		name += "Debug";
#endif

		std::string vso_filename = "CompiledShaders/" + name + ".so";

		std::ifstream vertex_shader_file(vso_filename.c_str(), std::ios::in|std::ios::binary|std::ios::ate);
		if(!vertex_shader_file.is_open()) throw Exception(L"Shader: File not found");

		size = vertex_shader_file.tellg();
		buffer = new char[size];
		vertex_shader_file.seekg(0, std::ios::beg);
		vertex_shader_file.read(buffer, size);
		vertex_shader_file.close();

		ID3D10VertexShader *vertex_shader;

		// Create vertex shader
		if((hresult = d3d10_device->CreateVertexShader(buffer,size,&vertex_shader)) != S_OK)
			throw Exception(L"D3DHelper: CreateVertexShader failed: " + GetD3D10Error(hresult));

		return vertex_shader;
	}

	ID3D10GeometryShader *CreateGeometryShaderFromFile(std::string name, char *&buffer, unsigned int &size, 
		D3D10_SO_DECLARATION_ENTRY *declaration_entries, unsigned int num_entries, unsigned int stream_output_stride)
	{
		HRESULT hresult;
		ID3D10Device *d3d10_device = engine.GetDevice();

		DWORD dwShaderFlags = 0;		
#ifdef _DEBUG
		dwShaderFlags |= D3D10_SHADER_DEBUG;
		name += "Debug";
#endif

		std::string gso_filename = "CompiledShaders/" + name + ".so";

		std::ifstream geometry_shader_file(gso_filename.c_str(), std::ios::in|std::ios::binary|std::ios::ate);
		if(!geometry_shader_file.is_open()) throw Exception(L"Shader: File not found");

		size = geometry_shader_file.tellg();
		buffer = new char[size];
		geometry_shader_file.seekg(0, std::ios::beg);
		geometry_shader_file.read(buffer, size);
		geometry_shader_file.close();

		ID3D10GeometryShader *geometry_shader;

		// Create geometry shader
		if(declaration_entries) {
			if((hresult = d3d10_device->CreateGeometryShaderWithStreamOutput(buffer, size, declaration_entries, 
				num_entries, stream_output_stride, &geometry_shader)) != S_OK) {
				throw Exception(L"D3DHelper: CreateGeometryShader failed: " + GetD3D10Error(hresult));
			}
		}
		else {
			if((hresult = d3d10_device->CreateGeometryShader(buffer, size, &geometry_shader)) != S_OK) {
				throw Exception(L"D3DHelper: CreateGeometryShader failed: " + GetD3D10Error(hresult));
			}
		}

		return geometry_shader;
	}

	ID3D10PixelShader *CreatePixelShaderFromFile(std::string name, char *&buffer, unsigned int &size)
	{
		HRESULT hresult;
		ID3D10Device *d3d10_device = engine.GetDevice();

		DWORD dwShaderFlags = 0;		
#ifdef _DEBUG
		dwShaderFlags |= D3D10_SHADER_DEBUG;
		name += "Debug";
#endif

		std::string pso_filename = "CompiledShaders/" + name + ".so";

		std::ifstream pixel_shader_file(pso_filename.c_str(), std::ios::in|std::ios::binary|std::ios::ate);
		if(!pixel_shader_file.is_open()) throw Exception(L"Shader: File not found");

		size = pixel_shader_file.tellg();
		buffer = new char[size];
		pixel_shader_file.seekg(0, std::ios::beg);
		pixel_shader_file.read(buffer, size);
		pixel_shader_file.close();

		ID3D10PixelShader *pixel_shader;

		// Create pixel shader
		if((hresult = d3d10_device->CreatePixelShader(buffer, size, &pixel_shader)) != S_OK)
			throw Exception(L"D3DHelper: CreatePixelShader failed: " + GetD3D10Error(hresult));

		return pixel_shader;
	}
}