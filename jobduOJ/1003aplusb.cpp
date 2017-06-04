#include<cstdio>
#define N 1000002
using namespace std;
long a[N], b[N];
long calMedian(int n, int m){
	
}
int main(){
	long ans;
	int n, m;
	while(scanf("%d",&n) != EOF){
		for(int i = 1; i < =n; ++i){
			scanf("%ld", &a[i]);
		}
		scanf("%d", &m);
		for(int i = 1; i <= m; ++i){
			scanf("%ld", &b[i]);
		}
	}
	ans = calMedian(n, m);
	return 0;
}