#include "Headers.h"
#include "MainUpate.h"

// ����ü�� Ŭ���� ����
// �⺻���� ����� ���̰� ���� ����.
// ������ : class�� �޸� �⺻���� public���� �����ȴ�.
// struct�� �ڷ����޼ӵ��� �̼��ϰ� ����, but �� �� ���̰� ����

//struct A
//{
//private:
//	int num;
//public:
//protected:
//};

// void return�� ���� �ʿ䰡 ����. ��ȯ�� �����شٴ� �� 

// private : ���� class�� ��밡��, �ٸ� Ŭ������ ���Ұ�, ���ȼ��� ���� �پ, 
// �⺻������ ĸ��ȭ�� �����ָ� private
// protected : ��ӹ��� class ������ ��밡��, ������ ���� ����(��������)
// public : ��� Ŭ����, �Լ����� ���ٰ���

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

// �Ȱ��� �̸��� �Լ��� ��ȯ�� �Ǵ� �Ű������� �޶����� �����ؼ� ȣ�� ����, ��ǥ���� ���� ���
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
	// GetTickCount(32bit), GetTickCount64 : ��ǻ�Ͱ� ������ �Ǹ鼭 ��ü������ tick�� �߻�, 
	// 1�ʿ� 1000 tick, �и� ������(ms): 1/1000 (�ܺο��� 1�� ������ ��ǻ�Ϳ��� 1000 tick�� ����)
	// 49�� 7�ð� ���� tick ī��Ʈ�� ����Ѵ�. ���Ŀ��� overflow�� �Ͼ�鼭 ī��Ʈ �ʱ�ȭ
	// GetTickCount64�� 5������ ��갡��
	// GetTickCount�� �� tick�� ��ȯ�Ѵ�.
	// system("cls"); �ܼ�ȭ�� �����

	// ��ǻ�͸� Ų �ð� ��ȯ
	auto TIME = GetTickCount64();
	MainUpate main;

	main.Initialize();

	while (true) 
	{
		// 1000 tick�� �ʹ� ���� ������Ʈ �Ǵϱ� tick count�� ���ѽ�Ų��.
		// 50tick �� ����Ǹ� ���ӿ��� �� �� ������Ʈ�Ѵ�.
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