// GeometricTransformationDoc.h : interface of the CGeometricTransformationDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_GEOMETRICTRANSFORMATIONDOC_H__942A6AB8_2E7F_47D6_B7B2_A4E40D0F116A__INCLUDED_)
#define AFX_GEOMETRICTRANSFORMATIONDOC_H__942A6AB8_2E7F_47D6_B7B2_A4E40D0F116A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CGeometricTransformationDoc : public CDocument
{
protected: // create from serialization only
	CGeometricTransformationDoc();
	DECLARE_DYNCREATE(CGeometricTransformationDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGeometricTransformationDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CGeometricTransformationDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CGeometricTransformationDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GEOMETRICTRANSFORMATIONDOC_H__942A6AB8_2E7F_47D6_B7B2_A4E40D0F116A__INCLUDED_)
