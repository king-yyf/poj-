#include<cstdio>
#include<cstring>
#define N 101
using namespace std;
int main(){
    int n = 5;


    while(scanf("%d",&n) != EOF){
        int ha[N] = {0};
    //    memset(ha, 0, sizeof(ha));
        int score;
        for(int i = 0; i < n; ++i){
            scanf("%d", &score);
            ha[score]++;
        }
        scanf("%d", &score);
        printf("%d\n",ha[score]);
    }

    return 0;
}
