
// mfcProjectDlg.h: 헤더 파일
//

#pragma once
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")

#define WIDTH	640
#define HEIGHT	480

// CmfcProjectDlg 대화 상자
class CmfcProjectDlg : public CDialogEx
{
// 생성입니다.
private:
	CImage m_image;
	BOOL validImagePos(int x, int y);
public:
	CmfcProjectDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCPROJECT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

private:
	void InitImage(CDC* pDC);
public:
	int m_nX1;
	int m_nY1;
	int m_nX2;
	int m_nY2;
	afx_msg void OnBnClickedBtnDraw();
	afx_msg void OnBnClickedBtnAction();
	afx_msg void OnBnClickedBtnOpen();
	void UpdateDisplay();
	void drawCircle(unsigned char* fm, int i, int j, int nRadius, int nGray);
	bool isInRange(int x, int range);
	bool isInCircle(int i, int j, int nCenterX, int nCenterY, int nRadius);
	void OutOfRange();
};
