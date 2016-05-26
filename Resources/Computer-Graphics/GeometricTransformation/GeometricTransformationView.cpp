// GeometricTransformationView.cpp : implementation of the CGeometricTransformationView class
//

#include "stdafx.h"
#include "GeometricTransformation.h"

#include "GeometricTransformationDoc.h"
#include "GeometricTransformationView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGeometricTransformationView

IMPLEMENT_DYNCREATE(CGeometricTransformationView, CView)

BEGIN_MESSAGE_MAP(CGeometricTransformationView, CView)
	//{{AFX_MSG_MAP(CGeometricTransformationView)
	ON_WM_PAINT()
	ON_WM_LBUTTONUP()
	ON_WM_RBUTTONUP()
	ON_WM_MBUTTONUP()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGeometricTransformationView construction/destruction

CGeometricTransformationView::CGeometricTransformationView()
{
	// TODO: add construction code here

}

CGeometricTransformationView::~CGeometricTransformationView()
{
}

BOOL CGeometricTransformationView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CGeometricTransformationView drawing

void CGeometricTransformationView::OnDraw(CDC* pDC)
{
	CGeometricTransformationDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CGeometricTransformationView printing

BOOL CGeometricTransformationView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CGeometricTransformationView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CGeometricTransformationView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CGeometricTransformationView diagnostics

#ifdef _DEBUG
void CGeometricTransformationView::AssertValid() const
{
	CView::AssertValid();
}

void CGeometricTransformationView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGeometricTransformationDoc* CGeometricTransformationView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGeometricTransformationDoc)));
	return (CGeometricTransformationDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGeometricTransformationView message handlers

void CGeometricTransformationView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	draw();
	// TODO: Add your message handler code here
	
	// Do not call CView::OnPaint() for painting messages
}

void CGeometricTransformationView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CRect rect;
	GetClientRect(rect);
    points.push_back(CPoint(point.x - rect.Width()/2, point.y - rect.Height()/2));
	CView::OnLButtonUp(nFlags, point);
}

void CGeometricTransformationView::OnRButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	draw();
	CView::OnRButtonUp(nFlags, point);
}

void CGeometricTransformationView::OnMButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	points.clear();

	CView::OnMButtonUp(nFlags, point);
}

void CGeometricTransformationView::draw()
{
    CDC *dc = GetDC();
	CRect rect;
	dc->GetClipBox(rect);
	dc->SetViewportOrg(rect.Width()/2, rect.Height()/2);

	// 绘制坐标轴
	dc->MoveTo(-rect.Width()/2, 0);
	dc->LineTo(rect.Width()/2, 0);
	dc->MoveTo(0, -rect.Height()/2);
	dc->LineTo(0, rect.Height()/2);

	if (points.size() < 3) {
		return;
	}
     int i;
	//绘制多边形
	dc->MoveTo(points[0].x, points[0].y);
	for (  i = 1; i < points.size(); i++) {
		dc->LineTo(points[i].x, points[i].y);
	}
	dc->LineTo(points[0].x, points[0].y);

	//向下平移300个单位
	dc->MoveTo(points[0].x, points[0].y+100);
	for (  i = 1; i < points.size(); i++) {
		dc->LineTo(points[i].x, points[i].y+100);
	}
	dc->LineTo(points[0].x, points[0].y+100);

	// 2倍放大后的多边形
	dc->MoveTo(2*points[0].x, 2*points[0].y);
	for ( i = 1; i < points.size(); i++) {
		dc->LineTo(2*points[i].x, 2*points[i].y);
	}
	dc->LineTo(2*points[0].x, 2*points[0].y);

	// 绕原点旋转60度
	double r = sqrt(points[0].x*points[0].x + points[0].y*points[0].y);
	double pi = acos(-1);
	double angle = pi*60/180;
	int x, y;
	x = points[0].x;
	y = points[0].y;
	dc->MoveTo(x*cos(angle)-y*sin(angle), x*sin(angle)+y*cos(angle));
	for ( i = 1; i < points.size(); i++) {
		x = points[i].x;
		y = points[i].y;
		dc->LineTo(x*cos(angle)-y*sin(angle), x*sin(angle)+y*cos(angle));
	}
	x = points[0].x;
	y = points[0].y;
	dc->LineTo(x*cos(angle)-y*sin(angle), x*sin(angle)+y*cos(angle));

	// 关于y轴反射变换
	dc->MoveTo(-points[0].x, points[0].y);
	for ( i = 1; i < points.size(); i++) {
		dc->LineTo(-points[i].x, points[i].y);
	}
	dc->LineTo(-points[0].x, points[0].y);

	// 错切
	double k = -2.3;
	dc->MoveTo(points[0].x + k*points[0].y, points[0].y);
	for ( i = 1; i < points.size(); i++) {
		dc->LineTo(points[i].x + k*points[i].y, points[i].y);
	}
	dc->LineTo(points[0].x + k*points[0].y, points[0].y);

	// 绕(-100, 120)旋转30度
	int ox = -100;
	int oy = 120;
	angle = pi*30/180;
	x = points[0].x;
	y = points[0].y;
	dc->MoveTo((x-ox)*cos(angle)-(y-oy)*sin(angle)+ox, (x-ox)*sin(angle)+(y-oy)*cos(angle)+oy);
	for ( i = 1; i < points.size(); i++) {
		x = points[i].x;
		y = points[i].y;
		dc->LineTo((x-ox)*cos(angle)-(y-oy)*sin(angle)+ox, (x-ox)*sin(angle)+(y-oy)*cos(angle)+oy);
	}
	x = points[0].x;
	y = points[0].y;
	dc->LineTo((x-ox)*cos(angle)-(y-oy)*sin(angle)+ox, (x-ox)*sin(angle)+(y-oy)*cos(angle)+oy);


}
