#include <iostream>
using namespace std;

struct matrix
{
    long long a;
    long long b;
    long long c;
    long long d;
};

matrix fibo = { 1, 1, 1, 0 };

long long n;

matrix Multiply(matrix m1, matrix m2)
{
    matrix result;
    result.a = (m1.a * m2.a + m1.b * m2.c) % 1000000;
    result.b = (m1.a * m2.b + m1.b * m2.d) % 1000000;
    result.c = (m1.c * m2.a + m1.d * m2.c) % 1000000;
    result.d = (m1.c * m2.b + m1.d * m2.d) % 1000000;
    return result;
}

matrix Solve(long long num)
{
    if (num == 0)
    {
        matrix mat = { 1, 0, 0, 1 };
        return mat;
    }

    if (num % 2 == 0)
    {
        matrix result = Solve(num / 2);
        result = Multiply(result, result);
        return result;
    }
    else
    {
        matrix result = Solve(num - 1);
        result = Multiply(fibo, result);
        return result;
    }
}

int main(void)
{
    cin >> n;

    matrix result = Solve(n);
    result = Multiply(result, { 1, 0, 0, 0 });
    cout << result.c << '\n';
    return 0;
}