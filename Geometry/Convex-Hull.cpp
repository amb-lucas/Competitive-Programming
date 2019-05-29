
void convex_hull(vector<pt> &v) {

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    vector<pt> up, down;

    for(pt p: v){

        while(up.size()>=2 && !cw(up[up.size()-2], up.back(), p) )
            up.pop_back();

        while(down.size()>=2 && !ccw(down[down.size()-2], down.back(), p) )
            down.pop_back();

        up.push_back(p);
        down.push_back(p);
    }

    v.clear();
    v = up;
    for(int i=down.size()-2; i>0; i--) v.push_back(down[i]);
}
