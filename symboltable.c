#include <stdio.h>
#include <string.h>

#define MAX 50

struct Symbol {
    char name[20];
    char type[20];
    int address;
};

struct Symbol table[MAX];
int count = 0;

/* Insert an entry */
void insertSymbol()
{
    if (count >= MAX) {
        printf("\nSymbol Table is full!\n");
        return;
    }

    printf("\nEnter symbol name: ");
    scanf("%19s", table[count].name);

    printf("Enter data type: ");
    scanf("%19s", table[count].type);

    printf("Enter address: ");
    scanf("%d", &table[count].address);

    count++;

    printf("\nEntry inserted successfully.\n");
}

/* Delete an entry */
void deleteSymbol()
{
    char name[20];
    int i, found = 0;

    printf("\nEnter symbol name to delete: ");
    scanf("%19s", name);

    for (i = 0; i < count; i++) {
        if (strcmp(table[i].name, name) == 0) {
            found = 1;

            for (int j = i; j < count - 1; j++) {
                table[j] = table[j + 1];
            }

            count--;

            printf("\nEntry deleted successfully.\n");
            break;
        }
    }

    if (!found) {
        printf("\nSymbol not found!\n");
    }
}

/* Display symbol table */
void display()
{
    if (count == 0) {
        printf("\nSymbol Table is empty!\n");
        return;
    }

    printf("\n------------- SYMBOL TABLE -------------\n");
    printf("%-15s %-15s %-10s\n",
           "Symbol", "Data Type", "Address");
    printf("----------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-15s %-15s %-10d\n",
               table[i].name,
               table[i].type,
               table[i].address);
    }
}

/* Main function */
int main()
{
    int choice;

    while (1) {
        printf("\n\n===== SYMBOL TABLE =====");
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");

        scanf("%d", &choice);

        switch (choice) {

            case 1:
                insertSymbol();
                break;

            case 2:
                deleteSymbol();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("\nProgram terminated.\n");
                return 0;

            default:
                printf("\nInvalid choice! Please enter 1-4.\n");
        }
    }

    return 0;
}