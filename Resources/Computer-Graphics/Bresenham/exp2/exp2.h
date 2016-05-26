// exp2.h : main header file for the EXP2 application
//

#if !defined(AFX_EXP2_H__1F53304B_A1EB_49D3_A8E3_3914489F11B0__INCLUDED_)
#define AFX_EXP2_H__1F53304B_A1EB_49D3_A8E3_3914489F11B0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CExp2App:
// See exp2.cpp for the implementation of this class
//

class CExp2App : public CWinApp
{
public:
	CExp2App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExp2App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CExp2App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXP2_H__1F53304B_A1EB_49D3_A8E3_3914489F11B0__INCLUDED_)
