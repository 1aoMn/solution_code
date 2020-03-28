#include <iostream>
#include <cstdio>
#include <cmath>
#define eps 0.000001
using namespace std;
struct Points
{
    double x, y;
} p[100];
bool isEqual(Points a, Points b)
{
    return fabs(a.x - b.x) <= eps && fabs(a.y - b.y) <= eps;
}
double dis2(Points a, Points b)
{
    return ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
bool pd(int a, int b, int m, int c)
{
    Points A = p[a], B = p[b], M = p[m], C = p[c];
    Points mid;
    mid.x = (A.x + B.x) / 2.0, mid.y = (A.y + B.y) / 2.0;
    //判中点
    if (!isEqual(mid, M))
        return false;
    //判长度
    double AB = dis2(A, B), MC = dis2(M, C);
    if (fabs(AB - MC) > eps)
        return false;
    //判垂直
    double AC = dis2(A, C), BC = dis2(B, C);
    if (fabs(AC - BC) > eps)
        return false;
    return true;
}
int main()
{
    int t, n;
    cin >> t;
    for (int kase = 1; kase <= t; kase++)
    {
        cout << "Set #" << kase << ": ";
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> p[i].x >> p[i].y;
        }
        int ans = 0;
        //A,B,M,C
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
                for (int k = 1; k <= n; k++)
                    if (k != i && k != j)
                        for (int p = 1; p <= n; p++)
                            if (p != i && p != j && p != k)
                                if (pd(i, j, k, p))
                                    ans++;
        }
        cout << ans << endl
             << endl;
    }
    return 0;
}