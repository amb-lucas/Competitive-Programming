
// Determina se as linhas a - b e c - d sao paralelas ou colineares
bool linesParallel(PT a, PT b, PT c, PT d){
	return abs((b-a)^(c-d))<eps;
}
bool linesCollinear(PT a, PT b, PT c, PT d){
	return a.alligned(c, d) && b.alligned(c, d);
}

// Projeta ponto c na linha a - b assumindo a != b
PT projectPointLine(PT a, PT b, PT c){
	if(a == b) return a;
	return a + (b-a)*((c-a)*(b-a))/((b-a)*(b-a));
}

// Determina se o ponto c esta na linha a - b assumindo a != b
bool pointInLine(PT a, PT b, PT c){
	return fabs((b-a)^(c-a)) < eps;
}

// Determina se o ponto c esta em um segmento a - b
bool pointInSegment(PT a, PT b, PT c){
	if(a == b) return a == c;
	bool x = min(a.x, b.x) <= c.x && c.x <= max(a.x, b.x);
	bool y = min(a.y, b.y) <= c.y && c.y <= max(a.y, b.y);
	return x && y && pointInLine(a, b, c);
}

// Determina se o segmento a - b intersecta com o segmento c - d
bool segmentsIntersect(PT a, PT b, PT c, PT d){

	if(a == b) return pointInSegment(c, d, a);
	if(c == d) return pointInSegment(a, b, c);

	if(linesCollinear(a,b,c,d)){
		if(a==c || a==d || b==c || b==d) return 1;
		if((c-a)*(c-b)>0 && (d-a)*(d-b)>0 && (c-b)*(d-b)>0) return 0;
		return 1;
	}

	if( ((d-a)^(b-a))*((c-a)^(b-a)) > 0) return 0;
	if( ((a-c)^(d-c))*((b-c)^(d-c)) > 0) return 0;
	return 1;
}

// Calcula a intersecao entre as retas a - b e c - d assumindo que uma unica intersecao existe
// Para intersecao de segmentos, cheque primeiro se os segmentos intersectam e que nao sao paralelos
PT computeLineIntersection(PT a, PT b, PT c, PT d){
	b=b-a; d=c-d; c=c-a;
	return a + b*(c^d)/(b^d);
}
