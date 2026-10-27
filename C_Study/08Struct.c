#include <stdio.h>

// 작성자: 양사무엘
// 작성일: 2026-10-27
// 공부 내용: 구조체의 이해

// [구조체란?]
// 하나 이상의 변수를 묶어서 새로운 자료형을 정의하는 도구이다.

// [왜 필요한가?]
// 관련된 여러 데이터를 하나의 단위로 묶어서 관리하기 쉽게 만들기 위해 필요하다.

// [어떻게 만들고 사용하는가?]
// 다음과 같이 만든다.
struct structName
{
    int var1;
    char var2;
};

// 사용은 다음과 같이 한다.
struct structName varName; // 구조체 변수선언의 기본 형태
// struct를 맨앞에 선언하고 이어서 구조체의 이름과 구조체 변수의 이름을 선언해야 한다.

// 구조체 내부 변수에 접근은 다음과 같이 한다.
// (구조체 변수의 이름).(구조체 멤버의 이름)
// 예를 들어 StructName의 int 변수에 접근한고 싶다면
// varName.var1 = 20; 처럼 한다.


// 구조체 변수를 가리키는 포인터는 어떨까?
// 다른 기본 자료형 포인터와 같다.
void Example(void)
{
    int num = 10;
    int * pnum = &num;
    *pnum = 20;

    // 위의 선언과 할당처럼 구조체도 포인터가 가리키고 역참조를 할 수 있다.
    struct structName sName;
    struct structName * pSName = &sName;
    (*pSName).var1 = 20;

    // 위의 역참조와 접근 연산자를 줄여서 `->` 연산으로 표현할 수 있다.
    pSName->var1 = 30;
}

// typedef를 통해 구조체 변수 선언시 struct 선언을 생략할 수 있다.
// 위의 structName을 typedef로 선언해보겠다.
typedef struct structName StructName;
// 이제 StructName이 struct structName을 대신할 수 있게 되었다.
StructName varName2;

// 또 구조체를 정의할 때 typedef 선언을 한데 묶을 수 있다. 또 이것이 일반적인 방법이다.
typedef struct someStruct
{
    int var1;
} SomeStruct;

// typedef 선언과 구조체의 정의를 한번에 할 시 구조체의 이름을 생략할 수도 있다.
typedef struct
{
    int var1;
} SomeStruct2;
// 이렇게 선언하면 구조체 변수를 구조체의 이름으로 선언할 수 없게되고 typedef에 의해 정의된 이름 SomeStruct2를 사용해야 한다.
SomeStruct2 varSome2;

int main(void)
{
    
    return 0;
}