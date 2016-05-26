// CoordinateSystem.h : main header file for the COORDINATESYSTEM application
//

#if !defined(AFX_COORDINATESYSTEM_H__96E7EE73_394A_4388_9935_A568E3F1689B__INCLUDED_)
#define AFX_COORDINATESYSTEM_H__96E7EE73_394A_4388_9935_A568E3F1689B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CCoordinateSystemApp:
// See CoordinateSystem.cpp for the implementation of this class
//

class CCoordinateSystemApp : public CWinApp
{
public:
	CCoordinateSystemApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCoordinateSystemApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CCoordinateSystemApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COORDINATESYSTEM_H__96E7EE73_394A_4388_9935_A568E3F1689B__INCLUDED_)
