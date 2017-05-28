#include<cstdio>
using namespace std;

typedef pair<int,int> PAIR;

char str[8];
char maze[8][8];
int go[][2] = {
	1,-1,0,0,
	0,0,1,-1
}
int dfs(PAIR s, PAIR d){
	if(s.first == d.first && s.second == d.second)
		return 0;
	
}
int main(){
	int n,m,t;
	while(scanf("%d%d%d",&n,&m,&t) && n){
		PAIR src, des;
		for(int i = 0; i < n; ++i){
			scanf("%s",str);
			for(int j = 0; j < m; ++j){
				maze[i][j] = str[j];
				if(str[j] == 'S'){
					src.first = i;
					src.second = j;
				}else if(str[j] == 'D'){
					des.first = i;
					des.second = j;
				}
			}
		}
		int ans = dfs(src,des);
	}
	return 0;
}