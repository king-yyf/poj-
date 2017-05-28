#include<cstdio>
#include<algorithm>
using namespace std;
#define MAX_N 26

int arr[MAX_N], b[MAX_N];

int LIS(int arr[], int n){
	int len = 1;
	b[0] = arr[0];
	for(int i = 0; i < n; ++i){
		if(arr[i] >=b[len - 1]){
			b[len++] = arr[i];
		}else{
			int pos = lower_bound(b, b + len, arr[i]) - b;
			b[pos] = arr[i];
		}
	}
	return len;
}
int main(){
	int k;
	while(scanf("%d",&k) != EOF){
		int tmp;
		for(int i = 0; i < k; ++i){
			scanf("%d",&tmp);
			arr[i] = -tmp;
		}
		printf("%d\n",LIS(arr,k));
	}
	return 0;
}