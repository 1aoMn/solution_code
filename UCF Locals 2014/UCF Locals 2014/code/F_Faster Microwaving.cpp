#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;

int calc(int f, int m) {
	int cnt = 0;
	if (f) {
		if (f >= 10) {
			if (f == 11 || f == 22)cnt += 2;
			else cnt += 3;
		}
		else cnt += 1;
		f = f % 10;
		if (m) {
			if ((m / 10) == f)cnt += 1;
			else cnt += 2;
			
			if ((m / 10) == (m % 10))cnt += 1;
			else cnt += 2;
		}
		else {
			if (f == 0)cnt += 2;
			else cnt += 3;
		}
	}
	else {
		if (m / 10 == m % 10)cnt += 2;
		else cnt += 3;
	}
	return cnt;
}

int main() {
	
	//freopen("in.txt", "r", stdin);
	int n, p, t, f, m;
	cin >> n;
	string str;
	for (int T = 1; T <= n; T++) {
		//cin >> f; getchar(); cin >> m;
		cin >> str;
		f = (str[0] - '0') * 10 + (str[1] - '0');
		m = (str[3] - '0') * 10 + (str[4] - '0');
		cin >> p;
		/*cout << "f = " << f << endl;
		cout << "m = " << m << endl;
		cout << "p = " << p << endl;*/
		p = p * (f * 60 + m) / 100;
		int ans = 0x3f3f3f3f, af, am, ansf, ansm;
		bool ex = true;
		for (int i = 0; i <= p;) {
			af = f;
			if (ex) {
				am = m + i;
				if (am >= 60) {
					af += am / 60;
					am = am % 60;
				}
			}
			else {
				am = m - i;
				while (am < 0) {
					af--;
					am += 60;
				}
			}		
			t = calc(af, am);
			if (t < ans) {
				ans = t;
				ansf = af; ansm = am;
			}
			if (am + 60 < 100 && af > 0) {
				t = calc(af - 1, am + 60);
				if (t < ans) {
					ans = t;
					ansf = af - 1; ansm = am + 60;
				}
			}
			ex = !ex;
			if (ex)i++;
		}
		cout << "Case #" << T << ": ";
		if (ansf)cout << ansf;
		else {
			cout << ansm << endl;
			continue;
		}
		if (ansm == 0)cout << "00" << endl;
		else {
			if (ansm < 10)cout << "0" << ansm << endl;
			else cout << ansm << endl;
		}
	}

	return 0;
}
