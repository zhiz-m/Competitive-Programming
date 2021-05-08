#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll n,k;cin>>n>>k;
	vector<int> ans;
	//int cnt=(n*n+n)/2-((n-k)*(n-k)+n-k)/2;
	for (int i=0;i<n;i++){
		ll input;cin>>input;
		if (input>n-k)
			ans.pb(i);
	}
	ll sum=1;
	for (int i=1;i<k;i++){
		sum=sum*(ans[i]-ans[i-1])%998244353;
	}
	cout<<(n*n+n)/2-((n-k)*(n-k)+n-k)/2<<" "<<sum<<'\n';
}