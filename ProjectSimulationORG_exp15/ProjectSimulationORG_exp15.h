
// ProjectSimulationORG_exp15.h : PROJECT_NAME アプリケーションのメイン ヘッダー ファイルです
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'pch.h' をインクルードしてください"
#endif

#include "resource.h"		// メイン シンボル


// CProjectSimulationORGexp15App:
// このクラスの実装については、ProjectSimulationORG_exp15.cpp を参照してください
//

class CProjectSimulationORGexp15App : public CWinApp
{
public:
	CProjectSimulationORGexp15App();

// オーバーライド
public:
	virtual BOOL InitInstance();

// 実装

	DECLARE_MESSAGE_MAP()
};

extern CProjectSimulationORGexp15App theApp;
