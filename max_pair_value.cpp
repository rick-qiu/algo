#include <vector>
#include <limits>
#include <algorithm>
#include <cstdio>

using namespace std;

static int max_pair_value(const vector<int>& v) {
    auto max_value = numeric_limits<int>::min();
    for(auto i = 0; i < v.size(); ++i) {
        for(int j = i; j < v.size(); ++j) {
            max_value = max(max_value, (j - i) * min(v[i], v[j]));
        }
    }
    return max_value;
}


int main(int argc, char *argv[]) {
    vector<int> v{1, 2, 3, 4, 5, 6};
    printf("max = %d\n", max_pair_value(v));
    return 0;
}
