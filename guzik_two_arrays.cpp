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
#define each(a,x) for(auto&a:(x))
#define DEBUG(x) cerr<<'<'<<#x<<": "<<x<<'\n'
#define nl '\n'
typedef vector<int> VI;
typedef vector<long long> VLL;
typedef pair<int,int> PII;
typedef long long ll;
typedef long double ld;
const ll MOD=1000000007;
mt19937 mrand(random_device{}()); 
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=MOD; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
void upgrade(){ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);}
//head: credit MiFaFaOvO

const int N=2020;
ll n,m,v1[N],v2[N],best,ans[4],num,s1,s2;
tuple<ll,ll,ll> a[2000100],b[2000100];

int main(){
    upgrade();
    s1=s2=0;
    cin>>n;
    rep(i,0,n)cin>>v1[i],s1+=v1[i];
    cin>>m;
    rep(i,0,m)cin>>v2[i],s2+=v2[i];
    best=abs(s1-s2);
    num=0;
    rep(i,0,n)rep(j,0,m){
        if (abs(s1-s2-2*v1[i]+2*v2[j])<best){
            best=abs(s1-s2-2*v1[i]+2*v2[j]);
            num=1;
            ans[0]=i,ans[1]=j;
        }
    }
    int p1=0,p2=0;
    rep(i,0,n)rep(j,i+1,n){
        a[p1++]={v1[i]+v1[j],i,j};
    }
    rep(i,0,m)rep(j,i+1,m){
        b[p2++]={v2[i]+v2[j],i,j};
    }
    sort(a,a+p1);
    sort(b,b+p2);
    rep(i,0,p1){
        int p=upper_bound(b,b+p2,make_tuple((2*get<0>(a[i])-s1+s2)/2,0,0))-b;
        ll t1=get<0>(a[i]),t2;
        if (p!=p2){
            t2=get<0>(b[p]);
            if (abs(s1-s2-2*t1+2*t2)<best){
                best=abs(s1-s2-2*t1+2*t2);
                num=2;
                ans[0]=get<1>(a[i]),ans[1]=get<1>(b[p]),ans[2]=get<2>(a[i]),ans[3]=get<2>(b[p]);
            }
        }
        if (p!=0){
            p--;
            t2=get<0>(b[p]);
            if (abs(s1-s2-2*t1+2*t2)<best){
                best=abs(s1-s2-2*t1+2*t2);
                num=2;
                ans[0]=get<1>(a[i]),ans[1]=get<1>(b[p]),ans[2]=get<2>(a[i]),ans[3]=get<2>(b[p]);
            }
        }
    }/*
    rep(i,0,p2){
        int p=upper_bound(a,a+p1,b[i])-a;
        ll t1=get<0>(b[i]),t2;
        if (p!=p1){
            t2=get<0>(a[p]);
            if (abs(s1-s2-2*t1+2*t2)<best){
                best=abs(s1-s2-2*t1+2*t2);
                num=2;
                ans[0]=get<1>(a[p]),ans[1]=get<1>(b[i]),ans[2]=get<2>(a[p]),ans[3]=get<2>(b[i]);
            }
        }
        if (p!=0){
            p--;
            t2=get<0>(a[p]);
            if (abs(s1-s2-2*t1+2*t2)<best){
                best=abs(s1-s2-2*t1+2*t2);
                num=2;
                ans[0]=get<1>(a[p]),ans[1]=get<1>(b[i]),ans[2]=get<2>(a[p]),ans[3]=get<2>(b[i]);
            }
        }
    }*/
    cout<<best<<nl<<num<<nl;
    rep(i,0,4)ans[i]++;
    if (num==1){
        cout<<ans[0]<<' '<<ans[1]<<nl;
    }
    else if (num==2){
        cout<<ans[0]<<' '<<ans[1]<<nl;
        cout<<ans[2]<<' '<<ans[3]<<nl;
    }
}