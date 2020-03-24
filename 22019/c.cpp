#include <bits/stdc++.h>
using namespace std;

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
    	int n;
    	cin>>n;
    	int prevc,prevj;
    	int c,j;
    	int x,y;

    	double minratio=INT_MAX,maxratio=INT_MIN;

    	int arr[n][2];

    	for(int i=0;i<n;i++){
    		cin>>arr[i][0]>>arr[i][1];
//	    		(prevc-c)*x < (j-prevj)*y
//				x/y < j-prevj / prevc - c
//    			x/y < ratio
//    			x < y*minratio
//    			x > y*maxratio

//				x/minratio < y
//				x/maxratio > y

    		c = arr[i][0];
    		j = arr[i][1];
    		for(int z=0;z<i;z++){
    			prevc=arr[z][0];
    			prevj=arr[z][1];
				double ratio= ((double)(j-prevj))/(prevc-c);
				if(ratio>0){
					if(ratio<minratio) minratio = ratio;
				}
				else{
					if((-1*ratio)>maxratio) maxratio = -1*ratio;
				}
    		}
    	}

    	cout<<minratio<<" "<<maxratio<<endl;

    	if(maxratio > minratio){
    		cout<<"IMPOSSIBLE"<<endl;
    	}
    	else{
    		x = 1;
    		while(1){
    			y = floor(x/minratio)+1;
    			if(y<x/maxratio){
    				break;
    			}
    			x++;
    		}
  		  	cout<<x<<" "<<y<<endl;
    	}


    }

}
