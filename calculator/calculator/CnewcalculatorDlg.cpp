// CnewcalculatorDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "calculator.h"
#include "CnewcalculatorDlg.h"
#include "afxdialogex.h"
#include"calculatorDlg.h"
#include"CString"


// CnewcalculatorDlg 对话框

IMPLEMENT_DYNAMIC(CnewcalculatorDlg, CDialogEx)

CnewcalculatorDlg::CnewcalculatorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, m_s1(_T(""))
	, m_s2(_T(""))
	, m_s3(_T(""))
{
	//m_str1.Format(L"%lf", m_temp1);
	//m_s1 = m_str1;
}

CnewcalculatorDlg::~CnewcalculatorDlg()
{
}

void CnewcalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_s1);
	DDX_Text(pDX, IDC_EDIT2, m_s2);
	DDX_Text(pDX, IDC_EDIT3, m_s3);
}


BEGIN_MESSAGE_MAP(CnewcalculatorDlg, CDialogEx)
	ON_BN_CLICKED(IDC_M2, &CnewcalculatorDlg::OnBnClickedM2)
	ON_BN_CLICKED(IDC_M2SUB, &CnewcalculatorDlg::OnBnClickedM2sub)
	ON_BN_CLICKED(IDC_M2ADD, &CnewcalculatorDlg::OnBnClickedM2add)
	ON_BN_CLICKED(IDC_M2C, &CnewcalculatorDlg::OnBnClickedM2c)
END_MESSAGE_MAP()


// CnewcalculatorDlg 消息处理程序


void CnewcalculatorDlg::OnBnClickedM2()
{
	// TODO: 在此添加控件通知处理程序代码
	CcalculatorDlg m_dlg3;
	ShowWindow(SW_HIDE); // 隐藏当前窗口
	m_dlg3.DoModal();
	ExitProcess(0);
}


void CnewcalculatorDlg::OnBnClickedM2sub()
{
	// TODO: 在此添加控件通知处理程序代码
	mflag = 2;
	UpdateData(true);
	m_temp1 = m_temp1 - _ttof(m_s1);
	m_s1.Format(L"%lf", m_temp1);
	rigdel(m_s1);
	UpdateData(false);
}


void CnewcalculatorDlg::OnBnClickedM2add()
{
	// TODO: 在此添加控件通知处理程序代码
	mflag = 1;
	UpdateData(true);
	m_temp1 = m_temp1 + _ttof(m_s1);
	m_s1.Format(L"%lf", m_temp1);
	rigdel(m_s1);
	UpdateData(false);
}


void CnewcalculatorDlg::OnBnClickedM2c()
{
	// TODO: 在此添加控件通知处理程序代码
	mflag = 3;
	m_temp1 = 0;
}
 
void CnewcalculatorDlg::set(double m_t)
{
	m_temp1 = m_t;
	m_str1.Format(L"%lf", m_temp1);
	m_s1 = m_str1; 
	rigdel(m_s1);
}

void CnewcalculatorDlg::rigdel(CString &m_str1)
{
	while (m_str1.Right(1) == "0")
	{
		m_str1.Delete(m_str1.GetLength() - 1, 1);
	}
	while (m_str1.Right(1) == ".")
	{
		m_str1.Delete(m_str1.GetLength() - 1, 1);
	}
};


