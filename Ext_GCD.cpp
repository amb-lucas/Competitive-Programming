
int extGCD(int a, int b, int *X, int *Y){

	if(b == 0){
		*X = 1;
		*Y = 1;
		return a;
	}

	int nx, ny;
    int gcd = extGCD(a%b, b, &nx, &ny); 

    *X = ny - (b/a)*nx;
    *Y = nx;

    return gcd;
}
