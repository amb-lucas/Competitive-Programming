
ll extGCD(ll a, ll b, ll &x, ll &y){

	if(a == 0){
        x = 0;
        y = 1;
        return b;
    }

    ll nx, ny;
    ll d = extGCD(b % a, a, nx, ny);
    x = ny-(b/a)*nx;
    y = nx;
	
    return d;
}

// Bezout's Identity states the following:
// ax + by = gcd(a,b) 

// More solutions as
// ( x + k*b/gcd(a,b), y – k*a/gcd(a,b))
