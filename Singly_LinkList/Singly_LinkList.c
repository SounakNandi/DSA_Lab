#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node {
    int data;
    struct node *next;
};

struct node *insert_at_begin(struct node *h, int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = h;
    return new_node;
}

struct node *insert_at_end(struct node *h, int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    if (h == NULL) return new_node;
    struct node *temp = h;
    while (temp->next != NULL) temp = temp->next;
    temp->next = new_node;
    return h;
}

struct node *insert_at_position(struct node *h, int data, int pos) {
    if (pos < 1) {
        printf("Invalid index\n");
        return h;
    }

    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;

    if (pos == 1) {
        new_node->next = h;
        return new_node;
    }

    struct node *temp = h;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) temp = temp->next;

    if (temp == NULL) {
        printf("Invalid index\n");
        free(new_node);
        return h;
    }

    new_node->next = temp->next;
    temp->next = new_node;
    return h;
}

int delete_at_begin(struct node **hptr) {
    if (*hptr == NULL) return INT_MIN;
    struct node *temp = *hptr;
    int data = temp->data;
    *hptr = (*hptr)->next;
    free(temp);
    return data;
}

int delete_at_end(struct node **hptr) {
    if (*hptr == NULL) return INT_MIN;
    if ((*hptr)->next == NULL) {
        int data = (*hptr)->data;
        free(*hptr);
        *hptr = NULL;
        return data;
    }
    struct node *temp = *hptr;
    while (temp->next->next != NULL) temp = temp->next;
    int data = temp->next->data;
    free(temp->next);
    temp->next = NULL;
    return data;
}

int delete_at_position(struct node **hptr, int pos) {
    if (*hptr == NULL) return INT_MIN;
    if (pos < 1) {
        printf("Invalid position\n");
        return INT_MIN;
    }

    if (pos == 1) return delete_at_begin(hptr);

    struct node *temp = *hptr;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) temp = temp->next;

    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position\n");
        return INT_MIN;
    }

    struct node *del_node = temp->next;
    int data = del_node->data;
    temp->next = del_node->next;
    free(del_node);
    return data;
}

int delete_value_from_list(struct node **hptr, int del_val) {
    if (*hptr == NULL) return INT_MIN;
    if ((*hptr)->data == del_val) return delete_at_begin(hptr);
    struct node *temp = *hptr;
    while (temp->next != NULL && temp->next->data != del_val) temp = temp->next;
    if (temp->next == NULL) return INT_MIN;
    struct node *del_node = temp->next;
    int data = del_node->data;
    temp->next = del_node->next;
    free(del_node);
    return data;
}

struct node *Reverse_Linked_list(struct node *h) {
    struct node *prev = NULL, *curr = h, *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void print_linked_list(struct node *h) {
    if (h == NULL) {
        printf("Empty list\n");
        return;
    }
    struct node *temp = h;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct node *head = NULL;
    int choice, data, pos, del_val;

    printf("1. Insert at Begin\n2. Insert at End\n3. Insert at Position\n4. Delete at Begin\n5. Delete at End\n6. Delete at Position\n7. Delete Value\n8. Reverse List\n0. Exit\n");

    do {
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                head = insert_at_begin(head, data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                head = insert_at_end(head, data);
                break;
            case 3:
                printf("Enter data and position: ");
                scanf("%d %d", &data, &pos);
                head = insert_at_position(head, data, pos);
                break;
            case 4:
                if (head == NULL) {
                    printf("Empty list\n");
                    break;
                }
                data = delete_at_begin(&head);
                if (data == INT_MIN) printf("List is empty\n");
                break;
            case 5:
                if (head == NULL) {
                    printf("Empty list\n");
                    break;
                }
                data = delete_at_end(&head);
                if (data == INT_MIN) printf("List is empty\n");
                break;
            case 6:
                if (head == NULL) {
                    printf("Empty list\n");
                    break;
                }
                printf("Enter position: ");
                scanf("%d", &pos);
                data = delete_at_position(&head, pos);
                if (data == INT_MIN) printf("Invalid position\n");
                break;
            case 7:
                if (head == NULL) {
                    printf("Empty list\n");
                    break;
                }
                printf("Enter value to delete: ");
                scanf("%d", &del_val);
                data = delete_value_from_list(&head, del_val);
                if (data == INT_MIN) printf("Value not found\n");
                break;
            case 8:
                if (head == NULL) {
                    printf("Empty list\n");
                    break;
                }
                head = Reverse_Linked_list(head);
                printf("List Reversed\n");
                break;
        }

        printf("Current List: ");
        print_linked_list(head);

    } while (choice != 0);

    return 0;
}
