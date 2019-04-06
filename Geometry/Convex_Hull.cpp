
struct pt {
    double x, y;
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

vector<pt> up, down;

void convex_hull(vector<pt>& a) {

    sort(a.begin(), a.end(), cmp);

    if(a.size()){
        up.push_back(a[0]);
        down.push_back(a[0]);
    }

    if(a.size()>1){
        up.push_back(a[1]);
        down.push_back(a[1]);
    }    

    for (int i=2; i<a.size(); i++) {

        while(up.size()>=2 && !cw(up[up.size()-2], up[up.size()-1], a[i]) ){
            up.pop_back();
        }

        up.push_back(a[i]);
        
        while(down.size()>=2 && !ccw(down[down.size()-2], down[down.size()-1], a[i]) ){
            down.pop_back();
        }

        down.push_back(a[i]);
    }

    a.clear();
    for(int i=0; i<up.size(); i++) a.push_back(up[i]);
    for(int i=down.size()-2; i; i--) a.push_back(down[i]);
}
