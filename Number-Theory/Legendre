
// Legendre's Formula
// the largest power of prime p that divides n! is
// n/p + n/p^2 + n/p^3 + ...

int largestPower(ll n, ll p){

	int ans = 0;
	while(n>=p){
		ans += (n/p);
		n /= p;
	}
	
	return ans;
}
