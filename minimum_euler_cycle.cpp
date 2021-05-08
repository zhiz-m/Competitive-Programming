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

ll nums[100100];

ll func(ll a){
	//DEBUG(a);
	return a*(a-1);
}

int main(){
	upgrade();
	//cout<<'a'<<endl;
	int t;cin>>t;
	rep(zzz,0,t){
		ll n,l,r;cin>>n>>l>>r;
		nums[0]=0;
		if (n==2){
			int a[4]={0,1,2,1};
			rep(i,l,r+1){
				cout<<a[i]<<' ';
			}
			cout<<nl;
			continue;
		}
		ll cnt=2*n-3;
		ll st;
		ll ind,mod,head,f,cur;
		bool c=1;
		rep(i,1,n+10){
			nums[i]=nums[i-1]+cnt;
			cnt-=2;
			//DEBUG(nums[i]);
			//DEBUG(cnt);
			if (nums[i]>=l){
				st=nums[i-1];
				ind=(ll)i;
				//DEBUG('h');
				break;
			}
			if(cnt<0){
				c=0;
				//DEBUG(nums[i-1]);
				//DEBUG(cnt);
				f=l-nums[i-1];
				break;
			}
		}
		if (c){
			mod=(l-st)%2;
			head = (ind==1)?1:(n+2-ind);
			f=mod;
			cur=(l-st-1)/2+2;
		}
		//DEBUG(r-l+1);
		//DEBUG(ind);
		//DEBUG(st);
		//DEBUG(head);
		//DEBUG(cur);
		//DEBUG(f);
		rep(i,0,r-l+1){
			//DEBUG('h');
			if (f==1){
				cout<<head<<' ';
				if (head==1 && cur==n){
					head=n;
					cur=2;
				}
				else if (head==3){
					f=2;
				}
				else if(head!=1 && cur==head-1){
					head--;
					cur=2;
				}
				else{
					f=0;
				}
			}
			else if (f==0){
				cout<<cur<<' ';
				cur++;
				f=1;
			}
			else{
				if (f!=n+1)
					cout<<f<<' ';
				else
					cout<<1<<' ';
				f++;
			}
		}
		//DEBUG(f);
		cout<<nl;
	}
}