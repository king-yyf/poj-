#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

typedef pair<int, int> PAIR;

struct Edge{
	int to,dis,cost;
	Edge(int t,int d,int c):to(t),dis(d),cost(c){}
};

vector<Edge> graph[1000];
int dis[1000];
int co[1000];
PAIR dijkstra(int s,int t){
	memset(dis,0x3f, sizeof(dis));
	memset(co,0x3f,sizeof(co));
	priority_queue<PAIR,vector<PAIR>,greater<PAIR> > que;
	dis[s] = co[s] = 0;
	que.push(PAIR(0,s));
	while(!que.empty()){
		PAIR p = que.top();
		que.pop();
		int v = p.second;
		for(size_t i = 0; i < graph[v].size(); ++i){
			Edge e = graph[v][i];
			if(dis[v] + e.dis < dis[e.to] || (dis[v] + e.dis == dis[e.to] && co[v] < co[e.to])){
				dis[e.to] = dis[v] + e.dis;
				co[e.to] = co[v] + e.cost;
				que.push(PAIR(dis[e.to],e.to));
			}
		}
	}
	PAIR res(dis[t],co[t]);
	return res;
} 
int main(){
	int n, m;
	while(scanf("%d%d",&n,&m) && n){
		int a,b,d,p;
		while(m--){
			scanf("%d%d%d%d",&a,&b,&d,&p);
			graph[a].push_back(Edge(b,d,p));
			graph[b].push_back(Edge(a,d,p));
		}
		int s,t;
		scanf("%d%d",&s,&t);
		PAIR ans = dijkstra(s,t);
		printf("%d %d\n",ans.first,ans.second);
	}
	return 0;
}