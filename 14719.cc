#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<int> blocks(W);

    for (int i = 0; i < W; ++i) {
        cin >> blocks[i];
    }

    stack<int> st;
    int waterTrapped = 0;

    for (int i = 0; i < W; ++i) {
        // 스택이 비어있지 않고, 현재 블록 높이가 스택의 탑 블록 높이보다 클 때
        while (!st.empty() && blocks[i] > blocks[st.top()]) {
            int top = st.top();
            st.pop();

            if (st.empty()) break;

            int distance = i - st.top() - 1;
            int boundedHeight = min(blocks[i], blocks[st.top()]) - blocks[top];

            waterTrapped += distance * boundedHeight;
        }
        st.push(i);
    }

    cout << waterTrapped << endl;

    return 0;
}
