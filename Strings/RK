const int ALFSZ = 26;

ll add_left(ll act, char a, int sz){
    ll inc = a-'a'+1;
    inc = (inc*pot[sz])%MOD;
    return (act+inc)%MOD;
}

ll add_right(ll act, char a){
    act = (act*ALFSZ)%MOD;
    act += a-'a'+1;
    return act%MOD;
}
