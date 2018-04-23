#include <stdio.h>

int divisors_count[3000009];

void seive(int n)
{
    int i, j;
    for (i = 1; i <= n / 2; i++)
    {
        for (j = 2 * i; j <= n; j += i)
        {
            divisors_count[j]++;
        }
    }
}

int used[3000009], n;
int sum, m, k;

int main()
{

    scanf("%d %d", &n, &k);

    if (k == 6)
    {
        if (n < 6)
        {
            printf("No\n");
        }
        else
        {
            printf("Yes\n");
            printf("5\n");
            printf("1 2 4 5 6\n");
        }
        return 0;
    }

    seive(n);

    for (int i = 1; i <= n; i++)
    {
        sum += divisors_count[i];
        m = i;
        if (sum >= k)
        {
            break;
        }
    }

    if (sum < k)
    {
        printf("No\n");
    }
    else
    {
        int cnt = m;
        for (int i = 1; i <= m; i++)
        {
            used[i] = 1;
        }

        int i = m;

        while (sum > k && i > m / 2)
        {
            if (divisors_count[i] <= sum - k)
            {
                sum -= divisors_count[i];
                used[i] = 0;
                cnt--;
            }
            i--;
        }

        printf("Yes\n");
        printf("%d\n", cnt);
        for (int i = 1; i <= m; i++)
        {
            if (used[i])
            {
                printf("%d ", i);
            }
        }
    }

    return 0;
}
