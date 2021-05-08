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
typedef long long ll;
const ll MOD=1000000007;
mt19937 mrand(random_device{}()); 
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=MOD; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
void upgrade(){ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);}
//head: credit MiFaFaOvO

int main(){
    upgrade();
    int n;cin>>n;
    VI v(n,0);
    rep(i,0,n){
        cin>>v[i];/*
        if (i!=0&&v[i]==v[i-1]){
            cout<<"sjfnb"<<nl;
            return 0;
        }*/
    }
    if (n==1){
        int t=v[0]%2;
        if (t==0)cout<<"cslnb"<<nl;
        else cout<<"sjfnb"<<nl;
        return 0;
    }
    sort(all(v));
    int cnt=0;
    rep(i,1,n){
        if (v[i]==v[i-1]){
            cnt++;
            if (v[i]==0 || (i>1 && v[i-2]+1==v[i-1])){
                cout<<"cslnb"<<nl;
                return 0;
            }
        }
    }
    if (cnt>1){
        cout<<"cslnb"<<nl;
        return 0;
    }
    ll ans=v[0];
    v[0]=0;
    rep(i,1,n){
        ans+=v[i]-v[i-1]-1;
        v[i]=v[i-1]+1;
    }
    int t=ans%2;
    if (t==0)cout<<"cslnb"<<nl;
    else cout<<"sjfnb"<<nl;
}