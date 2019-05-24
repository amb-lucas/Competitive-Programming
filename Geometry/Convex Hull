struct pt {
    ll x, y;
};

bool cmp(pt a, pt b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool cw(pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

bool ccw(pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

void convex_hull(vector<pt>& a) {

    if(a.size() < 2) return;

    sort(a.begin(), a.end(), cmp);
    vector<pt> up, down;
    up.push_back(a[0]);
    down.push_back(a[0]);

    int j=1;
    while(j<a.size() && a[0].x == a[j].x && a[0].y == a[j].y) j++;

    if(j<a.size()){

        up.push_back(a[j]);
        down.push_back(a[j]);

        for(int i=j+1; i<a.size(); i++){

            while(up.size()>=2 && !cw(up[up.size()-2], up[up.size()-1], a[i]))
                up.pop_back();

            while(down.size()>=2 && !ccw(down[down.size()-2], down[down.size()-1], a[i]))
                down.pop_back();

            up.push_back(a[i]);
            down.push_back(a[i]);
        }
    }

    a.clear();
    for(int i=0; i<up.size(); i++) a.push_back(up[i]);
    if(down.size()>2){
        for(int i=down.size()-2; i; i--) a.push_back(down[i]);
    }
}
