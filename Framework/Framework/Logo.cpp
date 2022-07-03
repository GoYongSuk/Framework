#include "Logo.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "Player.h"
#include "ObjectManager.h"

Logo::Logo()
{
}

Logo::~Logo()
{
	Relase();
}

void Logo::Initialize()
{
	// 부모 클래스에 만들어서 전체가 다 관리되도록 만든다.
	Object* pPlayer = new Player;
	pPlayer->Initialize();

	ObjectManager::GetInstance()->AddObject(pPlayer);
}

void Logo::Update()
{
	// GetKey는 키 입력을 반환한다.
	if (InputManager::GetInstance()->GetKey() == KEY_ENTER) 
	{
		SceneManager::GetInstance()->SetScene(MENU);
	}
}

void Logo::Render()
{
	cout << "LOGO" << endl;
}

void Logo::Relase()
{
}
