#include<cstdio>
#include<cstring>
#define MAX_N 100
#define MAX(a,b) (a) > (b) ? (a) : (b)
using namespace std;

int dp[MAX_N][MAX_N];

int LCS(char str1[], char str2[]){
	int n = strlen(str1);
	int m = strlen(str2);
	for(int i = 0; i < n; ++i) dp[i][0] = 0;
	for(int i = 0; i < m; ++i) dp[0][i] = 0;
	for(int i = 1; i < n; ++i){
		for(int j = 1; j < m; ++j){
			if(str1[i] == str2[j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
			{
				dp[i][j] = MAX(dp[i - 1][j],dp[i][j -1]);
			}
		}
	}	
	return dp[n -1][m - 1];
}
int main(){
	char str1[MAX_N];
	char str2[MAX_N];
	scanf("%s%s",str1,str2);
	int ans = LCS(str1,str2);
	printf("%d\n",ans);
	return 0;
}