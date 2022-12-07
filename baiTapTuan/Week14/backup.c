#include "binarySearchTree.h"

int main(){
  char choice;
  treeType root;

  elementType bongDa[2];
  bongDa[1].score = 0;
  bongDa[2].score = 0;
  
  makeNullTree(&root);

  while(1){
    printf("    ---MENU---\n"
	   "|1. Tao cay.      |\n"
	   "|2. Ket qua.      |\n"
	   "|3. Tim kiem.     |\n"
	   "|4. Xuong hang.   |\n"
	   "|5. Xuat file.    |\n"
	   "|6. Thoat         |\n");

    __fpurge(stdin);
    printf("Input your choice: ");
    scanf("%c", &choice);

    while(choice > '6' || choice < '1'){
      __fpurge(stdin);
      printf("Ivalid! Input your choice: ");
      scanf("%c", &choice);
    }

    
    
    switch(choice){
    case '1':{
      FILE* fptr = fopen("BongDa.txt", "r");
      if(fptr == NULL){
	printf("Cannot open BongDa.txt!\n");
	return 0;
      }

      while(fscanf(fptr, "%s\t%s\t%d\t%d\n", bongDa[1].name, bongDa[2].name, &bongDa[1].result, &bongDa[2].result) != EOF){
	if(search(bongDa[1].name, root) == NULL && search(bongDa[2].name, root) == NULL){//Ko tim thay truoc day
	  if(bongDa[1].result > bongDa[2].result){
	    bongDa[1].score += 3;
	  }
	  else if(bongDa[1].result < bongDa[2].result){
	    bongDa[2].score += 3;
	  }
	  else{
	    bongDa[1].score += 1;
	    bongDa[2].score += 1;
	  }

	  insertNode(bongDa[1], &root);
	  insertNode(bongDa[2], &root);
	}
	else if(search(bongDa[1].name, root) != NULL && search(bongDa[2].name, root) == NULL){//chi tim thay bongDa1
	  if(search(bongDa[1].name, root)->element.result > bongDa[2].result){
	    search(bongDa[1].name, root)->element.score += 3;
	  }
	  else if(search(bongDa[1].name, root)->element.result < bongDa[2].result){
	    bongDa[2].score += 3;
	  }
	  else{
	    search(bongDa[1].name, root)->element.score += 1;
	    bongDa[2].score += 1;
	  }
	  insertNode(bongDa[2], &root);
	}
	else if(search(bongDa[1].name, root) == NULL && search(bongDa[2].name, root) != NULL){//chi tim thay bongDa2
	  if(bongDa[1].result > search(bongDa[2].name, root)->element.result){
	    bongDa[1].score += 3;
	  }
	  else if(bongDa[1].result < search(bongDa[2].name, root)->element.result){
	    search(bongDa[2].name, root)->element.result += 3;
	  }
	  else{
	    bongDa[1].result += 1;
	    search(bongDa[2].name, root)->element.result += 1;
	  }
	  insertNode(bongDa[1], &root);		 
	}
	else{ //Neu tim thay ca 2
	  if(search(bongDa[1].name, root)->element.result > search(bongDa[2].name, root)->element.result){
	    search(bongDa[1].name, root)->element.score += 3;
	  }
	  else if (search(bongDa[1].name, root)->element.result < search(bongDa[2].name, root)->element.result){
	    search(bongDa[2].name, root)->element.result += 3;
	  }
	  else{
	    search(bongDa[1].name, root)->element.result += 1;
	    search(bongDa[2].name, root)->element.result += 1;
	  }
	}

      }
      fclose(fptr);
      
      break;
    }

    case '2':{
      inOrderPrint(root);
      break;
    }
      
    case '3':{
      char x[30];
      printf("Nhap ten doi bong: ");
      scanf("%s", x);

      if(search(x, root) == NULL){
	printf("Khong co doi bong nay!\n");
      }
      else printf("%-10s%-5d\n", search(x, root)->element.name, search(x, root)->element.score);
      break;
    }
      
    case '4':{
      int n;
      printf("Nhap so diem de tru hang: ");
      scanf("%d", &n);
      printf("\t---Nhung doi bi xuong hang---\n");
      lowerThanKey(n, root);
      
      break;
    }
      
    case '5':{
      
      break;
    }
      
    case '6':{
      freeTree(root);
      exit(0);
      break;
    }
    }
  }
  
}

