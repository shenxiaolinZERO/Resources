// GeometricTransformation.h : main header file for the GEOMETRICTRANSFORMATION application
//

#if !defined(AFX_GEOMETRICTRANSFORMATION_H__9C308575_4A4F_4A37_A265_9F29B6E660E7__INCLUDED_)
#define AFX_GEOMETRICTRANSFORMATION_H__9C308575_4A4F_4A37_A265_9F29B6E660E7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CGeometricTransformationApp:
// See GeometricTransformation.cpp for the implementation of this class
//

class CGeometricTransformationApp : public CWinApp
{
public:
	CGeometricTransformationApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGeometricTransformationApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CGeometricTransformationApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GEOMETRICTRANSFORMATION_H__9C308575_4A4F_4A37_A265_9F29B6E660E7__INCLUDED_)
