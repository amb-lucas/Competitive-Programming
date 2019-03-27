
int x, y;
int g = extGCD(a, m, &x, &y);

if (g == 1) x = (x % m + m) % m;

// Resposta em x
// Existe se e somente si a e m forem primos entre si
