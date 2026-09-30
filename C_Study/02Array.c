#include <stdio.h>

// 작성자: 양사무엘
// 작성일: 2026-09-28
// 공부 내용: 배열의 이해와 선언 및 초기화 방법

int main(void)
{
    char arr[5] = "char";
    arr[3] = 63;
    arr[4] = 64;
    printf("배열의 크기 : %d\n", sizeof(arr));
        printf("%s ", arr);
    
    return 0;
}