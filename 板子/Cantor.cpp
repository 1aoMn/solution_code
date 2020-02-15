int a[12], fac[12], int b[12];
bool vis[12];
void getfac(int n){
    fac[0] = 1;
    for(int i = 1; i < n; ++i) fac[i] = fac[i - 1]*i;
}
int cantor(int n){
    int ret = 0;
    for(int i = 0; i < n; ++i){
        int cnt = 0;
        for(int j = i + 1; j < n; ++j) if(a[i] > a[j]) ++cnt;
        ret += cnt*fac[n - 1 - i];
    }
    return ret;
}
void decantor(int x, int n){
    for(int i = 1; i <= n; ++i) vis[i] = false;
    int tot = 0;
    for(int i = n; i >= 1; --i){
        int q = x/fac[i - 1];
        int cnt = 0;
        for(int j = 1; j <= n; ++j){
            if(vis[j]) continue;
            if(++cnt > q){
                b[tot++] = j;
                vis[j] = true;
                break;
            }
        }
        x = x%fac[i - 1];
    }
}
