#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int i, n, temp, ctr = 0, loop = 1, arr[1000] = {0};
    while (scanf("%d", &n) != EOF)
    {
        for (i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        while (loop != 0)
        {
            loop = 0;
            for (i = n - 1; i > 0; i--)
                if (arr[i] < arr[i-1])
                {
                    temp = arr[i-1];
                    arr[i-1] = arr[i];
                    arr[i] = temp;
                    ctr++;
                    loop++;
                }
        }
        printf("Minimum exchange operations : %d\n", ctr);
        for (i = 0; i < n; i++)
            arr[i] = 0;
        ctr = 0;
        loop = 1;
    }
    return 0;
}
