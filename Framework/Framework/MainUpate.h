#pragma once
#include "Headers.h"

// main ������Ʈ ����, �Լ� ���� �κ�
// ctrl + . : cpp���Ͽ� �Լ� ����
class MainUpate
{
public:
	// ������ �Ҹ���
	MainUpate(); // ������
	~MainUpate(); // �Ҹ���, ������ �� �ڵ� ����

public:
	// �ѹ��� ����, �ʿ��� �� �ʱ�ȭ�ϴ� �Լ�
	void Initialize();
	
	// ������ tick ���� ������ ������Ʈ, ������ ���� �ʱ�ȭ
	void Update();
	
	// ������ tick ����, ȭ�� ���
	void Render();
	
	// �����͸� ����� �Լ�
	void Relase();
};

