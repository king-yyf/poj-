#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
typedef pair<int, int> PAIR;
bool cmp(PAIR p1, PAIR p2){
    return p1.first < p2.first;
}
int main(){
    int n, m;
    priority_queue<PAIR,vector<PAIR> > poly1;
    priority_queue<PAIR,vector<PAIR> > poly2;
    scanf("%d%d",&n,&m);
    for(int i = 0; i < n; ++i){
        int co,ex;
        scanf("%d%d",&co,&ex);
        poly1.push(PAIR(ex,co));
//        poly1.emplace_back(co,ex);
    }
    for(int i = 0; i < m; ++i){
        int co,ex;
        scanf("%d%d",&co,&ex);
        poly2.push(PAIR(ex,co));
    }

    vector<PAIR> sum;
    while(!poly1.empty() || !poly2.empty()){
        PAIR p1 = poly1.top(), p2 = poly2.top();
        if(p1.first < p2.first){
            sum.push_back(p2);
            poly2.pop();
        }else if(p1. first == p2.first){
            int ex = p1.first;;
            int co = p1.second + p2.second;
            if(co != 0)
            sum.push_back(PAIR(ex,co));
        }else{
            sum.push_back(p1);
            poly1.pop();
        }

    }
    while(!poly1.empty()){
        PAIR p = poly1.top();
        sum.push_back(p);
        poly1.pop();
    }
    while(!poly2.empty()){
        PAIR p = poly2.top();
        sum.push_back(p);
        poly2.pop();
    }
    sort(sum.begin(),sum.end(),cmp);
    for(size_t i = 0; i < sum.size() - 1; ++i){
        PAIR p = sum[i];
        printf("%dx^%d+",p.second,p.first);
    }
    PAIR p = sum[sum.size() - 1];
    if(p.first == 0)
        printf("%d\n",p.second);
    else
        printf("%dx^%d\n",p.second,p.first);
    return 0;
}
