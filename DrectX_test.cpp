/*
��������Ŀ��ļ���d3dx9d.lib,d3d9.lib,d3dx11.lib,dxerr.lib,dxguid.lib,winmm.lib,comctl32.lib

���������ò����Է���һ��

���ղ���Ӱ��2D��ɫ

2D�������ת������ʹ����������ѧϰ����2DͼƬӳ�䵽�����ϣ�Ȼ����������ת��Ҳ���Խ���������3D����������Z ����ת��

D3DMATERIAL9���Ժ���
Diffuse��ָ�����淴���������⣬�ڲ��ǻ�����ֱ���ʱ�����ֵ���ɫ��
Ambient��ָ�����淴��Ļ����⣬�������ΪĬ�ϣ�Ҳ����D3DXCOLOR��ֵ��Ϊ0.0f��ʱ����������ʲô��ɫ���������ʾʲô��ɫ��
Specular��ָ�����淴��ľ���⣬������ʲô�û���֪����
Emissive�����汾���Է���,���䱻ָ��ʱ�����ۻ����⣬���������ʲô��ֻ��ʾ����Ĺ⡣
Power ������߹⣬����ֵ�Ǹ߹������ֵ����ֵԽ���ʾ�߹�ǿ������Χ�������Խ��

���ģʽ��D3DRS_FILLMODE�������û�Ӱ�����л��Ƶ�3Dģ�ͣ�������������������ͼ�Ρ�

�۲����Ҳ�����������λ��Z��غ����ֵ�����

����ֻ���ڹ��տ���ʱ����Ч��Ҳ����˵�����������գ���ô����������Ҳ�ǰ׷ѣ�ͼ��ֻ����ʾ�䶥���ʽ�����õ���������ɫ�������˹��գ����û�����ò��ʣ���ô�����ʽ���õ�������
��û��Ч����;ֻ��ͬʱ�����˹��պͲ��ʣ��������õ���ɫ������ȷ��ʾ����.

����ͼ�θ�3D����֮ǰ��Clear�������ܻ�Ӱ��ͼƬ����ʾ���������Z������գ�����ܻ��Ʋ���ͼ��

����������Ҫע�⣺�����ʽһ��Ҫ����Ϊ������������ģ���ξ�����Ҫ��ȷ��ʾ����������ò��ʣ����Ҳ��ʵ���ɫ��Ӱ������ĵĻ��ʣ���������Ԫ�ؽ�����ɫ��ϡ�����ֻ��ӳ�䵽����
�����ϣ�����ӳ�䵽3D�����ϡ�
��������ȡֵ[0,1]֮�䣬ȡ��1��1����ʾ��������ͼƬ

͸������Alpha��ϣ�Alpha������Ҫ����ָ�����ص�͸���ȡ�Ĭ������£�Alpha����������;�����Ի�ȡ�������alpha,���ʵ�alpha,�����alpha����Ĭ������£�Alpha����ȡ��Alphaͨ������������Alphaͨ��ʱ��Alpha����ȡ�Զ�����ɫ��������Alphaͨ������ȡ��Alphaͨ��
��Ȼ������ͨ��SetRenderState����������Alphaֵ����Դ��alphaѡȡ�����ȼ�������>����>����

��ʹ��alpha��ϲ��裺1������alpha��Դ�����ʻ���alphaͨ������SetTextureStageState��
					 2������Ŀ���Դ������ӡ�SetRenderState��
					 3�����û�ϡ�SetRenderState��

�ƹ�Ŀ�����رգ�����Ӱ��Ӱ���������ʾ������Ŀǰ���Բ�Ӱ��

D3DXVec3Normalize��ʲô�ã���

�����Ѱַʲôʱ���ã�������

pdevice->SetRenderState(D3DRS_AMBIENT, 0xff505050) �������ʲô�ã�������

����Щ���գ���������Щ���÷�ʽ��ÿ��������ʲôЧ����

����ͼƬ��ʽ�Ĵ洢��ʽ���Լ�ͼƬ����������ȡ�ģ�����
*/
#include <stdio.h>
#include <windowsx.h>
#include <d3d9.h>
#include <D3DX10Math.h>
#include <d3dx9core.h>

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 800
#define WINDOW_CLASS_NAME TEXT("C_class")
#define SAFE_RELEASE(p) {if(p){(p)->Release();(p) = NULL;}}

#pragma comment(lib,"winmm.lib")
#pragma comment(lib,"d3d9.lib")
#pragma comment(lib,"d3dx9d.lib")
#pragma comment(lib,"comctl32.lib")

//�ṹ����
struct MVertex {
	MVertex() {};
	MVertex(float x, float y, float z,float u,float v) {
		m_x = x; m_y = y; m_z = z;
		m_u = u;
		m_v = v;
	}
	float m_x, m_y, m_z;
	float m_u, m_v;//��������
	static const DWORD FVF;
};
const DWORD MVertex::FVF = D3DFVF_XYZ | D3DFVF_TEX1;

//ȫ������
D3DMATERIAL9 mtrl_teatop;
D3DMATERIAL9 mtrl_sphere;
float time = 0.1f;
IDirect3DTexture9* g_texture;
ID3DXMesh* teatop = NULL;
ID3DXMesh* sphere = NULL;
ID3DXFont* g_pfont = NULL;
ID3DXMesh* text = NULL;
HWND g_hdc = NULL;
HINSTANCE g_hinstance = NULL;
IDirect3DDevice9* g_device = NULL;
IDirect3DVertexBuffer9* Vbuffer = NULL;
IDirect3DIndexBuffer9* g_indexbuffer = NULL;
typedef LRESULT (CALLBACK* WNDPROCRET)(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

//ȫ�ֺ���
//���ڴ���
LRESULT CALLBACK  WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
WNDCLASSEX&       gCreateWindowsClass(HINSTANCE hInstance, LPCTSTR name, WNDPROCRET lpfnproc,UINT style = CS_HREDRAW | CS_VREDRAW);
VOID              gMessageLoop();
//��Ϸ���
HRESULT           gGame_Init(HWND hwnd);
VOID              gRender(HWND hwnd);
VOID              Clean_Up(HWND hwnd);
//Direct3D��ʼ��
VOID              gCreateInterface_D3D(LPDIRECT3D9& pd3d);
VOID              gGetHalinfo(LPDIRECT3D9 pd3d,int& vp);
VOID              gFullParameter(HWND hwnd,D3DPRESENT_PARAMETERS& d3dpp);
//���㻺��
VOID              gCreateVertexBuffer(IDirect3DDevice9* pdevice);
VOID              gCreatecamera(IDirect3DDevice9* pdevice, D3DXVECTOR3& pos, D3DXVECTOR3& target, D3DXVECTOR3& up);
VOID              gTranslation(IDirect3DDevice9* pdevice);
VOID              gMydraw(float time, IDirect3DDevice9* pdevice);
VOID              gCreateIndex(IDirect3DDevice9* pdevice);
VOID              gCreateFont(IDirect3DDevice9* pdevice);
VOID              gCreate3DFont(IDirect3DDevice9* pdevice);
VOID              gSetlight(IDirect3DDevice9* pdevice);
VOID              gCreateTexture(IDirect3DDevice9* pdevice);
VOID              gInitMaterial(IDirect3DDevice9* pdevice);
VOID              gInput(IDirect3DDevice9* pdevice);


int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	g_hinstance = hInstance;

	WNDCLASSEX WClass = gCreateWindowsClass(hInstance, WINDOW_CLASS_NAME, WindowProc);

	if (!RegisterClassEx(&WClass))
	{
		MessageBox(0, TEXT("error"), TEXT("ע��ʧ�ܣ�"), MB_OK);
		return 0;
	}

	g_hdc = CreateWindow(WINDOW_CLASS_NAME, TEXT("CYX"), WS_OVERLAPPEDWINDOW | WS_EX_TOPMOST,0,0,WINDOW_WIDTH,WINDOW_HEIGHT,0,0,hInstance,0);
	if (!g_hdc)
	{
		MessageBox(0, TEXT("error"), TEXT("���ڴ���ʧ�ܣ�"), MB_OK);
		return 0;
	}

	ShowWindow(g_hdc, nShowCmd);
	UpdateWindow(g_hdc);

	if (FAILED(gGame_Init(g_hdc))) {
		MessageBox(0, TEXT("error"), TEXT("��Ϸ��ʼ��ʧ�ܣ�"), MB_OK);
		return 0;
	}
	
	gMessageLoop();

	UnregisterClass(WINDOW_CLASS_NAME, hInstance);
	return 0;
}

//��������
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg) {
	case WM_PAINT:
		BeginPaint(hwnd, NULL);
		gRender(hwnd);
		//ValidateRect(hwnd, NULL);//������������Ǻ����
		EndPaint(hwnd, NULL);
		break;
	case WM_DESTROY:
		Clean_Up(hwnd);
		PostQuitMessage(0);
		break;
	case WM_KEYDOWN:
		switch (wParam) {
		case VK_ESCAPE:
			DestroyWindow(hwnd);
			break;
		case VK_UP:
			time += 0.1f;
			break;
		case VK_DOWN:
			time -= 0.1f;
			break;
		default:
			gInput(g_device);
			break;
		}
	default:
		break;
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

WNDCLASSEX& gCreateWindowsClass(HINSTANCE hInstance,LPCTSTR name, WNDPROCRET lpfnproc, UINT style /* = CS_HREDRAW | CS_VREDRAW */) {

	static WNDCLASSEX Mywindowclass;
	Mywindowclass.cbSize = sizeof(Mywindowclass);
	Mywindowclass.cbClsExtra = 0;
	Mywindowclass.cbWndExtra = 0;
	Mywindowclass.lpfnWndProc = lpfnproc;
	Mywindowclass.hInstance = hInstance;
	Mywindowclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	Mywindowclass.hCursor = LoadCursor(0, IDC_ARROW);
	Mywindowclass.hIconSm = NULL;
	Mywindowclass.hIcon = NULL;
	Mywindowclass.lpszClassName = WINDOW_CLASS_NAME;
	Mywindowclass.lpszMenuName = NULL;
	Mywindowclass.style = style;

	return Mywindowclass;
}

VOID gMessageLoop() {
	MSG mmsg = { 0 };
	while (mmsg.message != WM_QUIT)
	{
		if (PeekMessage(&mmsg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&mmsg);
			DispatchMessage(&mmsg);
		}
		else
		{
			gRender(g_hdc);
		}
	}
}

HRESULT gGame_Init(HWND hwnd) {
	LPDIRECT3D9 pd3d = NULL;
	gCreateInterface_D3D(pd3d);

	int vp = 0;
	gGetHalinfo(pd3d,vp);

	D3DPRESENT_PARAMETERS d3dpp;
	gFullParameter(hwnd, d3dpp);

	if (FAILED(pd3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hwnd, vp, &d3dpp, &g_device)))
	{
		MessageBox(0, TEXT("error"), TEXT("�豸����ʧ�ܣ�"), MB_OK);
		return E_FAIL;
	}

	SAFE_RELEASE(pd3d);

	//�������
	D3DXCreateTeapot(g_device, &teatop, 0);

	//��������
	D3DXCreateSphere(g_device, 0.6f, 20, 20, &sphere, 0);

	//��������
	gCreateFont(g_device);
	gCreate3DFont(g_device);

	//�������㻺��
	//gCreateVertexBuffer(g_device);

	//������������
	//gCreateIndex(g_device);

	//���������
	D3DXVECTOR3 pos(0.0f, 5.0f, -10.0f);
	D3DXVECTOR3 tar(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 up(0.0f, 1.0f, 0.0f);
	gCreatecamera(g_device,pos,tar,up);

	//�رձ�������
	g_device->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
	//�任
	gTranslation(g_device);
	//���ò���
	gInitMaterial(g_device);
	//���õƹ�
	gSetlight(g_device);
	//��������
	//gCreateTexture(g_device);
	//g_device->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);
	//g_device->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);
	//g_device->SetSamplerState(0, D3DSAMP_MIPFILTER, D3DTEXF_NONE);
	//����ȫ�������
	//g_device->SetRenderState(D3DRS_MULTISAMPLEANTIALIAS, TRUE);

	//ָ���ò��ʵ����������Ϊalpha��Դ
	g_device->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_DIFFUSE);
	g_device->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_SELECTARG1);

	//�趨Ŀ��ͻ������
	g_device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

	//�����ں����㷽ʽ
	g_device->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);//Ĭ����D3DBLENDOP_ADD

	return S_OK;
}

VOID gRender(HWND hwnd) {
	gMydraw(time, g_device);
}

VOID Clean_Up(HWND hwnd) {
	SAFE_RELEASE(g_device);
	SAFE_RELEASE(Vbuffer);
	SAFE_RELEASE(g_indexbuffer);
	SAFE_RELEASE(g_pfont);
	SAFE_RELEASE(text);
	SAFE_RELEASE(g_texture);
	SAFE_RELEASE(teatop);
}

VOID gCreateInterface_D3D(LPDIRECT3D9& pd3d) {
	if (!(pd3d = Direct3DCreate9(D3D_SDK_VERSION)))
	{
		MessageBox(0, TEXT("error"), TEXT("�ӿڴ���ʧ�ܣ�"), MB_OK);
		return;
	}
}

VOID gGetHalinfo(LPDIRECT3D9 pd3d,int& vp) {
	D3DCAPS9 caps;
	if (FAILED(pd3d->GetDeviceCaps(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, &caps)))
	{
		MessageBox(0, TEXT("error"), TEXT("��ȡ�豸��Ϣʧ�ܣ�"), MB_OK);
		return;
	}
	if (caps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT)
	{
		vp = D3DCREATE_HARDWARE_VERTEXPROCESSING;
	}
	else
		vp = D3DCREATE_SOFTWARE_VERTEXPROCESSING;
}

VOID gFullParameter(HWND hwnd,D3DPRESENT_PARAMETERS& d3dpp) {
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.BackBufferWidth = WINDOW_WIDTH;
	d3dpp.BackBufferHeight = WINDOW_HEIGHT;
	d3dpp.BackBufferCount = 1;
	d3dpp.BackBufferFormat = D3DFMT_A8R8G8B8;
	d3dpp.AutoDepthStencilFormat = D3DFMT_D24S8;
	d3dpp.EnableAutoDepthStencil = TRUE;
	d3dpp.Flags = 0;
	d3dpp.hDeviceWindow = hwnd;
	d3dpp.FullScreen_RefreshRateInHz = 0;
	d3dpp.MultiSampleQuality = 0;
	d3dpp.MultiSampleType = D3DMULTISAMPLE_NONE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.Windowed = TRUE;
	d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;//�ò����Ǹ�ʲô�ģ���
}

VOID gCreateVertexBuffer(IDirect3DDevice9* pdevice) {
	if (FAILED(pdevice->CreateVertexBuffer(
		24 * sizeof(MVertex),
		D3DUSAGE_WRITEONLY,
		MVertex::FVF,
		D3DPOOL_MANAGED,
		&Vbuffer,
		0
	)))
	{
		MessageBox(0, TEXT("���㻺�洴��ʧ�ܣ�"), TEXT("error"), MB_OK);
		return;
	}

	//��䶨�㻺��
	MVertex* v = NULL;
	Vbuffer->Lock(0, 0, (VOID**)&v, 0);

	//����
	v[0] = MVertex(0.0f, 0.0f, 0.0f,0.0f,0.0f);     v[1] = MVertex(2.0f, 0.0f, 0.0f,1.0f,0.0f);
	v[2] = MVertex(2.0f, 2.0f, 0.0f,1.0f,1.0f);    v[3] = MVertex(0.0f, 2.0f, 0.0f,0.0f,1.0f);
	//����
	v[4] = MVertex(0.0f, 0.0f, 2.0f, 0.0f, 0.0f);     v[5] = MVertex(2.0f, 0.0f, 2.0f, 1.0f, 0.0f);
	v[6] = MVertex(2.0f, 2.0f, 2.0f, 1.0f, 1.0f);    v[7] = MVertex(0.0f, 2.0f, 2.0f, 0.0f, 1.0f);
	//����
	v[8] = MVertex(0.0f, 2.0f, 0.0f, 0.0f, 0.0f);     v[9] = MVertex(0.0f, 2.0f, 2.0f, 1.0f, 0.0f);
	v[10] = MVertex(2.0f, 2.0f, 2.0f, 1.0f, 1.0f);    v[11] = MVertex(2.0f, 2.0f, 0.0f, 0.0f, 1.0f);
	//����
	v[12] = MVertex(0.0f, 0.0f, 0.0f, 0.0f, 0.0f);     v[13] = MVertex(0.0f, 0.0f, 2.0f, 1.0f, 0.0f);
	v[14] = MVertex(2.0f, 0.0f, 2.0f, 1.0f, 1.0f);    v[15] = MVertex(2.0f, 0.0f, 0.0f, 0.0f, 1.0f);
	//����
	v[16] = MVertex(0.0f, 0.0f, 0.0f, 0.0f, 0.0f);     v[17] = MVertex(0.0f, 0.0f, 2.0f, 1.0f, 0.0f);
	v[18] = MVertex(0.0f, 2.0f, 2.0f, 1.0f, 1.0f);    v[19] = MVertex(0.0f, 2.0f, 0.0f, 0.0f, 1.0f);
	//����
	v[20] = MVertex(2.0f, 0.0f, 0.0f, 0.0f, 0.0f);     v[21] = MVertex(2.0f, 2.0f, 0.0f, 1.0f, 0.0f);
	v[22] = MVertex(2.0f, 2.0f, 2.0f, 1.0f, 1.0f);    v[23] = MVertex(2.0f, 0.0f, 2.0f, 0.0f, 1.0f);
	

	Vbuffer->Unlock();
}

VOID gCreateIndex(IDirect3DDevice9* pdevice) {
	if (FAILED(pdevice->CreateIndexBuffer(36 * sizeof(WORD), D3DUSAGE_WRITEONLY, D3DFMT_INDEX16, D3DPOOL_MANAGED, &g_indexbuffer, 0)))
	{
		MessageBox(0, TEXT("�������洴��ʧ�ܣ�"), TEXT("error"), MB_OK);
		return;
	}

	//�����������
	WORD* iv = NULL;
	g_indexbuffer->Lock(0, 0, (void**)&iv, 0);
	//����
	iv[0] = 0; iv[1] = 1; iv[2] = 2;
	iv[3] = 0; iv[4] = 2; iv[5] = 3;
	//����
	iv[6] = 4; iv[7] = 5; iv[8] = 6;
	iv[9] = 4; iv[10] = 6; iv[11] = 7;
	//����
	iv[12] = 8; iv[13] = 9; iv[14] = 10;
	iv[15] = 8; iv[16] = 10; iv[17] = 11;
	//����
	iv[18] = 12; iv[19] = 13; iv[20] = 14;
	iv[21] = 12; iv[22] = 14; iv[23] = 15;
	//����
	iv[24] = 16; iv[25] = 17; iv[26] = 18;
	iv[27] = 16; iv[28] = 18; iv[29] = 19;
	//����
	iv[30] = 20; iv[31] = 21; iv[32] = 22;
	iv[33] = 20; iv[34] = 22; iv[35] = 23;

	g_indexbuffer->Unlock();
}

VOID gCreatecamera(IDirect3DDevice9* pdevice, D3DXVECTOR3& pos, D3DXVECTOR3& target, D3DXVECTOR3& up) {
	D3DXMATRIX V;
	D3DXMatrixLookAtLH(&V, &pos, &target, &up);
	pdevice->SetTransform(D3DTS_VIEW, &V);
}

VOID gTranslation(IDirect3DDevice9* pdevice) {
	//ͶӰ�任
	D3DXMATRIX proj;
	//��Ȼ����D3DMatrixPerspectiveFovRH()
	D3DXMatrixPerspectiveFovLH(
		&proj,
		D3DX_PI*0.5f,
		(float)WINDOW_WIDTH / (float)WINDOW_HEIGHT,
		1.0f,
		100.0f
	);
	pdevice->SetTransform(D3DTS_PROJECTION, &proj);

	//�������ģʽ
	pdevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
}

VOID gMydraw(float time, IDirect3DDevice9* pdevice) {
	if (pdevice)
	{
		RECT rect;
		rect.bottom = 100;
		rect.top = 20;
		rect.left = 50;
		rect.right = 200;

		//��ת�任
		D3DXMATRIX Rx;
		static float y = 0.0f;
		D3DXMatrixRotationX(&Rx, y);
		y += (float)(time*0.002);
		if (y > 6.28f)
			y = 0.0f;
		pdevice->SetTransform(D3DTS_WORLD, &Rx);

		//���Ʊ�Ҫ����
		pdevice->Clear(0, 0, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(230, 230, 230), 1.0f, 0);
		//pdevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);
		pdevice->BeginScene();
		/*pdevice->SetStreamSource(0, Vbuffer, 0, sizeof(MVertex));
		pdevice->SetFVF(MVertex::FVF);
		pdevice->SetIndices(g_indexbuffer);
		pdevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST,0,0,8,0,12);*/
		g_device->SetMaterial(&mtrl_teatop);
		g_device->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
		teatop->DrawSubset(0);

		//D3DXMATRIX Y;
		//D3DXMatrixTranslation(&Y, 1.0f,0.0f, 0.0f);
		//pdevice->SetTransform(D3DTS_WORLD, &Y);
		g_device->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
		g_device->SetMaterial(&mtrl_sphere);
		sphere->DrawSubset(0);

		//������
		D3DXMATRIX X;  //ƽ�ƾ���
		D3DXMatrixTranslation(&X, 0.0f, 5.0f, 5.0f);
		pdevice->SetTransform(D3DTS_WORLD, &X);
		char tip[50] = { 0 };
		WCHAR ctip[50];
		sprintf_s(tip, -1, "��ǰalpha�� %f", mtrl_teatop.Diffuse.a);
		MultiByteToWideChar(CP_ACP, 0, tip, sizeof(tip), ctip, sizeof(ctip) / sizeof(ctip[0]));
		g_pfont->DrawText(0, ctip, -1, &rect, DT_CENTER, D3DXCOLOR(0.3f, 0.4f, 0.5f, 0.5f));
		text->DrawSubset(0);
		pdevice->EndScene();
		pdevice->Present(0, 0, 0, 0);
	}
}

VOID gCreateFont(IDirect3DDevice9* pdevice) {
	//�������巨һ��
	/*D3DXFONT_DESC fontdesc;
	ZeroMemory(&fontdesc, sizeof(D3DX10_FONT_DESC));
	fontdesc.Height = 25;
	fontdesc.Weight = 500;
	fontdesc.Width = 12;
	fontdesc.Italic = FALSE;
	fontdesc.OutputPrecision = 0;
	fontdesc.CharSet = DEFAULT_CHARSET;
	fontdesc.MipLevels = D3DX10_DEFAULT;
	fontdesc.PitchAndFamily = 0;
	fontdesc.Quality = 0;
	wcscpy_s(fontdesc.FaceName, TEXT("Time New Roman"));
	if (FAILED(D3DXCreateFontIndirect(pdevice, &fontdesc, &g_pfont))) {
		MessageBox(0, TEXT("��������ʧ��"), TEXT("error"), MB_OK);
		return;
	}*/

	//�������巨����
	D3DXCreateFont(pdevice, 15, 6, 500, D3DX_DEFAULT, TRUE, DEFAULT_CHARSET, 0, 0, 0, TEXT("Time New Roman"), &g_pfont);
}

VOID gCreate3DFont(IDirect3DDevice9* pdevice) {
	HDC hdc = CreateCompatibleDC(0);
	HFONT hfont = CreateFont(10, 10, 0, 0, 100, FALSE, FALSE, FALSE, DEFAULT_CHARSET, 0, 0, 0, 0, TEXT("Time New Roman"));
	HFONT hold = (HFONT)SelectObject(hdc, hfont);
	D3DXCreateText(pdevice, hdc, TEXT("��"), 0.002f, 0.2f, &text, 0, 0);
	SelectObject(hdc, hold);
	DeleteObject(hfont);
	DeleteDC(hdc);
}

VOID gSetlight(IDirect3DDevice9* pdevice) {
	//���õƹ�
	D3DXVECTOR3 vecDir;
	D3DLIGHT9 light;
	ZeroMemory(&light, sizeof(D3DLIGHT9));
	light.Type = D3DLIGHT_POINT;
	light.Diffuse.r = 1.0f;
	light.Diffuse.g = 0.0f;
	light.Diffuse.b = 0.0f;
	vecDir = D3DXVECTOR3(1, 1, 1);
	D3DXVec3Normalize((D3DXVECTOR3*)&light.Direction, &vecDir);
	light.Range = 1000.0f;
	light.Attenuation0 = 1.0f;
	light.Attenuation1 = 0.0f;
	light.Attenuation2 = 0.0f;
	pdevice->SetLight(0, &light);
	pdevice->LightEnable(0, TRUE);
	pdevice->SetRenderState(D3DRS_LIGHTING, TRUE);

	//���û�����
	pdevice->SetRenderState(D3DRS_AMBIENT, 0xff505050);
}

VOID gCreateTexture(IDirect3DDevice9* pdevice) {
	if (FAILED(D3DXCreateTextureFromFile(pdevice, TEXT("b.bmp"), &g_texture)))
	{
		MessageBox(0, TEXT("��������ʧ��"), TEXT("error"), MB_OK);
		return;
	}
	pdevice->SetTexture(0, g_texture);
}

VOID gInitMaterial(IDirect3DDevice9* pdevice) {
	ZeroMemory(&mtrl_teatop, sizeof(mtrl_teatop));
	D3DCOLORVALUE BLACK;
	BLACK.a = 0.5f; BLACK.r = 0.5f; BLACK.g = 0.0f; BLACK.b = 0.4f;
	mtrl_teatop.Ambient = BLACK;
	mtrl_teatop.Diffuse = BLACK;
	mtrl_teatop.Emissive = BLACK;
	mtrl_teatop.Specular = BLACK;
	mtrl_teatop.Power = 2.0f;

	D3DCOLORVALUE BLUE;
	ZeroMemory(&mtrl_sphere, sizeof(mtrl_sphere));
	BLUE.a = 0.5f; BLUE.r = 0.3f; BLUE.g = 0.0f; BLUE.b = 0.5f;
	mtrl_sphere.Diffuse = BLUE;
	mtrl_sphere.Ambient = BLUE;
	mtrl_sphere.Emissive = BLUE;
	mtrl_sphere.Specular = BLUE;
}

VOID gInput(IDirect3DDevice9* pdeveice) {
	if (pdeveice) {
		if (::GetAsyncKeyState('A') & 0x8000f) {
			mtrl_teatop.Diffuse.a += 0.1f;
			if (mtrl_teatop.Diffuse.a > 1.0)
				mtrl_teatop.Diffuse.a = 1.0f;

		}
		if(::GetAsyncKeyState('D') & 0x8000f){
			mtrl_teatop.Diffuse.a -= 0.1f;
			if (mtrl_teatop.Diffuse.a < 0.0f)
				mtrl_teatop.Diffuse.a = 0.0f;
		}
	}
}

