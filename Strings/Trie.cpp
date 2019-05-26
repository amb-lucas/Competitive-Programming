const int MAXN = 5e4+10;
const int LM = 50;
const int ALF = 52;

struct node{
	int next[ALF];
	int nstr;
};

int HASH(char a){
	if(a>='a') return a-'a'+26;
	return a-'A';
}

node trie[MAXN*LM];
int itrie;

int newnode(){
	int a = ++itrie;
	for(int i=0; i<ALF; i++) trie[a].next[i] = 0;
	trie[a].nstr = 0;
	return a;
}

void novocaso(){
	itrie = -1;
	newnode();
}

int istr;
string str;

void insert(int on = 0, int p = 0){

	if(str[p] == '\0') trie[on].nstr = istr;
	else{
		int c = HASH(str[p]);
		if(trie[on].next[c] == 0){
			trie[on].next[c] = newnode();
		}
		insert(trie[on].next[c], p+1);
	}
}
