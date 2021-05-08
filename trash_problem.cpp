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
int n,q,v[N];
map<int,int> c,dist;

int get_range(){
    return dist.rbegin()->fi-dist.begin()->fi;
}

int max_dist(){
    return c.rbegin()->fi;
}

void count_remove(int a){
    c[a]--;
    if (c[a]==0)c.erase(a);
}

int main(){
    upgrade();
    cin>>n>>q;
    rep(i,0,n){
        cin>>v[i];
    }
    sort(v,v+n);
    rep(i,0,n-1){
        dist[v[i]]=v[i+1]-v[i];
        c[v[i+1]-v[i]]++;
    }
    dist[v[n-1]]=0;
    c[0]=1;
    cout<<get_range()-max_dist()<<nl;
    rep(i,0,q){
        int a,b;cin>>a>>b;
        if (a==0){
            map<int,int>::iterator p = dist.find(b);
            count_remove(dist[b]);
            if (SZ(dist)==1){
                dist.clear();
                c.clear();
            }
            else if (p==dist.begin()){
                dist.erase(b);
            }
            else if (b==dist.rbegin()->fi){
                map<int,int>::iterator l = --p;
                p++;
                count_remove(l->se);
                dist[l->fi]=0;
                dist.erase(b);
                c[0]++;
            }
            else{
                map<int,int>::iterator l = --p;
                p++;
                count_remove(l->se);
                dist[l->fi] += dist[b];
                c[l->se]++;
                dist.erase(b);
            }
        }
        else{
            if (SZ(dist)==0){
                dist[b]=0;
                c[0]=0;
            }else{
                map<int,int>::iterator l,r;
                l=dist.begin(),r=--dist.end();
                if (l->fi>b){
                    dist[b]=l->fi-b;
                    c[l->fi-b]++;
                }
                else if (r->fi<b){
                    dist[r->fi]=b-r->fi;
                    c[b-r->fi]++;
                    dist[b]=0;
                    dist[r->fi]=r->se;
                }
                else{
                    map<int,int>::iterator p = dist.lower_bound(b),p_b;
                    p_b=--p;
                    p++;
                    count_remove(p_b->se);
                    dist[p_b->fi]=b-p_b->fi;
                    c[b-p_b->fi]++;
                    dist[b]=p->fi-b;
                    c[p->fi-b]++;
                }
            }
        }
        /*
        DEBUG(b);
        DEBUG(get_range());
        DEBUG(max_dist());
        DEBUG(c[max_dist()]);
        */
        if (SZ(dist)<=2)cout<<0<<nl;
        else cout<<get_range()-max_dist()<<nl;
    }
}