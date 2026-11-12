#include <iostream>

// 작성자: 양사무엘
// 작성일: 2026-11-12
// 공부 내용: OOP 프로젝트 1단계

// 구현 목표 : 은행계좌 관리 프로그램
// - 통장의 계좌번호는 중복되지 아니한다. (중복검사 하지 않겠다는 뜻)
// - 입금 및 출금액은 무조건 0보다 크다. (입금 및 출금액의 오류검사 않겠다는 뜻)
// - 고객의 계좌정보는 계좌번호, 고객이름, 고객의 잔액, 이렇게 3가지만 저장 및 관리한다.
// - 둘 이상의 고객 정보 저장을 위해서 배열을 사용한다.
// - 계좌번호는 정수의 형태이다.

const int NAME_LEN = 20;



class Customer
{
public:
    char _name[NAME_LEN];
    int _accountNum;
    int _accountMoney;

public:
    Customer(const char* name, int accountNum, int accountMoney)
    {
        std::snprintf(_name, sizeof(_name), "%s", name);
        _accountNum = accountNum;
        _accountMoney = accountMoney;
    }

    void PrintCustomerInfo()
    {
        std::cout<<"계좌 ID : "<<_accountNum<<std::endl;
        std::cout<<"고객 성함 : "<<_name<<std::endl;
        std::cout<<"계좌 잔액 : "<<_accountMoney<<std::endl;
    }
};

Customer * customerArr[100];
int accountID = 0;

void PrintMenu(void)
{
    std::cout<<"-----Menu-----"<<std::endl;
    std::cout<<"1. 계좌 개설"<<std::endl;
    std::cout<<"2. 입금"<<std::endl;
    std::cout<<"3. 출금"<<std::endl;
    std::cout<<"4. 계좌정보 전체 출력"<<std::endl;
    std::cout<<"5. 프로그램 종료"<<std::endl;
    std::cout<<"입력 : ";
}

void MakeAccount()
{
    std::cout<<"-----MakeAccount-----"<<std::endl;
    std::cout<<"이름을 입력해주세요 : ";
    char name[NAME_LEN];
    std::cin>>name;
    Customer * customerPtr = new Customer (name, accountID, 0);
    customerArr[accountID] = customerPtr;
    accountID++;
}

void InMoney()
{
    std::cout<<"-----입금-----"<<std::endl;
    std::cout<<"계좌번호를 입력해주세요 : ";
    int accountNum;
    std::cin>>accountNum;
    std::cout<<"넣을 금액을 입력해 주세요 : ";
    int inputMoney;
    std::cin>>inputMoney;
    for(int i = 0; i < accountID; i++)
    {
        Customer * customer = customerArr[i];
        if(customer->_accountNum == accountNum)
        {
            customer->_accountMoney += inputMoney;
            break;
        }
    }
}

int main()
{
    while(1)
    {
        PrintMenu();
        int input =0;
        std::cin>>input;

        switch(input)
        {
            case 1: MakeAccount(); break;
            case 2: InMoney(); break;
            case 3: break;
            case 4: break;
            case 5: return 0;
            default: break;
        }
    }
}