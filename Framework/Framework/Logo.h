#pragma once
#include "Scene.h"

class Logo : public Scene
{
public:
	Logo();
	virtual ~Logo();

// override: �����Լ��� �����ڴٴ� �ǹ�
// override, �����ε�(�����ڰ� �������� ����): �Ȱ��� �Լ� �̸��� ����� �� �ִ�.

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

