#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T, typename CMP>
typename vector<T>::size_type topk(vector<T>& a, typename vector<T>::size_type s, 
				   typename vector<T>::size_type e, int k, CMP cmp) {
    if(k <= 0) return a.size();
    if(a.size() <= k) return 0;
    typedef typename vector<T>::size_type idx_t;
    idx_t idx = s;
    for(idx_t i = s + 1; i < e; ++i) {
	if(cmp(a[i], a[s])) {
	    ++idx;
	    swap(a[idx], a[i]);
	}
    }
    swap(a[s], a[idx]);
    if(e - idx == k) {
	return idx;
    } else if(e - idx > k) {
	return topk(a, idx+1, e, k, cmp);
    } else {
	return topk(a, s, idx, k+idx-e, cmp);
    }
}


int main(int argc, char* argv[]) {
    vector<int> c = {5, 3, 4, 0, 2, 1};
    int k = 3;
    auto op = [](int a, int b)->bool{ return a < b; };
    int idx = topk(c, 0, c.size(), k, op);
    cout << "idx = " << idx << endl;
    for(int i = idx; i < c.size(); ++i) {
	cout << c[i] << " ";
    }
    cout << endl;
    return 0;
}
