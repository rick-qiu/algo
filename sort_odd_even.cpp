
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

static void sort_odd_even(vector<int>& v) {
    auto idx = v.begin() - 1;
    for(auto it = v.begin(); it != v.end(); ++it) {
        if((*it & 0x1) == 0) {
            ++idx;
            swap(*it, *idx);
        }
    }
}

int main(int argc, char* argv[]) {
    vector<int> v{8, 4, 1, -3, 6, 7, 4, 9, 3, 6, 4};
    sort_odd_even(v);
    for_each(v.begin(), v.end(), [](int i) { cout << i << ' ';});
    cout << endl;
    return 0;
}
