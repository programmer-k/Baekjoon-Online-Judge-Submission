#include <iostream>
#include <string>
#include <limits>
#include <deque>
using namespace std;

int n;
string expression;
bool use_parenthesis[9];
int max_value = numeric_limits<int>::min();

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  cin >> expression;
}

void CalcMaxExpr(int index) {
  // Base case: If adding parenthesis is done, calculate the expression.
  if (index >= ssize(expression) / 2) {
    deque<int> deq;
    
    // Fill a deque with operators and operands.
    for (int i = 0; i < ssize(expression); ++i) {
      if (i % 2 == 1 && use_parenthesis[i / 2]) {
        // Calculate the subexpression in the parenthesis.
        int operand1 = deq.back();
        int operand2 = expression[i + 1] - '0';
        deq.pop_back();

        int result = -1;
        switch (expression[i]) {
        case '+':
          result = operand1 + operand2;
          break;
        case '-':
          result = operand1 - operand2;
          break;
        case '*':
          result = operand1 * operand2;
          break;
        }

        deq.push_back(result);
        ++i;
      } else if (i % 2 == 1) {
        deq.push_back(expression[i]);
      } else {
        deq.push_back(expression[i] - '0');
      }
    }

    // Calculate the expression.
    while (deq.size() != 1) {
      int operand1 = deq.front();
      deq.pop_front();
      
      char op_code = deq.front();
      deq.pop_front();

      int operand2 = deq.front();
      deq.pop_front();

      int result = -1;
      switch (op_code) {
      case '+':
        result = operand1 + operand2;
        break;
      case '-':
        result = operand1 - operand2;
        break;
      case '*':
        result = operand1 * operand2;
        break;
      }

      deq.push_front(result);
    }

    max_value = max(max_value, deq.front());
    return;
  }

  // Case 1: Add a parenthesis at the current position.
  if (index == 0 || !use_parenthesis[index - 1]) {
    use_parenthesis[index] = true;
    CalcMaxExpr(index + 1);
  }

  // Case 2: Do not add a parenthesis at the current position.
  use_parenthesis[index] = false;
  CalcMaxExpr(index + 1);
}

void Solve() {
  CalcMaxExpr(0);
  cout << max_value << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}