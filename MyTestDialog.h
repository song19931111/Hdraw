#pragma once


// CMyTestDialog �Ի���

class CMyTestDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CMyTestDialog)

public:
	CMyTestDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMyTestDialog();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
