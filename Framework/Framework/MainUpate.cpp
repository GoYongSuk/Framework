#include "MainUpate.h"
#include "SceneManager.h"
#include "InputManager.h"

MainUpate::MainUpate()
{
}

MainUpate::~MainUpate()
{
	Relase();
}

void MainUpate::Initialize()
{
	SceneManager::GetInstance()->SetScene(LOGO);
}

void MainUpate::Update()
{
	// 키 입력
	InputManager::GetInstance()->InputKey();

	// 이미 만들어진 SceneManager 주소값을 반환받고 그 주소값의 업데이트 함수를 실행한다.
	SceneManager::GetInstance()->Update();
}

void MainUpate::Render()
{
	SceneManager::GetInstance()->Render();
}

void MainUpate::Relase()
{
}
