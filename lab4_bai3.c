#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;          
    struct Node *next; 
} Node;

Node* make_node(int x) {
    Node *p = (Node*)malloc(sizeof(Node));
    if (!p) { 
        fprintf(stderr, "Loi cap phat bo nho!\n"); 
        exit(1); 
    }
    p->data = x;
    p->next = NULL;
    return p;
}

void push_back(Node **head, int x) {
    Node *p = make_node(x);
    if (!*head) { 
        *head = p;
        return;
    }
    Node *cur = *head;
    while (cur->next)
        cur = cur->next;
    cur->next = p;
}

void push_front(Node **head, int x) {
    Node *p = make_node(x);
    p->next = *head;
    *head = p;
}

void print_list(Node *head) {
    printf("Danh sach hien tai: ");
    for (Node *cur = head; cur; cur = cur->next)
        printf("%d ", cur->data);
    printf("\n");
}

int size(Node *head) {
    int cnt = 0;
    for (Node *c = head; c; c = c->next)
        cnt++;
    return cnt;
}

Node* find_first(Node *head, int x) {
    for (Node *c = head; c; c = c->next)
        if (c->data == x)
            return c;
    return NULL;
}

void clear_list(Node **head) {
    Node *c = *head;
    while (c) {
        Node *t = c->next;
        free(c);
        c = t;
    }
    *head = NULL;
}

int main() {
    Node *head = NULL;
    int n;

    printf("Nhap so phan tu n: ");
    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0, x; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &x);
        push_back(&head, x);
    }

    print_list(head);

    printf("So luong phan tu: %d\n", size(head));

    int q;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &q);

    if (find_first(head, q))
        printf("Ket qua: FOUND (co ton tai %d trong danh sach)\n", q);
    else
        printf("Ket qua: NOT FOUND (khong tim thay %d)\n", q);
    clear_list(&head);
    return 0;
}
