
// Parameter R for rests and MOD for modules
// Returns the unique solution format {rest, mod}
// Or {-1, -1} in case there is no solution

pair<ll, ll> CRT(vector<ll> R, vector<ll> MOD){

    ll A = R[0]%MOD[0];
    ll M = MOD[0];

    for(int i=1; i<R.size(); i++){

        ll a2 = R[i];
        
        ll g = gcd(M, MOD[i]);
        if(A%g != R[i]%g) return {-1, -1};
        // If different, there's no solution
        
        ll p, q;
        extGCD(M/g, MOD[i]/g, p, q);

        // Updating MOD to incorporate new equation
        M = M/g * MOD[i];

        // Updating rest to incorporate new equation
        A = (A*((MOD[i]/g)%M))%M;
        A = (A*(q%M))%M;

        int B = ((R[i]%M)*((M/g)%M))%M;
        B = (B*(p%M))%M;

        A = (A+B)%M;
    }

    return {A, M};
}
