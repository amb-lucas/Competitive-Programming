
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

	return res;
}

bool teste(vector<PT> &P, double R){

	// push_back(q, p) -> halfplane em CW
	// push_back(p, q) -> halfplane em CCW

	vector<halfplane> HP;
	for(int i=0; i<P.size(); i++){
		PT p = P[i], q = P[(i+1)%P.size()];
		PT d = q-p;
		d = d.normalize().rotateCW();
		HP.push_back(halfplane(q+(d*R), p+(d*R)));
	}

	vector<PT> PP = intersect(HP);
	// existe se retornar mais de 3 pontos
	return PP.size() > 2;
}
