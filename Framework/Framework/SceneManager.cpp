#include "SceneManager.h"
#include "Logo.h"
#include "Menu.h"
#include "Stage.h"

// Instance�� ������ �������� �ö� �� nullptr�� �ʱ�ȭ
// SceneManager Ŭ������ ���� instance�� �ҷ��ͼ� ����Ű�� �ּҸ� nullptr�� �ϰڴٴ� �ǹ�
SceneManager* SceneManager::Instance = nullptr;

// SceneManager�� ������ �� �� SceneState�� nullptr�� �ʱ�ȭ
// : �ڿ� ���� ������ �ʱ�ȭ ���ְڴ�.
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
	// �����Ͱ� ����Ű�� ��ü�� ������ ����Ѵ�.
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
