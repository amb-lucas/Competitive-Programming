const int ALFSZ = 26;
const int FAT = ALFSZ+1;

ll add_left(ll act, char a, int sz){
    ll inc = a-'a'+1;
    inc = (inc*pot[sz])%MOD;
    return (act+inc)%MOD;
}

ll add_right(ll act, char a){
    act = (act*FAT)%MOD;
    act += a-'a'+1;
    return act%MOD;
}
