#pragma once
#include "Headers.h"

// LOGO, MENU, STAGE의 부모 클래스
class Scene 
{
public:
	Scene();
	~Scene();

// virtual : 가상함수, 자식함수에서 이 함수를 변형시켜서 사용가능
public:
	// 한번만 실행, 필요할 때 초기화하는 함수
	// PURE : 순수 가상함수, 상속 받은 클래스에서 수정하겠다는 의미
	// 함수 선언만큼의 메모리를 잡아먹음. 그래서 안에 비었든 아니던 간에 최소한의 메모리를 사용한다.
	// 코드가 데이터 영역에 올라가는 메모리를 잡아먹는다.
	// PURE를 사용하면 클래스 자체도 가상 클래스로 바뀐다.
	// 가상 클래스란, 데이터 영역에 형태는 존재하나 실체가 존재하지않아서 모호한 상태
	// 가상 클래스가 되면 hip 영역에 올릴 수 없다.

	virtual void Initialize()PURE;

	// 설정한 tick 마다 게임을 업데이트, 변수나 정보 초기화
	virtual void Update()PURE;

	// 설정한 tick 마다, 화면 출력
	virtual void Render()PURE;

	// 데이터를 지우는 함수
	virtual void Relase()PURE;
};

