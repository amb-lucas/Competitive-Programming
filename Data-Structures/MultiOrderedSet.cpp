#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
template<typename T>
class multi_ordered_set {
  tree<pair<T, int>, null_type, less<pair<T, int>>, rb_tree_tag,
	    tree_order_statistics_node_update> moset;
	unordered_map<T, int> freq;
	
	public:
	void insert(T x){
	    freq[x]++;
	    moset.insert({x, freq[x]});
	}
	void erase(T x){
	    if(!freq[x]) return;
	    moset.erase({x, freq[x]});
	    freq[x]--;
	}
	int order_of_key(T x){ return moset.order_of_key({x, 0}); }
	int count(T x) { return freq[x]; }
	int size(){ return moset.size(); }
};
 
