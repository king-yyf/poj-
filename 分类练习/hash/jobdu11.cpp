#include<cstdio>
#include<string.h>
#define OFFSET 500000
#define SIZE 1000001
int Hash[SIZE];
int main(){
    int n, m;
    while(scanf("%d%d", &n, &m) != EOF){

        memset(Hash,0,sizeof(Hash));
        for(int i = 0; i < n; ++i){
            int x;
            scanf("%d", &x);
            Hash[x + OFFSET] = 1;
        }
        for(int i = 500000; i > -500000; --i){
            if(Hash[i + OFFSET] == 1){
                m--;
                printf("%d",i);
                if(m != 0){
                    printf(" ");
                }else{
                    printf("\n");
                    break;
                }
            }
        }
    }

    return 0;
}
