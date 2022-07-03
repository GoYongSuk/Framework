#include "Player.h"
#include "InputManager.h"

Player::Player()
{
}

// Player가 생성될 때 위치값을 받으면 Object의 생성자를 실행한다.
// Object 생성자가 실행된다.
Player::Player(Transform _info) : Object(_info)
{
}

Player::~Player()
{
	Relase();
}

void Player::Initialize()
{
	// Object에 있는 strKey를 "Player"로 초기화한다.
	strKey = "Player";
}

void Player::Update()
{
	// GetKey는 키 입력을 반환한다.
	if (InputManager::GetInstance()->GetKey() == KEY_UP)
	{
		TransInfo.Position.y += 1;
	}

	if (InputManager::GetInstance()->GetKey() == KEY_DOWN)
	{
		TransInfo.Position.y -= 1;
	}

	if (InputManager::GetInstance()->GetKey() == KEY_RIGHT)
	{
		TransInfo.Position.x += 1;
	}

	if (InputManager::GetInstance()->GetKey() == KEY_LEFT)
	{
		TransInfo.Position.x -= 1;
	}
}

void Player::Render()
{
	cout << "Player" << endl;
	cout << "POS X : " << TransInfo.Position.x << endl;
	cout << "POS Y : " << TransInfo.Position.y << endl;
}

void Player::Relase()
{
}
