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
	// �θ� Ŭ������ ���� ��ü�� �� �����ǵ��� �����.
	Object* pPlayer = new Player;
	pPlayer->Initialize();

	ObjectManager::GetInstance()->AddObject(pPlayer);
}

void Logo::Update()
{
	// GetKey�� Ű �Է��� ��ȯ�Ѵ�.
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
