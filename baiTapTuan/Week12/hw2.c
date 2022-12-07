#include "BST_For_HW2.h"
void printData(TreeType T)
{
    printf("%s\n", T->key);
}

char *stringLower(char s[])
{
    int i=0;
    while(s[i]!='\0')
    {
        if(s[i]>='A' && s[i]<='Z'){
            s[i]=s[i]+32;
        }
        ++i;
    }
    return s;
}

TreeType binarySearch(char* s, TreeType T){
  if(T == NULL)
    return NULL;
  if(strcmp(s, T->key) == 0)
    printf("Found %s\n", s);
  else if(strcmp(s, T->key) < 0)
    return binarySearch(&(*s), T->left);
  else return binarySearch(&(*s), T->right);
}

int so_sanh(char name1[], char name2[])
{
    int len1 = strlen(name1);
    int len2 = strlen(name2);
    char s1[30], s2[30];

    strcpy(s1, name1);
    strcpy(s2, name2);
    stringLower(s1);
    stringLower(s2);

    int countSpace1 = 0, countSpace2 = 0;

    int i = len1, j = len2;
    while (1)
    {

        for (; i >= 0; i--)
        {
            if (s1[i] == ' ')
            {
                countSpace1++;
                break;
            }
        }

        for (; j >= 0; j--)
        {
            if (s2[j] == ' ')
            {
                countSpace2++;
                break;
            }
        }

        if (strcmp(s1 + i + 1, s2 + j + 1) > 0)
        {
            return 1;
        }
        else if (strcmp(s1 + i + 1, s2 + j + 1) < 0)
        {
            return -1;
        }
        else if(strcmp(s1 + i + 1, s2 + j + 1) == 0)
        {
            if(countSpace1 == 2 && countSpace2 == 2){
                return strcmp(s1, s2);
            }
            else
            {
                i--;
                j--;
                continue;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    TreeType T;
    makeNullTree(&T);
    FILE *fin;
    if ((fin = fopen("DSSV.txt", "r")) == NULL)
    {
        printf("Khong the mo file DSSV.txt\n");
        return 1;
    }

    char name[30];
    while (!feof(fin))
    {
        fscanf(fin, "%[^\n]%*c", name);
        insertNode(name, &T);
    }

    inOrderPrint(T);

    char key[50];
    printf("Input the name you want to search: ");
    scanf("%s", key);

    binarySearch(key, T);
    return 0;
    
}
