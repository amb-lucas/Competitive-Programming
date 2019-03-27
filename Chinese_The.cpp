
// Parameter R for rests and MOD for modules
// Returns the unique solution format {rest, mod}
// Or {-1, -1} in case there is no solution

pair<int, int> CRT(vector<int> R, vector<int> MOD){

    int A = R[0]%MOD[0];
    int M = MOD[0];

    for(int i=1; i<R.size(); i++){

        int a2 = A[i];

        int g = gcd(M, MOD[i]);
        if(A%g != A[i]%g) return {-1, -1};

        int p, q;
        extGCD(M/g, MOD[i]/g, &p, &q);

        // Updating MOD to new LCM
        M = M/g * MOD[i];

        // Updating rest to incorporate new equation
        A = (A*((MOD[i]/g)%M))%M;
        A = (A*(q%M))%M;

        int B = ((A[i]%M)*((M/g)%M))%M;
        B = (B*(p%M))%M;

        A = (A+B)%M;
    }

    return {A, M};
}
