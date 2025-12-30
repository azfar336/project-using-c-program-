#include <stdio.h>
#include <string.h>

struct book {
    int dib, f;
    char aname[100], bname[100];
    float p;
};

int main() {
    struct book b[100];
    FILE *f;
    int i = 0, j, ch, id = 100, az, bz;

    do {
        printf("\nAre you admin or student? (1 for admin, 2 for student): ");
        scanf("%d", &az);
        getchar(); 
        if (az == 1) {
            int xc = 4;
            char pass[20], og[20] = "admin123";
            while (xc) 
            {
                printf("Please enter the password:\n");
                scanf("%s", pass);
                if (strcmp(pass, og) == 0) 
                {
                    printf("Correct password\n");
                    break;
                } 
                else 
                {
                    xc--;
                    printf("Wrong password. You have %d chance(s) left.\n", xc);
                }
                if (xc == 0)
                {
                    printf("Access denied.\n");
                    return 0;
                }
            }
            printf("\n1. Add Book\n2. Issue Book\n3. Save Report\nEnter your choice: ");
            scanf("%d", &bz);
            getchar();
            if (bz == 1) {
                printf("Enter book name: ");
                fgets(b[i].bname, 100, stdin);
                b[i].bname[strcspn(b[i].bname, "\n")] = '\0';
                printf("Enter author name: ");
                fgets(b[i].aname, 100, stdin);
                b[i].aname[strcspn(b[i].aname, "\n")] = '\0';
                printf("Enter book price: ");
                scanf("%f", &b[i].p);
                getchar();
                b[i].dib = id++;
                b[i].f = 1;
                printf("Book added successfully. Book ID: %d\n", b[i].dib);
                i++;
            }
            else if (bz == 2) {
                int x, found = 0;
                printf("Enter book ID to issue: ");
                scanf("%d", &x);
                getchar();
                for (j = 0; j < i; j++) {
                    if (b[j].dib == x && b[j].f == 1) {
                        b[j].f = 0;
                        found = 1;
                        printf("Book issued successfully.\n");
                        break;
                    }
                }
                if (!found) {
                    printf("Book not available or already issued.\n");
                }
            }
            else if (bz == 3) {
                int x;
                printf("Enter book ID to save to file: ");
                scanf("%d", &x);
                getchar();
                for (j = 0; j < i; j++) {
                    if (x == b[j].dib) {
                        f = fopen("sample.txt", "a");
                        if (f == NULL) {
                            printf("Error opening file.\n");
                            break;
                        }
                        fprintf(f, "Book ID: %d\n", b[j].dib);
                        fprintf(f, "Book Name: %s\n", b[j].bname);
                        fprintf(f, "Author Name: %s\n", b[j].aname);
                        fprintf(f, "Price: %.2f\n\n", b[j].p);
                        fclose(f);
                        printf("Book details saved to file.\n");
                        break;
                    }
                }
            }
        } else if (az == 2) {
            printf("\n1. View Available Books\n2. Search Book by ID\n3. Return Book\nEnter your choice: ");
            scanf("%d", &bz);
            getchar();
            if (bz == 1) {
                int found = 0;
                for (j = 0; j < i; j++) {
                    if (b[j].f == 1) {
                        printf("%d | %s | %s | %.2f\n", b[j].dib, b[j].bname, b[j].aname, b[j].p);
                        found = 1;
                    }
                }
                if (!found)
                    printf("No available books.\n");
            }
            else if (bz == 2) {
                int x, found = 0;
                printf("Enter book ID to search: ");
                scanf("%d", &x);
                getchar();
                for (j = 0; j < i; j++) {
                    if (x == b[j].dib && b[j].f == 1) {
                        printf("%d | %s | %s | %.2f\n", b[j].dib, b[j].bname, b[j].aname, b[j].p);
                        found = 1;
                        break;
                    }
                }
                if (!found)
                    printf("Book not found or unavailable.\n");
            }
            else if (bz == 3) {
                int x, found = 0;
                printf("Enter book ID to return: ");
                scanf("%d", &x);
                getchar();
                for (j = 0; j < i; j++) {
                    if (x == b[j].dib && b[j].f == 0) {
                        b[j].f = 1;
                        found = 1;
                        printf("Book returned successfully.\n");
                        break;
                    }
                }
                if (!found)
                    printf("Invalid book ID or book already available.\n");
            }
        } else {
            printf("Invalid user type.\n");
        }
        printf("\nDo you want to continue? (1 for Yes, 0 for No): ");
        scanf("%d", &ch);
        getchar();
    } while (ch);
    return 0;
}