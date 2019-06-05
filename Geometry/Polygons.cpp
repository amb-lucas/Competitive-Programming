
// Determina se o ponto p esta dentro do triangulo (a, b, c)
bool pointInsideTriangle(PT &p, PT &a, PT &b, PT &c){
	if(pointInSegment(a,b,p)) return 1;
	if(pointInSegment(b,c,p)) return 1;
	if(pointInSegment(c,a,p)) return 1;
	bool A = p.cw(a, b), B = p.cw(b, c), C = p.cw(c, a);
	return A == B && A == C;
}

// Determina se o ponto esta num poligono convexo em O(lgn)
bool pointInConvexPolygon(vector<PT> &p, PT &q){

	if(p.size() == 0) return 0;
	if(p.size() == 1) return p[0] == q;
	if(p.size() == 2) return pointInSegment(p[0], p[1], q);

	if(pointInSegment(p[0], p[1], q)) return 1;
	if(q.ccw(p[0], p[1])) return 0;
	if(q.cw(p[0], p.back())) return 0;

	int l = 1, m, r = p.size()-1;
	while(l<r-1){
		m = (l+r)>>1;
		if(!q.cw(p[0], p[m])) r = m;
		else l = m;
	}
	return pointInsideTriangle(q, p[0], p[l], p[r]);
}

// Determina se o ponto esta estritamente dentro de um poligono convexo em O(lgn)
bool pointStriclyInConvexPolygon(vector<PT> &p, PT &q){

	if(p.size() < 3) return 0;

	if(pointInSegment(p[0], p[1], q)) return 0;
	if(pointInSegment(p[0],p.back(), q)) return 0;
	if(q.ccw(p[0], p[1])) return 0;
	if(q.cw(p[0], p.back())) return 0;

	int l = 1, m, r = p.size()-1;
	while(l<r-1){
		m = (l+r)>>1;
		if(!q.cw(p[0], p[m])) r = m;
		else l = m;
	}
	if(pointInSegment(p[l],p[r],q)) return 0;
	return pointInsideTriangle(q, p[0], p[l], p[r]);
}

// Calcula centro do circulo dado tres pontos
PT computeCircleCenter(PT a, PT b, PT c){
	b = (a+b)/2;
	c = (a+c)/2;
	return computeLineIntersection(b, b+(a-b).rotateCW(), c, c+(a-c).rotateCW());
}

// Calcula area de um poligono
double area(vector<PT> &P){
	double res = 0;
	for(int i=0; i<P.size(); i++){
		PT p = P[i], q = P[(i+1)%P.size()];
		res += (p.x-q.x)*(p.y+q.y);
	}
	return dabs(res)/2;
}

// Faz a interseção de um poligono com um semiplano (corte CW)
vector<PT> cutPolygon(vector<PT> &Q, PT a, PT b){
	
	PT normal = (b-a).rotateCW().normalize();
	vector<PT> resp;
	for(int i=0; i<Q.size(); i++){

		int j = (i+1)%Q.size();
		double n1 = (Q[i]-a)*(normal);
		double n2 = (Q[j]-a)*(normal);

		if(n1>=-eps) resp.push_back(Q[i]);
		if((n1<-eps && n2>eps) || (n1>eps && n2<-eps)){
			resp.push_back(computeLineIntersection(a, b, Q[i], Q[j]));
		}
	}
	return resp;
}
