#pragma once
#include "afxwin.h"
//ע�⣺�����ļ�����Scintilla��includeĿ¼   
#include "Scintilla.h"   
#include "SciLexer.h" 

class CScintillaWnd :	public CWnd
{
	DECLARE_DYNAMIC(CScintillaWnd)
public:
	CScintillaWnd();
	virtual ~CScintillaWnd();
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL Create(
		DWORD dwExStyle, DWORD dwStyle, const RECT& rect,
		CWnd* pParentWnd, UINT nID);
};

