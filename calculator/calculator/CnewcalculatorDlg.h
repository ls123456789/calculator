#pragma once


// CnewcalculatorDlg �Ի���

class CnewcalculatorDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CnewcalculatorDlg)

public:
	CnewcalculatorDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CnewcalculatorDlg();

	// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedM2();
	afx_msg void OnBnClickedM2sub();
	afx_msg void OnBnClickedM2add();
	afx_msg void OnBnClickedM2c();
	void set(double m_t);
	void rigdel(CString &m_s1);
	CString m_s1, m_s2, m_s3, m_str1;
	double m_temp1;
	int mflag;
};