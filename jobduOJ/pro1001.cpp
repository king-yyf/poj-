#include<stdio.h>
#include<string.h>
int matA[10][10],matS[10][10];

int calZeroNum(int m,int n){
	int cnt = 0;
	bool visit[10];
	memset(visit,0,sizeof(visit));
	for(int row = 0; row < m; ++row){
		bool flag = false;
		for(int col = 0; col < n; ++col){
			if(matS[row][col] != 0){
				visit[col] = true;
				flag = true;
				break;
			}
		}
		if(!flag) cnt++;
	}
	for(int col = 0; col < n; ++col){
		if(visit[col]) continue;
		bool flag = false;
		for(int row = 0; row < m; ++row){
			if(matS[row][col] != 0){
				flag = true;
				break;
			}
		}
		if(!flag) cnt++;
	}
	return cnt;
}
int main(){
	int m,n;
	while(scanf("%d %d",&m,&n) == 2){
		for(int i = 0; i < m; ++i){
			for(int j = 0; j < n; ++j){
				scanf("%d",&matA[i][j]);
			}
		}
		for(int i = 0; i < m; ++i){
			int now;
			for(int j = 0; j < n; ++j){
				scanf("%d",&now);
				matS[i][j] = matA[i][j] + now;
			}
		}
		printf("%d\n",calZeroNum(m,n));
	}
	return 0;
} 
