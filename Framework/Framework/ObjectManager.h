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
	// ������ ������ ��ȯ���� ������ְڴ�.
	// hip ������ �ִ� ��ȯ���� �����ϰڴ�.
	// new �����ڴ� hip ������ ������ ���� �����. new ������ �ڿ� ������ ������ Ÿ���� ���¸� �����.
	// �������� ������ hip ������ �ִ� �������� �ּҰ��� �޾ƿ´�.
	static ObjectManager* GetInstance()
	{
		if (Instance == nullptr)
		{
			Instance = new ObjectManager;
		}
		return Instance;
	}

private:
	// map<string, list<Object*>> �� �ڷ����� ���Ѵ�.
	map<string, list<Object*>> ObjectList;

public:
	// Object �߰�
	void AddObject(Object* _Object);

	// �ּҸ� ��ȯ�ϹǷ� ������
	list<Object*>* GetObjectList(string _strKey);
};

