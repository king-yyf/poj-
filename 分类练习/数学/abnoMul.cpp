#include<cstdio>
#include<vector>
#include<ctype.h>
using namespace std;
int main(){
    vector<int> v1;
    vector<int> v2;
    char x;
    while(scanf("%c",&x)&& isdigit(x)){
        v1.push_back(x - '0');
    }
//    getchar();
    while(scanf("%c",&x)&& isdigit(x)){
        v2.push_back(x- '0');
    }
    int ans = 0;
    for(size_t i = 0; i < v1.size(); i++){
        for(size_t j = 0; j < v2.size(); j++){
            ans += v1[i] * v2[j];
        }
    }
    printf("%d\n",ans);
    return 0;
}
