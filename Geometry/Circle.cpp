
struct circle {

	PT P;
	ld R;
	circle(PT P = PT(), ld R = 0): P(P), R(R) {};

	bool inside(const PT Q){
		return (P-Q).dist() < R-eps;}
	bool onBorder(const PT Q){
		return fabs((P-Q).dist()-R) <= eps;}
	bool outside(const PT Q){
		return (P-Q).dist() > R+eps;}
};


// MENOR CIRCULO QUE COBRE TODOS OS PONTOS

PT LineIntersection(PT a, PT b, PT c, PT d){
	b=b-a; d=c-d; c=c-a;
	return a + b*(c^d)/(b^d);
}

PT circleCenter(PT a, PT b, PT c){
	if(a == b) return (a+c)/2;
	if(a == c) return (a+b)/2;
	if(b == c) return (a+c)/2;
	if(a.aligned(b, c)){
		PT q[3] = {a,b,c};
		sort(q, q+3);
		return (q[0]+q[2])/2;
	}
	b = (a+b)/2;
	c = (a+c)/2;
	return LineIntersection(b, b+(a-b).rotateCW(), c, c+(a-c).rotateCW());
}

circle circleCover(PT a, PT b, PT c){
	PT P = circleCenter(a, b, c);
	ld R = max((P-a).dist(), (P-b).dist());
	R = max(R, (P-c).dist());
	return circle(P, R);
}

circle circleCover(vector<PT> P){

	int n = P.size();
	random_shuffle(P.begin(), P.end());
	circle C;

	for(int i=0; i<n; i++){
		if(C.outside(P[i])){
			C = circle(P[i], 0);

			for(int j=0; j<i; j++){
				if(C.outside(P[j])){
					C = circleCover(P[i], P[i], P[j]);

					for(int k=0; k<j; k++){
						if(C.outside(P[k]))
							C = circleCover(P[i], P[j], P[k]);
					}
				}
			}
		}
	}

	return C;
}


// falta o caso de apenas uma tangente
// quando um circulo tá centrado dentro do outro
// funciona pra circulos de mesmo raio

vector<pair<PT, PT>> getTangets(circle A, circle B){
	
	if(B.P < A.P) swap(A, B);
	vector<pair<PT, PT> > ans;

	if(B.P == A.P){
		// Caso degenerado (Ou infinitas tangentes ou 0 tangentes)
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
