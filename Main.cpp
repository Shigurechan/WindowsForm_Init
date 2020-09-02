#include "io.h"
#include "Fcntl.h"
#include "stdio.h"
#include "Windows.h"
#include "glew/include/GL/glew.h"
#include "gl/GL.h"
#include <iostream>

//int _hConsole;
//コンソール画面を開く
void CreateConsoleWindow()
{
	AllocConsole();
	FILE* fp;
    freopen_s(&fp, "CONOUT$","w", stdout);
    freopen_s(&fp, "CONIN$", "r", stdin);
}


//コンソールを閉じる
void closeConsoleWindow()
{
	//_close(_hConsole);
}

//ウインドウプロシージャ
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	//終了または閉じる時にプログラムを正常に終了する
	if( message && WM_DESTROY || message && WM_CLOSE)
	{
		PostQuitMessage(0);//正常終了
		return 0;
	}

	return DefWindowProcW(hWnd,message,wParam,lParam);//意味がない場合
}

int APIENTRY WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )
//int APIENTRY _tWinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow )
{
	CreateConsoleWindow();

    HWND hWnd;//ウインドウハンドル
	MSG lpMsg;//スレッドのメッセージキュー情報
	WNDCLASS wc;//汎用ウインドウ

	wc.style = CS_HREDRAW | CS_VREDRAW;//ウインドウのスタイル（ウインドウサイズを変更すると自動調整)
	wc.lpfnWndProc = WndProc;//ウインドウプロシージャを設定
	wc.cbClsExtra = 0;//構造体の後ろに補足バイト数
	wc.cbWndExtra = 0;//ウインドウインスタンスの後ろに補足バイト数
	wc.hInstance = hInstance;//ウインドウプロシージャがあるインスタンスハンドル
	wc.hIcon = NULL;//アイコンのハンドル
	wc.hCursor = LoadCursor(NULL,IDC_ARROW);//マウスカーソルのハンドル
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);//ウインドウ背景色
	wc.lpszMenuName = NULL;//デフォルトのメニュー名
	wc.lpszClassName = TEXT("line");//ウインドウクラスに付ける名前

	if( !RegisterClass(&wc))
	{
		return 1;
	}

	/*
	hWnd = CreateWindow(TEXT("STATIC"), TEXT("WinAPITest"),WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		500,500,500,500,
		NULL,NULL,hInstance,NULL);

	if(hWnd == NULL)
	{
		printf("null\n");
	}else{
		printf("nullじゃない");
	}*/

//		ShowWindow(hWnd,WS_POPUP);
	//	MessageBox(hWnd,TEXT("ボタンを押してください"),TEXT(""),MB_OKCANCEL | MB_ICONQUESTION);

	return 0;
}

int main()
{

}