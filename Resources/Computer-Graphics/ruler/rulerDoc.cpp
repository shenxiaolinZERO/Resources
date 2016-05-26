// rulerDoc.cpp : implementation of the CRulerDoc class
//

#include "stdafx.h"
#include "ruler.h"

#include "rulerDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRulerDoc

IMPLEMENT_DYNCREATE(CRulerDoc, CDocument)

BEGIN_MESSAGE_MAP(CRulerDoc, CDocument)
	//{{AFX_MSG_MAP(CRulerDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRulerDoc construction/destruction

CRulerDoc::CRulerDoc()
{
	// TODO: add one-time construction code here

}

CRulerDoc::~CRulerDoc()
{
}

BOOL CRulerDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CRulerDoc serialization

void CRulerDoc::Serialize(CArchive& ar)
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
// CRulerDoc diagnostics

#ifdef _DEBUG
void CRulerDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRulerDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRulerDoc commands
