#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int N;
    scanf("%d", &N);

    int T[16], P[16];
    int dp[18] = {0};  // dp[i]: i번째 날부터 얻을 수 있는 최대 수익

    for (int i = 1; i <= N; i++) {
        scanf("%d %d", &T[i], &P[i]);
    }

    // 뒤에서부터 계산
    for (int i = N; i >= 1; i--) {
        if (i + T[i] <= N + 1) {// 퇴사 전까지 일 할 수 있는 상황이라면
            dp[i] = max(dp[i + 1], P[i] + dp[i + T[i]]); //내일 일하는것 OR 오늘부터 일을 시작 하는것중 뭐가더 수익이 큰지 비교후 최대 수익 저장
        } else {
            dp[i] = dp[i + 1]; //퇴사 후까지 일해야하는 상황이 오니까, 내일 일을 수행하자
        }
    }

    printf("%d\n", dp[1]);
    return 0;
}

/*
이 문제가 dp인 이유
-내일일(과거)를 미리 계산해두고, 뒤에서 앞으로 가면서 과거에 저장해둔 데이터를 꺼내서 사용하기 때문이다.
최대 수익을 구하는건데, 쫌쫌따리 계속 계산해서 결과를 만들어 낸다.
*/
