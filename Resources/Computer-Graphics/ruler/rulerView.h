// rulerView.h : interface of the CRulerView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_RULERVIEW_H__998EB859_7B4A_4199_A4FA_FF5C45ECAC55__INCLUDED_)
#define AFX_RULERVIEW_H__998EB859_7B4A_4199_A4FA_FF5C45ECAC55__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CRulerView : public CView
{
protected: // create from serialization only
	CRulerView();
	DECLARE_DYNCREATE(CRulerView)

// Attributes
public:
	CRulerDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRulerView)
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
	virtual ~CRulerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CRulerView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in rulerView.cpp
inline CRulerDoc* CRulerView::GetDocument()
   { return (CRulerDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RULERVIEW_H__998EB859_7B4A_4199_A4FA_FF5C45ECAC55__INCLUDED_)
