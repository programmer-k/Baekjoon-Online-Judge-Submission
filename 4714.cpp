#include <cstdio>
using namespace std;

int main(void)
{
    while (true)
    {
        double num;
        scanf("%lf", &num);
        if (num < 0)
            break;
        printf("Objects weighing %.2f on Earth will weigh %.2f on the moon.\n", num, num * 0.167);
    }
    return 0;
}