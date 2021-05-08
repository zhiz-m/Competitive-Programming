#include <bits/stdc++.h>
#define pb push_back
#define DEBUG(x) cerr<< '<' << #x << ':' << x << endl

using namespace std;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t, a[200011],d[200011];cin>>t;
	while(t--){
		int n;cin>>n;
		fill_n(d,n+1,0);
		for (int i=0;i<n;i++){
			cin>>a[i];
		}
		a[n]=0;
		vector<int> ans;
		int cnt=0,suc=1;
		for (int i=0;i<=n;i++){
			//DEBUG(d[a[i]]);
			if (d[a[i]]||i==n){
				for (int i=1;i<=cnt;i++){
					if(!d[i]){
						suc=0;
						fill_n(d,n+1,0);
						//break;
					}
				}
				if (suc){
					ans.pb(cnt);
					cnt=0;
					fill_n(d,n+1,0);
					if (ans.size()==2 && i!=n){
						ans.clear();
						//break;
					}
					//i--;
					//continue;
				}
			}
			//DEBUG(a[i]);
			d[a[i]]=1;
			cnt++;
		}
		//DEBUG(ans.size());
		if (ans.size()%2==1)
			ans.clear();
		reverse(a,a+n);
		fill_n(d,n+1,0);
		cnt=0,suc=1;
		int c2=0;
		for (int i=0;i<=n;i++){
			//DEBUG(d[a[i]]);
			if (d[a[i]]||i==n){
				for (int i=1;i<=cnt;i++){
					if(!d[i]){
						suc=0;
						fill_n(d,n+1,0);
						//break;
					}
				}
				if (suc){
					ans.pb(cnt);
					cnt=0;
					fill_n(d,n+1,0);
					c2++;
					if (c2==2 && i!=n){
						ans.pop_back();ans.pop_back();
						c2=0;	
						//break;
					}
					//i--;
					//continue;
				}
			}
			//DEBUG(a[i]);
			d[a[i]]=1;
			cnt++;
		}
		//DEBUG(ans.size());
		//if (c2==1)ans.pop_back();
		if(c2==2)
			swap(ans[ans.size()-1],ans[ans.size()-2]);
		if (ans.size()==4 && ans[0]==ans[2] && ans[1]==ans[3]){
			ans.pop_back();
			ans.pop_back();
		}
		cout <<ans.size()/2<<'\n';
		for (int i=0;i<ans.size();i++){
			if (i==2)
				cout<<'\n';
			cout<<ans[i]<<" ";
			if (i==ans.size()-1)
				cout<<'\n';
		}
	}
}