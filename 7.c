#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char usn[25], name[25], branch[25];
    int sem;
    long int phone;
    struct node* link;
};
typedef struct node* NODE;

NODE start = NULL;
int count = 0;

NODE create() {
    NODE snode;
    snode = malloc(sizeof(struct node));
    if (snode == NULL) {
        printf("\nMemory is not available");
        exit(1);
    }
    printf("\nEnter the USN, Name, Branch, Semester, Phone No of the student:\n");
    scanf("%24s %24s %24s %d %ld", snode->usn, snode->name, snode->branch, &snode->sem, &snode->phone);
    snode->link = NULL;
    count++;
    return snode;
}

NODE insertfront() {
    NODE temp = create();
    if (start == NULL) {
        return temp;
    }
    temp->link = start;
    return temp;
}

NODE deletefront() {
    if (start == NULL) {
        printf("\nLinked list is empty");
        return NULL;
    }
    NODE temp = start;
    printf("\nThe student node with USN: %s is deleted", temp->usn);
    start = start->link;
    free(temp);
    count--;
    return start;
}

NODE insertend() {
    NODE temp = create();
    if (start == NULL) {
        return temp;
    }
    NODE cur = start;
    while (cur->link != NULL) {
        cur = cur->link;
    }
    cur->link = temp;
    return start;
}

NODE deleteend() {
    if (start == NULL) {
        printf("\nLinked List is empty");
        return NULL;
    }
    if (start->link == NULL) {
        printf("\nThe student node with USN: %s is deleted", start->usn);
        free(start);
        count--;
        return NULL;
    }
    NODE cur = start, prev = NULL;
    while (cur->link != NULL) {
        prev = cur;
        cur = cur->link;
    }
    printf("\nThe student node with USN: %s is deleted", cur->usn);
    free(cur);
    prev->link = NULL;
    count--;
    return start;
}

void display() {
    if (start == NULL) {
        printf("\nNo contents to display in the linked list.\n");
        return;
    }
    NODE cur = start;
    int num = 1;
    printf("\nThe contents of the linked list are:\n");
    while (cur != NULL) {
        printf("|%d| USN: %s | Name: %s | Branch: %s | Sem: %d | Phone: %ld\n",
               num++, cur->usn, cur->name, cur->branch, cur->sem, cur->phone);
        cur = cur->link;
    }
    printf("\nTotal number of student nodes: %d\n", count);
}

void stackdemo() {
    int ch;
    while (1) {
        printf("\n-------- Stack Demo using Linked List --------\n");
        printf("\n1: Push (Insert at Front)\n2: Pop (Delete from Front)\n3: Display\n4: Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                start = insertfront();
                break;
            case 2:
                start = deletefront();
                break;
            case 3:
                display();
                break;
            case 4:
                return;
            default:
                printf("\nInvalid choice. Try again.\n");
        }
    }
}

void free_list() {
    while (start != NULL) {
        start = deletefront();
    }
}

int main() {
    int ch, n, i;
    while (1) {
        printf("\n-------- Menu --------\n");
        printf("1: Create Linked List of Student Nodes\n");
        printf("2: Display\n");
        printf("3: Insert at End\n");
        printf("4: Delete from End\n");
        printf("5: Stack Demo using Linked List\n");
        printf("6: Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                
                printf("\nCreating a Linked List. Enter '0' to stop.\n");
                while (1) {
                printf("\nDo you want to add a student node? (1 for Yes / 0 for No): ");
                int add_choice;
                scanf("%d", &add_choice);
                if (add_choice == 0) {
                break;
            }
        start = insertfront();
    }
    break;

            case 2:
                display();
                break;
            case 3:
                start = insertend();
                break;
            case 4:
                start = deleteend();
                break;
            case 5:
                stackdemo();
                break;
            case 6:
                free_list();
                exit(0);
            default:
                printf("\nInvalid choice. Try again.\n");
        }
    }
    return 0;
}
