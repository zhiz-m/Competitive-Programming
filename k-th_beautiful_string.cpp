#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll dp[100001]={},maxi=0,n;

pair<ll,ll> get_i(int k){
	//if (k==1)return {n,n-1};
	for (ll i=1;;i++){
		if (dp[i]>k){
			return {n-i+1,n-k+dp[i-1]};
		}
		else{
			dp[i]=(i*i-i)/2+1;
		}
	}
	/*
	int i=1;
	int ans = (i*i-i)/2+1;
	while(1){
		if (ans >=k)
			return {n-i,n-k+ans};
		else {
			i++;
			ans = (i*i-i)/2+1;
		}
	}
	*/
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	//dp[1]=1;
	get_i(2000000000);
	int t; cin >> t;
	while (t--){
		int k;
		cin >> n >> k;
		pair<ll,ll>p=get_i(k);
		for (int i=1;i<=n;i++){
			if (i!=p.first && i!=p.second)
				putchar('a');
			else
				putchar('b');
		}
		putchar('\n');
	}
}