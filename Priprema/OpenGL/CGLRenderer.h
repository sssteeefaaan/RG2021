#pragma once

#pragma comment(lib, "OpenGL32.lib")
#pragma comment(lib, "glu32.lib")

#include <GL\gl.h>
#include <GL\glu.h>

#define _USE_MATH_DEFINES
#include <math.h>

class CGLRenderer
{
protected:
	HGLRC m_hrc;

	int viewR;
	float viewAngleXY;
	float viewAngleXZ;

	float viewPosition[3];
	float lookingAt[3];
	float upVector[3];

	bool showAxes;
public:
	CGLRenderer();
	virtual ~CGLRenderer();

	bool CreateGLContext(CDC* pDC);
	void PrepareScene(CDC* pDC);
	void Reshape(CDC* pDC, int w, int h);
	void DrawScene(CDC* pDC);
	void DestroyScene(CDC* pDC);

	void DrawAxes(double len = 50);
	void CalculatePosition();

	void OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);

	void DrawSide(double dx, double dy, int nStep = 16);
	void DrawCuboid(double dx, double dy, double dz, int nStep = 16);
	void DrawCylinder(double h, double r1, double r2, int nStep = 16);
	void DrawSphere(double r, int nStep1 = 16, int nStep2 = 16);
	void DrawTorus(double r1, double r2, int segNoAlpha = 16, int segNoBeta = 16);
};

