
// ProjectSimulationORG_exp15Dlg.h : ヘッダー ファイル
//

#pragma once


// CProjectSimulationORGexp15Dlg ダイアログ
class CProjectSimulationORGexp15Dlg : public CDialogEx
{
// コンストラクション
public:
	CProjectSimulationORGexp15Dlg(CWnd* pParent = nullptr);	// 標準コンストラクター

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROJECTSIMULATIONORG_EXP15_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV サポート


// 実装
protected:
	HICON m_hIcon;

	// 生成された、メッセージ割り当て関数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
};
