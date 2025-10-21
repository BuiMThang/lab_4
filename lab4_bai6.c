#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* make_node(int x) {
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = x;
    p->next = NULL;
    return p;
}

void push_back(Node **head, int x) {
    Node *p = make_node(x);
    if (!*head) { *head = p; return; }
    Node *cur = *head;
    while (cur->next) cur = cur->next;
    cur->next = p;
}

void print_list(Node *head) {
    Node *cur = head;
    while (cur) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

Node* merge_sorted(Node* a, Node* b) {
    Node dummy = {0, NULL};
    Node *tail = &dummy;

    while (a && b) {
        if (a->data <= b->data) {
            tail->next = a;
            a = a->next;
        } else {
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }

    tail->next = (a) ? a : b;

    return dummy.next;
}

int main() {
    Node *A = NULL, *B = NULL, *C = NULL;
    int n, m, x;

    printf("Nhap so phan tu cua danh sach A: ");
    scanf("%d", &n);
    int i;
	for (i = 0; i < n; i++) {
        scanf("%d", &x);
        push_back(&A, x);
    }

    printf("Nhap so phan tu cua danh sach B: ");
    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        scanf("%d", &x);
        push_back(&B, x);
    }

    printf("Danh sach A: "); print_list(A);
    printf("Danh sach B: "); print_list(B);

    C = merge_sorted(A, B);

    printf("Danh sach sau khi tron: ");
    print_list(C);

    return 0;
}
