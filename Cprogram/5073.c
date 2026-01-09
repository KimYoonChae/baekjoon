#include <stdio.h>

int main() {
    int a, b, c;

    while (1) {
        // 1. 입력 먼저 받기
        scanf("%d %d %d", &a, &b, &c);

        // 2. 종료 조건 확인
        if (a == 0 && b == 0 && c == 0) break;

        // 3. 가장 긴 변(max) 찾기
        int max = a;
        if (b > max) max = b;
        if (c > max) max = c;

        int sum = a + b + c;

        // 4. 삼각형 성립 조건 확인 (나머지 합 <= max 이면 Invalid)
        if (sum - max <= max) {
            printf("Invalid\n");
        }
        // 5. 세 변의 길이에 따른 분류
        else if (a == b && b == c) {
            printf("Equilateral\n");
        }
        else if (a == b || b == c || a == c) {
            printf("Isosceles\n");
        }
        else {
            printf("Scalene\n");
        }
    }

    return 0;
}
