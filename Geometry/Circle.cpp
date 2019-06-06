
struct Circle {

	PT P;
	double R;

	bool inside(PT &Q){
		return (P-Q).dist() < R-eps;}
	bool onBorder(PT &Q){
		return fabs((P-Q).dist()-R) <= eps;}
	bool outside(PT &Q){
		return (P-Q).dist() > R+eps;}
};

// falta o caso de apenas uma tangente
// quando um circulo tá centrado dentro do outro
// funciona pra circulos de mesmo raio

vector<pair<PT, PT>> getTangets(Circle A, Circle B){
	
	if(B.P < A.P) swap(A, B);
	vector<pair<PT, PT> > ans;

	if((B.P-A.P).dist() <= eps){
		// Caso degenerado (Ou infinitas tangentes ou 0 tangentes
		ans.push_back({A.P, A.P+PT(1,1)});
		return ans;
	}

	PT PC = A.P, dir = B.P-A.P;
	PC = PC + (dir*(A.R/(A.R+B.R)));

	if(A.onBorder(PC)){
		dir = dir.rotateCW();
		ans.push_back({PC, PC+dir});
	}
	else if(!A.inside(PC)){
		double alfa = acos(A.R/(PC-A.P).dist());
		dir = dir.rotateCW(alfa);
		ans.push_back({PC, PC+dir});
		dir = dir.rotateCCW(2*alfa);
		ans.push_back({PC, PC+dir});
	}

	double beta = atan2((B.R-A.R), (B.P-A.P).dist());
	dir = (B.P-A.P).normalize().rotateCCW();
	dir = dir.rotateCCW(beta);
	ans.push_back({A.P+(dir*A.R), B.P+(dir*B.R)});

	dir = (B.P-A.P).normalize().rotateCW();
	dir = dir.rotateCW(beta);
	ans.push_back({A.P+(dir*A.R), B.P+(dir*B.R)});

	return ans;
}
