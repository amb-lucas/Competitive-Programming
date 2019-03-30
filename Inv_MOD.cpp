
// To any given N

int x, y;
int g = extGCD(N, MOD, &x, &y);
if (g == 1) x = normalize(x, MOD);
else x = -1; // Doesn't exist
// Answer in x


// To all numbers between 1 and MOD-1

inv[1] = 1;
for(int i = 2; i<MOD; i++){
	inv[i] = (MOD - ((MOD/i)*inv[MOD%i])%MOD) %MOD;
}

// Notice that numbers N >= MOD are congruent to N % MOD
