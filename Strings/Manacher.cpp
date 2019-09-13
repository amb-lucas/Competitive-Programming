
vector<int> findOdd(string &str){
    int n = str.size();
    vector<int> d1(n);
    for(int i=0, l=0, r=-1, k; i<n; i++){
        if(i>r) k = 1;
        else k = min(d1[l+r-i], r-i+1);
        while(0 <= i-k && i+k < n && str[i-k] == str[i+k]) k++;
        d1[i] = k--;
        if(i+k > r){
            l = i-k;
            r = i+k;
        }
    }
    return d1;
}

vector<int> findEven(string &str){
    int n = str.size();
    vector<int> d2(n);
    for(int i=0, l=0, r=-1, k; i<n; i++){
        if(i > r) k = 0;
        else k = min(d2[l+r-i+1], r-i+1);
        while(0 <= i-k-1 && i+k < n && str[i-k-1] == str[i+k]) k++;
        d2[i] = k--;
        if(i+k > r){
            l = i-k-1;
            r = i+k;
        }
    }
    return d2;
}
