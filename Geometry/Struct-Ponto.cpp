const double eps = 1e-8;

struct PT {

	double x, y;
	PT(double x = 0, double y = 0): x(x), y(y) {}

	// Operações de soma vetoriais
	PT operator + (const PT &P){
		return PT(x + P.x, y + P.y);}
	PT operator - (const PT &P){
		return PT(x-P.x, y-P.y);}

	// Operações de multiplicação por constante
	PT operator * (const double d){
		return PT(x*d, y*d);}
	PT operator / (const double d){
		return PT(x/d, y/d);}

	// Produto Escalar
	double operator * (const PT &P){
		return x*P.x + y*P.y;}
	// Produto Vetorial
	double operator ^ (const PT &P){
		return x*P.y - y*P.x;}

	// Para ordenação e exclusão de repetidos
	bool operator < (const PT &P){
		if(x == P.x) return y < P.y;
		return x < P.x;}
	bool operator == (const PT &P){
		return (*this-P).dist() < eps;}
	bool operator != (const PT &p){
		return !(*this==p);
	}

	// Auxiliares de ângulo (0 - 2pi) e módulo
	double dist(){
		return sqrt(x*x+y*y);}
	double angle(){
		double a = atan2(y, x);
		if(a<0) a += 2*acos(-1);
		return a;}

	// Normalizar vetor (distância = 1)
	PT normalize(){
		return *this/dist();}

	// Rotaciona o ponto CCW ou CW ao redor da origem
	PT rotateCCW(double t = acos(-1)/2){
    	return PT(x*cos(t)-y*sin(t), x*sin(t)+y*cos(t));}
	PT rotateCW(double t = acos(-1)/2){
		return rotateCCW(2*acos(-1)-t);}

	// Reta AB gira CW ou CCW para ficar na direção de (x,y)
	bool cw(PT &a, PT &b){
		return ((*this-a)^(b-a)) < 0;}
	bool ccw(PT &a, PT &b){
		return ((*this-a)^(b-a)) > 0;}
	bool aligned(PT &a, PT &b){
		return fabs((*this-a)^(b-a)) < eps;}
};
