//����������
//����һ���������У�a0, a1, a2, ���� , an�������Ϊ�����������������������к͡���������������Ǹ�������ô��������к�Ϊ0��
//���磺��������-2�� 11�� -4�� 13�� -5�� �C2�� �������������к�Ϊ20����11��13������a1��a3����

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
