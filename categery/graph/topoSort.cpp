#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

vector<int> edge[501];

int main(){
	int n,m;
	while(scanf("%d%d",&n,&m) && n){
		memset(edge,0,sizeof(edge));
		vector<int> degree(n,0);
		while(m--){
			int a,b;
			scanf("%d%d",&a,&b);
			edge[a].push_back(b);
			degree[b]++;
		}
		queue<int> q;
		for(int i = 0; i < n; ++i){
			if(degree[i] == 0){
				q.push(i);
			}
		}
		int cnt = 0;
		while(!q.empty()){
			int v = q.front();
			cnt++;
			q.pop();
			for(size_t i = 0; i < edge[v].size(); ++i){
				if(--degree[edge[v][i]] == 0){
					q.push(edge[v][i]);
				}
			}
		}
		if(cnt == n) puts("YES");
		else puts("NO");
	}
	return 0;
}