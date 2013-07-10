#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

typedef int elem_t;

typedef vector<elem_t> container_t;

typedef typename container_t::const_iterator it_t;

pair<it_t, it_t> find_pair(const container_t& v, elem_t sum) {
    int i = 0;
    int j = v.size() - 1;
    while( i != j) {
	if(v[i] + v[j] > sum) {
	    --j;
	} else if(v[i] + v[j] < sum) {
	    ++i;
	} else {
	    return make_pair(v.begin()+i, v.begin()+j);
	}
    }
    return make_pair(v.end(), v.end());
} 


int main(int argc, char* argv[]) {
    container_t c = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    elem_t sum = 8;
    pair<it_t, it_t> p = find_pair(c, sum);
    if(p.first != c.end() && p.second != c.end()) {
	cout << *(p.first) << " + " << *(p.second) << " = " << sum << endl;
    } else {
	cout << "No pair's sum equals " << sum << endl;
    }
    return 0;
}
