#include <stdio.h>
#include <stdlib.h>

struct node {
    int num;
    struct node* next;
};
typedef struct node Node;

Node* insertInLinkedList(Node* head, int num) {
    Node* last = NULL;
    Node* current = head;

    while (current && current->num < num) {
        last = current;
        current = current->next;
    }

    Node* new = (Node*)malloc(sizeof(Node));
    new->num = num;

    if (last) {
        new->next = current;
        last->next = new;
    } else {
        new->next = current;
        head = new;
    }

    return head;
}

int getNumAtIndex(Node* head, int index) {
    int current = 0;

    while (current++ < index) {
        head = head->next;
    }

    return head->num;
}

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size) {

    Node* head = NULL;

    for (int i = 0; i < nums1Size; i++) {
        head = insertInLinkedList(head, nums1[i]);
    }

    for (int i = 0; i < nums2Size; i++) {
        head = insertInLinkedList(head, nums2[i]);
    }

    int total = nums1Size + nums2Size;
    double result = 0.0;

    if (total % 2) {
        // Total is odd
        int medianIndex = (total - 1) / 2;
        result = (double)getNumAtIndex(head, medianIndex);
    } else {
        // Total is even
        int firstMedianIndex = (total / 2) - 1;
        result += (double)getNumAtIndex(head, firstMedianIndex);
        result += (double)getNumAtIndex(head, (firstMedianIndex + 1));
        result /= 2;
    }

    return result;
}

int main(void) {

}
