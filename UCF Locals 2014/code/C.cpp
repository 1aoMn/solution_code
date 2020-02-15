#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
int dp[maxn];

int main() {
	//freopen("in.txt", "r", stdin);
	int n, c, d, mv;
	cin >> n;
	string s;
	for (int i = 1; i <= n; i++) {
		cin >> c >> d;
		cin >> s;
		memset(dp, 0x3f, sizeof(dp));
		dp[0] = 0;
		for (int j = 1; j < c; j++) {
			if (s[j] == 'X')continue;
			mv = 0x3f3f3f3f;
			for (int k = max(0, j - d - 1); k <= j - 1; k++) {
				if (s[k] == 'X')continue;
				mv = min(dp[k], mv);
			}
			dp[j] = mv + 1;
		}
		cout << "Day #" << i << endl;
		cout << c << " " << d << endl;
		cout << s << endl;
		if (dp[c - 1] >= 0x3f3f3f3f)cout << 0 << endl;
		else cout << dp[c - 1] << endl;
		cout << endl;
	}

	return 0;
}
