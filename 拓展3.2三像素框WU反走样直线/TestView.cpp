
// TestView.cpp : implementation of the CTestView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Test.h"
#endif

#include "TestDoc.h"
#include "TestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CTestView

IMPLEMENT_DYNCREATE(CTestView, CView)

BEGIN_MESSAGE_MAP(CTestView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CTestView::OnFilePrintPreview)
//	ON_WM_CONTEXTMENU()
//	ON_WM_RBUTTONUP()

	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CTestView construction/destruction

CTestView::CTestView()
{
	// TODO: add construction code here

}

CTestView::~CTestView()
{
}

BOOL CTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CTestView drawing

void CTestView::OnDraw(CDC* pDC)
{
	CTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: add draw code for native data here
	
}

// CTestView printing


void CTestView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CTestView diagnostics

#ifdef _DEBUG
void CTestView::AssertValid() const
{
	CView::AssertValid();
}

void CTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTestDoc* CTestView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTestDoc)));
	return (CTestDoc*)m_pDocument;
}
#endif //_DEBUG




void CTestView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	p0.x = point.x;
	p0.y = point.y;
	p0.c = CRGB(0.0, 0.0, 0.0);
	CView::OnLButtonDown(nFlags, point);
}


void CTestView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	p1.x = point.x;
	p1.y = point.y;
	p1.c = CRGB(0.0, 0.0, 0.0);
	CALine* pLine = new CALine;
	CDC* pDC = GetDC();//�����豸������ָ��
	CRect rect;//����ͻ�������
	GetClientRect(&rect);//��ÿͻ������ε���Ϣ
	pDC->SetMapMode(MM_ANISOTROPIC);//�Զ����ά����ϵ
	pDC->SetWindowExt(rect.Width(), rect.Height());//���ô��ڷ�Χ
	pDC->SetViewportExt(rect.Width(), -rect.Height());//����������Χ����x��ˮƽ����Ϊ����y�ᴹֱ����Ϊ��
	pDC->SetViewportOrg(rect.Width() / 2, rect.Height() / 2);//���ÿͻ�������Ϊ��ά����ϵԭ��
	rect.OffsetRect(-rect.Width() / 2, -rect.Height() / 2);//rect������ͻ����غ�
	//�豸����ϵ�еĵ����Զ�������ϵת��
	p0.x = p0.x - rect.Width() / 2;
	p0.y = rect.Height() / 2 - p0.y;
	p1.x = p1.x - rect.Width() / 2;
	p1.y = rect.Height() / 2 - p1.y;
	pLine->MoveTo(pDC, p0);
	pLine->LineTo(pDC, p1);
	delete pLine;
	ReleaseDC(pDC);//�ͷ��豸������ָ��
	CView::OnLButtonUp(nFlags, point);
}
