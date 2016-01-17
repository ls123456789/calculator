
// calculatorDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "calculator.h"
#include "calculatorDlg.h"
#include "afxdialogex.h"
#include "CString"
#include"math.h"
#include"CnewcalculatorDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_WM_MOUSEMOVE()
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CcalculatorDlg 对话框




CcalculatorDlg::CcalculatorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CcalculatorDlg::IDD, pParent)
	, m_str(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	flag = 0;
	mflag = 0;
	m_temp1 = NULL;
	m_temp2 = NULL;
	m_temp3 = NULL; 
}

void CcalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_str);
}

BEGIN_MESSAGE_MAP(CcalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_1, &CcalculatorDlg::OnBnClicked1)
	ON_BN_CLICKED(IDC_2, &CcalculatorDlg::OnBnClicked2)
	ON_BN_CLICKED(IDC_3, &CcalculatorDlg::OnBnClicked3)
	ON_BN_CLICKED(IDC_4, &CcalculatorDlg::OnBnClicked4)
	ON_BN_CLICKED(IDC_5, &CcalculatorDlg::OnBnClicked5)
	ON_BN_CLICKED(IDC_6, &CcalculatorDlg::OnBnClicked6)
	ON_BN_CLICKED(IDC_8, &CcalculatorDlg::OnBnClicked8)
	ON_BN_CLICKED(IDC_9, &CcalculatorDlg::OnBnClicked9)
	ON_BN_CLICKED(IDC_DOT, &CcalculatorDlg::OnBnClickedDot)
	ON_BN_CLICKED(IDC_ADD, &CcalculatorDlg::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_CALCUATOR, &CcalculatorDlg::OnBnClickedCalcuator)
	ON_BN_CLICKED(IDC_0, &CcalculatorDlg::OnBnClicked0)
	ON_BN_CLICKED(IDC_7, &CcalculatorDlg::OnBnClicked7)
	ON_BN_CLICKED(IDC_0, &CcalculatorDlg::OnBnClicked0)
	ON_BN_CLICKED(IDC_CLEAR, &CcalculatorDlg::OnBnClickedClear)
	ON_BN_CLICKED(IDC_SUB, &CcalculatorDlg::OnBnClickedSub)
	ON_BN_CLICKED(IDC_MUL, &CcalculatorDlg::OnBnClickedMul)
	ON_BN_CLICKED(IDC_DIV, &CcalculatorDlg::OnBnClickedDiv)
	ON_BN_CLICKED(IDC_CLEAR2, &CcalculatorDlg::OnBnClickedClear2)
	ON_BN_CLICKED(IDC_CLEAR3, &CcalculatorDlg::OnBnClickedClear3)
	ON_BN_CLICKED(IDC_SQRT, &CcalculatorDlg::OnBnClickedSqrt)
	ON_BN_CLICKED(IDC_RECIPROC, &CcalculatorDlg::OnBnClickedReciproc)
	ON_BN_CLICKED(IDC_SIGN, &CcalculatorDlg::OnBnClickedSign)
	ON_BN_CLICKED(IDC_CHANGESIGN, &CcalculatorDlg::OnBnClickedChangesign)
	ON_BN_CLICKED(IDC_M1, &CcalculatorDlg::OnBnClickedM1)
	ON_BN_CLICKED(IDC_M1ADD, &CcalculatorDlg::OnBnClickedM1add)
	ON_BN_CLICKED(IDC_M1SUB, &CcalculatorDlg::OnBnClickedM1sub)
	ON_BN_CLICKED(IDC_M1C, &CcalculatorDlg::OnBnClickedM1c)
	ON_BN_CLICKED(IDC_M1R, &CcalculatorDlg::OnBnClickedM1r)
	ON_WM_KEYUP()
	ON_BN_CLICKED(IDC_M1S, &CcalculatorDlg::OnBnClickedM1s)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CcalculatorDlg 消息处理程序

BOOL CcalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	SetTimer(1, 1000, NULL);
	sec = 0;

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CcalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CcalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CcalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}





//***********************************************
//*               此段为输入的数值              *
//***********************************************


void CcalculatorDlg::OnBnClicked0()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str = m_str + L"0";
	UpdateData(false);
}

void CcalculatorDlg::OnBnClicked1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str = m_str + L"1";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked2()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str = m_str + L"2";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked3()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str = m_str + L"3";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked4()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str = m_str + L"4";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked5()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str = m_str + L"5";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked6()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str = m_str + L"6";
	UpdateData(false);
}

void CcalculatorDlg::OnBnClicked7()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str = m_str + L"7";
	UpdateData(false);
}

void CcalculatorDlg::OnBnClicked8()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str = m_str + L"8";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked9()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str = m_str + L"9";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedDot()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	if(m_str.Find(L".")== -1)
	{
		if(m_str == "")
		{
			m_str = m_str + L"0";
		}
		m_str = m_str + L".";
	}
	UpdateData(false);
}



//***********************************************
//*               此段为输入的数值              *
//***********************************************







//***********************************************
//*               此段为基本运算                *
//***********************************************

void CcalculatorDlg::OnBnClickedAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	if (flag == 1)
	{
		temp = temp + _ttof(m_str);
	}
	else if (flag == 2)
	{
		temp = temp - _ttof(m_str);
	}
	else if (flag == 3)
	{
		temp = temp * _ttof(m_str);
	}
	else if (flag == 4)
	{
		if (_ttof(m_str) == 0)
		{
			m_str = L"false:The denominator cannot be 0";
			flag = 0;
		}
		else
		{
			temp = temp / _ttof(m_str);
			m_str.Format(L"%lf", temp);
		}
	}
	else
	{
		temp = _ttof(m_str);
	}
	flag = 1;
	m_str = "";
	UpdateData(false);

}

void CcalculatorDlg::OnBnClickedSub()
{
	// TODO: 在此添加控件通知处理程序代码

	UpdateData(true);
	if (flag == 1)
	{
		temp = temp + _ttof(m_str);
	}
	else if (flag == 2)
	{
		temp = temp - _ttof(m_str);
	}
	else if (flag == 3)
	{
		temp = temp * _ttof(m_str);
	}
	else if (flag == 4)
	{
		if (_ttof(m_str) == 0)
		{
			m_str = L"false:The denominator cannot be 0";
			flag = 0;
		}
		else
		{
			temp = temp / _ttof(m_str);
			m_str.Format(L"%lf", temp);
		}
	}
	else
	{
		temp = _ttof(m_str);
	}
	flag = 2;
	m_str = "";
	UpdateData(false);
}

void CcalculatorDlg::OnBnClickedMul()
{
	// TODO: 在此添加控件通知处理程序代码

	UpdateData(true);
	if (flag == 1)
	{
		temp = temp + _ttof(m_str);
	}
	else if (flag == 2)
	{
		temp = temp - _ttof(m_str);
	}
	else if (flag == 3)
	{
		temp = temp * _ttof(m_str);
	}
	else if (flag == 4)
	{
		if (_ttof(m_str) == 0)
		{
			m_str = L"false:The denominator cannot be 0";
			flag = 0;
		}
		else
		{
			temp = temp / _ttof(m_str);
			m_str.Format(L"%lf", temp);
		}
	}
	else
	{
		temp = _ttof(m_str);
	}
	flag = 3;
	m_str = "";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedDiv()
{
	// TODO: 在此添加控件通知处理程序代码

	UpdateData(true);
	if (flag == 1)
	{
		temp = temp + _ttof(m_str);
	}
	else if (flag == 2)
	{
		temp = temp - _ttof(m_str);
	}
	else if (flag == 3)
	{
		temp = temp * _ttof(m_str);
	}
	else if (flag == 4)
	{
		if (_ttof(m_str) == 0)
		{
			m_str = L"false:The denominator cannot be 0";
			flag = 0;
		}
		else
		{
			temp = temp / _ttof(m_str);
			m_str.Format(L"%lf", temp);
		}
	}
	else
	{
		temp = _ttof(m_str);
	}
	flag = 4;
	m_str = "";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedCalcuator()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	switch (flag)
	{
	case 1:temp = temp + _ttof(m_str);
		   m_str.Format(L"%lf", temp);
		   break;
	case 2:temp = temp - _ttof(m_str);
		   m_str.Format(L"%lf", temp);
		   break;
	case 3:temp = temp *  _ttof(m_str);
		   m_str.Format(L"%lf", temp);
		   break;
	case 4:if (_ttof(m_str) == 0)
	       {
		       m_str = L"false:The denominator cannot be 0";
			   flag = 0;
		   }
		   else
		   {
			   temp = temp / _ttof(m_str);
			   m_str.Format(L"%lf", temp);
		   }
		   break;
	}
	rigdel(m_str);
	UpdateData(false);
}


//***********************************************
//*               此段为基本运算                *
//***********************************************









//***********************************************
//*                 此段为清除                  *
//***********************************************


void CcalculatorDlg::OnBnClickedClear()
{
	// TODO: 在此添加控件通知处理程序代码
	flag = 0;
	temp = NULL;
	m_str = "";
	UpdateData(false);
}

void CcalculatorDlg::OnBnClickedClear2()
{
	// TODO: 在此添加控件通知处理程序代码
	m_str = "";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedClear3()
{
	// TODO: 在此添加控件通知处理程序代码
	m_str.Delete(m_str.GetLength()-1,1);
	UpdateData(false);
}


//***********************************************
//*                 此段为清除                  *
//***********************************************






//***********************************************
//*             此段为其他运算法则              *
//***********************************************



void CcalculatorDlg::OnBnClickedSqrt()//开方
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	temp = sqrt(_ttof(m_str));
	m_str.Format(L"%lf",temp);
	rigdel(m_str);
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedReciproc()//求倒数
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	if( _ttof(m_str) == 0)
	{
		m_str = L"false:The denominator cannot be 0";
		flag = 0;
	}
	else
	{
		temp = _ttof(m_str);
		temp=1/temp;
		m_str.Format(L"%lf",temp);
	}
	rigdel(m_str);
	UpdateData(false);
}



void CcalculatorDlg::OnBnClickedSign()//百分号
{
	// TODO: 在此添加控件通知处理程序代码
	double temp1;
	UpdateData(true);
	if(!(flag == 0||m_str == L""))
	{
		temp1 = _ttof(m_str);
		temp1 = temp1/100;
	}
	m_str.Format(L"%lf",temp1);
	rigdel(m_str);
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedChangesign()//相反数
{
	// TODO: 在此添加控件通知处理程序代码
	double temp2;
	UpdateData(true);
	temp2 = _ttof(m_str);
	temp2 = -temp2;
	m_str.Format(L"%lf",temp2);
	rigdel(m_str);
	UpdateData(false);
}


//***********************************************
//*             此段为其他运算法则              *
//***********************************************




//***********************************************
//*              此段为M系类储存                *
//***********************************************


void CcalculatorDlg::OnBnClickedM1()
{
	// TODO: 在此添加控件通知处理程序代码
	CnewcalculatorDlg m_dlg4;
	if (!mflag == 0 )
	{
		m_dlg4.set(m_temp1,m_temp2,m_temp3);
	}
	ShowWindow(SW_HIDE); // 隐藏当前窗口
	m_dlg4.DoModal();
	ExitProcess(0);
}


void CcalculatorDlg::OnBnClickedM1add()
{
	// TODO: 在此添加控件通知处理程序代码
	mflag = 1;
	UpdateData(true);
	m_temp1 = m_temp1 +  _ttof(m_str);
}


void CcalculatorDlg::OnBnClickedM1sub()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_temp1 = m_temp1 - _ttof(m_str);
}


void CcalculatorDlg::OnBnClickedM1c()
{
	// TODO: 在此添加控件通知处理程序代码
	m_temp1 = 0;
}


void CcalculatorDlg::OnBnClickedM1r()
{
	// TODO: 在此添加控件通知处理程序代码
	m_str.Format(L"%lf", m_temp1);
	rigdel(m_str);
	UpdateData(false);
}

void CcalculatorDlg::OnBnClickedM1s()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	switch (mflag)
	{
	default:MessageBox(L"存储空间不足");
		break;
	case 1:mflag = mflag + 1;
		m_temp2 = _ttof(m_str);
		break;
	case 0: m_temp1 = _ttof(m_str);
		mflag = mflag + 1;
		break;
	case 2: m_temp2 = _ttof(m_str);
		break;
	case 3: m_temp3 = _ttof(m_str);
		break;
	}
	mflag = mflag + 1;
	
}


//***********************************************
//*              此段为M系类储存                *
//***********************************************



//***********************************************
//*           此段为新创建的成员函数            *
//***********************************************

void CcalculatorDlg::rigdel(CString &m_s)
{
	while (m_s.Right(1) == "0")
	{
		m_s.Delete(m_s.GetLength() - 1, 1);
	}
	while (m_s.Right(1) == ".")
	{
		m_s.Delete(m_s.GetLength() - 1, 1);
	}
}


//***********************************************
//*           此段为新创建的成员函数            *
//***********************************************

void CcalculatorDlg::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CDialogEx::OnKeyUp(nChar, nRepCnt, nFlags);
}

//***********************************************
//*           此段为新创建的成员函数            *
//***********************************************






//***********************************************
//*                     钟表                    *
//***********************************************



void CAboutDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	TRACE("x=%d,y=%d\n", point.x, point.y);
	CDialogEx::OnMouseMove(nFlags, point);
	
}

void CAboutDlg::OnTimer(UINT_PTR nIDEvent)
{
	CDialogEx::OnTimer(nIDEvent);
}


void CcalculatorDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CTime time = CTime::GetCurrentTime();
	hor = time.GetHour();
	min = time.GetMinute();
	sec = time.GetSecond();
	//TRACE("%d,%d,%d\n", hor, min, sec);

	CDC *pDC;
	pDC = GetDC();
	pDC->SetWindowOrg(-430, -200);
	CPen *oldpen;
	CPen pen1(PS_SOLID, 13, RGB(255, 255, 255));

	oldpen = pDC->SelectObject(&pen1);
	h = hor*(PI / 6) + min*(PI / 360) + sec*(PI / 216000);
	CPen pen4(PS_SOLID, 2, RGB(0, 0, 0));
	oldpen = pDC->SelectObject(&pen4);
	x = r2*sin(h);
	y = -r2*cos(h);
	pDC->MoveTo(0, 0);
	pDC->LineTo(x, y);
	CDialogEx::OnTimer(nIDEvent);


	oldpen = pDC->SelectObject(&pen1);
	m = min*(PI / 30) + sec*(PI / 1800);
	CPen pen3(PS_SOLID, 2, RGB(0, 0, 255));
	oldpen = pDC->SelectObject(&pen3);
	x = r1*sin(m);
	y = -r1*cos(m);
	pDC->MoveTo(0, 0);
	pDC->LineTo(x, y);
	CDialogEx::OnTimer(nIDEvent);

	

	s = sec*(PI / 30) - (PI / 30);
	oldpen = pDC->SelectObject(&pen1);
	x = r*sin(s);
	y = -r*cos(s);
	pDC->MoveTo(0, 0);
	pDC->LineTo(x, y);
	CPen pen2(PS_SOLID, 2, RGB(255, 0, 0));
	oldpen = pDC->SelectObject(&pen2);
	x = r*sin(s);
	y = -r*cos(s);
	pDC->MoveTo(0, 0);
	pDC->LineTo(x, y);
	CDialogEx::OnTimer(nIDEvent);

	/*newpen.CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
	oldpen = pDC->SelectObject(&newpen);
	pDC->MoveTo(ox, oy);
	pDC->LineTo(x, y);
	pDC->SelectObject(oldpen);
	x = ox + r1*sin(c*3.1415926 / 180);
	y = oy + r1*cos(c*3.1415926 / 180);
	pDC->MoveTo(ox, oy);
	pDC->LineTo(x, y);
	c = c - 6;*/
}
