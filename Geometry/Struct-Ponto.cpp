typedef long double ld;
const ld eps = 1e-8;
const ld PI = acosl(-1);

struct PT {

	ld x, y;
	PT(ld x = 0, ld y = 0): x(x), y(y) {}

	PT operator + (const PT P){
		return PT(x + P.x, y + P.y);}
	PT operator - (const PT P){
		return PT(x-P.x, y-P.y);}

	PT operator * (const ld d){
		return PT(x*d, y*d);}
	PT operator / (const ld d){
		return PT(x/d, y/d);}

	ld operator * (const PT P){
		return x*P.x + y*P.y;}
	ld operator ^ (const PT P){
		return x*P.y - y*P.x;}

	bool operator < (const PT &P){
		if(fabs(x-P.x)<eps) return y < P.y;
		return x < P.x;}
	bool operator == (const PT &P){
		return (*this-P).dist() < eps;}

	ld dist(){
		return sqrt(x*x+y*y);}
	ld angle(){
		ld a = atan2l(y, x);
		if(a<0) a += 2*PI;
		return a;}

	PT normalize(){
		return *this/dist();}
	PT rotateCCW(ld t = PI/2){
    	return PT(x*cosl(t)-y*sinl(t), x*sinl(t)+y*cosl(t));}
	PT rotateCW(ld t = PI/2){
		return rotateCCW(2*PI-t);}

	// Reta AB gira CW ou CCW para ficar na direção de (x,y)
	bool cw(PT a, PT b){
		return ((*this-a)^(b-a)) < -eps;}
	bool ccw(PT a, PT b){
		return ((*this-a)^(b-a)) > eps;}
	bool aligned(PT a, PT b){
		return fabs((*this-a)^(b-a)) < eps;}
};
