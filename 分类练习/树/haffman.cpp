#include <cstdio>
#include <queue>
using namespace std;

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        priority_queue<int, vector<int>, greater<int> > heap;
        for(int i = 0; i < n; ++i){
            int x;
            scanf("%d",&x);
            heap.push(x);
        }
        int ans = 0;
        while(heap.size() > 1){
            int a = heap.top();
            heap.pop();
            int b = heap.top();
            heap.pop();
            ans += a + b;
            heap.push(a + b);
        }
        printf("%d\n", ans);
    }

    return 0;
}
