#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

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

template<typename ForwardIterator, typename CMP>
ForwardIterator topk(ForwardIterator begin, ForwardIterator end, CMP cmp, unsigned int k) {
    typedef typename iterator_traits<ForwardIterator>::difference_type diff_t;
    auto dist = static_cast<diff_t>(k); 
    auto ret(end);
    auto start(begin);
    while(distance(start, ret) > dist) {
        auto idx = start;
        for(auto it = start + 1; it != ret; ++it) {
            if(cmp(*it, *start)) {
                ++idx;
                swap(*idx, *it);
            }
        }
        swap(*start, *idx);
        ++idx;
        const auto d = distance(start, idx);
        if(d == dist) {
            ret = idx;
        } else if(d < dist) {
            start = idx;
            dist -= d;
        } else {
            ret = idx;
        }
    }
    return ret;
}


int main(int argc, char* argv[]) {
    vector<int> c = {5, 3, 4, -1, 0, 2, 6, 1};
    int k = 4;
    auto op = [](int a, int b)->bool{ return a < b; };
    auto idx = topk(c.begin(), c.end(), op, k);
    for(auto it = c.begin(); it != idx; ++it) {
        cout <<*it << ' ';
    }
    cout << endl;
    return 0;
}
