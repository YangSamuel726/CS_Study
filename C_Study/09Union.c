#include <stdio.h>

// 작성자: 양사무엘
// 작성일: 2026-10-27
// 공부 내용: Union의 정의와 이해


// [공용체(Union)이란?]
// 여러 형태의 데이터를 같은 공간으로 표현하는 자료형을 정의하는 도구

// [왜 필요한가?]
// 여러 종류의 데이터 중 하나만 필요할 때, 각각의 저장 공간을 모두 마련하지 않고 하나의 공간을 공유하기 위해 필요하다.
// 이는 다양한 접근방식을 제공한다.

// [어떻게 정의하고 선언하고 사용하는가?]
// 기본적으로 struct와 형태는 동일하다. struct키워드를 union으로 바꿔주면 된다.
typedef struct sbox
{
    int mem1;
    double mem2;
} SBox;

typedef union ubox
{
    int mem1;
    double mem2;
} UBox;

// 두 자료형을 변수로 선언해서 메모리 공간에 할당되는 값을 살펴보면 많은 차이가 있다.
void CheckSize(void)
{
    SBox somesbox;
    UBox someubox;

    // 16 8 출력
    printf("%zu %zu", sizeof(somesbox), sizeof(someubox));

    // Union은 제일 큰 변수의 크기를 출력하는 것을 볼 수 있다.
}

int main(void)
{
    CheckSize();
    return 0;
}