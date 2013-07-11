#include <iostream>

using namespace std;

static int count(int i) {
    int cnt = 0;
    while(i) {
	++cnt;
	i &= (i - 1);
    }
    return cnt;
}

static int test0() {
    if(0 == count(0)) {
	cout << "test0 passed" << endl;
	return 0;
    } else {
	cout << "test0 failed" << endl;
	return -1;
    }
}

static int test1() {
    if(1 == count(1)) {
	cout << "test1 passed" << endl;
	return 0;
    } else {
	cout << "test1 failed" << endl;
	return -1;
    }
}

static int test2() {
    if(1 == count(2)) {
	cout << "test2 passed" << endl;
	return 0;
    } else {
	cout << "test2 failed" << endl;
	return -1;
    }
}


int main(int argc, char* argv[]) {
    test0();
    test1();
    test2();
    return 0;
}
