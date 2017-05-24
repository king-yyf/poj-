#include <iostream>
#define MAX(a,b) (a > b) ? (a) : (b)
#define MIN(a,b) (a < b) ? (a) : (b)
const int MAX_N = 200000;
using namespace std;
int main(){
    int n;
    int R[MAX_N];
    cin>>n;
    for(int i = 0; i < n; ++i){
        cin>>R[i];
    }
    int maxv = -0x3fffffff;
    int minv = R[0];
    for(int i = 1; i < n; ++i){
        maxv = MAX(maxv, R[i] - minv);
        minv = MIN(minv,R[i]);
    }
    cout << maxv << endl;
    return 0;

}
