#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t,w;
    cin>>t>>w;

    ll response;


    for(int test=0;test<t;test++){
    	int r1,r2,r3,r4,r5,r6;
    	//ask 185

    	cout<<185<<endl;
    	fflush(stdout);
    	cin>>response;

    	for(int i=0;i<30;i++){
    		response/=2;
    	}

    	r6 = response%(ll)pow(2,7);
    	for(int i=0;i<7;i++){
    		response/=2;
    	}
    	r5 = response%(ll)pow(2,7);
    	for(int i=0;i<7;i++){
    		response/=2;
    	}

    	for(int i=0;i<2;i++){
    		response/=2;
    	}

    	r4 = response%(ll)pow(2,7);


    	//ask 38

    	cout<<38<<endl;
    	fflush(stdout);

    	cin>>response;

    	response-=r6*(ll)pow(2,6);
		response-=r5*(ll)pow(2,7);
		response-=r4*(ll)pow(2,9);

    	for(int i=0;i<12;i++){
    		response/=2;
    	}

    	r3 = response%(ll)pow(2,7);

    	for(int i=0;i<7;i++){
    		response/=2;
    	}

    	r2 = response%(ll)pow(2,7);

    	for(int i=0;i<7;i++){
    		response/=2;
    	}

    	for(int i=0;i<12;i++){
    		response/=2;
    	}

    	r1 = response%(ll)pow(2,7);

    	cout<<r1<<' '<<r2<<' '<<r3<<' '<<r4<<' '<<r5<<' '<<r6<<endl;
    	cin>>response;

    	if(response==-1){
    		cerr<<"FUCK ME"<<endl;
    		return 0;
    	}

    }
}