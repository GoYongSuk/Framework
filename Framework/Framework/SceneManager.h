#pragma once
#include "Headers.h"

// scene�� ������ ȣ��ȴ�.
// ���� ȣ��Ǹ� ���� ������ ������� ���� �����ؾ��Ѵ�.
// �׷��� ���� scene�� ��ġ ������ �����ϰ� �ִ�.
// �׷��� �ѹ��� ����ǰ� ���߿� �ٽ� ȣ������ �� ���� ��ü�� ȣ��Ǵ� �̱��� ������
// static ������ ������ �޸𸮸� �ø��ڴٴ� �ǹ�
// Singletone
// ���� ����, Scene�� �ִ��� �������� ������ �ϴ� ����� �� �ְ� �����.
class Scene;
class SceneManager
{
private:
	static SceneManager* Instance;

public:
	// ������ ������ ��ȯ���� ������ְڴ�.
	// hip ������ �ִ� ��ȯ���� �����ϰڴ�.
	// new �����ڴ� hip ������ ������ ���� �����. new ������ �ڿ� ������ ������ Ÿ���� ���¸� �����.
	// �������� ������ hip ������ �ִ� �������� �ּҰ��� �޾ƿ´�.
	static SceneManager* GetInstance() 
	{
		if(Instance == nullptr)
		{
			Instance = new SceneManager;
		}
		return Instance;
	}

private:
	SceneManager();

public:
	~SceneManager();

private:
	// ������ ���� ����
	// �ּҰ��� �޾ƿ� �غ� ����
	Scene* SceneState;

public:
	// ȣ���� �� �ѹ��� ����ǵ��� �� ��
	// init�̶� �ٸ��� ������ scene ��ȣ�� �Ű������� �� ��
	// ���Ŀ� ������� ���� ������ �޾ƿ´�.
	void SetScene(SCENEID _SceneState);

	// ������ tick ���� ������ ������Ʈ, ������ ���� �ʱ�ȭ
	void Update();

	// ������ tick ����, ȭ�� ���
	void Render();

	// �����͸� ����� �Լ�
	void Relase();

};

