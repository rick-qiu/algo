#include <cstdio>

char* reverse_string(char* str) {
    if(str == nullptr) {
        return nullptr;
    }
    auto end = str;
    while(*end != '\0') {
        ++end;
    }
    --end;
    auto begin = str;
    while(begin < end) {
        auto ch = *begin;
        *begin = *end;
        *end = ch;
        ++begin;
        --end;
    }
    return str;
}

int main(int argc, char *argv[]) {

    return 0;
}

