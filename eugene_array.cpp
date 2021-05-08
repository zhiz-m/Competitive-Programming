#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int a[100001];
	int n;cin>>n;
	int zero=0;
	for (int i=0;i<n;i++){
		cin>>a[i];
		if (a[i]==0) zero++;
	}
	if (n==1){
		if (a[0]==0)
			cout<<0<<'\n';
		else 
			cout<<1<<'\n';
		return 0;
	}
	sort(a,a+n);
	int l=0,r=0;/*
	while (a[r]==0){
		r++;
		if (r==n){
			cout<<0<<'\n';
			return 0;
		}
	}*/
	ll sum=a[0];
	//bool f=1;
	/*
	for (int i=0;i<n;i++){
		sum+=a[i];
		if (a[i]>0) {r=i;break;}
	}
	*/
	vector<pair<int,int>> ans;
	while (r<n && r>=l){
		//bool f1=1;
		if (sum==0){ 
			ans.pb({l,r}); 
			l++;r++;
			sum+=a[r]-a[l-1];
			continue;
			//puts("hi");
		}
		if (sum<0 || l==r){
			r++;
			if (r<n)sum+=a[r];
		}
		else {
			sum-=a[l];
			l++;
		}
	}
	int prev=0;
	int peak;
	ll tot=(ll)n*(n+1)/2;
	//cout<<tot<<'\n';
	//cout<<ans.size()<<'\n';
	//cout<<tot<<'\n';
	for (int j=0;j<ans.size();j++){
		auto i = ans[j];
		//printf("%d %d\n",i.first,i.second);
		peak=(j==ans.size()-1)?n : ans[j+1].first;
		tot-= (i.first+1-prev)*(peak-i.second);
		prev=i.second;
	}
	
	cout<<((n==1 && a[0]!=0)?1:tot)<<'\n';
}