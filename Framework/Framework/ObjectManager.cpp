#include "ObjectManager.h"
#include "Object.h"

ObjectManager* ObjectManager::Instance = nullptr;

ObjectManager::ObjectManager()
{

}

ObjectManager::~ObjectManager()
{
}

// �����͸� �Ű������� �޾���.
void ObjectManager::AddObject(Object* _Object)
{
	// map<string, list<Object*>>::iterator
	// iterator : �ݺ���, ����ü�� �����
	// ObjectList.find(_Object->GetKey()) : map �迭 �ȿ��� �ش��ϴ� index�� ã�´�.
	// .end() ������ ����, �����Ͱ� �ƹ� �͵� ���� ���� �ش��Ѵ�. �� �ں��� �� �ڿ� �ִ� �����
	// .begin(), ����, �����͸� �� ä���� ó���κк��� �տ� �ִ� �� ����
	// .emplace() ������ ������ ��ġ�� �ű��.
	map<string, list<Object*>>::iterator iter = ObjectList.find(_Object->GetKey());
	if (iter == ObjectList.end())
	{
		// list ���ο��� Object�� �ּҸ� ����ִ�.
		list<Object*> TempList;
		// .push_back, ����Ʈ �� �������� ���ο� �����͸� �߰��Ѵ�.
		// .push_front, ����Ʈ �� �տ� ���ο� �����͸� �߰��Ѵ�.
		TempList.push_back(_Object);
		// .insert�� �� ��ġ�� ������ �� �ִ�.
		// make_pair() : map �� ���� ������ �Է����ش�. ������� �־��ش�.
		ObjectList.insert(make_pair(_Object->GetKey(), TempList));
	}
	else 
	{
		// iter�� �������� ��ġ�� ã�´�. ���⼭ second�� ��ġ���� ������.
		iter->second.push_back(_Object);
	}
}

// ������ �� ���ϰ��� ������ �ڵ����� �����.
list<Object*>* ObjectManager::GetObjectList(string _strKey)
{
	map<string, list<Object*>>::iterator iter = ObjectList.find(_strKey);
	if(iter == ObjectList.end())
	{
		return nullptr;
	}

	return &iter->second;
}
