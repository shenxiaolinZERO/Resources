// exp2View.cpp : implementation of the CExp2View class
//

#include "stdafx.h"
#include "exp2.h"

#include "exp2Doc.h"
#include "exp2View.h"

#include "Math.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CExp2View

IMPLEMENT_DYNCREATE(CExp2View, CView)

BEGIN_MESSAGE_MAP(CExp2View, CView)
	//{{AFX_MSG_MAP(CExp2View)
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExp2View construction/destruction

CExp2View::CExp2View()
{
	// TODO: add construction code here

}

CExp2View::~CExp2View()
{
}

BOOL CExp2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CExp2View drawing

void CExp2View::OnDraw(CDC* pDC)
{
	CExp2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CExp2View printing

BOOL CExp2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CExp2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CExp2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CExp2View diagnostics

#ifdef _DEBUG
void CExp2View::AssertValid() const
{
	CView::AssertValid();
}

void CExp2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExp2Doc* CExp2View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExp2Doc)));
	return (CExp2Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CExp2View message handlers

void CExp2View::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	p1=point;
	CDC *pDC=this->GetDC();
	COLORREF c;
	DrawLine(pDC,p0,p1,c);
	CView::OnLButtonUp(nFlags, point);
}

void CExp2View::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	p0=point;
	CView::OnLButtonDown(nFlags, point);
}
void CExp2View::DrawLine(CDC *pDC, CPoint p0, CPoint p1,COLORREF c)
{   

	/*
	 double k=1.0*(p1.y-p0.y)/(p1.x-p0.x),d;
     int x,y;

	 if(fabs(k)>0&&fabs(k)<1){
      d=0.5-k;
	  for(x=p0.x,y=p0.y;x<=p1.x;x++){
		if(d>=0){
			pDC->SetPixel(x,y,0xff0000);
			d+=-k;
		}
		else{
			y++;
			pDC->SetPixel(x,y,0xff0000);
			d+=1-k;
		}
	  }
	}

	else if(fabs(k)>=1){
       d=1-0.5*k;
       for(x=p0.x,y=p0.y;x<=p1.x;y++){
		if(d>=0){
			x++;
			pDC->SetPixel(x,y,0x00ff00);
			d+=1-k;
		}
		else{
			pDC->SetPixel(x,y,0x00ff00);
			d+=1;
		}
	   }
	}

	else if(fabs(k)>-1&&fabs(k)<0){
       d=-0.5-k;
      for(x=p0.x,y=p0.y;x<=p1.x;x++){
		if(d>=0){
		    y=y-1;
			pDC->SetPixel(x,y,0x0000ff);
			d+=-1-k;
		}
		else{
			pDC->SetPixel(x,y,0x0000ff);
			d+=-k;
		}
	}
	}

	else if(fabs(k)<=-1){
      d=-1-0.5*k;
      for(x=p0.x,y=p0.y;x<=p1.x;y--){
		if(d>=0){
		pDC->SetPixel(x,y,0x00ffff);
			 d+=-1;	
		}
		else{
		    x=x+1;
			pDC->SetPixel(x,y,0x00ffff);
		   d+=-1-k;
		}
	}
	}
	*/
    
	
	/*
	//1.fabs(k)>0&&fabs(k)<1
	double k=1.0*(p1.y-p0.y)/(p1.x-p0.x), d=0.5-k;
	if(fabs(k)>1) return;
	int x,y;
	for(x=p0.x,y=p0.y;x<=p1.x;x++){
		if(d>=0){
			pDC->SetPixel(x,y,0xff0000);
			d+=-k;
		}
		else{
			y++;
			pDC->SetPixel(x,y,0xff0000);
			d+=1-k;
		}
	}
    */

	/*
    //2.fabs(k)>=1
	double k=1.0*(p1.y-p0.y)/(p1.x-p0.x), d=1-0.5*k;
	if(fabs(k)>0&&fabs(k)<1) return;
	int x,y;
	for(x=p0.x,y=p0.y;x<=p1.x;y++){
		if(d>=0){
			x++;
			pDC->SetPixel(x,y,0x00ff00);
			d+=1-k;
		}
		else{
			
			pDC->SetPixel(x,y,0x00ff00);
			d+=1;
		}
	}
  */

	/*
	//3.fabs(k)>-1&&fabs(k)<0
	double k=1.0*(p1.y-p0.y)/(p1.x-p0.x), d=-0.5-k;
	//if(fabs(k)>1||fabs(k)<-1||(fabs(k)>0&&fabs(k)<1)) return;
	int x,y;
	for(x=p0.x,y=p0.y;x<=p1.x;x++){
		if(d>=0){
		    y=y-1;
			pDC->SetPixel(x,y,0x0000ff);
			d+=-1-k;
		}
		else{
			pDC->SetPixel(x,y,0x0000ff);
			d+=-k;
		}
	}
    */

	///*
	//4.fabs(k)<=-1
	double k=1.0*(p1.y-p0.y)/(p1.x-p0.x), d=-1-0.5*k;
	//if(fabs(k)>1||(fabs(k)>0&&fabs(k)<1)||fabs(k)>-1&&fabs(k)<0) return;
	int x,y;
	for(x=p0.x,y=p0.y;x<=p1.x;y--){
		if(d>=0){
		pDC->SetPixel(x,y,0xff00ff);
			 d+=-1;	
		}
		else{
				x=x+1;
			pDC->SetPixel(x,y,0xff00ff);
		   d+=-1-k;
		}
	}
    //*/


}