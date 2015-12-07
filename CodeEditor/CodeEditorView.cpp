
// CodeEditorView.cpp : CCodeEditorView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "CodeEditor.h"
#endif

#include "CodeEditorDoc.h"
#include "CodeEditorView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCodeEditorView

IMPLEMENT_DYNCREATE(CCodeEditorView, CView)

BEGIN_MESSAGE_MAP(CCodeEditorView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CCodeEditorView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()

// CCodeEditorView ����/����

CCodeEditorView::CCodeEditorView()
{
	// TODO: �ڴ˴���ӹ������

}

CCodeEditorView::~CCodeEditorView()
{
}

BOOL CCodeEditorView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CCodeEditorView ����

void CCodeEditorView::OnDraw(CDC* /*pDC*/)
{
	CCodeEditorDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CCodeEditorView ��ӡ


void CCodeEditorView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CCodeEditorView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CCodeEditorView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CCodeEditorView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void CCodeEditorView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CCodeEditorView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CCodeEditorView ���

#ifdef _DEBUG
void CCodeEditorView::AssertValid() const
{
	CView::AssertValid();
}

void CCodeEditorView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCodeEditorDoc* CCodeEditorView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCodeEditorDoc)));
	return (CCodeEditorDoc*)m_pDocument;
}
#endif //_DEBUG


// CCodeEditorView ��Ϣ�������

int CCodeEditorView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������

	m_ScintillaWnd.Create(
		WS_EX_CLIENTEDGE,
		WS_CHILD | WS_VISIBLE,
		CRect(0, 0, lpCreateStruct->cx, lpCreateStruct->cy),
		this, 10000);

	return 0;
}


void CCodeEditorView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);
	if (m_ScintillaWnd.GetSafeHwnd())
	{
		m_ScintillaWnd.MoveWindow(0, 0, cx, cy);
	}
	// TODO: �ڴ˴������Ϣ����������
}


BOOL CCodeEditorView::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult)
{
	// TODO: �ڴ����ר�ô����/����û���
	LPNMHDR pnmh = (LPNMHDR)lParam;
	if (pnmh != NULL && pnmh->hwndFrom == m_ScintillaWnd.m_hWnd)
	{
		struct SCNotification* msg = (struct SCNotification*)lParam;
		switch (pnmh->code)
		{
		case SCN_CHARADDED:
			break;
		case SCN_MODIFIED:
			break;
		case SCN_ZOOM:
			break;
		}
	}
	return CView::OnNotify(wParam, lParam, pResult);
}
