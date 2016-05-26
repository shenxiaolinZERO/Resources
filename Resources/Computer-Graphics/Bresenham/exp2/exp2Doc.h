// exp2Doc.h : interface of the CExp2Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXP2DOC_H__3EBF3B4E_B0DD_4708_A389_E170B5784259__INCLUDED_)
#define AFX_EXP2DOC_H__3EBF3B4E_B0DD_4708_A389_E170B5784259__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CExp2Doc : public CDocument
{
protected: // create from serialization only
	CExp2Doc();
	DECLARE_DYNCREATE(CExp2Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExp2Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CExp2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CExp2Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXP2DOC_H__3EBF3B4E_B0DD_4708_A389_E170B5784259__INCLUDED_)
