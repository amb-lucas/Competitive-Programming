
ll extGCD(ll a, ll b, ll &x, ll &y){

	if(b == 0){
        x = 1;
        y = 0;
        return a;
    }

    ll nx, ny;
    ll d = extGCD(b, a%b, nx, ny);

    x = ny;
    y = nx-(a/b)*ny;
    return d;
}

// Bezout's Identity states the following:
// ax + by = gcd(a,b) 

// More solutions as
// ( x + k*b/gcd(a,b), y – k*a/gcd(a,b))
