#pragma once
#include "Headers.h"

// scene은 여러번 호출된다.
// 새로 호출되면 기존 정보가 사라지는 것을 주의해야한다.
// 그래서 현재 scene의 위치 정보를 저장하고 있다.
// 그래서 한번만 실행되고 나중에 다시 호출했을 때 기존 객체가 호출되는 싱글톤 방법사용
// static 데이터 영역에 메모리를 올리겠다는 의미
// Singletone
// 전방 선언, Scene을 있는지 없는지는 모르지만 일단 사용할 수 있게 만든다.
class Scene;
class SceneManager
{
private:
	static SceneManager* Instance;

public:
	// 포인터 형식의 반환값을 사용해주겠다.
	// hip 영역에 있는 반환값을 리턴하겠다.
	// new 연산자는 hip 영역에 데이터 값을 만든다. new 데이터 뒤에 선언한 데이터 타입의 형태를 만든다.
	// 포인터형 변수는 hip 영역에 있는 데이터의 주소값을 받아온다.
	static SceneManager* GetInstance() 
	{
		if(Instance == nullptr)
		{
			Instance = new SceneManager;
		}
		return Instance;
	}

private:
	SceneManager();

public:
	~SceneManager();

private:
	// 데이터 변조 방지
	// 주소값을 받아올 준비 상태
	Scene* SceneState;

public:
	// 호출할 때 한번만 실행되도록 할 것
	// init이랑 다르게 실행할 scene 번호를 매개변수로 줄 것
	// 이후에 만들어질 씬의 정보를 받아온다.
	void SetScene(SCENEID _SceneState);

	// 설정한 tick 마다 게임을 업데이트, 변수나 정보 초기화
	void Update();

	// 설정한 tick 마다, 화면 출력
	void Render();

	// 데이터를 지우는 함수
	void Relase();

};

