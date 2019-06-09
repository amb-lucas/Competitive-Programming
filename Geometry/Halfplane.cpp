struct halfplane {
	
	PT p1, p2;
	halfplane(PT tp1, PT tp2): p1(tp1), p2(tp2) {}
	
	double ang(){
		return atan2(p2.y - p1.y, p2.x - p1.x);}
	bool operator < (halfplane R){
		if(fabs(this->ang() - R.ang()) <= eps)
			return ((R.p2-R.p1)^(p2-p1)) > eps;
		return (this->ang() - R.ang()) < -eps;
	}
};

bool checkhp(halfplane h1, halfplane h2, halfplane h3){
	PT p = computeLineIntersection(h2.p1, h2.p2, h3.p1, h3.p2);
	return ((h1.p2 - h1.p1)^(p - h1.p1)) < -eps;
}

vector<PT> intersect(vector<halfplane> H){

	sort(H.begin(), H.end());

	vector<halfplane> pl(1, H[0]);
	for(int i=0; i<H.size(); i++){
		if(fabs(H[i].ang() - pl.back().ang()) >= eps) pl.push_back(H[i]);
	}

	deque<int> dq;
	dq.push_back(0);
	dq.push_back(1);

	for(int i=2; i<pl.size(); i++){

		while(dq.size()>1 && checkhp(pl[i], pl[dq.back()], pl[dq[dq.size()-2]]))
			dq.pop_back();

		while(dq.size()>1 && checkhp(pl[i], pl[dq[0]], pl[dq[1]]))
			dq.pop_front();

		dq.push_back(i);
	}

	while(dq.size()>1 && checkhp(pl[dq[0]], pl[dq.back()], pl[dq[dq.size()-2]]))
		dq.pop_back();

	while(dq.size()>1 && checkhp(pl[dq.back()], pl[dq[0]], pl[dq[1]]))
		dq.pop_front();
	
	vector<PT> res;
	for(int i=0; i<dq.size(); i++){
		res.emplace_back(computeLineIntersection(pl[dq[i]].p1, pl[dq[i]].p2, pl[dq[(i+1)%dq.size()]].p1, pl[dq[(i+1)%dq.size()]].p2));
	}

	// Espaço vazio -> Retorna < 3 pontos
	return res;
}

PT dir(halfplane h){
	PT a = h.p2 - h.p1;
	a = a.normalize().rotateCW();
	return a;
}

bool teste(vector<halfplane> &H, double R){

	// halfplane salvo em sentido horário
	// push_back(h.p2, h.p1) -> halfplane em CW
	// push_back(h.p1, h.p2) -> halfplane em CCW

	vector<halfplane> HP;
	for(auto h: H){
		PT d = dir(h);
		HP.push_back(halfplane(PT(h.p2+(d*R)), PT(h.p1+(d*R))));
	}

	vector<PT> P = intersect(HP);

	// existe se retornar mais de 3 pontos
	return P.size() > 2;
}
