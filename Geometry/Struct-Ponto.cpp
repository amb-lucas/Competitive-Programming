
struct pt {

	double x, y;
	pt(double x = 0, double y = 0): x(x), y(y) {}

	pt operator + (const pt &P){
		return pt(x + P.x, y + P.y);}

	pt operator - (const pt &P){
		return pt(x-P.x, y-P.y);}

	pt operator * (const double d){
		return pt(x*d, y*d);}
	pt operator / (const double d){
		return pt(x/d, y/d);}

	bool operator < (const pt &P){
		if(x == P.x) return y < P.y;
		return x < P.x;
	}
	bool operator == (const pt &P){
		return (x==P.x && y==P.y);}

	double abs(){
    	return x*x + y*y;}
	
	double angle(){
		double a = atan2(y, x);
		if(a<0) a += 2*acos(-1);
		return a;
	}
	
	// Reta AB gira cw ou ccw para chegar em x,y
	bool cw(const pt &a, const pt &b){
		return a.x*(b.y-y) + b.x*(y-a.y) + x*(a.y-b.y) < 0;
	}
	bool ccw(const pt &a, const pt &b){
		return a.x*(b.y-y) + b.x*(y-a.y) + x*(a.y-b.y) > 0;
	}
	bool lined(const pt &a, const pt &b){
		return a.x*(b.y-y) + b.x*(y-a.y) + x*(a.y-b.y) == 0;
	}
};
