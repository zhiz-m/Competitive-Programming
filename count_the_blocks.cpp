#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n;
ll a[200001];
const unsigned int m = 998244353;

int main(){
	int n;cin>>n;
	int s=0;
	a[0]=1;
	for (int i=1;i<=200000;i++){
		a[i]=a[i-1]*10 %m;
	}
	for (int i=1;i<=n-1;i++){
		s=0;
		int p=1;
		p=p*(n-i-1)%m;
		p=p*810%m;
		p=p*a[n-i-2]%m;
		s=(s+p)%m;
		p=1;
		p=p*180%m;
		p=p*a[n-i-1]%m;
		s=(s+p)%m;
		cout<<s<<' ';
	}
	s+=10;
	cout << 10 <<'\n';
}