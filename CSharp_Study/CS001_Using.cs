// 작성자 : 양사무엘
// 작성일자 : 2026-10-30
// 공부 주제 : using 키워드
// 목표 : using 키워드의 정의와 이해


// # using 이란?
// `using`은 C#의 키워드이고, 사용되는 위치에 따라 다른 의미를 가진다.
//   - 이름을 사용하는 방법을 지정하는 용도
//   - 자원의 정리를 보장하는 용도

// ## 이름을 사용하는 방법을 지정하는 용도
// using 다음에 다른 네임스페이스를 붙여 정의된 형식을 가져올 수 있다.
using System;

// 혹은 네임스페이스에 대한 별칭을 생성할 수 있다.
using Sys = System;

// ## 자원의 정리를 보장하는 용도
// 표현식 안에서 using을 통해 특정 자원의 정리를 보장할 수 있다.
void UsingDispose()
{
    // using을 통해 관리되는 객체는 IDisposable을 반드시 구현해야 한다.
    using (var reader = new System.IO.StreamReader("data.txt"))
    {
        // 임의의 작업 내용

        // 블록 끝 : Dispose를 호출하지 않아도 using 키워드가 Dispose 실행을 보장해 줌
    }

    // 블록이 따로 없는 경우 선언이 속한 범위가 끝날 때 정리된다.
    using var reader2 = new System.IO.StreamReader("data2.txt");
}