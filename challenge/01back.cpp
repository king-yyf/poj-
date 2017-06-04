//0,1 backpack

#include<cstdio>
#include<algorithm>
using namespace std;

int dp[100][100];
int w[100],v[100];
int n,W;
int rec(int i, int j){
	if(dp[i][j] >= 0) return dp[i][j];
	int res;
	if(i == n) res = 0;
	else if(j < w[i]) res = rec(i + 1, j);
	else
		res = max(rec(i + 1, j), rec(i + 1, j - w[i]) + v[i]);
	return dp[i][j] = res;
}
int main(){
	n = 4;
	W = 5;
	w[0] = w[3] = v[1] = v[3] = 2;
	v[0] = w[2] = 3;
	w[1] = 1;
	v[2] = 4;
	memset(dp, -1, sizeof(dp));
	printf("%d\n", rec(0, W));
	return 0;
}