#include "Stage.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "Player.h"
#include "ObjectManager.h"

Stage::Stage()
{
}

Stage::~Stage()
{
	Relase();
}

void Stage::Initialize()
{
	// Player�� ���� �� ��� �ִ� List�� ����Ų��.
	list<Object*>* PlayerList = ObjectManager::GetInstance()->GetObjectList("Player");

	if (PlayerList != nullptr) 
		// front�� ���� �տ� �ִ� ��ü�� ����Ų��.
		// begin�� ���� �տ� �ִ� �� ������ ����Ų��.
		pPlayer = PlayerList->front();
	
	if(pPlayer != nullptr)
		pPlayer->Initialize();
}

void Stage::Update()
{
	if (pPlayer != nullptr)
		pPlayer->Update();
}

void Stage::Render()
{
	cout << "STAGE" << endl;
	if (pPlayer != nullptr)
		pPlayer->Render();
}

void Stage::Relase()
{
	delete pPlayer;
	pPlayer = nullptr;
}
