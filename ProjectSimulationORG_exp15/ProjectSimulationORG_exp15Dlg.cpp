
// ProjectSimulationORG_exp15Dlg.cpp : 実装ファイル
//

#include "pch.h"
#include "framework.h"
#include "ProjectSimulationORG_exp15.h"
#include "ProjectSimulationORG_exp15Dlg.h"
#include "afxdialogex.h"
//#include <math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// アプリケーションのバージョン情報に使われる CAboutDlg ダイアログ

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

// 実装
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


// CProjectSimulationORGexp15Dlg ダイアログ



CProjectSimulationORGexp15Dlg::CProjectSimulationORGexp15Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PROJECTSIMULATIONORG_EXP15_DIALOG, pParent)
	, m_alpha_Pos(0)
	, m_beta_Pos(0)
	, m_alpha_Dist(0)
	, m_beta_Dist(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CProjectSimulationORGexp15Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_ALPHA_POS, m_alpha_Pos);
	DDX_Text(pDX, IDC_BETA_POS, m_beta_Pos);
	DDX_Text(pDX, IDC_ALPHA_MOVE, m_alpha_Dist);
	DDX_Text(pDX, IDC_BETA_MOVE, m_beta_Dist);
	DDX_Control(pDX, IDC_SCROLLBAR, m_vsbVal);
}

BEGIN_MESSAGE_MAP(CProjectSimulationORGexp15Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_STN_CLICKED(IDC_PICTURE, &CProjectSimulationORGexp15Dlg::OnStnClickedPicture)
	//ON_EN_CHANGE(IDC_EDIT4, &CProjectSimulationORGexp15Dlg::OnEnChangeEdit4)-----------------エラー
	ON_BN_CLICKED(IDC_ABSOLUTE, &CProjectSimulationORGexp15Dlg::OnBnClickedAbsolute)
	ON_BN_CLICKED(IDC_DRAW, &CProjectSimulationORGexp15Dlg::OnBnClickedDraw)
	ON_NOTIFY(NM_THEMECHANGED, IDC_SCROLLBAR, &CProjectSimulationORGexp15Dlg::OnNMThemeChangedScrollbar)
//	ON_WM_VSCROLL()
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDC_LEFT, &CProjectSimulationORGexp15Dlg::OnBnClickedLeft)
	ON_BN_CLICKED(IDC_RIGHT, &CProjectSimulationORGexp15Dlg::OnBnClickedRight)
END_MESSAGE_MAP()


// CProjectSimulationORGexp15Dlg メッセージ ハンドラー

BOOL CProjectSimulationORGexp15Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// "バージョン情報..." メニューをシステム メニューに追加します。

	// IDM_ABOUTBOX は、システム コマンドの範囲内になければなりません。
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

	// このダイアログのアイコンを設定します。アプリケーションのメイン ウィンドウがダイアログでない場合、
	//  Framework は、この設定を自動的に行います。
	SetIcon(m_hIcon, TRUE);			// 大きいアイコンの設定
	SetIcon(m_hIcon, FALSE);		// 小さいアイコンの設定

	// TODO: 初期化をここに追加します。
	m_vsbVal.SetScrollRange(-36, 36);	//スクロールバーの範囲を設定

	return TRUE;  // フォーカスをコントロールに設定した場合を除き、TRUE を返します。
}

void CProjectSimulationORGexp15Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// ダイアログに最小化ボタンを追加する場合、アイコンを描画するための
//  下のコードが必要です。ドキュメント/ビュー モデルを使う MFC アプリケーションの場合、
//  これは、Framework によって自動的に設定されます。

void CProjectSimulationORGexp15Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 描画のデバイス コンテキスト

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// クライアントの四角形領域内の中央
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// アイコンの描画
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ユーザーが最小化したウィンドウをドラッグしているときに表示するカーソルを取得するために、
//  システムがこの関数を呼び出します。
HCURSOR CProjectSimulationORGexp15Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CProjectSimulationORGexp15Dlg::OnStnClickedPicture()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
}


void CProjectSimulationORGexp15Dlg::OnEnChangeEdit4()
{
	// TODO: これが RICHEDIT コントロールの場合、このコントロールが
	// この通知を送信するには、CDialogEx::OnInitDialog() 関数をオーバーライドし、
	// CRichEditCtrl().SetEventMask() を関数し呼び出します。
	// OR 状態の ENM_CHANGE フラグをマスクに入れて呼び出す必要があります。

	// TODO: ここにコントロール通知ハンドラー コードを追加してください。
}


void CProjectSimulationORGexp15Dlg::OnBnClickedAbsolute()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
}

void CProjectSimulationORGexp15Dlg::OnNMThemeChangedScrollbar(NMHDR* pNMHDR, LRESULT* pResult)
{
	// この機能は Windows XP それ以降のバージョンを必要とします。
	// シンボル _WIN32_WINNT は >= 0x0501にならなければなりません。
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	*pResult = 0;
}

void CProjectSimulationORGexp15Dlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: ここにメッセージ ハンドラー コードを追加するか、既定の処理を呼び出します。

	int barPos;	//スクロールバーの位置

	//スクロールバーの現在位置を取得
	barPos = pScrollBar->GetScrollPos();

	//スクロールバーへの操作により処理を分ける
	switch (nSBCode) {
	case SB_LINELEFT:		//左矢印キーが押された
		barPos--;			//スクロールバーの位置を1減らす
		break;
	case SB_LINERIGHT:		//右矢印キーが押された
		barPos++;			//スクロールバーの位置を1増やす
		break;
	case SB_PAGELEFT:		//左矢印キーが押された
		barPos -= 10;		//スクロールバーの位置を10減らす
		break;
	case SB_PAGERIGHT:		//右矢印キーが押された
		barPos += 10;		//スクロールバーの位置を10増やす
		break;
	case SB_THUMBPOSITION:	//スクロールバーのつまみが動いた
		barPos = nPos;		//スクロールバーの位置を設定
		break;
	default:
		break;
	}

	//つまみの位置が範囲外にならないようにする
	if (barPos < -36) {
		barPos = -36;
	}
	if (barPos > 36) {
		barPos = 36;
	}

	//スクロールバーの位置を設定
	pScrollBar->SetScrollPos(barPos);

	//エディトボックスの値を設定
	//メンバ変数m_vsbValのスクロールバーの現在位置を検出して代入
	m_alpha_Dist = -m_vsbVal.GetScrollPos();

	//ダイアログボックスに変数(m_vsbVal.GetScrollPos())からデータを転送
	UpdateData(FALSE);

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CProjectSimulationORGexp15Dlg::OnBnClickedLeft()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。

	//ダイアログボックスから変数データを転送
	UpdateData(TRUE);

	m_beta_Dist++;	//変数m_addVal2の値を1増やす

	//変数(m_addVal2)からダイアログボックスにデータを転送
	UpdateData(FALSE);
}

void CProjectSimulationORGexp15Dlg::OnBnClickedRight()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。

	//ダイアログボックスから変数データを転送
	UpdateData(TRUE);

	m_beta_Dist--;	//変数m_addVal2の値を1増やす

	//変数(m_addVal2)からダイアログボックスにデータを転送
	UpdateData(FALSE);
}

void CProjectSimulationORGexp15Dlg::OnBnClickedDraw()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。

	CWnd* cwdPict = GetDlgItem(IDC_PICTURE);	//IDC_PICTUREのウィンドウハンドルを取得
	CDC* dcPict = cwdPict->GetDC();				//デバイスコンテキストの取得

	CRect pictRect;								//ピクチャ・ボックスの座標を格納
	cwdPict->GetClientRect(&pictRect);			//ピクチャ・ボックスの座標を取得

	COLORREF color = RGB(0, 0, 0);				//色の設定

	//ラジオボタンを利用可能にするためにIDを取得
	CButton* absoluteRadio = (CButton*)GetDlgItem(IDC_ABSOLUTE);
	CButton* relativeRadio = (CButton*)GetDlgItem(IDC_RELATIVE);

	//ピクチャ・ボックスをクリアする
	dcPict->FillSolidRect(pictRect, RGB(255, 255, 255));	//白色で塗りつぶす

	//原点のオフセットを設定
	int offsetX = 200;	//X軸の中心
	int offsetY = 250;	//Y軸の中心

	//アームロボットの初期位置を設定(相対座標で表現)
	int x_alpha_o[] = {   0,   0,  10,  10, -10, -10 };	//x_alpha_o[0]はロボットアームのジョイント位置, x_alpha_o[1]はロボットアームの先端の位置
	int y_alpha_o[] = {   0, 100,   0, 100, 100,   0 };	//y_alpha_o[0]はロボットアームのジョイント位置, y_alpha_o[1]はロボットアームの先端の位置
	int x_beta_o[]	= {	  0,   0,  10,  10, -10, -10 };	//x_beta_o[0]はロボットアームのジョイント位置, x_beta_o[1]はロボットアームの先端の位置
	int y_beta_o[]	= {	  0, 100,   0, 100, 100,   0 };	//y_beta_o[0]はロボットアームのジョイント位置,	y_beta_o[1]はロボットアームの先端の位置
	//int x_beta_o[]	= {	  0,   0,  10,  10, -10, -10 };	//X軸の初期位置(β軸）
	//int y_beta_o[]	= {	100, 200, 100, 200, 200, 100 };	//Y軸の初期位置(β軸)

	//アームロボットの現在位置を設定
	static int x_alpha[6] = { 0 };
	static int y_alpha[6] = { 0 };
	static int x_beta[6] = { 0 };
	static int y_beta[6] = { 0 };

	//ロボットの現在位置（静的変数）
	static int abs_alpha_Pos = 0;
	static int abs_beta_Pos = 0;

	//XY軸の描画
	for (int i = 0; i < 400; i++) {
		dcPict->SetPixel(i, offsetY, color);	//X軸
	}
	for (int j = 0; j < 250; j++) {
		dcPict->SetPixel(offsetX, j, color);	//Y軸
	}

	//ダイアログボックスから変数にデータを転送
	UpdateData(TRUE);

	//ラジオボタンの絶対位置に選択されているとき
	if (absoluteRadio->GetCheck()) {
		m_alpha_Pos = m_alpha_Dist;
		m_beta_Pos = m_beta_Dist;	//入力距離を移動位置に設定
		abs_alpha_Pos = 0;			//絶対位置の初期化
		abs_beta_Pos = 0;			//絶対位置の初期化
	}
	//ラジオボタンの相対位置に選択されているとき
	else if (relativeRadio->GetCheck()) {
		m_alpha_Pos = abs_alpha_Pos + m_alpha_Dist;		//絶対位置を移動位置に設定
		m_beta_Pos = abs_beta_Pos + m_beta_Dist;		//入力距離を移動位置に設定
	}
	else {
		MessageBox(_T("ラジオボタンが選択されていません。"), _T("エラー"), MB_ICONEXCLAMATION);
		return;
	
	}

	//位置の範囲をチェック
	if (m_alpha_Pos < -36) {
		m_alpha_Pos = -36;
	}
	else if (m_alpha_Pos > 36) {
		m_alpha_Pos = 36;
	}
	if (m_beta_Pos < -44) {
		m_beta_Pos = -44;
	}
	else if (m_beta_Pos > 44) {
		m_beta_Pos = 44;
	}
	/*if (m_alpha_Pos <= -36 || m_alpha_Pos >= 36) {
		MessageBox(_T("'α'が範囲外の値です。"), _T("エラー"), MB_ICONEXCLAMATION);
		return;
	}
	else if (m_beta_Pos <= -44 || m_beta_Pos >= 44) {
		MessageBox(_T("'β'が範囲外の値です。"), _T("エラー"), MB_ICONEXCLAMATION);
		return;
	}*/

	//角度を度数法から弧度法に変換
	const double M_PI = 3.14159265358979323846;	//円周率を定義
	double alpha = m_alpha_Pos * M_PI / 180;
	double beta = m_beta_Pos * M_PI / 180;

	//ダイアログボックスに変数からデータを転送
	UpdateData(FALSE);

	//アームロボットの初期位置------------------------------------------------------------
/*
	// α軸の位置
	//ペンの指定
	CPen myPen_alpha;
	myPen_alpha.CreatePen(PS_SOLID, 2, RGB(0, 0, 255));	//青色のペンを作成
	dcPict->SelectObject(&myPen_alpha);					//ペンを選択

	//関節関節(ジョイント)描画
	//dcPict->Ellipse(offsetX + x_alpha_o[0] - 20, offsetY - y_alpha_o[0] - 20, offsetX + x_alpha_o[0] + 20, offsetY - y_alpha_o[0] + 20);

	//ロボットアーム(リンク)の描画
	dcPict->MoveTo(offsetX + x_alpha_o[1], offsetY - y_alpha_o[1]);	//ロボットの初期位置に移動
	for (int i = 4; i >= 1; i--) {
		dcPict->LineTo(offsetX + x_alpha_o[i], offsetY - y_alpha_o[i]);
	}

	//ペンの開放
	myPen_alpha.DeleteObject();

	// β軸の位置
	//ペンの指定
	CPen myPen_beta;
	myPen_beta.CreatePen(PS_SOLID, 2, RGB(255, 0, 0));	//赤色のペンを作成
	dcPict->SelectObject(&myPen_beta);					//ペンを選択

	//関節関節(ジョイント)描画
	//dcPict->Ellipse(offsetX + x_beta_o[0] - 20, offsetY - y_beta_o[0] - 20, offsetX + x_beta_o[0] + 20, offsetY - y_beta_o[0] + 20);

	//ロボットアーム(リンク)の描画
	dcPict->MoveTo(offsetX + x_beta_o[1], offsetY - y_beta_o[1]);	//ロボットの初期位置に移動
	for (int i = 4; i >= 1; i--) {
		dcPict->LineTo(offsetX + x_beta_o[i], offsetY - y_beta_o[i]);
	}

	//ペンの開放
	myPen_beta.DeleteObject();*/

	//移動後のロボットの位置----------------------------------------------------------

	//α軸の移動後の位置--------------------------------------------------------------
	//ペンの指定
	CPen myPen_alpha2;
	myPen_alpha2.CreatePen(PS_SOLID, 2, RGB(250, 150, 50));	//ペンを作成
	dcPict->SelectObject(&myPen_alpha2);					//ペンを選択

	//2次元の回転行列を用いてロボットアームの位置を計算
	for (int i = 5; i >= 0; i--) {
		x_alpha[i] = x_alpha_o[i] * cos(-alpha) + y_alpha_o[i] * sin(-alpha) ;
		y_alpha[i] = -x_alpha_o[i] * sin(-alpha) + y_alpha_o[i] * cos(-alpha);
	}

	//関節関節(ジョイント)描画
	dcPict->Ellipse(offsetX + x_alpha[0] - 20, offsetY - y_alpha[0] - 20, offsetX + x_alpha[0] + 20, offsetY - y_alpha[0] + 20);

	//ロボットアーム(リンク)の描画
	dcPict->MoveTo(offsetX + x_alpha[2], offsetY - y_alpha[2]);
	for (int i = 5; i >= 2; i--) {
		dcPict->LineTo(offsetX + x_alpha[i], offsetY - y_alpha[i]);
	}

	//ペンの開放
	myPen_alpha2.DeleteObject();


	//β軸の移動後の位置--------------------------------------------------------------
	CPen myPen_beta2;
	myPen_beta2.CreatePen(PS_SOLID, 2, RGB(0, 0, 250));	//ペンを作成
	dcPict->SelectObject(&myPen_beta2);					//ペンを選択

	//2次元の回転行列を用いてロボットアームの位置を計算
	for (int i = 5; i >= 0; i--) {
		x_beta[i] = x_beta_o[i] * cos(-beta) + y_beta_o[i] * sin(-beta) + x_alpha[1];
		y_beta[i] = -x_beta_o[i] * sin(-beta) + y_beta_o[i] * cos(-beta) + y_alpha[1];
	}

	//関節関節(ジョイント)描画
	dcPict->Ellipse(offsetX + x_beta[0] - 20, offsetY - y_beta[0] - 20, offsetX + x_beta[0] + 20, offsetY - y_beta[0] + 20);

	//ロボットアーム(リンク)の描画
	dcPict->MoveTo(offsetX + x_beta[2], offsetY - y_beta[2]);
	for (int i = 5; i >= 2; i--) {
		dcPict->LineTo(offsetX + x_beta[i], offsetY - y_beta[i]);
	}

	//ペンの開放
	myPen_beta2.DeleteObject();


	//現在位置の更新
	abs_alpha_Pos = m_alpha_Pos;
	abs_beta_Pos = m_beta_Pos;
}