# 출제자를 위한 디렉토리 관리 방법

본 `problems` 디렉토리는 출제되는 모든 문제들의 지문과 테스트케이스를 관리합니다.

여러 사람들이 하나의 리포지토리에 각자의 문제들을 규칙없이 작성하면 일관성이 떨어지고 자동화가 어려워질 수 있습니다.

따라서 이 문서에서는 각 문제의 데이터를 효율적으로 관리하기 위해 지켜야 할 파일 관리 규칙을 서술합니다.

## 디렉토리 구조

`problems` 모든 문제의 데이터를 저장하는 최상위 디렉토리입니다. 출제자분들은 이 디렉토리에 **문제 ID(ASCII 문자열)를 제목으로 하는 하위 디렉토리**를 생성하고, 그 디렉토리에서 작업을 하시면 됩니다.

동일한 문제를 서로 다른 사람이 동시에 수정하면 나중에 Merge할 때 컨플릭트가 발생하는 등 골치아픈 일이 발생할 수 있으므로, **가급적이면 자신이 출제하는 문제의 디렉토리만 수정**하여 **Pull Request**를 보내는 것이 좋습니다.

예를 들어, UOSPC 2021에서는 각 문제들을 아래와 같이 디렉토리를 나누어 관리하였습니다.

```
problems
├── Parentheses_Flip
├── Police_Thief
├── broadcast-small
├── bulb-easy
├── bulb-hard
├── givememoney
├── library
├── mayday
├── mobile
├── stack-queue
├── str-queue
├── teamfestival
└── workout
```

### 문제별 디렉토리 구조

각 문제 디렉토리에는 1개의 마크다운(.md) 파일과 3~4개의 폴더가 있을 수 있습니다.

* `statements.md`: 문제 지문을 담고 있는 마크다운 파일입니다. 제목, 문제 설명, 입력 형식, 출력 형식, 예제 입출력을 포함하고 있어야 하며, 필요시 LaTeX 형식의 수식과 이미지를 포함할 수 있습니다.
    * `$`로 감싸 작성하는 LaTeX 수식은 GitHub와 DMOJ에서 모두 지원하므로 마음껏 사용하셔도 좋습니다. 
    * 이미지를 불러올 때는 `images` 디렉토리에 실제 이미지를 넣고 이 이미지를 상대경로로 참조하시기 바랍니다.
    * 문서 형식이 엄격하게 제한되어있진 않으나 가능하면 아래와 같은 형식을 따라주시기 바랍니다.
    ```
    # 문제 제목 A+B

    ## 문제

    <문제 설명> 두 개의 정수 $A$, $B$가 주어졌을 때, $A+B$를 계산하는 프로그램을 작성하시오.

    ## 입력

    <입력 형식 설명> 첫째 줄에 두 개의 정수 $A$, $B$가 공백으로 구분되어 주어진다. $(1 \leq A, B \leq 100)$

    ## 출력

    <출력 형식 설명> 첫째 줄에 $A+B$의 값을 출력한다.

    ## 예제 입력 1

    <예제 입력을 Code Block으로 감싸 작성>

    ## 예제 출력 1

    <예제 출력을 Code Block으로 감싸 작성>
    ```
* `images` (optional): `statements.md`에서 사용하는 이미지들을 담는 디렉토리입니다.
* `sources`: 문제의 정답 코드뿐만 아니라 의도적으로 틀리게(WA, TLE, MLE) 작성된 코드들을 정리합니다. 여기에 작성된 코드는 Polygon 시스템에서 테스트케이스 실행 및 스트레스 테스트에 이용될 수 있습니다.
* `generators`: 대회에 사용될 테스트케이스를 생성하는 코드를 저장합니다.
    * 단순히 랜덤한 테스트데이터만 생성하는 것으로는 부족하고, 엣지케이스나 특수한 케이스를 생성하는 생성기도 마련하시는 것을 권장합니다.
    * **생성기의 코드는 Mike Mirzayanov의 [testlib.h](https://github.com/MikeMirzayanov/testlib/blob/master/testlib.h)를 include하여 작성하셔야 합니다.**
        * https://github.com/MikeMirzayanov/testlib
* `testcases` (optional, 출제자가 직접 관리할 필요는 없음): Polygon 플랫폼에서 생성된 테스트데이터를 저장하는 디렉토리로 입력 데이터(ex. `01`)와 출력 데이터(ex. `01.a`)가 한 쌍을 이룹니다.
    * 보통 테스트데이터 생성은 Polygon에서 진행하고, 데이터를 강화하면서 자주 변하기도 하므로 출제자가 이를 직접 관리하지는 않아도 됩니다.
    * 대회 준비 후반기에 테스트데이터 작성이 거의 마무리되었을 때, Polygon에서 전체 패키지를 내려받아 한번에 커밋하는 것도 좋습니다.

위 구조의 한 예시로 UOSPC 2021의 브로드캐스트 네트워크 문제의 디렉토리 구조를 첨부합니다.

```
broadcast-small
├── generators
│   ├── gen-dense.cpp
│   ├── gen-random.cpp
│   ├── gen-tree.cpp
│   └── testlib.h
├── images
│   ├── broadcast-1.png
│   └── broadcast-2.png
├── sources
│   ├── matrix-power.cpp
│   └── naive-dp.cpp
├── statements.md
└── testcases
    ├── 01
    ├── 01.a
    ├── 02
    ├── 02.a
    ...
    ├── 33
    └── 33.a
```

## 참고

* UOSPC 2021의 예시: https://github.com/all1m-algorithm-study/uospc2021/tree/main/problems
    * 브로드캐스트 네트워크: https://github.com/all1m-algorithm-study/uospc2021/tree/main/problems/broadcast-small
