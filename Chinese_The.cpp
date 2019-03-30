
// Returns correct rest of r in mod m
ll normalize(ll r, ll m){
	return ((r%m)+m)%m;
}

// Parameter R for rests and MOD for modules
// Returns the unique solution format {rest, mod}
// Or {-1, -1} in case there is no solution

pair<ll, ll> CRT(vector<ll> R, vector<ll> MOD){
 
    ll A = R[0];
    ll M = MOD[0];
 
    for(int i=1; i<R.size(); i++){

        ll a = R[i];
        ll m = MOD[i];
 
        ll g = gcd(M, m);
        if (A%g != a%g) return {-1,-1};
 
        ll p, q;
        extGCD(M/g, m/g, p, q);
 
        ll mod = (M/g)*m;
 
 		A = (A*(m/g))%mod;
 		A = (A*q)%mod;

 		ll B = (a*(M/g))%mod;
 		B = (B*p)%mod;

 		A = (A+B)%mod;
 		M = mod;
 		A = normalize(A, M);
    }

    return {A, M};
}
