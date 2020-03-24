#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
const int N = 200002;

ll power(ll x, ll y, ll p) 
{ 
    ll res = 1;      // Initialize result 
  
    x = x % p;  // Update x if it is more than or  
                // equal to p 
  
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % p; 
  
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % p;   
    } 
    return res; 
} 


ll factorialNumInverse[N + 1]; 
  
// array to precompute inverse of 1! to N! 
ll naturalNumInverse[N + 1]; 
  
// array to store factorial of first N numbers 
ll fact[N + 1]; 
  
// Function to precompute inverse of numbers 
void InverseofNumber(ll p) 
{ 
    naturalNumInverse[0] = naturalNumInverse[1] = 1; 
    for (int i = 2; i <= N; i++) 
        naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p; 
} 
// Function to precompute inverse of factorials 
void InverseofFactorial(ll p) 
{ 
    factorialNumInverse[0] = factorialNumInverse[1] = 1; 
  
    // precompute inverse of natural numbers 
    for (int i = 2; i <= N; i++) 
        factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p; 
} 
  
// Function to calculate factorial of 1 to N 
void factorial(ll p) 
{ 
    fact[0] = 1; 
  
    // precompute factorials 
    for (int i = 1; i <= N; i++) { 
        fact[i] = (fact[i - 1] * i) % p; 
    } 
} 
  
// Function to return nCr % p in O(1) time 
ll Binomial(ll N, ll R, ll p) 
{ 
    if (R>N) return 0;
    // n C r = n!*inverse(r!)*inverse((n-r)!) 
    ll ans = ((fact[N] * factorialNumInverse[R]) 
              % p * factorialNumInverse[N - R]) 
             % p; 
    return ans; 
} 


int main(){
  ll p = MOD; 
  InverseofNumber(p);
  InverseofFactorial(p);
  factorial(p);

  ll t,n,m;
  cin>>t;
  ll ans = 0;
  for(int test = 0;test<t;test++){
    cin>>n;
    cin>>m;

    ans = fact[2*n];
    for(int i=1;i<=m;i++){
      cout<<ans<<endl;
      ans += (power(-1,i,MOD)*(Binomial(m,i,MOD))*power(2,i,MOD)*fact[2*n-i]);
      cout<<i<<" "<<ans<<" "<<(Binomial(m,i,MOD))*(power(2,i,MOD)*fact[2*n-i])%MOD<<endl;
      ans = ans%MOD;
      cout<<ans<<endl;
      cout<<endl;
      
    }

/*
ans = factorial(2*a)

(1..b).each do |z|
  puts ((-1)**z)*(binomial(b,z)%mod)*((2**z)%mod)*(factorial(2*a-z)%mod)
  ans += ((-1)**z)*(binomial(b,z)%mod)*((2**z)%mod)*(factorial(2*a-z)%mod)
  ans %=mod
end
*/
    cout<<ans<<endl;
  }
}
