#include "io.h"

#include "Fcntl.h"
#include "Windows.h"
#include "stdio.h"
#include <iostream>


// コンソール画面を開く
void CreateConsoleWindow();
void CreateConsoleWindow()
{
	AllocConsole();//コンソール画面を作成

	FILE* fp = NULL;
	freopen_s(&fp, "CONOUT$","w", stdout);
	freopen_s(&fp,"CONIN$","r",stdin);
}


//ウインドウプロシージャ
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	//正常または閉じる時にプログラムを終了する。
	if (message && WM_DESTROY || message && WM_CLOSE)
	{
		PostQuitMessage(0);	//正常終了
		return 0;
	}

	return DefWindowProcW(hWnd, message, wParam, lParam);//デフォルトのウインドウプロシージャ
}

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	CreateConsoleWindow();

	HWND hWnd;	//ウインドウハンドル
	MSG lpMsg;	//スレッドのメッセージキュー情報
	WNDCLASS wc;//汎用ウインドウ

	wc.style = CS_HREDRAW | CS_VREDRAW;						//ウインドウスタイル(サイズを変更すると自動調整)
	wc.lpfnWndProc = WndProc;								//ウインドウプロシージャを設定
	wc.cbClsExtra = 0;										//構造体の後ろに補足バイト数
	wc.cbWndExtra = 0;										//ウインドウインスタンスの後ろの補足バイト数
	wc.hInstance = hInstance;								//ウインドウプロシージャがあるインスタンスハンドル
	wc.hIcon = NULL;										//アイコン ハンドル
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);				//マウスカーソル ハンドル
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	//ウインドウ背景色
	wc.lpszMenuName = NULL;									//メニュー名	
	wc.lpszClassName = TEXT("line");						//ウインドウクラス名

	//ウインドクラスを登録する
	if (!RegisterClass(&wc))
	{
		return 1;
	}

	return 0;
}



int main()
{

}