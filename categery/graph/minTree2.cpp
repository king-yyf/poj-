#include<cstdio>
#include<vector>
#include<deque>
#define MAX_N 1000 
#define INF 0x3f3f3f3f
using namespace std;

struct Edge{
	int to;
	int cost;
	Edge(int t,int c):to(t),cost(c){}
};

vector<Edge> graph[MAX_N];
int dis[MAX_N];
bool markSet[MAX_N];
int minCost(int src,int des){
	memset(dis,0x3f,sizeof(dis));
	memset(markSet,0,sizeof(markSet));
	dis[src] = 0;
	markSet[src] = true;
	deque<int> que;
	que.push_back(src);
	while(!que.empty()){
		int u = que.front();
		markSet[u] = false;
		que.pop_front();
		for(size_t k = 0; k < graph[u].size(); ++k){
			int cost = dis[u] + graph[u][k].cost;
			int to = graph[u][k].to;
			if(cost < dis[to]){
				dis[to] = cost;
				if(!markSet[to]){
					que.push_front(to);
				}
				else{
					if(dis[to] <= dis[que.front()])
						que.push_front(to);
					else
						que.push_back(to);
				}
				markSet[to] = true;
			}
		}
	}
	return dis[des];
}

int main(){
	int m,n;
	while(scanf("%d%d",&n,&m) && n){
		int from,to,cost;
		while(m--){
			scanf("%d%d%d",&from,&to,&cost);
			graph[from].push_back(Edge(to,cost));
			graph[to].push_back(Edge(from,cost));
		}
		printf("%d\n",minCost(1,n));
	}
	return 0;
}