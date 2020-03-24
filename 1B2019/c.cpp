#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;

//THIS SOLUTION IS N**2. I don't know what the better solution is right now;

int main(){

	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    for(int test=0;test<t;test++){
    	int n,k;
    	cin>>n>>k;
    	int c[n];
    	int d[n];

    	for(int i=0;i<n;i++){
    		cin>>c[i];
    	}

    	for(int i=0;i<n;i++){
    		cin>>d[i];
    	}

    	int cmax[n][n];
    	for(int i=0;i<n;i++){
    		int max=0;
    		for(int j=i;j<n;j++){
    			if(c[j]>max) max=c[j];
//    			cout<<i<<" "<<j<<" "<<max<<endl;
    			cmax[i][j]=max;
    		}
    	}


    	int dmax[n][n];
    	for(int i=0;i<n;i++){
    		int max=d[i];
    		for(int j=i;j<n;j++){
    			if(d[j]>max) max=d[j];
    			dmax[i][j]=max;
    		}
    	}


    	// for(int i=0;i<n;i++){
    	// 	cout<<c[i]<<" ";
    	// }
    	// cout<<endl;

    	// for(int i=0;i<n;i++){
    	// 	for(int j=0;j<i;j++){
    	// 		cout<<0<<" ";
    	// 	}
    	// 	for(int j=i;j<n;j++){
    	// 		cout<<cmax[i][j]<<" ";
    	// 	}
    	// 	cout<<endl;
    	// }

    	ll ans=0;

    	for(int i=0;i<n;i++){
    		for(int j=i;j<n;j++){
    			if(abs(cmax[i][j]-dmax[i][j]) <=k){
    				ans++;
    			}
    		}
    	}

    	cout<<"Case #"<<test+1<<": "<<ans<<endl;

    }
}