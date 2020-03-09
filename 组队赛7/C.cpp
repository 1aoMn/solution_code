#include <cstdio>
#include <iostream>
#define LL long long
using namespace std;
inline LL lg2(LL n)
{
    LL sum = 0;
    while (n >>= 1)
        sum++;
    return sum;
}
inline LL pow2(LL &n)
{
    return (n * lg2(n)) >> 1;
}
LL calc(LL n)
{
    if (n == 0 || n == 1)
        return 0;
    LL t = 1;
    return pow2((t <<= lg2(n))) + (n - t) + calc(n - t);
}
int main()
{
    LL a, b;
    while (scanf("%lld %lld", &a, &b) != EOF)
        printf("%lld\n", calc(b + 1) - calc(a));
    return 0;
}