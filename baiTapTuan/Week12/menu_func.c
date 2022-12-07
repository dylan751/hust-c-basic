TreeType Tree = NULL;

void printData(DataType p)
{
	printf("%s\t%d\t%d\t%g\t%d\n", p.model, p.memory, p.space, p.screen_size, p.price);
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
