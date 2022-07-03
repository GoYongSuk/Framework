#pragma once
#include "Headers.h"

class Object;
class ObjectManager
{
private:
	ObjectManager();
	
public:
	~ObjectManager();

private:
	static ObjectManager* Instance;

public:
	// 포인터 형식의 반환값을 사용해주겠다.
	// hip 영역에 있는 반환값을 리턴하겠다.
	// new 연산자는 hip 영역에 데이터 값을 만든다. new 데이터 뒤에 선언한 데이터 타입의 형태를 만든다.
	// 포인터형 변수는 hip 영역에 있는 데이터의 주소값을 받아온다.
	static ObjectManager* GetInstance()
	{
		if (Instance == nullptr)
		{
			Instance = new ObjectManager;
		}
		return Instance;
	}

private:
	// map<string, list<Object*>> 가 자료형을 뜻한다.
	map<string, list<Object*>> ObjectList;

public:
	// Object 추가
	void AddObject(Object* _Object);

	// 주소를 반환하므로 포인터
	list<Object*>* GetObjectList(string _strKey);
};

