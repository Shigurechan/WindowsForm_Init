#include "io.h"
#include "Fcntl.h"
#include "stdio.h"
#include "Windows.h"
#include "glew/include/GL/glew.h"
#include "gl/GL.h"
#include <iostream>

//int _hConsole;
//�R���\�[����ʂ��J��
void CreateConsoleWindow()
{
	AllocConsole();
	FILE* fp;
    freopen_s(&fp, "CONOUT$","w", stdout);
    freopen_s(&fp, "CONIN$", "r", stdin);
}


//�R���\�[�������
void closeConsoleWindow()
{
	//_close(_hConsole);
}

//�E�C���h�E�v���V�[�W��
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	//�I���܂��͕��鎞�Ƀv���O�����𐳏�ɏI������
	if( message && WM_DESTROY || message && WM_CLOSE)
	{
		PostQuitMessage(0);//����I��
		return 0;
	}

	return DefWindowProcW(hWnd,message,wParam,lParam);//�Ӗ����Ȃ��ꍇ
}

int APIENTRY WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )
//int APIENTRY _tWinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow )
{
	CreateConsoleWindow();

    HWND hWnd;//�E�C���h�E�n���h��
	MSG lpMsg;//�X���b�h�̃��b�Z�[�W�L���[���
	WNDCLASS wc;//�ėp�E�C���h�E

	wc.style = CS_HREDRAW | CS_VREDRAW;//�E�C���h�E�̃X�^�C���i�E�C���h�E�T�C�Y��ύX����Ǝ�������)
	wc.lpfnWndProc = WndProc;//�E�C���h�E�v���V�[�W����ݒ�
	wc.cbClsExtra = 0;//�\���̂̌��ɕ⑫�o�C�g��
	wc.cbWndExtra = 0;//�E�C���h�E�C���X�^���X�̌��ɕ⑫�o�C�g��
	wc.hInstance = hInstance;//�E�C���h�E�v���V�[�W��������C���X�^���X�n���h��
	wc.hIcon = NULL;//�A�C�R���̃n���h��
	wc.hCursor = LoadCursor(NULL,IDC_ARROW);//�}�E�X�J�[�\���̃n���h��
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);//�E�C���h�E�w�i�F
	wc.lpszMenuName = NULL;//�f�t�H���g�̃��j���[��
	wc.lpszClassName = TEXT("line");//�E�C���h�E�N���X�ɕt���閼�O

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
		printf("null����Ȃ�");
	}*/

//		ShowWindow(hWnd,WS_POPUP);
	//	MessageBox(hWnd,TEXT("�{�^���������Ă�������"),TEXT(""),MB_OKCANCEL | MB_ICONQUESTION);

	return 0;
}

int main()
{

}