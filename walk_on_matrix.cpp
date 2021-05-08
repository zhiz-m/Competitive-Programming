#include <bits/stdc++.h>
using namespace std;

int main(){
	int k;cin>>k;
	cout << 3 << " " << 2 <<'\n';
	int a=131072;
	while ((a>>1)>k){
		a>>=1;
	}
	//cout << a << '\n';
	int b=k|a;
	cout << b;
	cout << " " << a << '\n' << k << " " << b;
	cout << '\n' << 0 << " " << k<<'\n';
}