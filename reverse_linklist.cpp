#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

struct node {
    node(int i, node* p): value(i), next(p) {}
    int value;
    node* next;
};

void create_linklist(const vector<int>& src, node*& head) {
    head = nullptr;
    for_each(src.rbegin(), src.rend(), [&](int i) { auto p = new node(i, head); head = p;});
}

void release_linklist(node*& head) {
    while(head != nullptr) {
        auto p = head;
        head = head->next;
        delete p;
    }
}

void print_linklist(const node* head) {
    while(head != nullptr) {
        printf("%d", head->value);
        if(head->next != nullptr) {
            printf("->");
        }
        head = head->next;
    }
    printf("\n");
}

void reverse_linklist(node*& head) {
    if(head == nullptr || head->next == nullptr) {
        return;
    }
    node* prev = nullptr;
    auto cur = head;
    auto next = cur->next;
    while(cur != nullptr && next != nullptr) {
        cur->next = prev;
        prev = cur;
        cur = next;
        next = cur->next;
    }
    cur->next = prev;
    head = cur;
}

void reverse_linklist(node*& head, int n) {
    if(head == nullptr || head->next == nullptr) {
        return;
    }
    node** tail = &head;
    auto subhead = head;
    while(true) {
        node* prev = nullptr;
        auto cur = subhead;
        auto next = cur->next;
        auto i = 0;
        while(next != nullptr && i < n) {
            cur->next = prev;
            prev = cur;
            cur = next;
            next = cur->next;
            ++i;
        }
        if(i == n) {
            *tail = prev;
            tail = &(subhead->next);
            subhead = cur;
        } else {
            cur->next = prev;
            *tail = cur;
            break;
        }
    }
}

int main(int argc, char *argv[]) {
    vector<int> source{1, 2, 3, 4, 5 ,6};
    node* head = nullptr;
    create_linklist(source, head);
    print_linklist(head);
    reverse_linklist(head, 4);
    print_linklist(head);
    release_linklist(head);
    return 0;
}
