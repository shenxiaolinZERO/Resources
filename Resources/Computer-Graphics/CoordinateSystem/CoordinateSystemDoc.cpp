// CoordinateSystemDoc.cpp : implementation of the CCoordinateSystemDoc class
//

#include "stdafx.h"
#include "CoordinateSystem.h"

#include "CoordinateSystemDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCoordinateSystemDoc

IMPLEMENT_DYNCREATE(CCoordinateSystemDoc, CDocument)

BEGIN_MESSAGE_MAP(CCoordinateSystemDoc, CDocument)
	//{{AFX_MSG_MAP(CCoordinateSystemDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCoordinateSystemDoc construction/destruction

CCoordinateSystemDoc::CCoordinateSystemDoc()
{
	// TODO: add one-time construction code here

}

CCoordinateSystemDoc::~CCoordinateSystemDoc()
{
}

BOOL CCoordinateSystemDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CCoordinateSystemDoc serialization

void CCoordinateSystemDoc::Serialize(CArchive& ar)
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
// CCoordinateSystemDoc diagnostics

#ifdef _DEBUG
void CCoordinateSystemDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCoordinateSystemDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCoordinateSystemDoc commands
