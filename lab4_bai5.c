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
    Node *cur;
    for (cur = head; cur; cur = cur->next)
        printf("%d ", cur->data);
    printf("\n");
}

void remove_duplicates_unsorted(Node *head) {
    Node *i, *j, *temp;
    for (i = head; i != NULL; i = i->next) {
        j = i;
        while (j->next != NULL) {
            if (j->next->data == i->data) {
                temp = j->next;
                j->next = j->next->next;
                free(temp);
            } else {
                j = j->next;
            }
        }
    }
}

void sorted_insert(Node **head, int x) {
    Node *p = make_node(x);
    if (!*head || (*head)->data >= x) {
        p->next = *head;
        *head = p;
        return;
    }
    Node *c = *head;
    while (c->next && c->next->data < x)
        c = c->next;
    p->next = c->next;
    c->next = p;
}

int main() {
    Node *head = NULL;
    int n, x;

    printf("Nhap so phan tu n: ");
    scanf("%d", &n);
    int i;
	for (i = 0; i < n; i++) {
        scanf("%d", &x);
        push_back(&head, x);
    }

    printf("Danh sach ban dau: ");
    print_list(head);

    remove_duplicates_unsorted(head);
    printf("Danh sach sau khi xoa trung lap: ");
    print_list(head);

    printf("Nhap gia tri can chen (vao ds tang dan): ");
    scanf("%d", &x);
    sorted_insert(&head, x);

    printf("Danh sach sau khi chen: ");
    print_list(head);

    return 0;
}
