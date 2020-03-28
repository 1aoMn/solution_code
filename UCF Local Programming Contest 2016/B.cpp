#include <iostream>
#include <cstring>
using namespace std;
struct repp
{
    char c1, c2;
} rep[10005];
bool pd(char ch[])
{
    int len = strlen(ch);
    for (int i = 0; i < len / 2; i++)
        if (ch[i] != ch[len - i - 1])
            return false;
    return true;
}
int main()
{
    int t, n1, n2;
    char ch1, ch2, ch[55];
    cin >> t;
    for (int kase = 1; kase <= t; kase++)
    {
        cout << "Test case #" << kase << ":" << endl;
        cin >> n1;
        for (int i = 1; i <= n1; i++)
        {
            cin >> ch1 >> ch2;
            rep[i].c1 = ch1, rep[i].c2 = ch2;
        }
        cin >> n2;
        for (int i = 1; i <= n2; i++)
        {
            cin >> ch;
            char ore[55];
            memcpy(ore, ch, 55);
            int len = strlen(ch);
            for (int j = 1; j <= n1; j++)
            {
                for (int k = 0; k < len; k++)
                {
                    if (ch[k] == rep[j].c1)
                        ch[k] = rep[j].c2;
                }
            }
            if (pd(ch))
            {
                cout << ore << " YES\n";
            }
            else
            {
                cout << ore << " NO\n";
            }
        }
        cout << endl;
    }
    return 0;
}