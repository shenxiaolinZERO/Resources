// rulerDoc.h : interface of the CRulerDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_RULERDOC_H__D0B41D00_2634_4F77_8EDE_5E9D13ED0DFA__INCLUDED_)
#define AFX_RULERDOC_H__D0B41D00_2634_4F77_8EDE_5E9D13ED0DFA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CRulerDoc : public CDocument
{
protected: // create from serialization only
	CRulerDoc();
	DECLARE_DYNCREATE(CRulerDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRulerDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CRulerDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CRulerDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RULERDOC_H__D0B41D00_2634_4F77_8EDE_5E9D13ED0DFA__INCLUDED_)
