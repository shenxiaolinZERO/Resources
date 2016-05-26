// GeometricTransformationDoc.cpp : implementation of the CGeometricTransformationDoc class
//

#include "stdafx.h"
#include "GeometricTransformation.h"

#include "GeometricTransformationDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGeometricTransformationDoc

IMPLEMENT_DYNCREATE(CGeometricTransformationDoc, CDocument)

BEGIN_MESSAGE_MAP(CGeometricTransformationDoc, CDocument)
	//{{AFX_MSG_MAP(CGeometricTransformationDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGeometricTransformationDoc construction/destruction

CGeometricTransformationDoc::CGeometricTransformationDoc()
{
	// TODO: add one-time construction code here

}

CGeometricTransformationDoc::~CGeometricTransformationDoc()
{
}

BOOL CGeometricTransformationDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CGeometricTransformationDoc serialization

void CGeometricTransformationDoc::Serialize(CArchive& ar)
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
// CGeometricTransformationDoc diagnostics

#ifdef _DEBUG
void CGeometricTransformationDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CGeometricTransformationDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGeometricTransformationDoc commands
