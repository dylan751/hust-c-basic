
TreeType Tree = NULL;

void printData(DataType p)
{
	 printf("%-25s%-7d%-7d%-7g%-12d\n", p.model, p.memory, p.space, p.screen_size, p.price);
}

DataType getData()
{
	DataType new;
	printf("Model: ");
	scanf("%s%*c", new.model);
	printf("Memory: ");
	scanf("%d%*c", &new.memory);
	printf("Space: ");
	scanf("%d%*c", &new.space);
	printf("Screen size: ");
	scanf("%lf%*c", &new.screen_size);
	printf("Price: ");
	scanf("%d%*c", &new.price);
	return new;
}

void inOrderPrint(TreeType tree)
{
	if (tree != NULL)
	{
		inOrderPrint(tree->left);
		printData(tree->data);
		inOrderPrint(tree->right);
	}
}

void importFromDat()
{
	int n;
	FILE *f;
	if ((f = fopen("PhoneDB.dat", "rb")) == NULL)
	{
		printf("Khong the mo file PhoneDB.dat!\n");
		return;
	}

	fseek(f, 0, SEEK_END);
	n = ftell(f) / sizeof(DataType); //Dem so dong` co trong file
	rewind(f);
	DataType tmp;
	for (int i = 0; i < n; i++)
	{
	  fread(&tmp, sizeof(DataType), 1, f);
	  insertNode(tmp, &Tree);
	}

	printf("\tImported!!!\n");
	fclose(f);
}

void importFromTxt()
{
	int n;
	FILE *f;
	if ((f = fopen("PhoneDB.txt", "r")) == NULL)
	{
		printf("Khong the mo file PhoneDB.txt!\n");
		return;
	}

	DataType tmp;

	while (!feof(f))
	{
		fscanf(f, "%s\t%d\t%d\t%lf\t%d\n", tmp.model, &(tmp.memory), &(tmp.space), &(tmp.screen_size), &(tmp.price));
		insertNode(tmp, &Tree);
	}

	printf("\tImported!!!\n");
	fclose(f);
}

void display()
{
	printf("\tDISPLAY\n");
	inOrderPrint(Tree);
}

void addPhoneModel()
{
	printf("-------------------------\n"
		   "\t ADD NEW PHONE \n");
	insertNode(getData(), &Tree);
	printf("\t ADDED! \n");
}

void saveInOrder(TreeType T, FILE *fout)
{
	if (T != NULL)
	{
	  saveInOrder(T->left, fout);
	  fwrite(&(T->data), sizeof(DataType), 1, fout);
	  saveInOrder(T->right, fout);
	}
}

void saveTreeToDat(char *filename)
{

	printf("\t SAVE TO DAT \n");
	FILE *f = fopen(filename, "wb");
	if (f == NULL)
	{
		printf("Khong the mo file nen khong the luu file.\n");
		return;
	}
	saveInOrder(Tree, f);
	printf("Da luu file thanh cong!\n");
	fclose(f);
}

void Free()
{
	freeTree(&Tree);
}

void deleteModel()
{
	printf("\t DELETE MODEL \n");
	KeyType key[50];
	printf("Nhap Model can xoa: ");
	scanf("%s%*c", key);

	deleteNode(key, &Tree);
}

void searching()
{
	printf("\t SEARCHING MODEL \n");
	KeyType key[50];
	printf("Find Model: ");
	scanf("%s%*c", key);
	TreeType found;
	if ((found = Search(key, Tree)) == NULL)
	{
		printf("Khong tim thay hoac cay rong!\n");
	}
	else
	{
		printf("Tim thay!!!\n");
		printData(found->data);
	}
}

void update()
{
	printf("----------------\n"
		   "-----UPDATE-----\n");
	KeyType key[50];
	printf("Nhap ten Model: ");
	scanf("%s%*c", key);

	TreeType found;
	if ((found = Search(key, Tree)) == NULL)
	{
		printf("Khong tim thay hoac cay rong!\n");
	}
	else
	{
		deleteNode(key, &Tree);
		insertNode(getData(), &Tree);
	}
}

void adjust(DataType list[], int root, int n){
  int child;
  KeyType rootkey[50];//Gia tri cua node root
  DataType temp;
  temp = list[root];
  strcpy(rootkey, list[root].model); 
  child = 2*root;//Vi tinh ca phan tu 0 ->right child = 2*root+2
  
  while(child <= n){
    if((child < n) && (strcmp(list[child].model, list[child+1].model) < 0)){
      child++;
    }
    if(rootkey > list[child].model)
      break;
    else{
      list[child/2] = list[child];
      child = child*2;
    }
  }  
  list[child/2] = temp;
  
}

void swap(DataType* a, DataType *b){
  DataType tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

//Dang bieu dien cay bang` mang?
void heapsort(DataType list[], int n){
  int i, j;
  DataType temp;
  for(j = n/2; j > 0; j--){
    adjust(list, j, n);//Ham vun dong
  }
  for(i = n-1; i > 0; i--){
    swap(&list[1], &list[i+1]);

    adjust(list, 1, i);//Ham vun dong
  }

  for(i = 1; i <= n; i++){
    printf("%-25s%-7d%-7d%-7g%-12d\n", list[i].model, list[i].memory, list[i].space, list[i].screen_size, list[i].price);
  }
}


/*void sort(){
  FILE* fptr = fopen("PhoneDB.dat", "rb");
  int count; //count the number of lines in file
  int i;
  DataType *arr;
  
  if(fptr == NULL){
    printf("Cannot open PhoneDB.dat!\n");
    return;
  }

  fseek(fptr, 0, SEEK_END);
  count = ftell(fptr)/sizeof(DataType);
  rewind(fptr);

  arr = (DataType*)malloc(sizeof(DataType));
  fread(arr, sizeof(DataType), count, fptr);//Bo qua phan tu arr[0]

  heapsort(arr, count);
  fclose(fptr);
  }*/
