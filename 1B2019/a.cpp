#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> intpair;
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
    	int p,q;
    	cin>>p>>q;

    	q++;

    	int x[p];
    	int y[p];
    	char d[p];

    	for(int i=0;i<p;i++){
    		cin>>x[i]>>y[i];
    		cin>>d[i];
    	}

    	int xdircumeast[q];
    	int xdircumwest[q];
    	int ydircumnorth[q];
    	int ydircumsouth[q];

    	for(int i=0;i<q;i++){
    		xdircumeast[i]=0;
	    	xdircumwest[i]=0;
	    	ydircumnorth[i]=0;
	    	ydircumsouth[i]=0;
    	}

    	for(int i=0;i<p;i++){
    		if(d[i]=='E'){
    			xdircumeast[x[i]+1]++;
    		}
    		if(d[i]=='W'){
    			xdircumwest[x[i]-1]++;
    		}
    		if(d[i]=='N'){
    			ydircumnorth[y[i]+1]++;
    		}
    		if(d[i]=='S'){
    			ydircumsouth[y[i]-1]++;
    		}
    	}


    	int xdir[q];
    	int ydir[q];

    	for(int i=0;i<q;i++){
    		xdir[i]=0;
    		ydir[i]=0;
    	}

    	int curr=0;
    	for(int i=0;i<q;i++){
    		curr+=xdircumeast[i];
    		xdir[i]+=curr;
    	}

    	curr=0;
    	for(int i=q-1;i>=0;i--){
    		curr+=xdircumwest[i];
    		xdir[i]+=curr;
    	}

    	curr=0;
    	for(int i=0;i<q;i++){
    		curr+=ydircumnorth[i];
    		ydir[i]+=curr;
    	}

    	curr=0;
    	for(int i=q-1;i>=0;i--){
    		curr+=ydircumsouth[i];
    		ydir[i]+=curr;
    	}

    	int xmax=xdir[0];
    	int ymax=ydir[0];
    	int xmaxind=0;
    	int ymaxind=0;


    	for(int i=0;i<q;i++){
    		if(xdir[i]>xmax){
    			xmax=xdir[i];
    			xmaxind=i;
    		}

    		if(ydir[i]>ymax){
    			ymax=ydir[i];
    			ymaxind=i;
    		}
    	}

    	cout<<"Case #"<<test+1<<": "<<xmaxind<<" "<<ymaxind<<endl;
    }
}