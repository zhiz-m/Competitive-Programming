#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	int suc=1;
	//int end=1;
	//int c[100001];
	vector<int> c; //color,number
	for (int i=1;i<=m;i++){
		int input;cin>>input;
		c.pb(input);
	}
	//sort(c.begin(),c.end(),greater<pair<int,int>>());
	//c.pb(c[m-1]-1);
	vector<int> ans;
	vector<int> ends;
	int lg=1;
	int cnt=0;
	int inc=0;
	for (int i=0;i<m;i++){
		ans.pb(++cnt);
		ends.pb(cnt+c[i]-1);
		lg=max(lg,ends[i]);
		//lg=max(lg,)
		/*
		int start = min(lg,n-c[i+1]);
		lg = max(lg,start+c[i].first-1); 
		ans.pb(start);
		*/
	}
	if (lg>n){
		cout<<-1;
		//cout <<'h';
		return 0;
	}
	int st[m];int b=-1;
	if (lg==n)
		goto abab;
	for (int i=m-1;i>=0;i--){
		st[i]=max(b,ends[i]);
		b=st[i];
		//cout << st[i] << " ";
	}
	for (int i=1;i<m;i++){
		int tr = ends[i-1]-ans[i]+1;
		inc=min(n-st[i],tr);
		ends[i]+=inc;
		ans[i]+=inc;
		//inc=min(n-st[i],inc+tr);
		lg=max(lg,ends[i]);
		//lg=max(lg,lg+inc);
		//ans[i]+=inc;
	}
	//sort(ans.begin(),ans.end());
	//cout << lg <<endl;
	//for (auto i : ans){cout << i.second << " ";}
	abab:
	if (lg==n){
		for (auto i : ans){
			cout << i << " ";
		}
		//cout <<' ' << lg;
	}
	else {
		cout<<-1;
	}
	cout << '\n';
}