#include <bits/stdc++.h>
#define pb push_back

#if 0
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#else
#define DEBUG(x) 
#endif
using namespace std;

int main(){
	int t,input;scanf("%d",&t);
	vector<int> v;
	while(t--){
		v.clear();
		int n,x;scanf("%d %d",&n,&x);
		for (int i=0;i<n;i++){
			scanf("%d",&input);
			v.pb(input);
		}
		sort(v.begin(),v.end());
		int cur=0;
		int i=0;
		//int prev=-100;
		while(x>0){
			
			//int temp=i;
			//if (x==0) break;
			if (i>=n){
				x--;
				cur++;
				continue;
			}
			cur++;
			if (v[i]!=cur){
				x--;
				//if (i>=n) continue;
			}
			while (v[i]<=cur){
				i++;
				if (i==n){continue;}
			}
			DEBUG(cur);
		}
		for (;i<n;i++){
			if (cur+1==v[i])cur++;
		}
		printf("%d\n",cur);
	}
}