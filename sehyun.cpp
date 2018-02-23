#include <stdio.h>

int main()
{
    int a, b, c, sum = 0;

    scanf("%d %d %d", &a, &b, &c);

    for (int i = 0; i < b; i++)
    {
        printf("\n%dsquare", i+1);

        for (int j = 0; j < a; j++)
        {
            printf(" %dtime", j+1);

            while (sum >= c)
            {
                sum = sum - c;
                printf(" %d", sum);
            }

            sum = sum + a;
            printf(" %d", sum);
        }
    }

    while (sum >= c)
        {
            sum = sum - c;
            printf(" %d", sum);
        }

    printf("\n%d", sum);

    return 0;
}