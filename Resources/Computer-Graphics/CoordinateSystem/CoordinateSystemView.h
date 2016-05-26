// CoordinateSystemView.h : interface of the CCoordinateSystemView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_COORDINATESYSTEMVIEW_H__CC492A6A_BF57_4CB5_9460_467CBF70D230__INCLUDED_)
#define AFX_COORDINATESYSTEMVIEW_H__CC492A6A_BF57_4CB5_9460_467CBF70D230__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CCoordinateSystemView : public CView
{
protected: // create from serialization only
	CCoordinateSystemView();
	DECLARE_DYNCREATE(CCoordinateSystemView)

// Attributes
public:
	CCoordinateSystemDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCoordinateSystemView)
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
	virtual ~CCoordinateSystemView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCoordinateSystemView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in CoordinateSystemView.cpp
inline CCoordinateSystemDoc* CCoordinateSystemView::GetDocument()
   { return (CCoordinateSystemDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COORDINATESYSTEMVIEW_H__CC492A6A_BF57_4CB5_9460_467CBF70D230__INCLUDED_)
