#ifndef RENDEROBJECT_H_
#define RENDEROBJECT_H_
#include "MyD3D11app.h"
#include "FXControl.h"
#include"VertexIndexControl.h"
#include"StateControl.h"
#include<vector>
#include<fstream>
#include<string>
#define  PI 3.1415926f

class RenderObject: public MyD3D11app{

private:
	void KeyDown(WPARAM wParam);
	void MouseButtonDown(WPARAM wParam,float fMousePointx,float fMousePointy);
	void MouseMove(WPARAM wParam,float fMousePointx,float fMousePointy);

	void Release();
	void DrawScene();
	void UpdateScene(const float dt); //��ʵ����Ӧ��Ҫ�Ӹ�ʱ��
	HRESULT Resize(float window_width,float window_height);
	HRESULT ObjectInit();

	ID3D11ShaderResourceView * m_d3d11SRVFloor;
	ID3D11ShaderResourceView * m_d3d11SRVWall;
	ID3D11ShaderResourceView * m_d3d11SRVMirror;

	XMFLOAT3 m_vLightPos;

	XMFLOAT3 m_v3WorldCoordinate_Skull;
	XMFLOAT3 m_v3Rotation_Skull;
	XMFLOAT3 m_v3Scailing_Skull;

	XMMATRIX m_matSkullWorld;


	XMMATRIX m_matWorldTranslate;
	XMMATRIX m_matWorldRotate;
	XMMATRIX m_matWorldScailing;

	XMFLOAT3 m_v3WorldCoordinate;
	XMFLOAT3 m_v3Rotation;
	XMFLOAT3 m_v3Scailing;

	XMMATRIX m_matWorld,m_matView,m_matProj;
	XMMATRIX m_matWorldViewProj;

	 float m_MousePosLastx;
	 float m_MousePosLasty;
	 float m_Phi;
	 float m_Thea;
	 float m_MousePosNowx;
	 float m_MousePosNowy;
public:
	RenderObject();
	virtual ~RenderObject();

	float m_fRadius;
	float m_CameraPosx;
	float m_CameraPosy;
	float m_CameraPosz;

	int Init(HINSTANCE hInstance,int nShowCmd);
	// Math base
	XMMATRIX MatrixInverseTranspose(XMMATRIX& matrix);
};


#endif