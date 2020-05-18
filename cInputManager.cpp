#include "DXUT.h"
#include "cInputManager.h"


cInputManager::cInputManager()
{
}


cInputManager::~cInputManager()
{
	Release();
}

bool cInputManager::MouseLPress()
{
	return (NowMouse[0] == true && OldMouse[0] == true);
}

bool cInputManager::MouseLUp()
{
	return (NowMouse[0] == false && OldMouse[0] == true);
}

bool cInputManager::MouseLDown()
{
	return (NowMouse[0] == true && OldMouse[0] == false);
}

bool cInputManager::MouseRPress()
{
	return (NowMouse[1] == true && OldMouse[1] == true);
}

bool cInputManager::MouseRUp()
{
	return (NowMouse[1] == false && OldMouse[1] == true);
}

bool cInputManager::MouseRDown()
{
	return (NowMouse[1] == true && OldMouse[1] == false);
}

bool cInputManager::KeyPress(int key)
{
	return (NowInput[key] == true && OldInput[key] == true);
}

bool cInputManager::KeyUp(int key)
{
	return (NowInput[key] == false && OldInput[key] == true);
}

bool cInputManager::KeyDown(int key)
{
	return (NowInput[key] == true && OldInput[key] == false);
}

void cInputManager::Init()
{
}

void cInputManager::Update()
{
	ScreenToClient(DXUTGetHWND(), &ptMouse);
	GetCursorPos(&ptMouse);
	for (int i = 0; i < 2; i++) {
		OldMouse[i] = NowMouse[i];
	}
	for (int i = 0; i < 256; i++) {
		OldInput[i] = NowInput[i];
	}

	for (int i = 0; i < 256; i++) 
		NowInput[i] = GetAsyncKeyState(i) ? TRUE : FALSE;
	
	NowMouse[0] = GetAsyncKeyState(VK_LBUTTON) && PtInRect(&WINRECT, ptMouse) ? TRUE : FALSE;
	NowMouse[1] = GetAsyncKeyState(VK_RBUTTON) && PtInRect(&WINRECT, ptMouse) ? TRUE : FALSE;
}

void cInputManager::Release()
{
}

int cInputManager::GetHorizontalAxis()
{
	if (KeyPress('A') || KeyPress('a') || KeyPress(VK_LEFT))
		return -1;
	else if (KeyPress('D') || KeyPress('d') || KeyPress(VK_RIGHT))
		return 1;
	else
		return 0;
}

int cInputManager::GetVerticalAxis()
{
	if (KeyPress('W') || KeyPress('w') || KeyPress(VK_UP))
		return -1;
	else if (KeyPress('S') || KeyPress('s') || KeyPress(VK_DOWN))
		return 1;
	else
		return 0;
}
