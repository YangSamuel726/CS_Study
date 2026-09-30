#include <stdio.h>

// 작성자: 양사무엘
// 작성일: 2026-09-24
// 공부 내용: 열혈 C 프로그래밍 248p에 있는 도전프로그래밍 문제 풀기


// Problem01
// 10진수 정수를 입력 받아서 16진수로 출력하는 프로그램을 작성해 보자.
// Hint : 서식문자를 활용하자.
void DecimalToHexa()
{
    int num;
    scanf("%d", &num);
    printf("%x", num);
}

// Problem02
// 프로그램 사용자로부터 두 개의 정수를 입력 받아서 구구단을 출력하는 프로그램을 작성해 보자.
// 사용자는 입력 순서에 자유로워야 한다. 3,5를 하든 5,3을 하든 3~5단의 구구단이 출력되어야 한다.
void MultiplicationTable()
{
    int num1, num2;
    printf("정수 2개를 입력해 주세요!");
    scanf("%d %d", &num1, &num2);
    if(num1 > num2)
    {
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }

    for(int i = num1; i <= num2; i++)
    {
        printf("[구구단 %d단]\n", i);
        for(int j = 1; j <= 9; j++)
        {
            printf("%dX%d=%d\n", i, j, i*j);
        }
        printf("\n");
    }
}

// Problem03
// 두 개의 정수를 입력 받아서 최대 공약수(GCD)를 구하는 프로그램을 작성 해 보자.
int GetGDC(int num1, int num2)
{
    if(num1 % num2 == 0) return num2;
    else return GetGDC(num2, num1 % num2);
}

void GDCProblem()
{
    int num1, num2;
    scanf("%d %d", &num1, &num2);
    printf("두 수의 최대공약수 : %d", GetGDC(num1, num2));
}

// Problem04
// 현재 5천원이 있다. DVD한편을 빌리면 3,500원이 남고 슈퍼에 들려서 크림빵(500원), 새우깡(700원), 콜라(400원)를 사려한다. 잔돈을 하나도 남기지 않고 이 세가지 물건을 하나 이상 반드시 구매하려면 어떻게 구매를 진행해야 하는가?
void Problem04(void)
{
    int money = 3500;

    // 빵이 1개 이상에서 돈에 과자와 음료를 제외한 돈보다 적으면 실행
    for (int bread = 1; bread * 500 <= money - 700 - 400; bread++)
    {
        for (int snack = 1; bread * 500 + snack * 700 <= money - 400; snack++)
        {
            int remaining = money - bread * 500 - snack * 700;

            if (remaining % 400 == 0)
            {
                printf("크림빵%d개, 새우깡%d개, 콜라%d개\n",
                       bread, snack, remaining / 400);
            }
        }
    }
}

// Problem05
// 10개의 소수를 출력하는 프로그램을 작성해보자.
bool IsPrimeNumber(int num)
{
    if(num < 2) return false;
    for(int divisor = 2; divisor <= num/divisor; divisor++)
    {
        if(num % divisor == 0) return false;
    }
    return true;
}

void Problem05()
{
    int num1, count;
    count = 0;
    printf("소수 몇 개를 출력할까요?");
    scanf("%d", &num1);
    for(int i = 1; count < num1; i++)
    {
        if(IsPrimeNumber(i)) 
        {
            printf("%d ", i);
            count++;
        }
    }
}

// Problem06
// 사용자로부터 초(second)를 입력 받은 후에, 이를 [시, 분, 초]의 형태로 출력하는 프로그램을 작성해보자.
void Problem06()
{
    int num;
    scanf("%d", &num);
    int hour = num / 3600;
    int minute = num % 3600 / 60;
    int second = num % 60;
    printf("h:%d, m:%d, s:%d", hour, minute, second);
}

// Problem07
// 프로그램 사용자로부터 숫자 n을 입력 받는다. 그리고 나서 다음 공식이 성립하는 k의 최댓값을 계산해서 출력하는 프로그램을 작성해보자
// 2^k <= n
void Problem07()
{
    int num;
    printf("상수 n 입력 : ");
    scanf("%d", &num);

    // for(int k = 0; ; k++)
    // {
    //     if(1<<k > num) 
    //     {
    //         printf("공식을 만족하는 k의 최댓값은 %d", k-1); 
    //         break;
    //     }
    // }

    int k = 0;

    while (num >= 2)
    {
        num /= 2;
        k++;
    }

    printf("공식을 만족하는 k의 최댓값은 %d\n", k);
}

// Problem08
// 2의 n승을 구하는 함수를 재귀적으로 구현해보자.
void Problem08()
{
    int num;
    scanf("%d", &num);
    long long result = 1LL<<num;
    printf("2의 %d승은 %lld", num, result);
}


int main(void)
{
    Problem08();
    return 0;
}