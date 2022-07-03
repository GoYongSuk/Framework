#include "Player.h"
#include "InputManager.h"

Player::Player()
{
}

// Player�� ������ �� ��ġ���� ������ Object�� �����ڸ� �����Ѵ�.
// Object �����ڰ� ����ȴ�.
Player::Player(Transform _info) : Object(_info)
{
}

Player::~Player()
{
	Relase();
}

void Player::Initialize()
{
	// Object�� �ִ� strKey�� "Player"�� �ʱ�ȭ�Ѵ�.
	strKey = "Player";
}

void Player::Update()
{
	// GetKey�� Ű �Է��� ��ȯ�Ѵ�.
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
