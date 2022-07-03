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
	// Player를 전부 다 담고 있는 List를 가리킨다.
	list<Object*>* PlayerList = ObjectManager::GetInstance()->GetObjectList("Player");

	if (PlayerList != nullptr) 
		// front는 제일 앞에 있는 객체를 가리킨다.
		// begin은 제일 앞에 있는 빈 공간을 가리킨다.
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
