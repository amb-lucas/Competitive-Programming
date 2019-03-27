
// Para apenas um determinado N

int x, y;
int g = extGCD(N, MOD, &x, &y);
if (g == 1) x = (x % MOD + MOD) % MOD;

// Resposta em x
// Existe se e somente si a e m forem primos entre si


// Para todos os números entre 1 e MOD-1

inv[1] = 1;
for(int i = 2; i<MOD; i++){
	inv[i] = (MOD - ((MOD/i)*inv[MOD%i])%MOD) %MOD;
}

// Note que os números >= a MOD são congruentes à num%mod
