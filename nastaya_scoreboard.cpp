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

int nums[10]={119,18,93,91,58,107,111,82,127,123};
string nums2[10]={"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
vector<string> v(2005);
vector<VI> cost(2005,VI(10,-2));
vector<VI> dp(2005,VI(2005,-1));

int compare(string cur, string num){ //current bitset, correct bitset
    int cnt=0;
    rep(i,0,7){
        if (cur[i]==num[i])continue;
        if (cur[i]=='1'&&num[i]=='0')return -1;
        else cnt++;
    }
    return cnt;
}

int main(){
    upgrade();
    int n,k;cin>>n>>k;
    rep(i,0,n)cin>>v[i];
    rep(i,0,n){
        rep(j,0,10){
            cost[i][j]=compare(v[i],nums2[j]);
        }
    }
    rep(i,0,10){
        int c=cost[n-1][i];
        if (c!=-1){
            dp[n-1][c]=i;
        }
    }
    per(i,0,n-1){
        rep(j,0,10){
            int c=cost[i][j];
            if (c!=-1){
                rep(pre,0,k-c+1){
                    auto p=dp[i+1][pre];
                    if (p==-1)continue;
                    dp[i][c+pre]=j;
                }
            }
        }
    }
    if (dp[0][k]==-1){
        cout<<-1<<nl;
        return 0;
    }
    int t=k;
    rep(i,0,n){
        cout<<dp[i][t];
        t-=cost[i][dp[i][t]];
    }/*
    rep(i,1,n){
        cout<<dp[i][p].fi;
        p=dp[i][p].se;
    }*/
    cout<<nl;
}