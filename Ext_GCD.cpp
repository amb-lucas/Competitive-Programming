
ll extGCD(ll a, ll b, ll& X, ll& Y){

	if(b == 0){
		X = 1;
		Y = 1;
		return a;
	}
	
	ll nx, ny;
	ll gcd = extGCD(a%b, b, nx, ny); 
	
	X = ny - (b/a)*nx;
	Y = nx;
	
	return gcd;
}

// Bezout's Identity states the following:
// ax + by = gcd(a,b) 

// More solutions as
// ( x + k*b/gcd(a,b), y – k*a/gcd(a,b))
