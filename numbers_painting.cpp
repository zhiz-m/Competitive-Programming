#include <bits/stdc++.h>

using namespace std;

int main(){
	int ans[10001];
	int n;cin>>n;
	fill_n(ans,n+1,1);
	int m=0;
	int a;
	for (int i=1;i<=n;i++){
		if (ans[i]>m){
			m=ans[i];
			a=i;
		}
		//m=max(m,ans[i]);
		for(int j=i+i;j<=n;j+=i){
			if (ans[j]==ans[i])ans[j]++;
		}
	}
	//cout << 'h';
	printf("%d\n",m);
	//printf("%d",a);
	for (int i=1;i<=n;i++){
		printf("%d ",ans[i]);
	}
}