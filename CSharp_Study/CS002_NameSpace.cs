using System;
using Game;
using Audio;
using System.Runtime.InteropServices;

// 작성자 : 양사무엘
// 작성일자 : 2026-10-30
// 공부 주제 : namespace 키워드
// 목표 : namespace의 정의와 이해

// [namespace란?]
// 네임스페이스는 성격이나 하는 일이 비슷한 클래스, 구조체, 인터페이스, 대리자, 열거 형식 등을 하나의 이름 아래 묶는 일을 한다.


// 네임스페이스라는 소속 공간에 따라서 변수나 함수가 같은 이름임에도 다른 식으로 구분이 될 수 있다.
// 예를 들어 게임을 플레이하는 Player와 오디오를 재생하는 Player라는 이름을 같이 사용하고 싶다면 둘의 namespace를 통해 소속을 정해주어 분류해 줄 수 있다.
namespace Game
{
    public class Player { }
}
namespace Audio
{
    public class Player { }
}

class CS002_NameSpace
{
    static void Main()
    {
        // using을 통해 두 네임스페이스를 사용하여 Player를 사용할 수 있게 되었다. 그러나
        // Player player = new Player();
        // Player player2 = new Player();
        // 이렇게 선언하면 Game과 Audio중에 어떤 Player를 말하는 것인지 헷갈리기 때문에(컴파일러가 오류도 낸다.)
        // namespace를 사용하여 소속을 확실히 하여 해결할 수 있다.
        Game.Player player1 = new Game.Player();
        Audio.Player player2 = new Audio.Player();

        string asdf = new string("asdf");
        string hdh = "";
    }
}

// 어떻게 보면 namespace도 하나의 객체가 아닌가 생각한다.