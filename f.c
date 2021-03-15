#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<string.h>
#include<stdlib.h>
void verify();
int menu();
void createaccount();
void login();
FILE *fp;
struct user u,U;
int choice,i;
char fname[20],lname[20],uname[20],pss[20],C;
struct user
{
    char pass[20];
    char username[20];
    char fname[20];
    char lname[20];
    char address[100];
    char phone[15];
    char rname[20];
    int temp;
};
void SetColor(int ForgC)
{
     WORD wColor;
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}
int welcome()
{
    SetColor(4);
    printf("\t\t\t\t\t\t * * *\t\t\t\t\t\t\t      * * *\n");
    printf("\t\t\t\t\t\t * * *\t\t\t\t\t\t\t      * * *\n");
    printf("\t\t\t\t\t\t *****\t\t\t\t\t\t\t      *****\n");
    printf("\t\t\t\t\t\t *****\t\t\t\t\t\t\t      *****\n");
    printf("\t\t\t\t\t\t  ***\t\t\t\t\t\t\t       ***\n");
    SetColor(2);
    printf("\t\t\t\t\t\t   *");
    SetColor(3);
    printf("\t\t#### Flower Shop Management System ####\t\t");
    SetColor(2);
    printf("*\n");
    printf("\t\t\t\t\t\t** * **\t\t\t\t\t\t\t     ** * **\n");
    printf("\t\t\t\t\t\t** * **\t\t\t\t\t\t\t     ** * **\n");
    printf("\t\t\t\t\t\t   *\t\t\t\t\t\t\t        *\n");
    printf("\t\t\t\t\t\t   *\t\t\t\t\t\t\t        *\n\n\n");
}
int main()
{
    int a;
    system("cls");
    welcome();
    SetColor(7);
    printf("\t\t\t\t\t\t\t1. User Panal\t\t\t2.Admin Panal\n");
    printf("\n\t\t\t\t\t\t\t\t    Enter your choice: ");
    scanf("%d",&a);
    switch (a)
        {
        case 1:
            system("cls");
            printf("\n\t\t\t\t\t\tWelcome to the User Panal!\n");
            userchoice();
            userchoicelist();
            break;

        case 2:
            system("cls");
            printf("\n\t\t\t\t\t\tWelcome to the Admin Panal!\n");
            adminv();
            //adminchoicelist();
            break;
        default:
            printf("\n\t\t\t\t\t\t\tProgram finished...");
            return 0;
            break;
        }
}
int menu()
{
    int ch;
    printf("\n\n\t\t\t\t\t\t\t1. Create Account\n");
    printf("\t\t\t\t\t\t\t2. Login\n");
    printf("\t\t\t\t\t\t\t3. Exit to main\n");
    printf("\n\t\t\t\t\t\t Enter your choice :  ");
    scanf("%d",&ch);
    return ch;
}
int userchoice()
{
        switch (menu())
        {
        case 1:
            createaccount();
            break;

        case 2:
            login();
            break;

        case 3:
            main();
        default:
            printf("\n\t\t\t\t\t\t\tInvalid Choice! ");
            break;
        }


}

void createaccount()
{
    struct user U;
    FILE *fp;
    system("cls");
    printf("\n\t\t\t\t\t\t\t");
    for(i=0;i<15;i++)
    {
        printf("\xdb");
    }
    printf(" CREATE ACCOUNT ");
    for(i=0;i<15;i++)
    {
        printf("\xdb");
    }
    printf("\n\n");
    printf("\t\t\t\t\t\t    Enter First Name: ");
    fflush(stdin);
    gets(U.fname);
    printf("\n");
    printf("\t\t\t\t\t\t    Enter Last Name: ");
    gets(U.lname);
    printf("\n");
    printf("\t\t\t\t\t\t    Enter Username: ");
    scanf("%s",U.username);
    printf("\n");
    printf("\t\t\t\t\t\t    Enter Password: ");
    scanf("%s",U.pass);
    fp = fopen ("username.txt", "wb+");
    if (fp == NULL)
    {
        printf("\n\t\t\t\t\t\tError opened file\n");
        exit (1);
    }
    fwrite(&U, sizeof(struct user), 1, fp);
    fclose (fp);
    printf("\n\n\n\n\t\t\t\t\t\t\tAccount Created Successfully. Press any key to continue...");
    getch();
    system("cls");
    login();
}
void login()
{
    char uname[20],pss[20];
    FILE *fp;
    struct user u;
    system("cls");
    printf("\n\t\t\t\t\t\t\t");
    for(i=0;i<15;i++)
    {
        printf("\xdb");
    }
    printf(" LOGIN TO YOUR ACCOUNT ");
    for(i=0;i<15;i++)
    {
        printf("\xdb");
    }
    printf("\n\n\t\t\t\t\t\t    Enter Username: ");
    scanf("%s",uname);
    printf("\n");
    printf("\t\t\t\t\t\t    Enter Password: ");
    scanf("%s",pss);
    fp=fopen("username.txt","rb+");
    if(fp==NULL)
    {
        printf("\n\t\t\t\t\t\tFile not found");
        return 1;
    }
    while(fread(&u, sizeof(struct user), 1, fp)){
        if(strcmp(uname,u.username) == 0 && strcmp(pss,u.pass)==0)
        {
            printf("\n\n\n\n\t\t\t\t\t\t\tUsername And Password is Correct. Welcome %s %s ", u.fname,u.lname);
            printf("\n\n\n\t\t\t\t\t\t\t\t\tPress any key to continue....");
            getch();
        }
        else
        {
            printf("\n\t\t\t\t\t\t\tUsername And Password is Incorrect. Press any key to continue...");
            getch();
            exit(0);
        }
    }
    fclose(fp);
    system("cls");
}
int userchoicelist()
{
    system("cls");
    printf("\n\t\t\t\t\t\t\t");
    for(i=0;i<15;i++)
    {
        printf("\xdb");
    }
    printf(" MAIN MENU ");
    for(i=0;i<15;i++)
    {
        printf("\xdb");
    }
    printf("\n\n\t\t\t\t\t\t    1. Flower List");
    printf("\n\t\t\t\t\t\t    2. Search Flower");
    printf("\n\t\t\t\t\t\t    3. Add to Cart");
    printf("\n\t\t\t\t\t\t    4. Place Order");
    printf("\n\t\t\t\t\t\t    5. Payment Gateway");
    printf("\n\t\t\t\t\t\t    6. About Us");
    printf("\n\t\t\t\t\t\t    7. Log Out\n");
    printf("\n\n\t\t\t\t\t\t    Enter your choice between 1 to 7: ");
    scanf("%d", &choice);
    system("cls");
    switch(choice)
    {
    case 1:
        read_item();
        userchoicelist();
        break;
    case 2:
        Search_Flower();
        userchoicelist();
        break;
    case 3:
        Add_to_Cart();
        userchoicelist();
        break;
    case 4:
        Place_Order();
        break;
    case 5:
        Payment_Getaway();
        break;
    case 6:
        About_Us();
        userchoicelist();
        break;
    case 7:
        main();
        break;
    default:
        printf("\n\t\t\t\t\t\t\tInvalid Choice!");
        getch();
    }
}
void adminv()
{
    userchoice();
    printf("\n\t\t\t\t\t\t\tGive the pin code of the shop to verify yourself!\n");
    int a=0,i=0;
    char c=' ',code[10],pass[10]="3091014";
    do
    {

        printf("\n\n\t\t\t\t\t\t\t\t\tPin Code: ");
        while(i<10)
        {
            code[i]=getch();
            c=code[i];
            if(c==13)
                break;
            else
                printf("*");
            i++;
        }
        code[i]='\0';
        i=0;
        if(strcmp(code,"3091014")==0)
        {
            printf("\n\t\t\t\t\t\t\tWelcome to the information editing panal!!!!");
            printf("\n\t\t\t\t\t\t\tPress enter to continue...");
            getch();
            adminchoicelist();
            break;
        }
        else
        {
            printf("\n\t\t\t\t\t\t\tSorry!!!! You entry is denied.");
            a++;
            getch();

        }
    } while(a<=2);
    if (a>2)
    {
        printf("\n\t\t\t\t\t\t\tSorry you have entered the wrong pin code for four times!!!");

        getch();

    }
    system("cls");
}
void adminchoicelist()
{
    system("cls");
    int choice;
    printf("\n");
    printf("\n\t\t\t\t\t\t\t");
    for(i=0;i<15;i++)
    {
        printf("\xdb");
    }
    printf(" Flower Shop Management System ");
    for(i=0;i<15;i++)
    {
        printf("\xdb");
    }
    printf("\n");
    printf("\n\t\t\t\t\t\t\t 1. Add Items");
    printf("\n\t\t\t\t\t\t\t 2. Delete Items");
    printf("\n\t\t\t\t\t\t\t 3. View Items");
    printf("\n\t\t\t\t\t\t\t 4. Search Items");
    printf("\n\t\t\t\t\t\t\t 5. Edit Items");
    printf("\n\t\t\t\t\t\t\t 6. Log Out");
    printf("\n\n\n\t\t\t\t\t\t\t Enter your choice between 1 to 5: ");
    scanf("%d", &choice);
    system("cls");
    switch(choice)
    {
    case 1:
        add_item();
        adminchoicelist();
        break;
    case 2:
        delete_product();
        adminchoicelist();
        break;
    case 3:
        read_item();
        adminchoicelist();
        break;
    case 4:
        Search_Flower();
        adminchoicelist();
        break;
    case 5:
        edit_item();
        adminchoicelist();
        break;
    case 6:
        main();
        break;
    default:
        printf("\n\t\t\t\t\t\t\t Invalid Choice!");
        getch();
    }
}
void gotoxy(short x, short y)
{
	COORD pos ={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
struct item
{
    char name[40],color[40],c;
    int productid;
    int price;
    int qnt;
} st;
void add_item()
{
	int index, valid;
	char c;
	int a=0;

	FILE *fp;
	do
	{
		system("cls");
		printf("\n\t\t\t\t\t\t\t<--<<Add Item>>-->\n\n");
		printf("\n\t\t\t\t\t\t\t");
		for(i=0;i<12;i++)
        {
            printf("\xdb");
        }
		printf("Enter Item Details ");
		for(i=0;i<12;i++)
        {
            printf("\xdb");
        }
		int ID;
		fp = fopen("item.txt","a+");

		if((fp = fopen("item.txt","a+"))!=NULL)
		{
			I:
			printf("\n\t\t\t\t\t\t\tCode\t : ");
			scanf("%i",&ID);
			while(fscanf(fp,"%s %s %i %i %i", st.name, st.color, &st.price, &st.productid,&st.qnt)!=EOF)
			{
				if(ID == st.productid)
				{
					printf("\n\t\t\t\t\t\t\t THE PRODUCT CODE ALREADY EXIST.\n");
					goto I;
				}
			}
			st.productid = ID;
		}
		else
		{
			printf("\n\t\t\t\t\t\t\t Code\t : ");
			scanf("%i",&st.productid);
		}
		do
		{
			fflush(stdin);
			printf("\n\t\t\t\t\t\t\t Flower's Name\t : ");
			gets(st.name);
			st.name[0]=toupper(st.name[0]);

			for (index=0; index<strlen(st.name); ++index)
			{
				if(isalpha(st.name[index]))
					valid = 1;
				else
				{
					valid = 0;
					break;
				}
			}
			if (!valid)
			{
				printf("\n\t\t\t\t\t\t Name contain invalid character. Please 'Enter' again");
				getch();


			}
		}while(!valid);



			do
		{
			char color[40];
			fflush(stdin);
			printf("\n\t\t\t\t\t\t\t Color\t : ");
			gets(st.color);
			st.color[0]=toupper(st.color[0]);
			for (index=0; index<strlen(st.color); ++index)
			{
				if(isalpha(st.color[index]))
					valid = 1;
				else
				{
					valid = 0;
					break;
				}
			}
			if (!valid)
			{
				printf("\n\t\t\t\t\t Name contain invalid character. Please 'Enter' again");
				getch();


			}
		}while(!valid);
		do
			{
				printf("\n\t\t\t\t\t\t\tPrice per stick or branch: ");
				scanf("%i",&st.price);
				if(st.price>5000)
				{
					printf("\n\t\t\t\t\t\t\t Decrease the price.");
				}
			}while(st.price>5000);
            printf("\n\t\t\t\t\t\t\t Quantity available \t: ");
            scanf("%i",&st.qnt);

		fp=fopen("item.txt","a");
		fprintf(fp,"\n%s %s %i %i %i", st.name, st.color,st.price, st.productid,st.qnt);
		fclose(fp);
		printf("\n\t\t\t\t\t Press 'Enter' to add more item and any other key to go to back to editing panal");

	}
	while((c = getch()) =='\r');
	adminchoicelist();
}
void Search_Flower()
{
	char c, targetname[40], targetcolor[40];
	printf("\n\t\t\t\t\t\t\t<--<<Search Item>>-->\n\n");
	do
	{
	int found=0;
	FILE *sfile;
	sfile=fopen("item.txt","r");

	printf("\n\n\t\t\t\t\t\t\tEnter flower name to search: ");
	fflush(stdin);
	gets(targetname);
	printf("\n\t\t\t\t\t\t\tEnter flower color: ");
	fflush(stdin);
	gets(targetcolor);
	targetname[0]=toupper(targetname[0]);
	targetcolor[0]=toupper(targetcolor[0]);
	while (!feof(sfile) && found==0)
	{
		fscanf(sfile,"%s %s %i %i %i", st.name, st.color, &st.price, &st.productid,&st.qnt);
		if((strcmp(targetname, st.name)==0) && (strcmp(targetcolor, st.color)==0))
		{
			found=1;
		}
	}

	if(found)
	{
		printf("\n\t\t\t\t\t\t\t Record found");
		printf("\n\n\t\t\t\t\t\t\t Flower's Name\t: %s  \n\t\t\t\t\t\t\t Color\t\t: %s \n\t\t\t\t\t\t\t Price\t\t: %i \n\t\t\t\t\t\t\t ID\t\t:%i \n\t\t\t\t\t\t\t Quantity\t: %i\n", st.name, st.color, st.price, st.productid, st.qnt);

	}
	else
		printf("\n\t\t\t\t\t\t\t No Record found");
    fclose(sfile);
    printf("\n\n\t\t\t\t\t\t\t Press 'Enter' to search more item and any other key to go to back to main menu. ");
		}while((c = getch()) =='\r');
		//userchoicelist();

}
void delete_product()
{
    char c;
    printf("\n\t\t\t\t\t\t\t<--<<Delete Item>>-->\n\n");
    do
	{
    int target,found=0;
    FILE *sfile, *tfile;
    sfile=fopen("item.txt","r");
    tfile=fopen("temp.txt","w+");

    printf("\n\t\t\t\t\t\t\t Enter flower code to delete: ");
    fflush(stdin);
    scanf("%d",&target);
    while (fscanf(sfile,"%s %s %i %i %i\n",st.name,st.color, &st.price,&st.productid,&st.qnt)!=EOF)
    {
        if(target==st.productid)
        {
            found=1;
        }
        else
        {
            fprintf(tfile,"%s %s %i %i %i\n", st.name,st.color, st.price,st.productid,st.qnt);
        }
    }
    if(!found)
    {
        printf("\n\t\t\t\t\t\t\t Record not Found...");
        getch();
    }
    else
    {
        printf("\n\t\t\t\t\t\t\t Record deleted");
    }
    fclose(sfile);
    fclose(tfile);
    remove("item.txt");
    rename("temp.txt","item.txt");

    printf("\n\n\t\t\t\t\t\t\tPress 'Enter' to delete more item and any other key to go to back to editing panal ");
	}while((c = getch()) =='\r');
    adminchoicelist();
}

void read_item()
{
    system("cls");
	FILE *f;
	int i, q;
	if((f=fopen("item.txt","r"))==NULL)
	{

		gotoxy(10,3);
		printf("\n\t\t\t\t\t\t\tNO RECORDS");
		printf("\n\n\t\t\t\t\t\t\tPress any key to go back to Menu.");
		getch();
		menu();


	}
	else
	{
	printf("\n\t\t\t");
    for(i=0;i<15;i++)
    {
        printf("\xdb");
    }
    printf(" FLOWER LIST ");
    for(i=0;i<15;i++)
    {
        printf("\xdb");
    }
		gotoxy(0,5);
			for(i=0;i<100;i++)
		{
			printf("\xdb");
		}
		gotoxy(5,6);
		printf("Flower's Name");
		gotoxy(25,6);
		printf("Price");
		gotoxy(40,6);
		printf("Color");
		gotoxy(60,6);
		printf("Code");
		gotoxy(80,6);
		printf("Quantity\n");

		for(i=0;i<100;i++)
		{
			printf("\xdb");
		}
		q=8;
		while(fscanf(f,"%s %s %i %i %i\n", st.name,st.color, &st.price, &st.productid,&st.qnt)!=EOF)
		{
			gotoxy(5,q);
			printf("%s",st.name);
			gotoxy(25,q);
			printf("%i",st.price);
			gotoxy(40,q);
			printf("%s",st.color);
			gotoxy(60,q);
			printf("%i",st.productid);
			gotoxy(80,q);
			printf("%i",st.qnt);

			q++;
		}
		printf("\n");
		for(i=0;i<100;i++)
			printf("\xdb");
	}
	fclose(f);
	printf("\n\n\nPress any key to continue...");
	getch();
}
void edit_item()
{
	int index, valid;
	char target[40];
	FILE *fp, *rp;
	int a=0;
	int id;
	char edit;
	long int size=sizeof(st);
	if((fp=fopen("item.txt","r+"))==NULL)
	{
		printf("\n\t\t\t\t\t\t\t NO RECORD ADDED.");
		menu();
	}
	else
	{
		rp = fopen("temp.txt","a");
		system("cls");
		printf("\n\t\t\t\t\t\t\t Enter Flower's Code for edit:");
		scanf("%i",&id);
		fflush(stdin);
		while(fscanf(fp,"%s %s %i %i %i\n", st.name,st.color, &st.price, &st.productid,&st.qnt)!=EOF)
		{
			if(id==st.productid)
			{

				a=1;
				printf("\n\t\t\t\t\t\t\t\xdb\xdb\xdb\xdb\xdb Record Found \xdb\xdb\xdb\xdb\xdb");
				printf("\n\t\t\t\t\t\t\tItem's Name\t\t: %s",st.name);
				printf("\n\t\t\t\t\t\t\tItems's Color\t\t: %s",st.color);
				printf("\n\t\t\t\t\t\t\tPrice\t\t\t: %i",st.price);
				printf("\n\t\t\t\t\t\t\tItem's Code\t\t: %i",st.productid);
				printf("\n\t\t\t\t\t\t\tItem's Quantity\t\t:%i",st.qnt);

				printf("\n\n\t\t\t\t\t\t\t*** New Record ***");
			do
				{

					fflush(stdin);
					printf("\n\t\t\t\t\t\t\tNew Item's Name\t\t: ");
					gets(st.name);
					st.name[0]=toupper(st.name[0]);

					for (index=0; index<strlen(st.name); ++index)
					{
						if(isalpha(st. name[index]))
							valid = 1;
						else
						{
							valid = 0;
							break;
						}
					}
					if (!valid)
					{
						printf("\n\t\t\t\t\t\t\t Name contain invalid character. Please 'Enter' again");
						getch();


					}
				}while(!valid);
				do
				{
					char color[40];
					fflush(stdin);
					printf("\n\t\t\t\t\t\t\tNew Item's Color\t:");
					gets(st.color);
					st.color[0]=toupper(st.color[0]);

					for (index=0; index<strlen(st.color); ++index)
					{
						if(isalpha(st.color[index]))
							valid = 1;
						else
						{
							valid = 0;
							break;
						}
					}
					if (!valid)
					{
						printf("\n\t\t\t\t\t\t\t Name contain invalid character. Please 'Enter' again");
						getch();


					}
				}while(!valid);



				printf("\n\t\t\t\t\t\t\tNew Price :\t");
				scanf("%i",&st.price);
				if(st.price>5000)
				{
					printf("\n\t\t\t\t\t\t\tDecrease the price and re-Enter.");
				}


				printf("\n\t\t\t\t\t\t\tEnter New Item's Code\t:");
				scanf("%i",&st.productid);

				printf("\n\t\t\t\t\t\t\tNew Quantity :\t");
				scanf("%i",&st.qnt);

				printf("\n\t\t\t\t\t\t\tPress 'y' to edit the existing record or any key to cancel...");
				edit=getche();
				if(edit=='y' || edit=='Y')
				{
					fprintf(rp,"%s %s %i %i %i\n", st.name, st.color, st.price, st.productid,st.qnt);
					fflush(stdin);
					printf("\n\n\n\t\t\t\t\t\t\tYOUR RECORD IS SUCCESSFULLY EDITED!!!");
				}
			}
			else
			{
				fprintf(rp,"%s %s %i %i %i\n", st.name, st.color, st.price, st.productid,st.qnt);
				fflush(stdin);
			}

		}
		if(!a)
		{
			printf("\n\n\t\t\t\t\t\t\tTHIS ITEM DOESN'T EXIST!!!!");
		}
		fclose(rp);
		fclose(fp);
		remove("item.txt");
		rename("temp.txt","item.txt");
		getch();
	}
	adminchoicelist();
}
void Add_to_Cart()
{
    int i,n,c,tp=0,pp=0,q,target;
    printf("\n\t\t\t\t\t\t\t\t\t<--<<Buy Products>>-->\n\n");
    printf("\n\t\t\t\t\t\t\tHow many types of flower do you want to buy? Enter the number: ");
    scanf("%d",&n);
    if(n>0)
    {
    char uname[20],pss[20];
    FILE *fp;
    struct user u;


    FILE *order;
    order=fopen("order.txt","a");
    for(i=0;i<n;i++)
    {
    int found=0;
    FILE *sfile;

    sfile=fopen("item.txt","rb+");

    target=0;

    printf("\n\t\t\t\t\t\t\tEnter flower id: ");
    scanf("%i",&target);
    fflush(stdin);


    while (!feof(sfile) && found==0)
    {
    	fscanf(sfile,"%s %s %i %i %i", st.name, st.color, &st.price, &st.productid,&st.qnt);
    	if(target==st.productid)
    	{
    		found=1;
    	}
    }

    if(found)
    {
    	printf("\n\t\t\t\t\t\t\tFlower's Name\t:%s  \n\t\t\t\t\t\t\tColor\t\t:%s \n\t\t\t\t\t\t\tPrice\t\t:%i \n\t\t\t\t\t\t\tQuantity we can provide at a time: %i", st.name, st.color, st.price, st.qnt);
    	printf("\n\t\t\t\t\t\t\tEnter the quantity you want to buy: ");
    	scanf("%i",&q);
    	pp = st.price*q;
    	tp=tp+pp;
    	printf("\n\t\t\t\t\t\t\tPrice of %d %s id %d/-TK\n",q,st.name,pp);

		fprintf(order,"Name: %s \tColor: %s \tUnit Price: %i \tID: %i \tOrdered Quantity: %i \tTotal price: %i\n", st.name, st.color,st.price, st.productid, q, pp);
		//fclose(order);
    }
    else printf("\nNo Record found");
    fclose(sfile);
    }
    printf("\n\n\t\t\t\t\t\t\tTotal bill is %d",tp);
    //order=fopen("order.txt","a");
    fprintf(order,"Total price: %i\n",tp);
    fprintf(order,"Order code: %i\n",tp*11);
    fclose(order);
    printf("\n\t\t\t\t\t\t\tYour order code is %d. Please place your order manually.\n",tp*11);
    printf("\n\t\t\t\t\t\t\tPress any key to continue...");
    getch();
    }
}
void Place_Order()
{
    system("cls");
    struct user o;
    int oc;
    FILE *op;
    if(op = fopen ("order.txt", "wb+") == NULL)
	{
		printf("\n\t\t\t\t\t\t\t NO RECORD ADDED.");
		menu();
	}
	else
    {
    printf("\n\t\t\t\t\t\t\t\t\t<--<<Place Order>>-->\n\n");
    printf("\n\n");
    //getch();
    printf("\n\t\t\t\t\t\t    Enter your User name: ");
    fflush(stdin);
    gets(o.username);
    printf("\n");
    printf("\t\t\t\t\t\t    Enter the receiver's name: ");
    gets(o.rname);
    printf("\n");
    printf("\t\t\t\t\t\t    Enter Address: ");
    gets(o.address);
    printf("\n");
    printf("\t\t\t\t\t\t    Enter Phone number: ");
    scanf("%s",o.phone);
    printf("\n\t\t\t\t\t\t    Enter Order No: ");
    scanf("%s",&o.temp);
    printf("\n\t\t\t\t\t\t\t1. Cash on delivery\n\t\t\t\t\t\t\t2. Online Payment\n\t\t\t\t\t\t\tEnter your choice: ");
    scanf("%d",&oc);
    if(oc==1)
        printf("\n\t\t\t\t\t\t\tYour Order is Successful.");
    else
        printf("\n\t\t\t\t\t\t\tPlease make a payment manually.\n ");
    }
    printf("\n\t\t\t\t\t\t\tPress any key to continue...");
    getch();
    userchoicelist();
}
void Payment_Getaway()
{
    system("cls");
    int o,pc,p,a;
    char r,pn[15],id[20],d[20];
    printf("\n\t\t\t\t\t\t\t\t\t<--<<Online Payment Gateway>>-->\n\n");
    printf("\n\t\t\t\t\t\t\t\t\t1. Bkash/Rocket\n");
    printf("\n\t\t\t\t\t\t\t\t\t2. Visa Card/Master Card\n");
    printf("\n\t\t\t\t\t\t\t\t\t3. DBBL/SIBL\n\n");
    printf("\n\t\t\t\t\t\t\t\t\tEnter your choice: ");
    scanf("%d", &pc);
    switch(pc)
    {
    case 1:
        printf("\n\t\t\t\t\t\t\tEnter your order no: ");
        scanf("%d",&o);
        printf("\n\t\t\t\t\t\t\tEnter your phone number: ");
        scanf("%s",&pn);
        printf("\n\t\t\t\t\t\t\tEnter your amount: ");
        scanf("%d",&a);
        printf("\n\t\t\t\t\t\t\tEnter your pin code: ");
        scanf("%d",&p);
        printf("\n\t\t\t\t\t\t\tPayment accepted. Your order is placed successfully\n");
        getch();
        break;
    case 2:
        printf("\n\t\t\t\t\t\t\tEnter your order no: ");
        scanf("%d",&o);
        printf("\n\t\t\t\t\t\t\tEnter your account number: ");
        scanf("%s",&pn);
        printf("\n\t\t\t\t\t\t\tEnter your amount: ");
        scanf("%d",&a);
        printf("\n\t\t\t\t\t\t\tEnter your pin code: ");
        scanf("%d",&p);
        printf("\n\t\t\t\t\t\t\tPayment accepted. Your order is placed successfully\n");
        getch();
        break;
    case 3:
        printf("\n\t\t\t\t\t\t\tEnter your order no: ");
        scanf("%d",&o);
        printf("\n\t\t\t\t\t\t\tEnter your card number: ");
        scanf("%s",&pn);
        printf("\n\t\t\t\t\t\t\tEnter your amount: ");
        scanf("%d",&a);
        printf("\n\t\t\t\t\t\t\tEnter your pin code: ");
        scanf("%d",&p);
        printf("\n\t\t\t\t\t\t\tPayment accepted. Your order is placed successfully\n");
        getch();
        break;
    default:
        printf("\n\t\t\t\t\t\t\t Invalid Choice!");
        getch();
    }
    printf("\n\n\n\t\t\t\t\t\t\tThank you so much for playing a pivotal role in our growth.  Happy shopping! ");
    userchoicelist();
}
void About_Us()
{
    system("cls");
    printf("\n\t\t\t\t\t\t\t\t\t<--<<About us>>-->\n\n");
    printf("\n\t\t\t\t\t\t    Name:\t\t\t\t\tEmail:");
    printf("\n\t\t\t\t\t\t    Tamima Nishat\t\t\t\tnisattamima44cse@gmail.com");
    printf("\n\t\t\t\t\t\t    Afrina Akter Mim\t\t\t\tafrina141mim@gmail.com");
    printf("\n\t\t\t\t\t\t    Md. Hasibul Islam\t\t\t\thasibislam2k18@gmail.com");
    printf("\n\n\t\t\t\t\t\t    Address: \n\t\t\t\t\t\t    Rupnagar, Mirpur, Dhaka-1216\n");
    printf("\n\t\t\t\t\t\t    Contact Number: +8801744253687\n\n");
    printf("\n\t\t\t\t\t\t\t\t    Press any key to continue...");
    getch();
}
