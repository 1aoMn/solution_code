int n, m;
const int maxn = 10005;
vector<int> G[maxn];

int pa[maxn];
int deg[maxn];
int vis[maxn];

int find(int x) {
	return pa[x] == x ? x : pa[x] = find(pa[x]);
}
/*
һ������ͼ����ŷ��·���ҽ�����ͼ����ͨ��������ֻ��2����Ķ�������������ʱ��������ֻ����Ϊŷ��·���������յ�
*/ 
int main() {
	while(scanf("%d %d", &n, &m) != EOF) {
		memset(vis, 0, sizeof(vis));
		for(int i = 0; i <= n; i ++) {
			pa[i] = i;
		}
		for(int i = 0; i < m; i ++) {
			int u, v;
			scanf("%d %d", &u, &v);
			int fu = find(u);
			int fv = find(v);
			if(fu != fv) pa[fu] = fv;
			deg[u] ++;
			deg[v] ++;
		}
		
		int flag = 1;
		//�ж��ж��ٸ���Ķ���Ϊ���� 
		int cnt = 0;
		for(int i = 1; i <= n; i ++) {
			if(deg[i] & 1) {
				cnt ++;
			}
		}
		if(!(cnt == 0 || cnt == 2)) {
			flag = 0;
		}
		//���鼯�ж���ͨ���� 
		cnt = 0;
		for(int i = 1; i <= n; i ++) {
			int f = find(i);
			if(!vis[f]) {
				cnt ++;
				vis[f] = 1;
			}
		}
		if(cnt != 1) flag = 0;
		
		if(flag == 1) {
			printf("Full\n");
		}
		else {
			printf("Part\n");
		}
	}
	return 0;
}
