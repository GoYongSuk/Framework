#pragma once
#include "Object.h"

class Player : public Object
{
public:
	// ������, �Ҹ���
	Player();
	Player(Transform _info);
	virtual ~Player();

public:
	// �ѹ��� ����, �ʿ��� �� �ʱ�ȭ�ϴ� �Լ�
	virtual void Initialize()override;

	// ������ tick ���� ������ ������Ʈ, ������ ���� �ʱ�ȭ
	virtual void Update()override;

	// ������ tick ����, ȭ�� ���
	virtual void Render()override;

	// �����͸� ����� �Լ�
	virtual void Relase()override;

};

