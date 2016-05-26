// exp2View.h : interface of the CExp2View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXP2VIEW_H__3C64A2FE_F4EE_4121_BCCC_211A5B4242EB__INCLUDED_)
#define AFX_EXP2VIEW_H__3C64A2FE_F4EE_4121_BCCC_211A5B4242EB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CExp2View : public CView
{
protected: // create from serialization only
	CExp2View();
	DECLARE_DYNCREATE(CExp2View)

// Attributes
public:
	CExp2Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExp2View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	void DrawLine(CDC *pDC,CPoint p0,CPoint p1,COLORREF c);
	CPoint p1;
	CPoint p0;
	virtual ~CExp2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CExp2View)
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in exp2View.cpp
inline CExp2Doc* CExp2View::GetDocument()
   { return (CExp2Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXP2VIEW_H__3C64A2FE_F4EE_4121_BCCC_211A5B4242EB__INCLUDED_)
