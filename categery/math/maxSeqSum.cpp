#include<iostream>

using namespace std;

int maxSubSum(int arr[], int n){
	int maxSum = 0, thisSum = 0;
	for(int i = 0; i < n; ++i){
		thisSum += arr[i];
		maxSum = max(maxSum, thisSum);
		if(thisSum < 0) thisSum = 0;
	}
	return maxSum;
}
int main(){
	int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	int ans = maxSubSum(arr, 9);
	cout<<ans<<endl;
	return 0;
}