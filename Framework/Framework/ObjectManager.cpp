#include "ObjectManager.h"
#include "Object.h"

ObjectManager* ObjectManager::Instance = nullptr;

ObjectManager::ObjectManager()
{

}

ObjectManager::~ObjectManager()
{
}

// 포인터를 매개변수로 받았음.
void ObjectManager::AddObject(Object* _Object)
{
	// map<string, list<Object*>>::iterator
	// iterator : 반복자, 구조체에 가까움
	// ObjectList.find(_Object->GetKey()) : map 배열 안에서 해당하는 index를 찾는다.
	// .end() 마지막 순서, 데이터가 아무 것도 없을 때도 해당한다. 맨 뒤보다 더 뒤에 있는 빈공간
	// .begin(), 시작, 데이터를 다 채운후 처음부분보다 앞에 있는 빈 공간
	// .emplace() 지정된 데이터 위치를 옮긴다.
	map<string, list<Object*>>::iterator iter = ObjectList.find(_Object->GetKey());
	if (iter == ObjectList.end())
	{
		// list 내부에는 Object의 주소만 담겨있다.
		list<Object*> TempList;
		// .push_back, 리스트 맨 마지막에 새로운 데이터를 추가한다.
		// .push_front, 리스트 맨 앞에 새로운 데이터를 추가한다.
		TempList.push_back(_Object);
		// .insert는 들어갈 위치를 지정할 수 있다.
		// make_pair() : map 두 개의 정보를 입력해준다. 순서대로 넣어준다.
		ObjectList.insert(make_pair(_Object->GetKey(), TempList));
	}
	else 
	{
		// iter는 데이터의 위치를 찾는다. 여기서 second는 위치값을 가진다.
		iter->second.push_back(_Object);
	}
}

// 정의할 때 리턴값이 있으면 자동으로 생긴다.
list<Object*>* ObjectManager::GetObjectList(string _strKey)
{
	map<string, list<Object*>>::iterator iter = ObjectList.find(_strKey);
	if(iter == ObjectList.end())
	{
		return nullptr;
	}

	return &iter->second;
}
