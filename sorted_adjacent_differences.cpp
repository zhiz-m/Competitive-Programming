#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define fi first
#define se second
#define SZ(x) (int)(x).size()
#define rep(i,a,b) for (int i=a;i<b;i++)
#define per(i,a,b) for (int i=b-1;i>=a;i--)
#define DEBUG(x) cerr<<'<'<<#x<<": "<<x<<'\n'
#define nl '\n'
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef long long ll;
void upgrade(){ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);}

int main(){
	upgrade();
	int t;cin>>t;
	while(t--){
		int v[100001];
		int n;cin>>n;
		//v.clear();
		rep(i,0,n)cin>>v[i];
		sort(v,v+n);
		per(i,0,(n-1)/2+1){
			int cj = n-i-1;
			//DEBUG(i);
			//DEBUG(cj);
			if (i==cj)
				cout<<v[i]<<' ';
			else
				cout <<v[cj]<<' '<<v[i]<<' ';
		}
		cout<<nl;
	}
}