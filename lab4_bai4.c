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
    if (!*head) {
        *head = p;
        return;
    }
    Node *cur = *head;
    while (cur->next)
        cur = cur->next;
    cur->next = p;
}

void print_list(Node *head) {
    Node *cur;               
    cur = head;             
    while (cur != NULL) {    
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

void reverse(Node **head) {
    Node *prev = NULL;
    Node *cur = *head;
    while (cur) {
        Node *next = cur->next; 
        cur->next = prev;       
        prev = cur;          
        cur = next;         
    }
    *head = prev; 
}

int main() {
    Node *head = NULL;
    int n, x;

    printf("Nhap so phan tu n: ");
    scanf("%d", &n);
	int i;
    for (i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &x);
        push_back(&head, x);
    }

    printf("\nDanh sach ban dau: ");
    print_list(head);

    reverse(&head);

    printf("Danh sach sau khi dao nguoc: ");
    print_list(head);

    return 0;
}
