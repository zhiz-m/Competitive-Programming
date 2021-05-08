#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n,k,d;

vector<ll> v;
unordered_set<ll> nums;
unordered_map<ll, pair<ll,ll>> dp_f={},dp_b={}; // pair: turns,amount
unordered_map<ll,ll> a={};

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> k;
	ll input;
	ll quick=0;
	ll mini=1000000001,maxi=-1;
	//v.push_back(-1);
	for (int i=0;i<n;i++){
		cin >> input;
		v.push_back(input);
		//nums.insert(input);
		if ((++a[input])==k)
			quick=1;
		mini = min(mini,input);
		maxi = max(maxi,input);
	}
	//nums.insert(mini+1);
	//nums.insert(maxi-1);
	//vector<ll> v(nums.begin(),nums.end());
	v.push_back(maxi-1);
	v.push_back(mini+1);
	sort(v.begin(),v.end());
	ll prev=v[0];
	//for (int i: v)cout << i << " ";
	d=v.size();
	ll cur=v[0],amt=a[v[0]],t=0;
	for (int i = 1; i < d; i++){
		if (v[i]==prev) continue;
		prev=v[i];
		ll j = v[i]-1;
		t += amt*(j-cur);
		dp_f[v[i]]=make_pair(t,amt);
		//cout << t << " " << amt << '\n';
		t+=amt;
		amt += a[v[i]];
		cur=v[i];
		//t-=a[v[i]];
	}
	t=0, cur=v[d-1],amt=a[v[d-1]],prev=v[d-1];
	for (int i = d-2; i >= 0; i--){
		if (v[i]==prev) continue;
		prev=v[i];
		ll j = v[i]+1;
		t += amt*(cur-j);
		dp_b[v[i]]=make_pair(t,amt);
		t += amt;
		amt += a[v[i]];
		cur=v[i];
		//t-=a[v[i]];
	}
	ll ans=LLONG_MAX;
	for (int i=1;i<d-1;i++){
		ll node = v[i];
		if (dp_f[node].second + a[node]>=k)
			ans=min(ans,dp_f[node].first+k-a[node]);
		if (dp_b[node].second + a[node]>=k)
			ans=min(ans,dp_b[node].first+k-a[node]);
		ans=min(ans,dp_b[node].first+dp_f[node].first+k-a[node]);
	}
	//cout << a[maxi] << " ";
	ans=min(ans,dp_f[maxi].first+k-a[maxi]);
	//cout << ans << " ";
	ans=min(ans,dp_b[mini].first+k-a[mini]);
	//cout << ans << " ";
	if (quick)
		cout << 0 <<'\n';
	else
		cout << ans <<'\n';
}