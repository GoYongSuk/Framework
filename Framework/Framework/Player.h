#pragma once
#include "Object.h"

class Player : public Object
{
public:
	// 생성자, 소멸자
	Player();
	Player(Transform _info);
	virtual ~Player();

public:
	// 한번만 실행, 필요할 때 초기화하는 함수
	virtual void Initialize()override;

	// 설정한 tick 마다 게임을 업데이트, 변수나 정보 초기화
	virtual void Update()override;

	// 설정한 tick 마다, 화면 출력
	virtual void Render()override;

	// 데이터를 지우는 함수
	virtual void Relase()override;

};

