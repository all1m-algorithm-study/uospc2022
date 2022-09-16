# 피보나치 EASY

## 문제

(이 문제는 Easy Version 으로, Hard Version과 n의 범위만 다릅니다.)

두 자연수 n, x 가 주어질 때, 정확히 n개의 피보나치 수열의 항의 합으로 x를 만들 수 있는지 판별하라. 이때 피보나치 수열의 항을 중복하여 선택할 수 있다.

피보나치 수열이란, F1 = F2 = 1, Fn = F(n-1) + F(n-2) 로 정의되는 수열이다.

## 입력

첫째 줄에 테스트케이스의 수 T가 주어진다. (1 <= T <= 100)

이후 T개의 줄에 피보나치 항의 개수 n과 만들고자 하는 자연수 x가 주어진다. (1 <= n <= 3, 1 <= x <= 1e16)

## 출력

T개 줄에 걸쳐 문제에 대한 해답을 출력한다.

만들 수 있다면 YES, 만들 수 없다면 NO를 출력하라

## 예제 입력 1

```
2
3 12
1 4
```

## 예제 출력 1

```
YES
NO
```