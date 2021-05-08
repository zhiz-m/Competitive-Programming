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

const int N=100100;
int n, v[N], r[N];

int get(){
    if (r[1]!=0)return 2;
    int cur=1;
    while(cur<n && (v[cur]==0 || cur==r[0]))cur++;
    if (cur<r[0])cur++;
    return cur;
}

int main(){
    upgrade();
    string str; cin>>str;
    n=SZ(str);
    rep(i,0,n)v[i]=str[i]-'0';
    int m=0, a=1, b=2;
    rep(i,0,n)m=(m+v[i])%3;
    if (m==0){
        cout<<str<<nl;
        return 0;
    }
    if (m!=0 && n==1){
        cout<<-1<<nl;
        return 0;
    }
    if (m==1)swap(a,b);
    int cur=1e9, pos=-1;
    per(i,0,n){
        if (v[i]%3==b){
            pos=i;
            cur=1;
            break;
        }
    }
    if (pos==0){
        int i=1;
        while(pos+i<n&&v[pos+i]==0)i++;
        cur=i;
    }
    int tot=0;
    per(i,0,n)if(v[i]%3==a)r[tot++]=i;
    int nex = get();
    if (nex==n)nex--;
    if (cur==n)cur--;
    if (tot<2){
        //DEBUG(1);
        //DEBUG(pos),DEBUG(cur);
        if (cur==1e9) cout<<-1<<nl;
        else {
            rep(i,0,n)if(i<pos || i>=pos+cur)cout<<v[i];
            cout<<nl;
        }
        return 0;
    }
    if (cur != 1e9 && nex>cur){
        rep(i,0,n)if(i<pos||i>=pos+cur)cout<<v[i];
        cout<<nl;
        //DEBUG(2);
        return 0;
    }

    if (r[0]<nex){
        //DEBUG(3);
        rep(i,nex,n)cout<<v[i];
    }
    else{
        //DEBUG(4);
        //DEBUG(nex),DEBUG(r[0]),DEBUG(r[1]);
        if (n==2){
            cout<<-1<<nl;
            return 0;
        }
        rep(i,0,r[1])cout<<v[i];
        rep(i,r[1]+nex-1,n)if (i!=r[0])cout<<v[i];
    }
    cout<<nl;
}