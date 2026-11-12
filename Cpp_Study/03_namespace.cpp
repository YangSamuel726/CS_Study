#include <iostream>

// 작성자: 양사무엘
// 작성일: 2026-11-11
// 공부 내용: 이름공간(namespace)

// [네임스페이스의 역할]
// 성격이나 하는 일이 비슷한 클래스, 구조체, 함수 등을 하나의 이름 아래 묶어주는 역할이다.

// 서로 다른 팀에서 작업을 했는데 서로 같은 이름의 클래스, 함수 등이 나온다면 이를 다시 다 바꿔야 하는 번거로움이 생긴다.
// 프로젝트의 규모가 클수록 이러한 것은 불가피하고 더욱 일이 커지게 되는데 이를 namespace가 해결해준다.
namespace InGame
{
    void Play(void);
}

namespace Audio
{
    void Play(void);
}

int main()
{
    InGame::Play();
    Audio::Play();
    return 0;
}

void InGame::Play(void)
{

}

void Audio::Play()
{
    
}

// '::'연산자를 가리켜 '범위지정 연산자'라고 하며, 네임스페이스, 클래스, 열거형, 전역범위 등 범위를 지정할 때 사용하는 연산자이다.