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

int main(){
    upgrade();
    int tc;cin>>tc;
    VI v, kv,pre,suf,kmin,kmax;
    while(tc--){
        int n,k;cin>>n>>k;
        v.assign(n+1,0);
        kv.assign(2*k+2,0);
        pre.assign(2*k+2,0);
        suf.assign(2*k+2,0);
        kmin.assign(k+2,0);
        kmax.assign(k+2,0);
        rep(i,0,n)cin>>v[i];/*
        int mx=INT_MIN,mn=INT_MAX;
        //rep(i,0,n)
        rep(i,0,n/2){
            mx=max(mx,min(v[i],v[n-i+1]));
            mn=min(mn,max(v[i],v[n-i+1]));
        }
        mn+=k;*/
        //int b=v[0]+v[n-1];
        rep(i,0,n/2){
            kv[v[i]+v[n-i-1]]++;
            kmin[min(v[i],v[n-i-1])]++;
            kmax[max(v[i],v[n-i-1])]++;
        }
        //rep(i,2,2*k+1){DEBUG(i);DEBUG(kv[i]);}
        rep(i,1,k+1){
            pre[i]=pre[i-1]+kmax[i];
        }
        per(i,1,k+1){
            suf[i]=suf[i+1]+kmin[i];
            //DEBUG(suf[i]);
        }
        int ans=INT_MAX;
        rep(i,2,2*k+1){
            int cost=0;
            if (i-k>1)
                cost+=pre[i-k-1];
            cost+=suf[i];
            ans=min(ans,(n-2*kv[i])/2+cost);
            //DEBUG(i);DEBUG(cost);
        }
        //DEBUG(cur);
        cout<<ans<<nl;
    }
}