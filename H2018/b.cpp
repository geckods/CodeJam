#include <bits/stdc++.h>
using namespace std;

int main(){
  int t,n;
  cin>>t;

  for(int test=0;test<t;test++){
    cin>>n;
//    cout<<t<<" "<<n<<endl;
    int *arr;
    arr = (int*)malloc(sizeof(int)*n);
    char c;
    for(int i=0;i<n;i++){
      cin>>c;
      arr[i] = (int)(c-'0');
    }
   
    int *prefarr;
    prefarr = (int*)malloc(sizeof(int)*n);
    int tot = 0;

    for(int i=0;i<n;i++){
      tot+=arr[i];
      prefarr[i] = tot;
    }

    int maxsum=0;
    int last,ans,start;

    for(int i=0;i<n;i++){
      last = ((i+n+1)/2)-1;
      last = min(last,n-1);
      start = (i+1)/2;
      if(start==0){
        ans = prefarr[last]-0;
      }
      else{
        ans = prefarr[last]-prefarr[start-1];
      }
//      cout<<i<<" "<<last<<" "<<ans<<endl;

      if (ans>maxsum) maxsum = ans;
    }

    cout<<"Case #"<<test+1<<": "<<maxsum<<endl;
  }
}
