#include <bits/stdc++.h>
using namespace std;

//_SRT _VSC
char s[10][3][6], fir[10][5] = { "SV", "SS", "SC", "RV", "RS", "RC", "TV", "TS", "TC" };
int arr[9], n, r, c, gg[10][2], G[3][3];
//bool hasans, vis[10];
bool mz() {
	bool meet, isf;
	char s1, s2;
	for (int i = 0; i < n; i++) {
		meet = false;
		for (int j = 0; j + gg[i][0] <= 2; j++) {
			for (int k = 0; k + gg[i][1] <= 2; k++) {
				//G上移动，比较线索
				isf = true;
				for (int a = 0; a <= gg[i][0]; a++) {
					for (int b = 0; b <= gg[i][1]; b++) {
						s1 = fir[G[j + a][k + b]][0];
						s2 = fir[G[j + a][k + b]][1];
						if ((s[i][a][b * 2] != '_' && s[i][a][b * 2] != s1) || (s[i][a][b * 2 + 1] != '_' && s[i][a][b * 2 + 1] != s2)) {
							isf = false;
						}
					}
					if (!isf)break;
				}
				if (isf)meet = true;
			}
			if (meet)break;
		}
		if (!meet)return false;
	}
	return true;
}
void solve() {
	do {
		G[0][0] = arr[0]; G[0][1] = arr[1]; G[0][2] = arr[2];
		G[1][0] = arr[3]; G[1][1] = arr[4]; G[1][2] = arr[5];
		G[2][0] = arr[6]; G[2][1] = arr[7]; G[2][2] = arr[8];
		if (mz()) {
			printf("%s %s %s\n", fir[G[0][0]], fir[G[0][1]], fir[G[0][2]]);
			printf("%s %s %s\n", fir[G[1][0]], fir[G[1][1]], fir[G[1][2]]);
			printf("%s %s %s\n", fir[G[2][0]], fir[G[2][1]], fir[G[2][2]]);
			return;
		}
	} while (next_permutation(arr, arr + 9));
}

int main() {
	//freopen("in.txt", "r", stdin);
	int T; scanf("%d", &T);
	
	for (int rnd = 1; rnd <= T; rnd++) {
		for (int i = 0; i < 9; i++)arr[i] = i;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &r, &c);
			gg[i][0] = r - 1; gg[i][1] = c - 1;
			getchar();
			for (int j = 0; j < r; j++) {
				for (int k = 0; k < c; k++) {
					s[i][j][k * 2] = getchar();
					s[i][j][k * 2 + 1] = getchar();
					getchar();
				}
			}
		}
		printf("Puzzle #%d:\n", rnd);
		solve();
	}

	return 0;
}
