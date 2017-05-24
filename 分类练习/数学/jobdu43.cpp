#include<cstdio>
int ans[32];
using namespace std;
int main(){
    int a,b,m;
    while(scanf("%d",&m) && m){
        scanf("%d%d",&a,&b);
        int sum = a + b;
        int idx = 0;
        while(sum){
            ans[idx++] = sum % m;
            sum /= m;
        }
        while(--idx > -1){
            printf("%d",ans[idx]);
        }
        printf("\n");
    }
    return 0;
}
