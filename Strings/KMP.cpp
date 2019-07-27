const int LIMSZ = 1e6+10;
string text, patt;
int b[LIMSZ];

void kmp_pre(){
	int i = 0, j = -1;
	b[i] = j;
	while(patt[i] != '\0'){
		while(j >= 0 && patt[j] != patt[i]) j = b[j];
		j++, i++;
		b[i] = j;
	}
}

vector<int> v;

void kmp_search(){
	int i = 0, j = 0;
	while(text[i] != '\0'){
		while(j >= 0 && text[i] != patt[j]) j = b[j];
		i++, j++;
		if(patt[j] == '\0'){
			// Match at i-j
			v.push_back(i-j);
			j = b[j];
		}
	}
}
