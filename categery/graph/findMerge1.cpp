#include<cstdio>
#include<cstring>
#define MAX_N 1000
int fa[MAX_N];
int rank[MAX_N];
using namespace std;

int find(int x){
	if(x == fa[x])
		return x;
	else
		return fa[x] = find(fa[x]);
}

void merge(int x, int y){
	if(rank[x] > rank[y]){
		fa[find(y)] = find(x);
		rank[y] = ++ rank[x]; 
	}
	else{
		fa[find(x)] = find(y);
		rank[x] = ++ rank[y];
	}
		
}

bool same(int x, int y){
	return find(x) == find(y);
}

void reset(int n){
	memset(rank,0,sizeof(rank));
	for(int i = 0; i < n; ++i){
		fa[i] = i;
	}
}

int main(){
	int n, m;
	while(scanf("%d%d",&n,&m) != EOF){
		reset(n);
		int from, to;
		for(int i = 0; i < m; ++i){
			scanf("%d%d",&from,&to);
			if(!same(from, to)){
				merge(from, to);
			}
		}
		int ans = 0;//base = find(0);
		// for(int i = 1; i < n; ++i){
// 			if(find(i) != base){
// 				merge(i,0);
// 				ans ++;
// 				base = find(i);
// 			}
// 		}
		for(int i = 0; i < n; ++i){
			if(fa[i] == i) ans++;
		}
		printf("%d\n",ans-1);
	}
	return 0;
}