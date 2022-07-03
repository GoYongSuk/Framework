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
	// Ű �Է�
	InputManager::GetInstance()->InputKey();

	// �̹� ������� SceneManager �ּҰ��� ��ȯ�ް� �� �ּҰ��� ������Ʈ �Լ��� �����Ѵ�.
	SceneManager::GetInstance()->Update();
}

void MainUpate::Render()
{
	SceneManager::GetInstance()->Render();
}

void MainUpate::Relase()
{
}
