#include "stdafx.h"

using namespace DirectX;

const LONG	g_WindowHeight		= 600;
const LONG	g_WindowWidth		= 800;
LPCSTR		g_WindowClassName	= "DirectXWindowClass";
LPCSTR		g_WindowName		= "DirectX Test";
HWND		g_WindowHandle		= NULL;
const BOOL	g_EnableVSync		= TRUE;

// DirectX Device and Swap Chain
ID3D11Device *g_d3dDevice = nullptr;
ID3D11DeviceContext * g_d3dDeviceContext = nullptr;
IDXGISwapChain *g_d3dSwapChain = nullptr;

// Render target view for the back buffer of the swap chain.
ID3D11RenderTargetView *g_d3dRenderTargetView = nullptr;
// Define the functionality of the depth/stencil stages.
ID3D11DepthStencilState *g_d3dDepthStencilState = nullptr;
// A texture to associate to the depth stencil view.
ID3D11Texture2D *g_d3dDepthStencilBuffer = nullptr;
// Depth/stencil view for use as a depth buffer.
ID3D11DepthStencilView *g_d3dDepthStencilView = nullptr;
// Define the functionality of the rasterizer stage.
ID3D11RasterizerState *g_d3dRasterizerState = nullptr;

D3D11_VIEWPORT g_Viewport = { 0 };

// Vertex buffer
ID3D11InputLayout *g_d3dInputLayout = nullptr;
ID3D11Buffer *g_d3dVertexBuffer = nullptr;
ID3D11Buffer *g_d3dIndexBuffer = nullptr;

// Shaders
ID3D11VertexShader *g_d3dVertexShader = nullptr;
ID3D11PixelShader *g_d3dPixelShader = nullptr;
enum ConstantBuffer
{
	CB_Application,
	CB_Frame,
	CB_Object,
	
	CB_Last
};
ID3D11Buffer *g_d3dConstantBuffers[CB_Last];

// Vertex data for a colored cube.
struct VertexPosColor
{
	XMFLOAT3 Position;
	XMFLOAT3 Color;
};

VertexPosColor g_Vertices[8] =
{
	{ XMFLOAT3(-1.0f, -1.0f, -1.0f), XMFLOAT3(0.0f, 0.0f, 0.0f) }, // 0
	{ XMFLOAT3(-1.0f,  1.0f, -1.0f), XMFLOAT3(0.0f, 1.0f, 0.0f) }, // 1
	{ XMFLOAT3(1.0f,  1.0f, -1.0f), XMFLOAT3(1.0f, 1.0f, 0.0f) }, // 2
	{ XMFLOAT3(1.0f, -1.0f, -1.0f), XMFLOAT3(1.0f, 0.0f, 0.0f) }, // 3
	{ XMFLOAT3(-1.0f, -1.0f,  1.0f), XMFLOAT3(0.0f, 0.0f, 1.0f) }, // 4
	{ XMFLOAT3(-1.0f,  1.0f,  1.0f), XMFLOAT3(0.0f, 1.0f, 1.0f) }, // 5
	{ XMFLOAT3(1.0f,  1.0f,  1.0f), XMFLOAT3(1.0f, 1.0f, 1.0f) }, // 6
	{ XMFLOAT3(1.0f, -1.0f,  1.0f), XMFLOAT3(1.0f, 0.0f, 1.0f) }  // 7
};

WORD g_Indicies[36] =
{
	0, 1, 2, 0, 2, 3,
	4, 6, 5, 4, 7, 6,
	4, 5, 1, 4, 1, 0,
	3, 2, 6, 3, 6, 7,
	1, 5, 6, 1, 6, 2,
	4, 0, 3, 4, 3, 7
};

// Forward declarations.
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

bool LoadContent();
void UnloadContent();

void Update(float deltaTime);
void Render();
void Cleanup();

int InitDirectX(HINSTANCE hInstance, BOOL vSync);

int InitApplication(HINSTANCE hInstance, int nCmdShow)
{
	WNDCLASSEX wndClass = { 0 };
	wndClass.cbSize = sizeof(WNDCLASSEX);
	wndClass.style = CS_HREDRAW | CS_VREDRAW;
	wndClass.lpfnWndProc = &WndProc;
	wndClass.hInstance = hInstance;
	wndClass.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wndClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wndClass.lpszMenuName = nullptr;
	wndClass.lpszClassName = g_WindowClassName;

	if (RegisterClassEx(&wndClass))
	{
		RECT windowRect = { 0, 0, g_WindowWidth, g_WindowHeight };
		AdjustWindowRect(&windowRect, WS_OVERLAPPEDWINDOW, FALSE);
		int nWidth = windowRect.right - windowRect.left;
		int nHeight = windowRect.bottom - windowRect.top;

		g_WindowHandle = CreateWindowA(g_WindowClassName, g_WindowName, WS_OVERLAPPEDWINDOW,  CW_USEDEFAULT, CW_USEDEFAULT, nWidth, nHeight, nullptr, nullptr, hInstance, nullptr);

		if (g_WindowHandle)
		{
			ShowWindow(g_WindowHandle, nCmdShow);
			UpdateWindow(g_WindowHandle);

			return 0;
		}
	}

	return -1;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT Paint;
	HDC hDC;

	switch (message)
	{
	case WM_PAINT:
	{
		hDC = BeginPaint(hWnd, &Paint);
		EndPaint(hWnd, &Paint);
	}
	break;
	case WM_DESTROY:
	{
		PostQuitMessage(0);
	}
	break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

	return 0;
}

int Run()
{
	MSG msg = { 0 };

	static DWORD tmPrevious = timeGetTime();
	static const float fTargetFrameRate = 30.0f;
	static const float fMaxTimeStep = 1.0f / fTargetFrameRate;

	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			DWORD tmCurrent = timeGetTime();
			float fDelta = std::min<float>((float)(tmCurrent - tmPrevious), fMaxTimeStep);
			tmPrevious = tmCurrent;

			//Update(fDelta);
			//Render();
		}
	}

	return (int)msg.wParam;
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE prevInstance, LPWSTR cmdLine, int cmdShow)
{
	UNREFERENCED_PARAMETER(cmdLine);
	UNREFERENCED_PARAMETER(prevInstance);

	if (!XMVerifyCPUSupport())
	{
		MessageBox(nullptr, TEXT("DirectX not supported"), TEXT("Error"), MB_OK);
		return -1;
	}

	if (InitApplication(hInstance, cmdShow) != 0)
	{
		MessageBox(nullptr, TEXT("Init Failed"), TEXT("Error"), MB_OK);
		return -1;
	}

	if (InitDirectX(hInstance, g_EnableVSync) != 0)
	{
		MessageBox(nullptr, TEXT("Init DirectX Failed"), TEXT("Error"), MB_OK);
		return -1;
	}

	return Run();
}

int InitDirectX(HINSTANCE hInstance, BOOL vSync)
{
	UNREFERENCED_PARAMETER(vSync);
	UNREFERENCED_PARAMETER(hInstance);

	assert(g_WindowHandle != 0);

	RECT rectClient;
	GetClientRect(g_WindowHandle, &rectClient);
	UINT nWidth = rectClient.right - rectClient.left;
	UINT nHeight = rectClient.bottom - rectClient.top;

	// 1/6 Initialize the DirectX device and swap chain.
	DXGI_SWAP_CHAIN_DESC swapChainDesc;
	ZeroMemory(&swapChainDesc, sizeof(DXGI_SWAP_CHAIN_DESC));

	swapChainDesc.BufferCount = 1;
	swapChainDesc.BufferDesc.Width = nWidth;
	swapChainDesc.BufferDesc.Height = nHeight;
	swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	swapChainDesc.BufferDesc.RefreshRate.Numerator = 0; //TODO How to properly get the QueryRefreshRate(nWidth, nHeight, vSync);
	swapChainDesc.BufferDesc.RefreshRate.Numerator = 1;
	swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	swapChainDesc.OutputWindow = g_WindowHandle;
	swapChainDesc.SampleDesc.Count = 1;
	swapChainDesc.SampleDesc.Quality = 0;
	swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
	swapChainDesc.Windowed = TRUE;

	UINT nFlags = 0;
#if _DEBUG
	nFlags = D3D11_CREATE_DEVICE_DEBUG;
#endif

	D3D_FEATURE_LEVEL featureLevels[] =
	{
		D3D_FEATURE_LEVEL_11_1,
		D3D_FEATURE_LEVEL_11_0,
		D3D_FEATURE_LEVEL_10_1,
		D3D_FEATURE_LEVEL_10_0,
		D3D_FEATURE_LEVEL_9_3,
		D3D_FEATURE_LEVEL_9_2,
		D3D_FEATURE_LEVEL_9_1
	};
	int nFeatureLevelsCount = sizeof(featureLevels) / sizeof(featureLevels[0]);
	D3D_FEATURE_LEVEL featureLevel;

	HRESULT hResult = D3D11CreateDeviceAndSwapChain(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, nFlags, featureLevels, nFeatureLevelsCount, D3D11_SDK_VERSION, &swapChainDesc, &g_d3dSwapChain, &g_d3dDevice, &featureLevel, &g_d3dDeviceContext);
	if (hResult == E_INVALIDARG) // If DirectX 11 is not supported
		hResult = D3D11CreateDeviceAndSwapChain(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, nFlags, &featureLevels[1], nFeatureLevelsCount, D3D11_SDK_VERSION, &swapChainDesc, &g_d3dSwapChain, &g_d3dDevice, &featureLevel, &g_d3dDeviceContext);
	if (FAILED(hResult))
		return -1;

	// 2/6 Create a render target view of the swap chain’s back buffer
	ID3D11Texture2D *pBuffer;
	hResult = g_d3dSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&pBuffer);
	if (FAILED(hResult))
		return -1;

	hResult = g_d3dDevice->CreateRenderTargetView(pBuffer, nullptr, &g_d3dRenderTargetView);
	if (FAILED(hResult))
		return -1;

	SafeRelease(pBuffer);

	// 3/6 Create a texture for the depth-stencil buffer
	D3D11_TEXTURE2D_DESC depthStencilBufferDesc;
	ZeroMemory(&depthStencilBufferDesc, sizeof(D3D11_TEXTURE2D_DESC));

	depthStencilBufferDesc.ArraySize = 1;
	depthStencilBufferDesc.BindFlags = D3D11_BIND_DEPTH_STENCIL;
	depthStencilBufferDesc.CPUAccessFlags = 0; // No CPU access required.
	depthStencilBufferDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
	depthStencilBufferDesc.Width = nWidth;
	depthStencilBufferDesc.Height = nHeight;
	depthStencilBufferDesc.MipLevels = 1;
	depthStencilBufferDesc.SampleDesc.Count = 1;
	depthStencilBufferDesc.SampleDesc.Quality = 0;
	depthStencilBufferDesc.Usage = D3D11_USAGE_DEFAULT;

	hResult = g_d3dDevice->CreateTexture2D(&depthStencilBufferDesc, nullptr, &g_d3dDepthStencilBuffer);
	if (FAILED(hResult))
		return -1;

	// 4/6 Create a depth - stencil view from the depth - stencil buffer
	hResult = g_d3dDevice->CreateDepthStencilView(g_d3dDepthStencilBuffer, nullptr, &g_d3dDepthStencilView);
	if (FAILED(hResult))
		return -1;
	
	// 5/6 Create a depth - stencil state object that defines the behaviour of the output merger stage
	D3D11_DEPTH_STENCIL_DESC depthStencilStateDesc;
	ZeroMemory(&depthStencilStateDesc, sizeof(D3D11_DEPTH_STENCIL_DESC));

	depthStencilStateDesc.DepthEnable = TRUE;
	depthStencilStateDesc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
	depthStencilStateDesc.DepthFunc = D3D11_COMPARISON_LESS;
	depthStencilStateDesc.StencilEnable = FALSE;

	hResult = g_d3dDevice->CreateDepthStencilState(&depthStencilStateDesc, &g_d3dDepthStencilState);
	if (FAILED(hResult))
		return -1;

	// 6/6 Create a rasterizer state object that defines the behaviour of the rasterizer stage
	D3D11_RASTERIZER_DESC rasterizerDesc;
	ZeroMemory(&rasterizerDesc, sizeof(D3D11_RASTERIZER_DESC));

	rasterizerDesc.AntialiasedLineEnable = FALSE;
	rasterizerDesc.CullMode = D3D11_CULL_BACK;
	rasterizerDesc.DepthBias = 0;
	rasterizerDesc.DepthBiasClamp = 0.0f;
	rasterizerDesc.DepthClipEnable = TRUE;
	rasterizerDesc.FillMode = D3D11_FILL_SOLID;
	rasterizerDesc.FrontCounterClockwise = FALSE;
	rasterizerDesc.MultisampleEnable = FALSE;
	rasterizerDesc.ScissorEnable = FALSE;
	rasterizerDesc.SlopeScaledDepthBias = 0.0f;

	hResult = g_d3dDevice->CreateRasterizerState(&rasterizerDesc, &g_d3dRasterizerState);
	if (FAILED(hResult))
		return -1;

	// Initialize the viewport
	g_Viewport.Height = (FLOAT)nHeight;
	g_Viewport.Width = (FLOAT)nWidth;
	g_Viewport.TopLeftX = 0.0f;
	g_Viewport.TopLeftY = 0.0f;
	g_Viewport.MinDepth = 0.0f;
	g_Viewport.MaxDepth = 1.0f;

	return 0;
}

bool LoadContent()
{
	assert(g_d3dDevice);

	D3D11_BUFFER_DESC vertexBufferDesc;
	ZeroMemory(&vertexBufferDesc, sizeof(D3D11_BUFFER_DESC));

	vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	vertexBufferDesc.ByteWidth = sizeof(VertexPosColor) * _countof(g_Vertices);
	vertexBufferDesc.CPUAccessFlags = 0;
	vertexBufferDesc.Usage = D3D11_USAGE_DEFAULT;

	D3D11_SUBRESOURCE_DATA resourceData;
	ZeroMemory(&resourceData, sizeof(D3D11_SUBRESOURCE_DATA));
	resourceData.pSysMem = g_Vertices;

	HRESULT hResult = g_d3dDevice->CreateBuffer(&vertexBufferDesc, &resourceData, &g_d3dVertexBuffer);
	if (FAILED(hResult))
		return false;

	D3D11_BUFFER_DESC indexBufferDesc;
	ZeroMemory(&indexBufferDesc, sizeof(D3D11_BUFFER_DESC));

	indexBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
	indexBufferDesc.ByteWidth = sizeof(WORD) * _countof(g_Indicies);
	indexBufferDesc.CPUAccessFlags = 0;
	indexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	resourceData.pSysMem = g_Indicies;

	hResult = g_d3dDevice->CreateBuffer(&indexBufferDesc, &resourceData, &g_d3dIndexBuffer);
	if (FAILED(hResult))
		return false;

	D3D11_BUFFER_DESC constantBufferDesc;
	ZeroMemory(&constantBufferDesc, sizeof(D3D11_BUFFER_DESC));

	constantBufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	constantBufferDesc.ByteWidth = sizeof(XMMATRIX);
	constantBufferDesc.CPUAccessFlags = 0;
	constantBufferDesc.Usage = D3D11_USAGE_DEFAULT;

	hResult = g_d3dDevice->CreateBuffer(&indexBufferDesc, nullptr, &g_d3dConstantBuffers[CB_Application]);
	if (FAILED(hResult))
		return false;

	hResult = g_d3dDevice->CreateBuffer(&indexBufferDesc, nullptr, &g_d3dConstantBuffers[CB_Frame]);
	if (FAILED(hResult))
		return false;

	hResult = g_d3dDevice->CreateBuffer(&indexBufferDesc, nullptr, &g_d3dConstantBuffers[CB_Object]);
	if (FAILED(hResult))
		return false;

#if _DEBUG
	LPCWSTR compiledVertexShaderObject = L"SimpleVertexShader_d.cso";
	LPCWSTR compiledPixelShaderObject = L"SimplePixelShader_d.cso";
#else
	LPCWSTR compiledVertexShaderObject = L"SimpleVertexShader.cso";
	LPCWSTR compiledPixelShaderObject = L"SimplePixelShader.cso";
#endif

	ID3DBlob *vertexShaderBlob;
	hResult = D3DReadFileToBlob(compiledVertexShaderObject, &vertexShaderBlob);
	if (FAILED(hResult))
		return false;

	ID3DBlob *pixelShaderBlob;
	hResult = D3DReadFileToBlob(compiledPixelShaderObject, &pixelShaderBlob);
	if (FAILED(hResult))
		return false;

	hResult = g_d3dDevice->CreateVertexShader(vertexShaderBlob->GetBufferPointer(), vertexShaderBlob->GetBufferSize(), nullptr, &g_d3dVertexShader);
	if (FAILED(hResult))
		return false;

	hResult = g_d3dDevice->CreatePixelShader(pixelShaderBlob->GetBufferPointer(), pixelShaderBlob->GetBufferSize(), nullptr, &g_d3dPixelShader);
	if (FAILED(hResult))
		return false;
}