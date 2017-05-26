#include<iostream>
using namespace std;
inline void swap(int & a, int & b){
    int tmp = a;
    a = b;
    b = tmp;
}
void insert_sort(int a[],int n){
    for(int i = 1; i < n; ++i){
        int v = a[i];
        int j = i - 1;
        while(j >= 0 && a[j] > v){
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = v;
    }
}
void bubble_sort(int a[], int n){
    bool flag = 1;
    for(int i = 0; flag; i++){

        flag = 0;
        for(int j = n - 1; j > i; --j){
            if(a[j] < a[j - 1]){
                swap(a[j],a[j - 1]);
                flag = 1;
            }
        }
    }
}
int main(){
    int max_n = 100;
    int n,a[max_n];
    cin>>n;
    for(int i = 0; i < n; ++i){
        cin>>a[i];
    }
//    insert_sort(a,n);
    bubble_sort(a,n);
    for(int i = 0; i < n; ++i){
        cout<<a[i]<<"\t";
    }
    cout<<endl;
    return 0;
}
