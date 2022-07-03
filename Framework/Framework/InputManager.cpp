#include "InputManager.h"

// Instance�� ������ �������� �ö� �� nullptr�� �ʱ�ȭ
// InputManager Ŭ������ ���� instance�� �ҷ��ͼ� ����Ű�� �ּҸ� nullptr�� �ϰڴٴ� �ǹ�
InputManager* InputManager::Instance = nullptr;

InputManager::InputManager() : Key(0)
{

}

InputManager::~InputManager()
{
}

void InputManager::InputKey()
{
	// Key ���� ���� ������ �ȵǹǷ�, �������� �� ������ �ʱ�ȭ ���ش�.
	Key = 0;
	
	// GetAsyncKeyState�� Ű �Է��� �޾ƿ´�.
	// virtual key, �Ű� ������ Ű �Է��� �޴´�.
	// |= �� ���� ���ÿ� �������� �Է��� �� �� �ִ�.
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


