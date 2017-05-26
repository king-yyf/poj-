//问题描述：
//给定一个整数序列，a0, a1, a2, …… , an（项可以为负数），求其中最大的子序列和。如果所有整数都是负数，那么最大子序列和为0；
//例如：对于序列-2， 11， -4， 13， -5， –2。 所求的最大子序列和为20（从11到13，即从a1到a3）。

#include<cstdio>
#include<vector>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    vector<int> arr(n);
    for(int i = 0; i < n; ++i){
        scanf("%d",&arr[i]);
    }
    int curSum = 0, maxSum = 0;
    for(int i = 0; i < n; ++i){
        curSum += arr[i];
        if(curSum > maxSum){
            maxSum = curSum;
        }else if(curSum < 0){
            curSum = 0;
        }
    }
    printf("%d\n",maxSum);
    return 0;
}
