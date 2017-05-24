#include<cstdio>
int main(){
    int a,b;
    while(scanf("%d%d",&a,&b) != EOF && a){
        int ans = 1;
        while(b != 0){
            if(b % 2 == 1){
                ans *= a;
                ans %= 1000;
            }
            b = b >> 1;
            a *= a;
            a %= 1000;
        }
        printf("%d\n",ans);
    }
    return 0;
}
