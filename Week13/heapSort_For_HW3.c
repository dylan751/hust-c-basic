
void adjust(DataType list[], int root, int n){
  int max = root;
  int leftChild, rightChild;
  KeyType rootkey[50];//Gia tri cua node root
  DataType temp;
  temp = list[root];
  strcpy(rootkey, list[root].model); 
  leftChild = 2*root + 1;//Vi tinh ca phan tu 0 ->right child = 2*root+2
  rightChild = 2*root + 2;
  
  //Tim phan tu Max trong root va 2 child
  if(leftChild < n && strcmp(list[leftChild].model, list[max].model) > 0)
    max = leftChild;
  
  if(rightChild < n && strcmp(list[rightChild].model, list[max].model) > 0)
    max = rightChild;
  
  if(max != root){//Doi cho root va max
    temp = list[root];
    list[root] = list[max];
    list[max] = temp;

    adjust(list, max, n);
  }
  
}


//Dang bieu dien cay bang` mang?
void heapsort(DataType list[], int n){
  int i;
  DataType temp;
  for(i = (n/2-1); i >= 0; i--){
    adjust(list, i, n);//Ham vun dong
  }
  for(i = n-1; i >= 0; i--){
    temp = list[0];
    list[0] = list[i];
    list[i] = temp;

    adjust(list, 0, i);//Ham vun dong
  }

  for(i = 0; i < n; i++){
    printf("%15s", list[i].model);
  }
}
