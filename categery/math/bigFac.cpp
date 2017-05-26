#include<cstdio>
#include<cstring>
using namespace std;

struct BigDecimal{
	BigDecimal(){
		memset(digit,0,sizeof(digit));
		size = 0;
	}
	void init(){
		digit[0] = 1;
		size = 1;
	}
	int digit[1000];
	int size;
	void output(){
		printf("%d",digit[size - 1]);
		for(int i = size - 2; i >= 0; --i){
			printf("%04d",digit[i]);
		}
		printf("\n");
	}
	BigDecimal operator * (int x) const{
		BigDecimal * ret = new BigDecimal();
	//	ret.init();
		int carry = 0;
		for(int i = 0; i < size; ++i){
			int tmp = x * digit[i] + carry;
			carry = tmp / 10000;
			tmp %= 10000;
			ret->digit[ret->size ++] = tmp;
		}
		if(carry){
			ret->digit[ret->size++] = carry;
		}
		return *ret;
	}
};
int main(){
	int n;
	while(scanf("%d",&n) != EOF){
		BigDecimal var;
		var.init();
		for(int i = 2; i <= n; ++i){
			var = var * i;
		}
		var.output();
	}
	return 0;
}