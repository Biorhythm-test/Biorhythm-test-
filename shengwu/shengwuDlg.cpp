
// shengwuDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "shengwu.h"
#include "shengwuDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框
int fun(int x) {
	if ((x % 4 == 0 && x % 100 != 0) || x % 400 == 0) {
		return 1;
	}
	else {
		return 0;
	}
}
int fun1(int year, int month, int day) {
	int c[12];		//用数组c来存每个月的天数
	int i, j;		//i:循环计数  j用来判断是否为闰年  
	int k = 0;		//k-函数返回的总天数

	int a[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int b[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	j = fun(year);
	if (j == 1) {
		for (i = 0; i < 12; i++) {
			c[i] = a[i];
		}
	}
	else {
		for (i = 0; i < 12; i++) {
			c[i] = b[i];			//把每个月天数依次存到数组c中
		}
	}
	for (i = 0; i < month; i++) {
		k = k + c[i];		//把存在数组c的总天数全部加到k上
	}
	k = k + day;	//把之前的天数也加上去

	return k;
}

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CshengwuDlg 对话框



CshengwuDlg::CshengwuDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SHENGWU_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CshengwuDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CshengwuDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CshengwuDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CshengwuDlg::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT5, &CshengwuDlg::OnEnChangeEdit5)
END_MESSAGE_MAP()


// CshengwuDlg 消息处理程序

BOOL CshengwuDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CshengwuDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CshengwuDlg::OnPaint()
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
HCURSOR CshengwuDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CshengwuDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void CshengwuDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString cs1;
	CString cs2;
	CString cs3;
	CString cs4;
	CString cs5;
	CString cs6;
	CString out1;//输出体力语句
	CString out2;//输出情绪语句
	CString out3;//输出智慧语句

	GetDlgItemText(IDC_EDIT1, cs1);
	GetDlgItemText(IDC_EDIT2, cs2);
	GetDlgItemText(IDC_EDIT3, cs3);
	GetDlgItemText(IDC_EDIT4, cs4);
	GetDlgItemText(IDC_EDIT5, cs5);
	GetDlgItemText(IDC_EDIT6, cs6);

	int pastyear = _tstoi(cs1);
	int pastmonth = _tstoi(cs2);
	int pastday = _tstoi(cs3);
	int thisyear = _tstoi(cs4);
	int thismonth = _tstoi(cs5);
	int thisday = _tstoi(cs6);

	int y = fun1(thisyear, thismonth, thisday);		//今年总天数。
	int x = fun1(pastyear, pastmonth, pastday);		//1月1日到生日月日的天数
	int yeardiff = thisyear - pastyear;				//年份差
	int years1 = 365 * yeardiff;					//全算是平年的总天数
	int leaps = years1 / 4;							//闰年个数
	int years2 = years1 + leaps;					//相隔年份总天数
	int SUM = years2 - (x + pastday) + (y + thisday);	//总天数

	int labor = SUM % 23;
	int emotion = SUM % 28;
	int widsom = SUM % 33;

	if (labor == 0)
		out1 = "您的体力刚好是周期日！新行动易在此时产生,状况起伏不定，请您最近勿要盲动!";
	else if (labor == 12)
		out1 = "您的体力刚好是临界日！请您近日注意休息~";
	else if (labor > 12)
		out1 = "您的体力处于低潮期，请您注意能量补充~";
	else
		out1 = "您的体力处于高潮期，可以适当加强您的日常运动哦~";
	//体力部分
	if (emotion == 0)
		out2 = "您的情绪刚好是周期日！新的情绪容易在此时产生，请您最近勿要盲动";
	else if (emotion == 14)
		out2 = "您的情绪刚好是临界日！人的机体自我感觉低落，情绪波动大，请注意休息";
	else if (emotion > 14)
		out2 = "您的情绪处于低潮期，请您注意适当调节您的心情";
	else
		out2 = "您的情绪处于高潮期，每天拥有好心情~";
	//情绪部分
	if (widsom == 0)
		out3 = "您的智慧刚好是周期日！新的想法易在此时产生，请您最近勿要盲动";
	else if (widsom == 17)
		out3 = "您的智慧刚好是临界日！思维记忆都受到一定影响，请注意休息";
	else if (widsom > 17)
		out3 = "您的智慧处于低潮期,大脑储能中，请注意休息";
	else
		out3 = "您的智慧处于高潮期，大脑运作能力很强哦~";
	//智慧部分

	MessageBox(out1, _T("人体周期节律查询："));
	MessageBox(out2, _T("人体周期节律查询："));
	MessageBox(out3, _T("人体周期节律查询："));

}


void CshengwuDlg::OnEnChangeEdit5()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
