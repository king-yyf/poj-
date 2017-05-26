//给定n,a，求最大的k,使n!能被a^k整除，不能被(a^k+1)整除

#include <cstdio>
#include <cstring>
using namespace std;
bool mark[1010];
int prime[1010];
int primeSize;

void init(){
    primeSize = 0;
    prime[primeSize++] = 2;
    for(int i = 3; i <= 1000; i += 2){
        if(mark[i]) continue;
        mark[i] = true;
        prime[primeSize++] = i;
        for(int j = i * i; j <= 1000; j += i){
            mark[j] = true;
        }
    }
}
int cnt[1010];
int cnt2[1010];
int main(){
    int n,a;
    init();
//    for(int i = 0; i < primeSize; ++i){
//        printf("%d\t",prime[i]);
//        if(i % 10 == 9){
//            printf("\n");
//        }
//    }
    while(scanf("%d%d",&n,&a) == 2){
        memset(cnt,0,sizeof(cnt));
        memset(cnt2,0,sizeof(cnt2));
        for(int i = 0; i < primeSize; ++i){
            int t = n;
            while(t){
                cnt[i] += t / prime[i];
                t = t / prime[i];
            }
        }
        int ans = 0x3f3f3f3f;
        for(int i = 0; i < primeSize; ++i){
            while(a % prime[i] == 0){
                cnt2[i]++;
                a /= prime[i];
            }
            if(cnt2[i] == 0) continue;
            if(cnt[i] / cnt2[i] < ans)
                ans = cnt[i] / cnt2[i];
        }
        printf("%d\n",ans);
    }

    return 0;
}
