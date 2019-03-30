
// Returns correct rest of r in mod m
ll normalize(ll r, ll m){
	r %= m;
	if(r<0) r+=m;
	return r;
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
 		ll x = ((__int128)A*(m/g)%mod*q%mod + (__int128)a*(M/g)%mod*p%mod)%mod;

 		M = mod;
 		A = normalize(x, M);
    }

    return {A, M};
}
