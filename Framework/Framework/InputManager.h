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

// 데이터 변조 방지
private:
	DWORD Key;

public:
	// 키 값을 반환하는 함수
	// 인라인 함수로 만들어서 제일 먼저 실행되도록 한다.
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

