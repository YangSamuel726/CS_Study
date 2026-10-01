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
    // double num = 3.14;
    // int* pnum = &num; // 컴파일 에러!
    // printf("%d", *pnum); // 예측 불가능한 의미 없는 출력
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
// 해당 변수의 값을 가지고 주소에 접근한다.
// 이를 통해 대상의 값을 읽거나 수정할 수 있다.
// 예: int value = *pnum;
// 예: *pnum = 20;
// 단, 실제 접근 시에는 유효한 대상을 가리켜야 한다.

// [& : 주소 연산자]
// 피연산자의 주소 값을 반환하는 연산자이다. &는 주소를 취할 수 있는 객체나 함수의 주소를 구하는 연산자이다.
// 예: pnum = &num;
// const 객체의 주소도 구할 수 있지만, 리터럴에 &10처럼 사용할 수는 없다.

// [포인터 연산]
// 포인터 변수를 대상으로 증감연산을 수행할 수 있다.
// 포인터에 +1을 할 경우 가리키는 자료형의 크기만큼 주소값이 커지는 것을 확인할 수 있다.
void Example05(void)
{
    int num = 10;
    int* pnum = &num;

    printf("%p\n", &num); // 000000F6EAFFFAF4
    printf("%p\n", pnum); // 000000F6EAFFFAF4, num 주소 값을 출력
    printf("%p\n", pnum+1); // 000000F6EAFFFAF8, num 주소에서 int크기(4)만큼 더해진 주소 출력
}
// 즉 포인터를 대상으로 n의 크기만큼 증가하거나 감소하면 (주소값) + n * sizeof(자료형)만큼 증감하는 것이다.

// 이러한 연산특성으로 인해 배열에서 다음과 같은 접근이 가능하다. 
void Example06(void)
{
    int arr[3] = {11, 22, 33};
    int* ptr = arr; // int* ptr = &arr[0]; 과 같은 문장

    printf("%d %d %d \n", *ptr, *(ptr+1), *(ptr+2)); // 11 22 33 출력

    printf("%d ", *ptr); ptr++; // 11출력
    printf("%d ", *ptr); ptr++; // 22출력
    printf("%d ", *ptr); ptr--; // 33출력
    printf("%d ", *ptr); ptr--; // 22출력
    printf("%d ", *ptr); // 11출력

    // arr[i] == *(arr+i)
}

// 문자를 가리키는 포인터 변수 배열
void Example07(void)
{
    char* strArr[3] = {"Simple", "String", "Array"};
    printf("%s\n", strArr[0]); // Simple 출력
    printf("%s\n", strArr[1]); // String 출력
    printf("%s\n", strArr[2]); // Array 출력

    *(strArr[0]) = 'X'; // 문자열 리터럴을 수정하려는 시도: 정의되지 않은 동작
    printf("%s\n", strArr[0]); // Simple 출력
}

// [Trouble01] : (*pnum)++과 *pnum++의 차이
void Trouble01(void)
{
    int num1 = 10;
    int* pnum1 = &num1;
    int num2 = 10;
    int* pnum2 = &num2;

    printf("%p %p \n", pnum1, pnum2);

    *pnum1++;
    (*pnum2)++;

    printf("%p %d \n", pnum1, *pnum1); // 주소값이 4(int 크기)증가했고 값은 쓰레기 값이 나옴
    printf("%p %d \n", pnum2, *pnum2); // 주소값이 이전과 동일하고 값이 11로 증가

    // *pnum++; // pnum이 가리키는 메모리 주소에 접근한 다음에 pnum에 저장된 주소 값 증가시킴
    // (*pnum)++; // pnum이 가리키는 메모리 주소에 접근한 다음에 해당 값을 증가시킴
}


int main(void)
{
    Trouble01();
    return 0;
}