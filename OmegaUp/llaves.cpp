#include <iostream>
#include <algorithm>
#include <vector>

template<typename iter, typename T>
int binary_search_ret(iter first, iter last, const T& value)
{
	int compare;
	auto inicio = first;
    first = std::lower_bound(first, last, value);
    if (!(first == last) && !(value < *first)) {
    	compare = (int) (first - inicio);
    } else {
    	compare = -1;
    }	
    return compare;
}

int main(void) 
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	
	int l, i, k;
	std::cin >> l;
	std::vector<int> v_m;
	for ( i = 0; i < l; ++i) {
		std::cin >> k;
		v_m.push_back(k);
	}
	std::cin >> l;
	std::vector<int> v_n;
	for ( i = 0; i < l; ++i) {
		std::cin >> k;
		v_n.push_back(k);
	}

	for (int i = 0; i < l; ++i) {
		k = binary_search_ret(v_m.begin(),v_m.end(),v_n[i]);
		if(k!=-1) {
			std::cout << k+1;
		} else {
			std::cout << '0';
		}
		std::cout << ' ';
	}
	std::cout << '\n';
	return(0);
}