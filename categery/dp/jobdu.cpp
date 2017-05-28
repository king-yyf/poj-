#include<cstdio>
#include<algorithm>
#define MAX 2002
using namespace std;
int dp[MAX>>1][MAX];
int arr[MAX];
int minDp(int n, int k){
	for(int i = 1; i <= n; ++i) dp[0][i] = 0;
	for(int i = 1; i <= k; ++i){
		for(int j = (i<<1); j <= n; ++j){
			if(j > 2 * i)
				dp[i][j] = dp[i][j - 1];
			else
				dp[i][j] = 0x3f3f3f3f;
			int co = (arr[j] - arr[j-1]) * (arr[j] - arr[j-1]);
			if(dp[i][j] > dp[i-1][j-2] + co)
				dp[i][j] = dp[i-1][j-2] + co;
		}
	}
	return dp[k][n];
}
int main(){
	int n, k;
	scanf("%d%d",&n,&k);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &arr[i]);
	}
	sort(arr + 1, arr + n + 1);
	printf("%d\n",minDp(n,k));
	return 0;
}