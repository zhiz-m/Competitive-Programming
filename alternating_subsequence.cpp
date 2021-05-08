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
typedef vector<long long> VLL;
typedef pair<int,int> PII;
typedef pair<long long, long long> PLL;	
typedef long long ll;
void upgrade(){ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);}

VLL v(200001);
int n;
int p;

ll check(){
    ll mx=v[p];
    p++;
    if (mx>0)
    while(p<n && v[p]>0){
        mx=max(mx,v[p]);
        p++;
    }
    else
    while(p<n && v[p]<0){
        mx=max(mx,v[p]);
        p++;
    }
    return mx;
}
/*
void solve(int p){
    int p2=p+1;
    while(p2<n && v[p2]>0){
        p2++;
    }

    if (v[p]<0){
        p++;
        while(p<n && v[p]<0){
            p++;
        }
    }
}*/

int main(){
    upgrade();
    int tc;cin>>tc;
    while(tc--){
        cin>>n;
        rep(i,0,n){
            cin>>v[i];
        }
        p=0;
        ll ans=0;
        while (p<n){
            ans+=check();
        }
        cout<<ans<<nl;
    }
}