#include <stdio.h>

// 작성자: 양사무엘
// 작성일: 2026-09-28
// 공부 내용: 배열의 이해와 선언 및 초기화 방법


// [배열이란?]
// 연속된 메모리 위치에 동일한 타입의 데이터를 고정된 크기만큼 보유하는 자료구조이다.

// [C에서 배열은]
// 배열의 이름은 포인터이다. 단 그 값을 바꿀 수 없는 '상수 형태의 포인터'이다.
// 포인터처럼 이름이 존재하고 메모리의 주소 값을 저장하지만 주소값의 변경은 불가능하다.
void CanChangeArrayPointer(void)
{
    int arr1[5];
    int arr2[5];

    printf("%p\n", &arr1);
    printf("%p\n", &arr1[0]); // &arr1과 주소 값이 같다!
    printf("%p\n", &arr1[1]); // &arr1[0]에서 4만큼(int크기)떨어진 위치이다.

    // arr1 = &arr2[0]; // 컴파일 에러!
}

int main(void)
{
    CanChangeArrayPointer();
    return 0;
}