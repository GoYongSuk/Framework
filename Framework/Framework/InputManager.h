#pragma once
#include "Headers.h"
class InputManager
{
private:
	static InputManager* Instance;

public:
	// Singletone
	static InputManager* GetInstance()
	{
		if (Instance == nullptr)
		{
			Instance = new InputManager;
		}
		return Instance;
	}

// ������ ���� ����
private:
	DWORD Key;

public:
	// Ű ���� ��ȯ�ϴ� �Լ�
	// �ζ��� �Լ��� ���� ���� ���� ����ǵ��� �Ѵ�.
	DWORD GetKey() 
	{
		return Key;
	};

	void InputKey();

private:
	InputManager();

public:
	~InputManager();
};

