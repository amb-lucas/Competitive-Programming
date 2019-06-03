
void convex_hull(vector<PT> &v) {

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	vector<PT> up, down;

	for(PT p: v){

		while(up.size()>=2 && !p.cw(up[up.size()-2], up.back()))
			up.pop_back();

		while(down.size()>=2 && !p.ccw(down[down.size()-2], down.back()))
			down.pop_back();

		up.push_back(p);
		down.push_back(p);
	}

	v.clear();
	v = up;
	for(int i=down.size()-2; i>0; i--) v.push_back(down[i]);
}
