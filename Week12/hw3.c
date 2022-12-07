#include "BST_For_HW3.h"
#include "menu_func.c"

int main()
{
    int ch;
    while (1)
    {
        printf("--------------\n"
               ">>>> MENU <<<<<\n"
               "1. Import data from PhoneDB.txt\n"
               "2. Import data from PhoneDB.dat\n"
               "3. Add phone model\n"
               "4. Delete\n"
               "5. Update\n"
               "6. Searching\n"
               "7. Displaying\n"
               "8. Save to PhoneDB.dat\n"
               "9. Exit\n"
               "->> Select: ");
        scanf("%d%*c", &ch);
        switch (ch)
        {
        case 1:
            importFromTxt();
            break;
        case 2:
            importFromDat();
            break;
        case 3:
            addPhoneModel();
            break;
        case 4:
            deleteModel();
            break;
        case 5:
            update();
            break;
        case 6:
            searching();
            break;
        case 7:
            display();
            break;
        case 8:
            saveTreeToDat("PhoneDB.dat");
            break;
        case 9:
            printf("\tBye! Bye!\n");
            Free();
            exit(0);
            break;
        default:
            perror("Error Key!\n");
            break;
        }
    }
}
