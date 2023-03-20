#include <iostream>
using namespace std;

struct Matrix
{
    int elements[5][5];
};

int n;
long long b;
Matrix mat;

Matrix Multiply(const Matrix m1, const Matrix m2)
{
    Matrix ret = { 0, };
    //cout << ret.elements[0][0] << '\n';
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                ret.elements[i][j] += m1.elements[i][k] * m2.elements[k][j];
                ret.elements[i][j] %= 1000;
            }
        }
    }
    return ret;
}

void GetInput()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    cin >> b;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mat.elements[i][j];
}

Matrix Power(const Matrix input, const long long power)
{
    if (power == 1)
        return input;

    if (power % 2 == 0)
    {
        Matrix temp = Power(input, power / 2);
        return Multiply(temp, temp);
    }
    else
    {
        return Multiply(Power(input, power - 1), input);
    }
}

void Solve()
{
    Matrix result = Power(mat, b);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << result.elements[i][j] % 1000 << ' ';
        cout << '\n';
    }
}

int main(void)
{
    GetInput();
    Solve();
    return 0;
}