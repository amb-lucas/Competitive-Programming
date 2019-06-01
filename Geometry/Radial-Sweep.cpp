
struct evento {

	double ang;
	int tipo;
	evento(double ang = 0, int tipo = 0): ang(ang), tipo(tipo) {}

	bool operator < (const evento &E){
		if(ang == E.ang) return tipo > E.tipo;
		return ang < E.ang;
	}
};

double normalizar(double ang){
	if(ang>2*acos(-1)) return ang-2*acos(-1);
	if(ang<0) return ang+2*acos(-1);
	return ang;
}

int N;
vector<pt> P;

int query(int p, double R){

	vector<evento> ev;

	int cnt = 0;
	for(int i=0; i<N; i++){

		if(P[p] == P[i]) cnt++;
		else if(2*R >= (P[i]-P[p]).abs()){

			double alfa = (P[i]-P[p]).angle();
			double beta = acos((P[i]-P[p]).abs()/(2*R));

			double ini = normalizar(alfa - beta);
			double fim = normalizar(alfa + beta);

			if(ini > fim) cnt++;

			ev.push_back(evento(ini, 1));
			ev.push_back(evento(fim, -1));
		}
	}

	int qans = cnt;
	sort(ev.begin(), ev.end());

	for(int i=0; i<ev.size(); i++){
		evento E = ev[i];
		cnt += E.tipo;
		qans = max(qans, cnt);
	}

	return qans;
}
