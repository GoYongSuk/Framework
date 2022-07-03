#include "Headers.h"
#include "MainUpate.h"

// 구조체랑 클래스 차이
// 기본적인 기능은 차이가 거의 없다.
// 차이점 : class와 달리 기본값이 public으로 설정된다.
// struct가 자료전달속도가 미세하게 빠름, but 둘 다 차이가 없음

//struct A
//{
//private:
//	int num;
//public:
//protected:
//};

// void return을 써줄 필요가 없다. 반환을 안해준다는 뜻 

// private : 지금 class만 사용가능, 다른 클래스는 사용불가, 보안성이 제일 뛰어남, 
// 기본적으로 캡슐화를 안해주면 private
// protected : 상속받은 class 까지만 사용가능, 정보를 많이 넣음(개인정보)
// public : 모든 클래스, 함수에서 접근가능

//class D 
//{
//private:
//	int num;
//protected:
//public:
//	int getNum() 
//	{
//		return num;
//	}
//	void setNum(int i) 
//	{
//		num = i;
//	}
//};

// 똑같은 이름의 함수라도 반환값 또는 매개변수가 달라지면 선택해서 호출 가능, 좌표에서 많이 사용
// 1.
//void a()
//{
//
//}
//
// 2.
//void a(int a)
//{
//	int i;
//}

int main(void) 
{	
	// ULONG : unsigned long
	// GetTickCount(32bit), GetTickCount64 : 컴퓨터가 부팅이 되면서 자체적으로 tick이 발생, 
	// 1초에 1000 tick, 밀리 세컨드(ms): 1/1000 (외부에서 1초 지나면 컴퓨터에서 1000 tick이 진행)
	// 49일 7시간 정도 tick 카운트가 계산한다. 이후에는 overflow가 일어나면서 카운트 초기화
	// GetTickCount64은 5억년까지 계산가능
	// GetTickCount는 그 tick을 반환한다.
	// system("cls"); 콘솔화면 지우기

	// 컴퓨터를 킨 시간 반환
	auto TIME = GetTickCount64();
	MainUpate main;

	main.Initialize();

	while (true) 
	{
		// 1000 tick이 너무 빨리 업데이트 되니까 tick count를 제한시킨다.
		// 50tick 이 진행되면 게임에서 한 번 업데이트한다.
		if(TIME + 50 < GetTickCount64())
		{
			TIME = GetTickCount64();
			system("cls");
			main.Update();
			main.Render();
		}
	}
	
	
	
	return 0;
}