// rulerView.cpp : implementation of the CRulerView class
//

#include "stdafx.h"
#include "ruler.h"

#include "rulerDoc.h"
#include "rulerView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRulerView

IMPLEMENT_DYNCREATE(CRulerView, CView)

BEGIN_MESSAGE_MAP(CRulerView, CView)
	//{{AFX_MSG_MAP(CRulerView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRulerView construction/destruction

CRulerView::CRulerView()
{
	// TODO: add construction code here

}

CRulerView::~CRulerView()
{
}

BOOL CRulerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CRulerView drawing

void CRulerView::OnDraw(CDC* pDC)
{
	CRulerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CRect rect;   //声明客户区矩形
    GetClientRect(&rect);   //获得客户区坐标
    pDC->SetMapMode(MM_LOMETRIC);  //设置映射模式为：MM_LOMETRIC，即每个逻辑坐标被转换为0.1 mm。正x向右，正y向上。
    //设置实际的客户区窗口的长度和宽度范围
    int height=rect.Height()*2.5;
	int width=rect.Width()*2.5;
    int i;
	
    //top ruler 画顶部的尺子
	//先在最上部画一条直线，作为尺子的度量边缘，从上（/左）往下（/右）画
	pDC->MoveTo(0,0);  
	pDC->LineTo(width-100,0);
	COLORREF c=RGB(0,0,255);
    //开始进行循环，画尺子的刻度
	for( i=0;i<width-100;i+=10)
	{   
        //尺子距离为1厘米的，刻度竖线长度为7毫米
		if(i%100==0)
		{ 
			pDC->MoveTo(i,0);
		    pDC->LineTo(i,-70);
		}
        //尺子距离为5毫米的，刻度竖线长度为6毫米
		else if(i%50==0)
		{
            pDC->MoveTo(i,0);
			pDC->LineTo(i,-60);

		}
		//尺子距离为1毫米的，刻度竖线长度为5毫米
		else 
		{
			pDC->MoveTo(i,0);
			pDC->LineTo(i,-50);
		}
	}
	//bottom ruler  画底部的尺子
	//先在底部画一条直线，作为尺子的度量边缘（从上/左往下/右画）
	pDC->MoveTo(width,-height+100);
	pDC->LineTo(100,-height+100);
    //开始进行循环，画尺子的刻度
	for( i=0;i<width-100;i+=10)
	{    //尺子距离为1厘米的，刻度竖线长度为7毫米
		if(i%100==0)
		{ 
			pDC->MoveTo(width-i,-height+100);
		    pDC->LineTo(width-i,-height+30);
		}
		 //尺子距离为5毫米的，刻度竖线长度为6毫米
		else if(i%50==0)
		{
            pDC->MoveTo(width-i,-height+100);
			pDC->LineTo(width-i,-height+40);

		}
		//尺子距离为1毫米的，刻度竖线长度为5毫米
		else 
		{
			pDC->MoveTo(width-i,-height+100);
			pDC->LineTo(width-i,-height+50);
		}
	}
	//*/

    ///*
	//left ruler  画左边的尺子
    //先在最左部画一条直线，作为尺子的度量边缘（从上/左往下/右画）
    pDC->MoveTo(0,-height);
	pDC->LineTo(0,-100);
	//开始进行循环，画尺子的刻度
	for( i=0;i<height-100;i+=10)
	{
		 //尺子距离为1厘米的，刻度竖线长度为7毫米
		if(i%100==0)
		{ 
			pDC->MoveTo(0,-height+i);
		    pDC->LineTo(70,-height+i);
		}
		 //尺子距离为5毫米的，刻度竖线长度为6毫米
		else if(i%50==0)
		{
            pDC->MoveTo(0,-height+i);
			pDC->LineTo(60,-height+i);

		}
		//尺子距离为1毫米的，刻度竖线长度为5毫米
		else 
		{
			pDC->MoveTo(0,-height+i);
			pDC->LineTo(50,-height+i);
		}
	}
	//*/
    //right ruler  画右边的尺子
	//先在最右边画一条直线，作为尺子的度量边缘（从右往左画）
    pDC->MoveTo(width,0);
	pDC->LineTo(width,-height+150);
	//开始进行循环，画尺子的刻度
	for( i=0;i<height-150;i+=10)
	{   
		 //尺子距离为1厘米的，刻度竖线长度为7毫米
		if(i%100==0)
		{ 
			pDC->MoveTo(width,-i);
		    pDC->LineTo(width-70,-i);
		}
		 //尺子距离为5毫米的，刻度竖线长度为6毫米
		else if(i%50==0)
		{
            pDC->MoveTo(width,-i);
			pDC->LineTo(width-60,-i);

		}
		//尺子距离为1毫米的，刻度竖线长度为5毫米
		else 
		{
			pDC->MoveTo(width,-i);
			pDC->LineTo(width-50,-i);
		}
	}
}

/////////////////////////////////////////////////////////////////////////////
// CRulerView printing

BOOL CRulerView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CRulerView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CRulerView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CRulerView diagnostics

#ifdef _DEBUG
void CRulerView::AssertValid() const
{
	CView::AssertValid();
}

void CRulerView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CRulerDoc* CRulerView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRulerDoc)));
	return (CRulerDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRulerView message handlers
