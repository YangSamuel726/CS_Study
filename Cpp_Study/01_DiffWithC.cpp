#include <iostream>

// 작성자: 양사무엘
// 작성일: 2026-11-11
// 공부 내용: C와의 차이점 1

// [printf와 scanf를 대신하는 입출력 방식]
// 기존의 stdio.h에서 iostream으로 입출력 헤더가 변경되었음
// 'std::cout'를 통해 출력을 하며 '<<' 연산자를 통해 추가 출력이 가능함
// 'std::endl'은 개행문자임
void Example()
{
    int num = 20;
    std::cout<<"Hello World!"<<std::endl;
    std::cout<<"Hello "<<"World!"<<std::endl;
    std::cout<<num<<' '<<'A';
    std::cout<<' '<<3.14<<std::endl<<"아 ㅋㅋ";
}

// 'std::cin'을 통해 입력을 받으며 '>>' 연산자를 통해 입력을 변수에 할당함
void Example2()
{
    int val1;
    std::cout<<"첫 번째 숫자 입력: ";
    std::cin>>val1;

    int val2;
    std::cout<<"두 번째 숫자 입력: ";
    std::cin>>val2;

    int result = val1+val2;
    std::cout<<"덧셈결과: "<<result<<std::endl;
}

// [지역변수 선언]
// C에서는 함수를 정의함에 있어서 지역변수의 선언이 항상 앞에 와야 했으나(지금은 또)
// C++의 지역변수 선언은 함수 내 어디든 삽입이 가능하다.
void Example3()
{
    int val1, val2;
    int result=0;
    std::cout<<"두 개의 숫자입력: ";
    std::cin>>val1>>val2; // 연속적인 입력 요구 가능 

    std::cout<<val1<<' '<<val2<<std::endl;

    if(val1<val2)
    {
        for(int i = val1 + 1; i < val2; i++)
        {
            result +=i;
        }
    }
    else
    {
        for(int i = val2 + 1; i < val1; i++)
        {
            result +=i;
        }
    }

    std::cout<<"두 수 사이의 정수 합: "<<result<<std::endl;
}

// 미리 선언하는 것은 C와 같지만 디폴트 값을 설정할 수 있다.
int MyFunc(int num = 5, int i = 6);
#define SOME(x) x * x

int main()
{
    std::cout<<SOME(2)<<std::endl;
    return 0;
}


int MyFunc(int num, int i)
{
    return num + i;
}