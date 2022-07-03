#pragma once
#include "Headers.h"

// �Ҹ��ڿ� virtual�� ���ִ� ����
// Object���� �������� ����ϴ� �Ҹ��ڸ� ������ �ǰ� 
// �ڽ� Ŭ���������� �Ҹ��ڸ� �⺻���� ����ϰ� �߰��� ��� �� �ִ�. 
class Object
{
public:
	// ������, �Ҹ���
	Object();
	// �����ε�
	Object(Transform _info);
	virtual ~Object();

public:
	// �ѹ��� ����, �ʿ��� �� �ʱ�ȭ�ϴ� �Լ�
	virtual void Initialize()PURE;

	// ������ tick ���� ������ ������Ʈ, ������ ���� �ʱ�ȭ
	virtual void Update()PURE;

	// ������ tick ����, ȭ�� ���
	virtual void Render()PURE;

	// �����͸� ����� �Լ�
	virtual void Relase()PURE;

// �ڽ� Ŭ�������� ����ϱ� ���ؼ�
protected:
	Transform TransInfo;
	// �������� ������Ʈ �߿� � ������Ʈ���� �˷��ֱ� ���� ���� ����
	string strKey;

public:
	string GetKey() { return strKey; }

};



