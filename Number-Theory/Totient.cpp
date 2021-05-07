// x^n = x^(phi(m)+ n%phi(m)) mod m
// n >= log(m) 

// N = p1ˆk1 * p2ˆk2 ...
// phi(N) = N * (1-1/p1) * (1-1/p2) * ...
// phi(N) = (p1-1)*p1ˆ(k1-1) *  (p2-1)*p2ˆ(k2-1) * ... 

ll phi(ll n) {
	ll ans = n;
	for(int i = 2; i <= n/i; i++) {
		if(n % i == 0) {
			ans /= i;
			ans *= (i-1);
			while(n % i == 0) n /= i;
		}
	}
	if(n > 1){
		ans /= n;
		ans *= (n-1);
	}
	return ans;
}
