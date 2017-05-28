#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int dre[][3]=
{
	{1, 0, 0},
	{-1, 0, 0},
	{0, 1, 0},
	{0, -1, 0},
	{0, 0, 1},
	{0, 0, -1}
};

int maze[51][51][51];
struct Point{
	int x, y, z;
	Point(int _x,int _y, int _z):x(_x),y(_y),z(_z){}
};
typedef pair<Point,int> PAIR;
int bfs(int a, int b, int c, int t){
	queue<PAIR> que;
	int visit[51][51][51] = {0};
	int res = 0;
	que.push(PAIR(Point(0,0,0),0));
	bool go = 1;
	while(!que.empty() && go){
		PAIR q = que.front();
		Point p = q.first;
//		printf("Point:(%d,%d,%d),step: %d\n",p.x,p.y,p.z,q.second);
		que.pop();
//		visit[p.x][p.y][p.z] = 1;
		for(int i = 0; i < 6; ++i){
			int nx = p.x + dre[i][0];
			int ny = p.y + dre[i][1];
			int nz = p.z + dre[i][2];
			if(nx >=0 && ny >= 0 && nz >=0 && nx < a && ny < b && nz < c){
				if(!visit[nx][ny][nz] && maze[nx][ny][nz] == 0){
					int step = q.second + 1;
					que.push(PAIR(Point(nx,ny,nz),step));
					printf("Point:(%d,%d,%d),step: %d\n",nx,ny,nz,step);
					if(nx == a - 1 && ny == b - 1 && nz == c -1){
						res = step;
						go = 0;
					}
					visit[nx][ny][nz] = 1;
				}
			}
		}
	}
	return res <= t ? res : -1;
}

int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		int a,b,c,t;
		scanf("%d%d%d%d",&a,&b,&c,&t);
		for(int i = 0; i < a; ++i){
			for(int j = 0; j < b; ++j){
				for(int k = 0; k < c; ++k){
					scanf("%d",&maze[i][j][k]);
				}
			}
		}
		int ans = bfs(a,b,c,t);
		printf("%d\n",ans);
	}
	return 0;
}