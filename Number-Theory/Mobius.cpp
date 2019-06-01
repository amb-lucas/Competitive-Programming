
/*

N = p1^k1 * p2^k2 * p3^k3 ... pm^km

if there's a ki>=2, then M(N) = 0
else if m%2 = 1, then M(N) = -1   // odd number of primes
else M(N) = 1                     // even number of primes

*** M(1) = 1 ***

*/

for(int i=1; i<LIM; i++){
	mobius[i] = 1;
	primo[i] = 1;
}
  
for(int i=2; i<LIM; i++){

	if(primo[i]){
		
		for(int j=i; j<LIM; j+=i){
			mobius[j] = -mobius[j];
			primo[j] = 0;
		}
		
		if(i<=LIM/i){
			for(int j=i*i; j<LIM; j+=(i*i)){
				mobius[j] = 0;
			}
		}
	}
}
