
// Determina se as linhas a - b e c - d sao paralelas ou colineares
bool linesParallel(PT a, PT b, PT c, PT d){
	return abs((b-a)^(c-d))<eps;
}
bool linesCollinear(PT a, PT b, PT c, PT d){
	return a.alligned(c, d) && b.alligned(c, d);
}

// Projeta ponto c na linha a - b assumindo a != b
PT projectPointLine(PT a, PT b, PT c){
	return a + (b-a)*((c-a)*(b-a))/((b-a)*(b-a));
}

// Determina se o segmento a - b intersecta com o segmento c - d
bool segmentsIntersect(PT a, PT b, PT c, PT d){

	if(linesCollinear(a,b,c,d)){
		if((a-c).dist()<eps || (a-d).dist()<eps || (b-c).dist()<eps || (b-d).dist()<eps) return 1;
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

// Calcula centro do circulo dado tres pontos
PT computeCircleCenter(PT a, PT b, PT c){
	b = (a+b)/2;
	c = (a+c)/2;
	return computeLineIntersection(b, b+(a-b).rotateCW(), c, c+(a-c).rotateCW());
}
