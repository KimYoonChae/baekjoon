#include <iostream>
#include <vector>
using namespace std;

int N, M;
bool used[9];          // 숫자 사용 여부 (1~8)
vector<int> stk;      // 스택: 현재 선택된 수열

void backtrack() {
    // 종료 조건: 길이가 M이면 출력
    if (stk.size() == M) {
        for (int x : stk) {
            cout << x << ' ';
        }
        cout << '\n';
        return;
    }

    // 선택
    for (int i = 1; i <= N; i++) {
        if (used[i]) continue;

        // push (선택)
        used[i] = true;
        stk.push_back(i);

        // 다음 단계
        backtrack();

        // pop (되돌리기)
        stk.pop_back();
        used[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    backtrack();
    return 0;
}
