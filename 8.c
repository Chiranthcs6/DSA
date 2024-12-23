#include<stdio.h>
#include<stdlib.h>

struct node {
    char ssn[25], name[25], dept[10], desg[100];
    int sal;
    long int phno;
    struct node* llink;
    struct node* rlink;
};

typedef struct node* NODE;

NODE first = NULL;
int count = 0;

// Create a new node
NODE create() {
    NODE enode;
    enode = (NODE)malloc(sizeof(struct node));
    if (enode == NULL) {
        printf("\nRunning out of memory\n");
        exit(0);
    }
    printf("\nEnter the SSN, Name, Department, Designation, Salary, Phone no of the employee:\n");
    scanf("%s %s %s %s %d %ld", enode->ssn, enode->name, enode->dept, enode->desg, &enode->sal, &enode->phno);
    enode->llink = NULL;
    enode->rlink = NULL;
    count++;
    return enode;
}

// Insert at the front
NODE insertfront() {
    NODE temp;
    temp = create();
    if (first == NULL) {
        return temp;
    }
    temp->rlink = first;
    first->llink = temp;
    return temp;
}

// Display the list
void display() {
    NODE cur;
    int nodeno = 1;
    if (first == NULL) {
        printf("\nNo data to display\n");
        return;
    }
    printf("\nEmployee Details:\n");
    cur = first; // Initialize cur to the first node
    while (cur != NULL) {
        printf("\n|%d| SSN: %s | Name: %s | Dept: %s | Designation: %s | Salary: %d | Phone: %ld", 
               nodeno, cur->ssn, cur->name, cur->dept, cur->desg, cur->sal, cur->phno);
        cur = cur->rlink;
        nodeno++;
    }
    printf("\nNumber of nodes: %d\n", count);
}

// Delete from the front
NODE deletefront() {
    NODE temp;
    if (first == NULL) {
        printf("\nList is empty\n");
        return NULL;
    }
    if (first->rlink == NULL) {
        printf("\nThe employee node deleted is: %s\n", first->ssn);
        free(first);
        count--;
        return NULL;
    }
    temp = first;
    first = first->rlink;
    first->llink = NULL;
    printf("\nThe employee node deleted is: %s\n", temp->ssn);
    free(temp);
    count--;
    return first;
}

// Insert at the end
NODE insertend() {
    NODE temp, cur;
    temp = create();
    if (first == NULL) {
        return temp;
    }
    cur = first;
    while (cur->rlink != NULL) {
        cur = cur->rlink;
    }
    cur->rlink = temp;
    temp->llink = cur;
    return first;
}

// Delete from the end
NODE deleteend() {
    NODE prev, cur;
    if (first == NULL) {
        printf("\nList is empty\n");
        return NULL;
    }
    if (first->rlink == NULL) {
        printf("\nThe node deleted is: %s\n", first->ssn);
        free(first);
        count--;
        return NULL;
    }
    cur = first;
    while (cur->rlink != NULL) {
        cur = cur->rlink;
    }
    prev = cur->llink;
    prev->rlink = NULL;
    printf("\nThe node deleted is: %s\n", cur->ssn);
    free(cur);
    count--;
    return first;
}

// Main function
void main() {
    int ch, i, n;
    while (1) {
        printf("\n-----MENU------\n");
        printf("1. Create a DLL\n");
        printf("2. Display Status\n");
        printf("3. Insert At Front\n");
        printf("4. Delete At Front\n");
        printf("5. Insert At End\n");
        printf("6. Delete At End\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        getchar(); // Clear newline from the buffer

        switch (ch) {
            case 1:
                printf("\nEnter the number of employees: ");
                scanf("%d", &n);
                getchar(); // Clear newline
                for (i = 0; i < n; i++) {
                    printf("\nAdding employee %d of %d:\n", i + 1, n);
                    first = insertend();
                }
                break;

            case 2:
                display();
                break;

            case 3:
                first = insertfront();
                break;

            case 4:
                first = deletefront();
                break;

            case 5:
                first = insertend();
                break;

            case 6:
                first = deleteend();
                break;

            case 7:
                exit(0);

            default:
                printf("\nInvalid input. Please try again.\n");
        }
    }
}
