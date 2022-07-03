#pragma once
#include "Headers.h"

// 소멸자에 virtual을 써주는 이유
// Object에서 공통으로 사용하는 소멸자를 가지게 되고 
// 자식 클래스에서는 소멸자를 기본으로 사용하고 추가로 덮어쓸 수 있다. 
class Object
{
public:
	// 생성자, 소멸자
	Object();
	// 오버로드
	Object(Transform _info);
	virtual ~Object();

public:
	// 한번만 실행, 필요할 때 초기화하는 함수
	virtual void Initialize()PURE;

	// 설정한 tick 마다 게임을 업데이트, 변수나 정보 초기화
	virtual void Update()PURE;

	// 설정한 tick 마다, 화면 출력
	virtual void Render()PURE;

	// 데이터를 지우는 함수
	virtual void Relase()PURE;

// 자식 클래스에서 사용하기 위해서
protected:
	Transform TransInfo;
	// 여러개의 오브젝트 중에 어떤 오브젝트인지 알려주기 위해 만든 변수
	string strKey;

public:
	string GetKey() { return strKey; }

};



