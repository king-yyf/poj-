#include<cstdio>
int fib(int n){
	int ans = 0;
	if (n <= 2)
		ans = n > 1 ? 2 : 1;
	else{
		int a = 1,b = 2;
		for(int i = 3; i <= n; ++i){
			ans = a + b;
			a = b;
			b = ans;
		}
	} 
	return ans;
}

int main(){
	int n;
	while(scanf("%d",&n) != EOF){
		printf("%d\n",fib(n));
	}
	return 0;
}