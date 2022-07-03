#include "Menu.h"
#include "InputManager.h"
#include "SceneManager.h"

Menu::Menu()
{
}

Menu::~Menu()
{
	Relase();
}

void Menu::Initialize()
{
}

void Menu::Update()
{
	if (InputManager::GetInstance()->GetKey() == KEY_ENTER)
	{
		SceneManager::GetInstance()->SetScene(STAGE);
	}
}

void Menu::Render()
{
	cout << "MENU" << endl;
}

void Menu::Relase()
{
}
