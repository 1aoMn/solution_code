#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e3 + 10;
int t1[N], t2[N];

int main()
{
   // freopen("input.txt", "r", stdin);
    int T, kase = 1;
    cin >> T;
    while (T--)
    {
        int n1;
        cin >> n1;
        for (int i = 0; i < n1; i++)
            cin >> t1[i];
        for (int i = 0; i < 4 * n1; i++)
            cin >> t2[i];
        sort(t1, t1 + n1);
        sort(t2, t2 + 4 * n1);
        int ans = 0;
        int cnt = 0;
        for (int i = 4 * n1 - 1; i >= 0; i -= 4)
        {
            ans = max(ans, t2[i] + t1[cnt]);
            cnt++;
        }
        printf("Trip #%d: ", kase++);
        cout << ans << endl;
    }
    return 0;
}

