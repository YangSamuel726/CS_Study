#include <stdio.h>

// 작성자: 양사무엘
// 작성일: 2026-09-28
// 공부 내용: 포인터의 이해

void Example01()
{
    int num = 5;
    int* pnum1 = &num;
    int** pnum2 = &pnum1;
    printf("%d %d", *pnum1, **pnum2);
}

void Example02()
{
    int num =10;
    int* ptr1 = &num;
    int* ptr2 = ptr1;

    printf("%p\n", ptr1);
    printf("%d\n", *ptr1);
    (*ptr1)++;
    printf("%p\n", ptr1);
    printf("%d\n", *ptr1);
    *ptr2++;
    printf("%d \n", num);
}

void Example03()
{
    int num = 20;
    printf("%d", *&*&*&*&*&*&num);
}

void Example04()
{
    double num = 3.14;
    int* pnum = &num; // 컴파일 에러!
    printf("%d", *pnum); // 예측 불가능한 의미 없는 출력
}

int main(void)
{
    Example04();
    return 0;
}

// [포인터 변수란?]
// 어떤 대상을 가리키는 주소(포인터 값)를 저장하는 변수이다.
// 객체 포인터는 특정 타입의 객체(변수, 배열 원소 등)를
// 가리키는 데 사용한다.
// 예: int* pnum; → int를 가리키는 포인터 변수 pnum 선언

// 다양한 포인터형이 존재하는 이유는 타입이 '*'연산자를 통해 메모리 공간을 참조하는 기준이 되기 때문이다.

// [선언에서의 *]
// 선언한 변수가 포인터 타입임을 나타낸다.
// 이때의 *는 역참조 연산을 수행하는 것이 아니다.

// [표현식에서의 * : 역참조 연산자]
// 포인터가 가리키는 메모리 공간에 접근할 때 사용하는 연산자이다.
// 이를 통해 대상의 값을 읽거나 수정할 수 있다.
// 예: int value = *pnum;
// 예: *pnum = 20;
// 단, 실제 접근 시에는 유효한 대상을 가리켜야 한다.

// [& : 주소 연산자]
// 피연산자의 주소 값을 반환하는 연산자이다. 이때 피연산자는 상수가 아닌 변수여야 한다. 대상의 주소를 나타내는 포인터 값을 얻는다.
// 예: pnum = &num;