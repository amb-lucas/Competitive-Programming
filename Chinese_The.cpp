
// Parâmetro R de restos e MOD de módulos
// Retorna {resto, módulo}, onde resto é a solução única em módulo
// Caso não exista solução, retorna {-1, -1}

pair<int, int> CRT(vector<int> R, vector<int> MOD){

    int A = R[0]%MOD[0];
    int M = MOD[0];

    for(int i=1; i<R.size(); i++){

        int a2 = A[i];

        int g = gcd(M, MOD[i]);
        if(A%g != A[i]%g) return {-1, -1};

        int p, q;
        extGCD(M/g, MOD[i]/g, &p, &q);

        // Atualização do MOD para novo LCM
        M = M/g * MOD[i];

        // Atualização do resto
        A = (A*((MOD[i]/g)%M))%M;
        A = (A*(q%M))%M;

        int B = ((A[i]%M)*((M/g)%M))%M;
        B = (B*(p%M))%M;

        A = (A+B)%M;
    }

    return {A, M};
}
