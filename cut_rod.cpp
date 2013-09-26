#include <vector>
#include <algorithm>
#include <cassert>
#include <cstdio>

using namespace std;

static const vector<int> price{0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};

static int max_value(int length) {
    vector<int> mv(length+1, 0);
    mv.assign(price.begin(), price.end());
    for(auto i = 2; i <= length; ++i) {
        for(auto j = 1; j <= i/2; ++j) {
            mv[i] = max(mv[i], mv[j] + mv[i-j]);
        }
    }
    return mv[length];
}

int main(int argc, char *argv[]) {
    for(auto i = 0; i < 100; ++i) {
        printf("length = %d, max cut value = %d\n", i, max_value(i));
    }
    return 0;
}
