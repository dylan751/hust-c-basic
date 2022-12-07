#include "BST_For_HW2.h"

int main(){
  float x;
  elementType stu;
  treeType root;
  makeNullTree(&root);
  
  FILE* fptr = fopen("DSSV.txt", "r");
  if(fptr == NULL){
    printf("Cannot open DSSV.txt\n");
    return 0;
  }

  while(fscanf(fptr, "%s\t%f", stu.name, &stu.grade) != EOF){
    insertNode(stu, &root);
  }

  printf("\t---Student list---\n");
  inOrderPrint(root);
  
  printf("\n\nInput a grade (>0, <10): ");
  scanf("%f", &x);
  printf("---The students that has the grade < than %.2f---\n", x);
  lowerThanKey(x, root);

  printf("\n---The students that has the grade >= than %.2f---\n", x);
  higherThanKey(x, root);
}
