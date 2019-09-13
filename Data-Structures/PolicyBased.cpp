
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;


typedef tree<int, null_type, less<int>, rb_tree_tag,
	tree_order_statistics_node_update> ordered_set;
	
// Inserir
s.insert(X);

// Remover
s.erase(X);

// Contar quantia de elementos estritamente menores que o parâmetro
s.order_of_key(X);
