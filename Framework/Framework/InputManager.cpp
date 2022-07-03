#include "InputManager.h"

// Instance가 데이터 영역으로 올라갈 때 nullptr로 초기화
// InputManager 클래스로 만든 instance를 불러와서 가리키는 주소를 nullptr로 하겠다는 의미
InputManager* InputManager::Instance = nullptr;

InputManager::InputManager() : Key(0)
{

}

InputManager::~InputManager()
{
}

void InputManager::InputKey()
{
	// Key 값이 남아 있으면 안되므로, 프레임이 돌 때마다 초기화 해준다.
	Key = 0;
	
	// GetAsyncKeyState는 키 입력을 받아온다.
	// virtual key, 매개 변수로 키 입력을 받는다.
	// |= 를 통해 동시에 여러개의 입력을 할 수 있다.
	if (GetAsyncKeyState(VK_UP))
		Key |= KEY_UP;
		//cout << "KEY UP" << endl;

	if (GetAsyncKeyState(VK_DOWN))
		Key |= KEY_DOWN;
		//cout << "KEY DOWN" << endl;

	if (GetAsyncKeyState(VK_LEFT))
		Key |= KEY_LEFT;
		//cout << "KEY LEFT" << endl;
	
	if (GetAsyncKeyState(VK_RIGHT))
		Key |= KEY_RIGHT;
		//cout << "KEY RIGHT" << endl;
	
	if (GetAsyncKeyState(VK_SPACE))
		Key |= KEY_SPACE;
	
	if (GetAsyncKeyState(VK_RETURN))
		Key |= KEY_ENTER;
	
	if (GetAsyncKeyState(VK_CONTROL))
		Key |= KEY_CTRL;
	
	if (GetAsyncKeyState(VK_MENU))
		Key |= KEY_ALT;
}


