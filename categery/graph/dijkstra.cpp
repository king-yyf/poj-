#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int, int> PAIR;
struct Edge{
	int to,cost;
	Edge(int t, int c):to(t),cost(c){}
};
int dis[100];
vector<Edge> graph[100];

int dijkstra(int s,,int t){
	memset(dis,0x3f,sizeof(dis));
	dis[s] = 0;
	priority_queue<PAIR, vector<PAIR>, greater<PAIR> > que;
	que.push(PAIR(0,s));
	while(!que.empty()){
		PAIR p = que.top();
		que.pop();
		int v = p.second;
		for(size_t i = 0; i < graph[v].size(); ++i){
			Edge e = graph[v][i];
			if(dis[e.to] > dis[v] + e.cost){
				dis[e.to] = dis[v] + e.cost;
				que.push(PAIR(dis[e.to],e.to));
			}
		}
	}
	return dis[t];
}
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m) && n){
		while(m--){
			int from,to,cost;
			scanf("%d%d%d",&from,&to,&cost);
			graph[from].push_back(Edge(to,cost));
			graph[to].push_back(Edge(from,cost));
		}
		printf("%d\n",dijkstra(1,n));
	}
	return 0;
}