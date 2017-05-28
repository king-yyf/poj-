#include<cstdio>
#include<cstring>
using namespace std;
char grid[101][101];
char str[101];
int dir[][2] = {
	1,0,
	-1,0,
	0,1,
	0,-1,
	1,1,
	1,-1,
	-1,1,
	-1,-1
};
void reset(int i, int j, int n, int m){
	grid[i][j] = '*';
	for(int k = 0; k < 8; ++k){
		int nx = i + dir[k][0];
		int ny = j + dir[k][1];
		if(nx >= 0 && nx < n && ny >= 0 && ny < m){
			if(grid[nx][ny] == '@')
				reset(nx,ny,n,m);
		}
	}
}
int count(int n, int m){
	int res = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(grid[i][j] == '@'){
				reset(i,j,n,m);
				res++;
			}
		}
	}
	return res;
}
int main(){
	int m,n;
	while(scanf("%d%d",&n,&m) && m){
		for(int i = 0; i < n; ++i){
			scanf("%s",str);
			for(int j = 0; j < m; ++j){
				grid[i][j] = str[j];
			}
		}
		int ans = count(n,m);
		printf("%d\n",ans);
	}
	return 0;
}