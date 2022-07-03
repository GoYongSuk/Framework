#include "SceneManager.h"
#include "Logo.h"
#include "Menu.h"
#include "Stage.h"

// Instance가 데이터 영역으로 올라갈 때 nullptr로 초기화
// SceneManager 클래스로 만든 instance를 불러와서 가리키는 주소를 nullptr로 하겠다는 의미
SceneManager* SceneManager::Instance = nullptr;

// SceneManager가 생성이 될 때 SceneState를 nullptr로 초기화
// : 뒤에 오는 값들을 초기화 해주겠다.
SceneManager::SceneManager() :SceneState(nullptr)
{
}

SceneManager::~SceneManager()
{
	Relase();
}

void SceneManager::SetScene(SCENEID _SceneState)
{
	if (SceneState != nullptr) 
	{
		delete SceneState;
		SceneState = nullptr;
	}
	switch (_SceneState)
	{
	case LOGO:
		SceneState = new Logo;
		break;
	case MENU:
		SceneState = new Menu;
		break;
	case STAGE:
		SceneState = new Stage;
		break;
	case EXIT:
		exit(NULL);
		break;
	default:
		break;
	}
	SceneState->Initialize();
}

void SceneManager::Update()
{
	// 포인터가 가리키는 객체의 정보를 사용한다.
	SceneState->Update();	
}

void SceneManager::Render()
{
	SceneState->Render();	
}

void SceneManager::Relase()
{
	delete SceneState;
	SceneState = nullptr;
}
