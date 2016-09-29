// MyTestDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "HDraw.h"
#include "MyTestDialog.h"
#include "afxdialogex.h"


// CMyTestDialog 对话框

IMPLEMENT_DYNAMIC(CMyTestDialog, CDialogEx)

CMyTestDialog::CMyTestDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMyTestDialog::IDD, pParent)
{

}

CMyTestDialog::~CMyTestDialog()
{
}

void CMyTestDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMyTestDialog, CDialogEx)
END_MESSAGE_MAP()


// CMyTestDialog 消息处理程序
