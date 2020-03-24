a = 10
b = 5

mod =  10**9 + 7

def factorial(x)
  ans = 1
  return 1 if x<= 1
  (1..x).each {|z| ans*=z}
  return ans
end

def binomial(n,r)
  return factorial(n)/(factorial(n-r)*factorial(r))
end

ans = factorial(2*a)%mod

(1..b).each do |z|
  puts ans
  puts ((-1)**z)*(binomial(b,z)%mod)*((2**z)%mod)*(factorial(2*a-z)%mod)
  ans += ((-1)**z)*(binomial(b,z)%mod)*((2**z)%mod)*(factorial(2*a-z)%mod)
  puts ans
  puts
  ans %=mod
end

puts ans
