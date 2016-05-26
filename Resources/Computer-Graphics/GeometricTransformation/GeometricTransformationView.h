// GeometricTransformationView.h : interface of the CGeometricTransformationView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_GEOMETRICTRANSFORMATIONVIEW_H__EFE3DB31_953D_40DC_88E2_D52B5CEE1118__INCLUDED_)
#define AFX_GEOMETRICTRANSFORMATIONVIEW_H__EFE3DB31_953D_40DC_88E2_D52B5CEE1118__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <vector>

using std::vector;

#include<math.h>


class CGeometricTransformationView : public CView
{
protected: // create from serialization only
	CGeometricTransformationView();
	DECLARE_DYNCREATE(CGeometricTransformationView)

// Attributes
public:
	CGeometricTransformationDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGeometricTransformationView)
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

	void draw(void);
	vector<CPoint> points;
	virtual ~CGeometricTransformationView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CGeometricTransformationView)
	afx_msg void OnPaint();
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in GeometricTransformationView.cpp
inline CGeometricTransformationDoc* CGeometricTransformationView::GetDocument()
   { return (CGeometricTransformationDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GEOMETRICTRANSFORMATIONVIEW_H__EFE3DB31_953D_40DC_88E2_D52B5CEE1118__INCLUDED_)
