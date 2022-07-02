# Framework
2022.07.02
***
# 1. 자료형

- ULONMG : unsigned long (4byte, 0 ~ 4,294,967,295)<br>

- ULONG LONG : unsigned long long (8byte, 0 ~ 18,446,744,073,709,551,615)<br>

- auto : 선언된 변수의 초기화 식을 사용하여 해당 형식을 추론하도록 컴파일러에 지시한다. 이 기능은 생성 시 변수를 초기화할 때만 작동한다. 초기화 값을 사용하지 않고 생성된 변수는 이 기능을 사용할 수 없다. <br>

- auto 사용 시 주의사항
    - auto 키워드는 함수 매개변수로 사용할 수 없음
    - auto 키워드는 구조체나 클래스의 멤버 변수로 사용 불가(해당 객체 자료형 크기를 모르기 때문)
    - 가독성이 떨어짐으로 적당히 사용해야 함

<br>

- ```void``` : 반환값이 없다. 즉 return이 없다. main함수 매개변수 안에 void가 있으면 공백을 뜻한다.

<br>

- ```static``` : 데이터 영역에 메모리를 올린다.

<br>

- ```new``` : new 연산자는 힙 영역에 데이터 값을 만든다. new 데이터 뒤에 선언한 데이터 타입의 형태를 만든다.

<br>

# 2. GetTickCount

컴퓨터를 부팅하면 컴퓨터 자체적으로 Tick이 발생한다. GetTickCount는 Tick값을 반환한다. <br>

밀리 세컨드(ms) : 1/1000, 1초당 1000 Tick (현실에서 1초는 컴퓨터에서 1000 Tick) <br>

- GetTickCount() : 32bit, 대략 49일 7시간정도 카운트가 계산된다. 이후에는 Overflow가 발생하면서 카운트가 초기화된다. <br>

- GetTickCount64() : 64bit, 대략 5억년까지 계산가능. <br>

```c++
auto TIME = GetTickCount64();

while (true) 
{
    // 1000 tick이 너무 빨리 업데이트 되니까 tick count를 제한시킨다.
    // 50tick 이 진행되면 게임에서 한 번 업데이트한다.
    if(TIME + 50 < GetTickCount64())
    {
        TIME = GetTickCount64();
        system("cls");  // 콘솔화면 지우기
        main.Update();
        main.Render();
    }
}
```

<br>

# 3. 헤더 파일

- ```#pragma once``` : 헤더 파일의 중복 선언을 막아준다. <br>
- ```#include <stdio.h>``` : <> 를 사용하는 경우는 기본 제공 라이브러리일 때
- ```#include "Headers.h"``` : 프로젝트 내부에 있는 라이브러리

<br>

# 4. 함수 실행순서 및 단축키

- 인라인 함수 : 데이터 영역에 먼저 올라간다. 프로젝트를 실행할 때 제일 먼저 실행된다. 헤터 파일에서 만든 함수는 인라인 함수이다. <br>

- 단축키
    - Alt + 방향키 : 한 줄 이동
    - Ctrl + D : 한 줄 복사
    - Ctrl + . : 헤더 파일에서 사용한 함수를 드래그한 후 사용하면, cpp파일에 함수 정의

<br>

# 5. Singletone

인스턴스 생성을 한번만 한 후 이후에 다시 호출했을 때 힙 영역에 올라간 객체(인스턴스)를 포인터를 통해 호출한다. <br>

```c++
private:
	static SceneManager* Instance;

public:
	// 포인터 형식의 반환값을 사용해주겠다.
	// hip 영역에 있는 반환값을 리턴하겠다.
	// new 연산자는 hip 영역에 데이터 값을 만든다. new 데이터 뒤에 선언한 데이터 타입의 형태를 만든다.
	// 포인터형 변수는 hip 영역에 있는 데이터의 주소값을 받아온다.
	static SceneManager* GetInstance() 
	{
		if(Instance == nullptr)
		{
			Instance = new SceneManager;
		}
		return Instance;
	}
```

<br>

# 6. virtual

가상함수 : 자식함수에서 부모 클래스에 있는 함수를 변형시켜서 사용가능하게 해준다. <br>
- PURE : 순수 가상함수, 상속 받은 클래스에서 수정한다는 의미 <br>
ex) ```virtual void Initialize()PURE;``` <br>
    - 의의 : 함수를 선언하면 함수 선언만큼의 메모리를 잡아먹는다. 그래서 안에 비어있던 아니던 간에 최소한의 메모리를 사용한다. PURE를 사용하면 동일한 함수에 대한 메모리를 아낄 수 있다.

- override: 가상함수를 덮어씌우겠다는 의미
- 오버로드(연산자가 존재하지 않음) : 똑같은 이름의 함수라도 반환값 또는 매개변수가 달라지면 선택해서 호출 가능, 좌표에서 많이 사용

```c++
// 1.
void a()
{
}

// 2.
void a(int a)
{
	int i;
}

int main(void)
{
    // 오버로드 1
    a();

    // 오버로드 2
    a(3);
}
```

<br>

# 7. 캡슐화, 클래스와 구조체의 차이

- private : 지금 class만 사용가능, 다른 클래스는 사용불가, 보안성이 제일 뛰어남, 
기본적으로 캡슐화를 안해주면 private
- protected : 상속받은 class 까지만 사용가능, 정보를 많이 넣음(개인정보)
- public : 모든 클래스, 함수에서 접근가능

```c++
// 다른 함수에서 private로 캡슐화한 변수를 수정하는 방법
class D 
{
private:
	int num;
protected:
public:
	int getNum() 
	{
		return num;
	}
	void setNum(int i) 
	{
		num = i;
	}
};

int main(void)
{
    D d; // 인스턴스 생성
    d.setNum(3); // setNum 함수를 통해 private 로 선언된 변수를 수정
    d.getNum(); //getNum 함수를 통해 private 로 선언된 변수를 불러온다.
}
```

<br>

- 구조체와 클래스의 차이점
    - 기본적인 기능은 차이가 없다.
    - 클래스와 달리 기본값이 ```public```으로 설정된다. 클래스는 기본값이 ```private```
    - struct가 자료전달속도가 미세하게 빠름, but 둘 다 차이가 없음, 가급적이면 ```class```를 사용