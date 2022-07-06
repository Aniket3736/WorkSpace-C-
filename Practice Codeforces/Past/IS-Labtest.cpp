#include <stdio.h>
void solve()
{
    char transposition[] = {8, 4, 3, 2, 17, 15, 14, 10, 9, 1, 5, 8, 12, 13, 7, 11, 6};
    char input[256] = "ThekeyselectionismaderandomlyinDES\n";
    int len = sizeof(transposition);
    char ch, temp[len];
    int i, j, k;

    j = i = 0;
    do
    {
        for (; '\0' != (ch = input[i]) && ch != '\n'; ++i)
        {
            temp[j++] = ch;
            if (j == len)
            {
                j = 0;
                ++i;
                break;
            }
        }
        while (j != 0)
        {
            temp[j++] = '.'; // pading if(i % len != 0)
            if (j == len)
                j = 0;
        }
        for (k = 0; i && k < len; ++k)
        {
            printf("%c", temp[transposition[k]]);
        }
    } while (ch != '\n' && ch != '\0');
    printf("\n");
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
        solve();

    return 0;
}