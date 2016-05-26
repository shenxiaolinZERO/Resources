// exp2Doc.cpp : implementation of the CExp2Doc class
//

#include "stdafx.h"
#include "exp2.h"

#include "exp2Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CExp2Doc

IMPLEMENT_DYNCREATE(CExp2Doc, CDocument)

BEGIN_MESSAGE_MAP(CExp2Doc, CDocument)
	//{{AFX_MSG_MAP(CExp2Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExp2Doc construction/destruction

CExp2Doc::CExp2Doc()
{
	// TODO: add one-time construction code here

}

CExp2Doc::~CExp2Doc()
{
}

BOOL CExp2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CExp2Doc serialization

void CExp2Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CExp2Doc diagnostics

#ifdef _DEBUG
void CExp2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CExp2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CExp2Doc commands
