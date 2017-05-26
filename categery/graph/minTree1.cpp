#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX_N 1000
using namespace std;
int fa[MAX_N];
struct Edge{
	int from, to, cost;
	bool operator < (const Edge & other) const{
		return cost < other.cost;
	}
};

int find(int x){
	if(fa[x] == x)
		return x;
	else
		return fa[x] = find(fa[x]);
}

Edge edges[MAX_N];
int main(){
	int n;
	while(scanf("%d", &n) && n){
		int end = (n * (n - 1))>>1;
		for(int i = 1; i <= end; ++i){
			scanf("%d%d%d",&edges[i].from,&edges[i].to,&edges[i].cost);
		}
		sort(edges + 1, edges + 1 + end);
		for(int i = 1; i <= end; ++i)
			fa[i] = i;
		int ans = 0;
		for(int i = 1,eNum = 0; i <= end; ++i){
			if(eNum == n -1) break;
			if(find(edges[i].from) != find(edges[i].to)){
				fa[find(edges[i].from)] = find(edges[i].to);
				ans += edges[i].cost;
				eNum ++;
			}
		}
		printf("%d\n",ans);
		
	}	
	return 0;
}