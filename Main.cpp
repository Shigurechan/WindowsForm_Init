#include "io.h"

#include "Fcntl.h"
#include "Windows.h"
#include "stdio.h"
#include <iostream>


// �R���\�[����ʂ��J��
void CreateConsoleWindow();
void CreateConsoleWindow()
{
	AllocConsole();//�R���\�[����ʂ��쐬

	FILE* fp = NULL;
	freopen_s(&fp, "CONOUT$","w", stdout);
	freopen_s(&fp,"CONIN$","r",stdin);
}


//�E�C���h�E�v���V�[�W��
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	//����܂��͕��鎞�Ƀv���O�������I������B
	if (message && WM_DESTROY || message && WM_CLOSE)
	{
		PostQuitMessage(0);	//����I��
		return 0;
	}

	return DefWindowProcW(hWnd, message, wParam, lParam);//�f�t�H���g�̃E�C���h�E�v���V�[�W��
}

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	CreateConsoleWindow();

	HWND hWnd;	//�E�C���h�E�n���h��
	MSG lpMsg;	//�X���b�h�̃��b�Z�[�W�L���[���
	WNDCLASS wc;//�ėp�E�C���h�E

	wc.style = CS_HREDRAW | CS_VREDRAW;						//�E�C���h�E�X�^�C��(�T�C�Y��ύX����Ǝ�������)
	wc.lpfnWndProc = WndProc;								//�E�C���h�E�v���V�[�W����ݒ�
	wc.cbClsExtra = 0;										//�\���̂̌��ɕ⑫�o�C�g��
	wc.cbWndExtra = 0;										//�E�C���h�E�C���X�^���X�̌��̕⑫�o�C�g��
	wc.hInstance = hInstance;								//�E�C���h�E�v���V�[�W��������C���X�^���X�n���h��
	wc.hIcon = NULL;										//�A�C�R�� �n���h��
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);				//�}�E�X�J�[�\�� �n���h��
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	//�E�C���h�E�w�i�F
	wc.lpszMenuName = NULL;									//���j���[��	
	wc.lpszClassName = TEXT("line");						//�E�C���h�E�N���X��

	//�E�C���h�N���X��o�^����
	if (!RegisterClass(&wc))
	{
		return 1;
	}

	return 0;
}



int main()
{

}