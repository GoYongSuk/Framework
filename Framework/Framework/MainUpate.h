#pragma once
#include "Headers.h"

// main 업데이트 변수, 함수 선언 부분
// ctrl + . : cpp파일에 함수 정의
class MainUpate
{
public:
	// 생성자 소멸자
	MainUpate(); // 생성자
	~MainUpate(); // 소멸자, 없어질 때 자동 실행

public:
	// 한번만 실행, 필요할 때 초기화하는 함수
	void Initialize();
	
	// 설정한 tick 마다 게임을 업데이트, 변수나 정보 초기화
	void Update();
	
	// 설정한 tick 마다, 화면 출력
	void Render();
	
	// 데이터를 지우는 함수
	void Relase();
};

