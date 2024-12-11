
// mfcProjectDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "mfcProject.h"
#include "mfcProjectDlg.h"
#include "afxdialogex.h"

#include <iostream>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#endif

// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CmfcProjectDlg 대화 상자



CmfcProjectDlg::CmfcProjectDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCPROJECT_DIALOG, pParent)
	, m_nX1(100)
	, m_nY1(100)
	, m_nX2(400)
	, m_nY2(400)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CmfcProjectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_X1, m_nX1);
	DDX_Text(pDX, IDC_EDIT_Y1, m_nY1);
	DDX_Text(pDX, IDC_EDIT_X2, m_nX2);
	DDX_Text(pDX, IDC_EDIT_Y2, m_nY2);
}

BEGIN_MESSAGE_MAP(CmfcProjectDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_DRAW, &CmfcProjectDlg::OnBnClickedBtnDraw)
	ON_BN_CLICKED(IDC_BTN_ACTION, &CmfcProjectDlg::OnBnClickedBtnAction)
	ON_BN_CLICKED(IDC_BTN_OPEN, &CmfcProjectDlg::OnBnClickedBtnOpen)
END_MESSAGE_MAP()


// CmfcProjectDlg 메시지 처리기

BOOL CmfcProjectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	MoveWindow(0, 0, 850, 600);
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CmfcProjectDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CmfcProjectDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CPaintDC dc(this);
		InitImage(&dc);

		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CmfcProjectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CmfcProjectDlg::InitImage(CDC* pDC)
{
	int nBpp = 8;
	//무채색으로
	m_image.Create(WIDTH, -HEIGHT, nBpp);
	if (nBpp == 8) {
		static RGBQUAD rgb[256];
		for (int i = 0; i < 256; i++)
			rgb[i].rgbRed = rgb[i].rgbGreen = rgb[i].rgbBlue = i;
		m_image.SetColorTable(0, 256, rgb);
	}

	unsigned char* fm = (unsigned char*)m_image.GetBits(); //필드이미지 = 이미지 첫번째 포인터 값
	memset(fm, 0xff, sizeof(unsigned char) * WIDTH * HEIGHT);

	//draw outline
	pDC->MoveTo(WIDTH, 0);
	pDC->LineTo(WIDTH, HEIGHT);
	pDC->LineTo(0, HEIGHT);

	m_image.Draw(*pDC, 0, 0);
}

void CmfcProjectDlg::UpdateDisplay()
{
	CClientDC dc(this);
	m_image.Draw(dc, 0, 0);
}

void CmfcProjectDlg::OnBnClickedBtnDraw()
{
	UpdateData(TRUE);
	int nWidth = m_image.GetWidth();
	int nHeight = m_image.GetHeight();
	if (isInRange(m_nX1, nWidth) && isInRange(m_nY1, nHeight)) {
		int nRadius = rand() % 200;

		unsigned char* fm = (unsigned char*)m_image.GetBits();
		memset(fm, 0xff, sizeof(unsigned char) * nWidth * nHeight);

		drawCircle(fm, m_nX1, m_nY1, nRadius, rand() % 0xff);

		UpdateDisplay();
	}
	else {
		OutOfRange();
	}
	UpdateData(FALSE);
}

bool CmfcProjectDlg::isInRange(int x, int range)
{
	return (x >= 0 && x < range);
}

void CmfcProjectDlg::drawCircle(unsigned char* fm, int x, int y, int nRadius, int nGray)
{
	int nPitch = m_image.GetPitch();

	for (int j = y - nRadius; j < y + nRadius; j++) {
		for (int i = x - nRadius; i < x + nRadius; i++) {
			if (isInCircle(i, j, x, y, nRadius) && validImagePos(i, j))
				fm[j * nPitch + i] = nGray;
		}
	}
}

bool CmfcProjectDlg::isInCircle(int i, int j, int nCenterX, int nCenterY, int nRadius)
{
	bool bRet = false;

	double dX = i - nCenterX;
	double dY = j - nCenterY;
	double dDist = dX * dX + dY * dY;

	if (dDist < nRadius * nRadius) {
		bRet = true;
	}

	return bRet;
}

BOOL CmfcProjectDlg::validImagePos(int x, int y)
{
	int nWidth = m_image.GetWidth();
	int nHeight = m_image.GetHeight();

	CRect rect(0, 0, nWidth, nHeight); //영역 생성

	return rect.PtInRect(CPoint(x, y)); // 포인트가 영역 안에 들어가면 TRUE
}

void CmfcProjectDlg::OnBnClickedBtnAction()
{
	UpdateData(TRUE);
	int nWidth = m_image.GetWidth();
	int nHeight = m_image.GetHeight();
	if (isInRange(m_nX1, nWidth) && isInRange(m_nY1, nHeight) && isInRange(m_nX2, nWidth) && isInRange(m_nY2, nHeight)) {

		int nRadius = rand() % 200;
		unsigned char* fm = (unsigned char*)m_image.GetBits();

		memset(fm, 0xff, sizeof(unsigned char) * nWidth * nHeight);

		for (int i = -1; i <= 2; i) {
			drawCircle(fm, m_nX1 * (3 - i) / 3 + m_nX2 * i / 3, m_nY1 * (3 - i) / 3 + m_nY2 * i / 3, nRadius, 0xff);
			UpdateDisplay();
			i++;
			drawCircle(fm, m_nX1 * (3 - i) / 3 + m_nX2 * i / 3, m_nY1 * (3 - i) / 3 + m_nY2 * i / 3, nRadius, rand() % 0xff);
			UpdateDisplay();
			Sleep(500);

			CString strFile;
			strFile.Format(_T("C:\\image\\image%d.jpg"), i);
			m_image.Save(strFile);
		}
	}
	else {
		OutOfRange();
	}
	UpdateData(FALSE);
}

void CmfcProjectDlg::OutOfRange()
{
	int nWidth = m_image.GetWidth();
	int nHeight = m_image.GetHeight();

	CString strRange;
	strRange.Format(_T("[0, 0] ~ [%d, %d]"), nWidth - 1, nHeight - 1);
	AfxMessageBox(strRange);
}

void CmfcProjectDlg::OnBnClickedBtnOpen()
{
	CFileDialog fileDlg(TRUE, NULL, NULL, 0, _T("그림파일|*.jpg;*.png||"), this);

	if (fileDlg.DoModal() == IDOK) {
		CString g_strFilePath = fileDlg.GetPathName();

		if (m_image != NULL) {
			m_image.Destroy();
		}
		HRESULT loadResult = m_image.Load(g_strFilePath);
		if (FAILED(loadResult)) {
			CString strFailToLoad;
			strFailToLoad.Format(_T("Failed to load"));
			AfxMessageBox(strFailToLoad);
		}
		else {
			unsigned char* fm = (unsigned char*)m_image.GetBits();
			int nPitch = m_image.GetPitch();
			int nSumX = 0;
			int nSumY = 0;
			int nCount = 0;
			for (int j = 0; j < HEIGHT; j++) {
				for (int i = 0; i < WIDTH * 3; i++) {
					if (fm[j * nPitch + i] < 0xff) {
						nSumX += i;
						nSumY += j;
						nCount++;
					}
				}
			}
			double dCenterX = (double)nSumX / nCount;
			double dCenterY = (double)nSumY / nCount;

			int nCenterX = (int)dCenterX;
			int nCenterY = (int)dCenterY;

			fm[nCenterY * nPitch + nCenterX] = 0x00;
			for (int j = -10; j <= 10; j++) {
				fm[(nCenterY + j) * nPitch + nCenterX] = 0x00;
			}
			for (int i = -10 * 3; i <= 10 * 3; i++) {
				fm[nCenterY * nPitch + (nCenterX + i)] = 0x00;
			}
			CPaintDC dc(this);
			//m_image.Draw(dc, 0, 0);

			CString strCenter;
			strCenter.Format(_T("(%d, %d)"), nCenterX / 3, nCenterY);

			CDC* pDC = CDC::FromHandle(m_image.GetDC());
			pDC->SetBkMode(TRANSPARENT);
			pDC->TextOutW(nCenterX / 3, nCenterY, strCenter);
			m_image.ReleaseDC();
			m_image.BitBlt(dc.m_hDC, 0, 0);

			UpdateDisplay();
		}
	}
}
