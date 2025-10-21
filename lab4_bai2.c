#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int heSo;
    int soMu;
    struct Node* next;
} Node;

Node* taoNode(int heSo, int soMu) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->heSo = heSo;
    newNode->soMu = soMu;
    newNode->next = NULL;
    return newNode;
}

void themCuoi(Node** head, int heSo, int soMu) {
    Node* newNode = taoNode(heSo, soMu);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void hienThi(Node* head) {
    Node* temp = head;
    printf("Bieu thuc da thuc: ");
    while (temp != NULL) {
        printf("%dx^%d", temp->heSo, temp->soMu);
        if (temp->next != NULL && temp->next->heSo >= 0)
            printf(" + ");
        else if (temp->next != NULL)
            printf(" ");
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    int n, heSo, soMu;

    printf("Nhap so luong so hang n: ");
    scanf("%d", &n);
	int i;
    for (i = 0; i < n; i++) {
        printf("Nhap he so va so mu cua so hang thu %d: ", i + 1);
        scanf("%d %d", &heSo, &soMu);
        themCuoi(&head, heSo, soMu);
    }

    hienThi(head);
    return 0;
}
