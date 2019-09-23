/*
- Number of correct bracket sequence consisting of n opening and n closing brackets.
- The number of rooted full binary trees with n+1 leaves (vertices are not numbered). A rooted binary tree is full if every vertex has either two children or no children.
- The number of ways to completely parenthesize n+1 factors.
- The number of triangulations of a convex polygon with n+2 sides (i.e. the number of partitions of polygon into disjoint triangles by using the diagonals).
- The number of ways to connect the 2n points on a circle to form n disjoint chords.
- The number of non-isomorphic full binary trees with n internal nodes (i.e. nodes having at least one son).
- The number of monotonic lattice paths from point (0,0) to point (n,n) in a square lattice of size n×n, which do not pass above the main diagonal (i.e. connecting (0,0) to (n,n)).
- Number of permutations of length n that can be stack sorted (i.e. it can be shown that the rearrangement is stack sorted if and only if there is no such index i<j<k, such that ak<ai<aj ).
- The number of non-crossing partitions of a set of n elements.
- The number of ways to cover the ladder 1…n using n rectangles (The ladder consists of n columns, where ith column has a height i).
*/

/*
C(n) = (2n!)/(n+1)!n!
ou
C(n) = C(n-1)*2*(2*n-1)/(n+1)
*/

typedef long long ll;

const int LIM = 5e3+10;
ll cat[LIM];
ll inv[LIM+10];

void pre(){
    inv[1] = 1;
    for(int i = 2; i<LIM+10; i++)
    	inv[i] = (MOD - ((MOD/i)*inv[MOD%i])%MOD) %MOD;
    
    cat[1] = 1;
    for(int i=2; i<LIM-1; i++){
        cat[i] = (cat[i-1]<<1)%MOD;
        cat[i] = (cat[i]*(2*i-1))%MOD;
        cat[i] = (cat[i]*inv[i+1])%MOD;
    }
}
