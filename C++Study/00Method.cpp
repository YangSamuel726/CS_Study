#include <stdio.h>

// 작성자: 양사무엘
// 작성일: 2026-09-24
// 공부 내용: 함수의 실행과 순서

int Add(int, int);
int ReadNum();
void Sum(int);
int staticNum = 0;



int main(int argc, char const *argv[])
{
    Sum(5); // 5
}

int Add(int num1, int num2)
{
    return num1+num2;
}

void Sum(int num)
{
    staticNum += num;
    printf("%d", staticNum);
}

int ReadNum(void)
{
    int num;
    scanf("%d", &num);
    return num;
}

// 컴파일러가 위에서부터 차례대로 코드를 확인하기 때문에 사용하려는 함수가 코드의 위치보다 낮게 위치해서는 안된다. 적어도 정의가 아래에 있으면 선언은 위에 있어야 한다.