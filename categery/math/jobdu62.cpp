#include<cstdio>
#include<cstring>
#define maxDigits 100
struct BigInteger{
	int digit[maxDigits];
	int size;
	void init(){
		size = 0;
		memset(digit,0,sizeof(digit));
	}
	void set(int x){
		init();
		do{
			digit[size++] = x % 10000;
			x /= 10000;
		}while(x);
	}
	void output(){
		printf("%d", digit[size - 1]);
		for(int i = size - 2; i >= 0; --i){
			printf("%04d",digit[i]);
		}
	}
	BigInteger operator * (int x)const {
		BigInteger * ret = new BigInteger();
		ret->init();
		int carry = 0;
		for(int i = 0; i < size; ++i){
			int tmp = x * digit[i] + carry;
			carry = tmp / 10000;
			tmp %= 10000;
			ret->digit[ret->size ++] = tmp;
		}
		if(carry){
			ret->digit[ret->size ++] = carry;
		}
		return *ret;
	}
	BigInteger operator + (const BigInteger & other) const {
		BigInteger *ret = new BigInteger(); 
		ret->init();
		int carry = 0;
		for(int i = 0; i < other.size || i < size; ++i){
			int tmp = other.digit[i] + digit[i] + carry;
			carry = tmp / 10000;
			tmp %= 10000;
			ret->digit[ret->size ++] = carry;
		}
		if(carry){
			ret->digit[ret->size ++] = carry;
		}
		return *ret;
	}
	BigInteger operator / (int x) const{
		BigInteger *ret = new BigInteger();
		ret->init();
		int remainder = 0;
		for(int i = size - 1; i >= 0; --i){
			int t = (remainder * 10000 + digit[i]) / x;
			int r = (remainder * 10000 + digit[i]) % x;
			ret->digit[i] = t;
			remainder = r;
		}
		ret->size = 0;
		for(int i = 0; i < maxDigits; ++i){
			if(digit[i] != 0){
				ret->size = i;
			}
		}
		ret->size ++;
		return *ret;
	}
	int operator % (int x) const {
		int remainder = 0;
		for(int i = size - 1; i >= 0; --i){
			int t = (remainder * 10000 + digit[i]) / x;
			int r = (remainder * 10000 + digit[i]) % x;
			remainder = r;
		}
		return remainder;
	}
}a,b,c;
char str[10000];
char ans[10000];
int main(){
	int n, m;
	while(scanf("%d%d",&m,&n) != EOF){
		scanf("%s",str);
		int len = strlen(str);
		a.set(0);
		b.set(1);
		for(int i = len - 1; i >= 0; i --){
			int t;
			if(str[i] >= '0' && str[i] <= '9'){
				t = str[i] - '0';
			}else 
				t = str[i] - 'A' + 10;
			a = a + b * t;
			b = b * m;
		}
		int size = 0;
		do{
			int t = a % n;
			if(t >= 10)
				ans[size ++] = t - 10 + 'a';
			else
				ans[size++] = t + '0';
			a = a / n;
		}while(a.digit[0] || a.size != 1);
		for(int i = size - 1; i >= 0; i --){
			printf("%c",ans[i]);
		}
		printf("\n");
	}
	return 0;
}

