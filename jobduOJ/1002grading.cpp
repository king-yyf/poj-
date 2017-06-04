#include<cstdio>
using namespace std;
int ABS(int a){
	return a > 0 ? a : -a;
}
float max(int g1, int g2, int g3){
	if(g1 < g2)
		return g2 > g3 ? g2 : g3;
	return g1 > g3 ? g1 : g3;
}
int main(){
	int p, t, g1, g2, g3, gj;
	while(scanf("%d%d%d%d%d%d", &p,&t,&g1,&g2,&g3,&gj) != EOF){
		float ans;
		if(ABS(g1 - g2) <= t){
			ans = (g1 + g2) / 2.0;			
		} 
		else {
			int m = ABS(g1 - g3) > ABS(g2 - g3) ? ABS(g1 - g3) : ABS(g2 - g3);
			int n = ABS(g1 - g3) < ABS(g2 - g3) ? ABS(g1 - g3) : ABS(g2 - g3);
			if(n > t){
				ans = gj;
				
			}else if(m > t){
				if(ABS(g1 - g3) < ABS(g2 - g3)) ans = (g1 + g3) / 2.0;
				else ans = (g2 + g3) / 2.0;
		//		printf("[m > t]ans: %f\n", ans);
			}else{
				ans = max(g1, g2, g3);
		//		printf("[m <= t]ans: %f\n", ans);
			}
		}
		printf("%.1f\n", ans);
	}
	return 0;
}