#include <bits/stdc++.h>
using namespace std;
#define pb push_back
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

//vector<vector<ll>> mp;
int last;

void add_pow(int ind,int val){
	int p=0;
	int a=val;
	//DEBUG(1);
	while (a!=0){
		int temp=1<<p;
		if ((temp&a)==temp){
			//mp[val].pb(ind);
			a-=temp;
			last=max(last,p);
		}
		p++;
	}
	//DEBUG(2);
}

int main(){
	ll a[100001];
	ll add[100001];
	add[0]=0;
	upgrade();
	int t;cin>>t;
	while(t--){
		//mp.assign(33,{});
		last=-1;
		int n;cin>>n;
		rep(i,0,n){
			cin>>a[i];
		}
		ll mx=a[0];
		rep(i,1,n){
			if (a[i]<mx){
				add[i]=mx-a[i];
				add_pow(i,add[i]);
			}
			else{
				add[i]=0;
				mx=a[i];
			}
		}
		cout<<last+1<<nl;
	}
}