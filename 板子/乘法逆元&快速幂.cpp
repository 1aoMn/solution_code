LL pow(LL a, LL n, LL p)
{
    LL ans = 1;
    while(n)
    {
        if(n & 1) ans = ans * a % p;
        a = a * a % p;
        n >>= 1;
    }
    return ans;
}
LL niYuan(LL a, LL b)
{
    return pow(a, b - 2, b);
}
