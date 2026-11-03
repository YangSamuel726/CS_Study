// 작성자 : 양사무엘
// 작성일자 : 2026-10-30
// 공부 주제 : using 키워드
// 목표 : using 키워드의 정의와 이해

// > [!Note]
// > 박상현 저자의 『이것이 C#이다』를 바탕으로 학습하고, 이해한 내용을 제 말로 정리한 글입니다.\
// > 설명에 오류가 있을 수 있습니다. 잘못된 내용이나 보완할 점을 알려 주시면 확인 후 수정하겠습니다. :)

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