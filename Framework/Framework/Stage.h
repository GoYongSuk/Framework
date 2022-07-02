#pragma once
#include "Scene.h"

class Stage : public Scene
{
public:
	Stage();
	~Stage();

	// override: 가상함수를 덮어씌우겠다는 의미
	// override, 오버로드(연산자가 존재하지 않음): 똑같은 함수 이름을 사용할 수 있다.

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



