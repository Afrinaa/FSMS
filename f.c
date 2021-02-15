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
};
int welcome()
{
    printf(" * * *\t\t\t\t\t\t\t      * * *\n");
    printf(" * * *\t\t\t\t\t\t\t      * * *\n");
    printf(" *****\t\t\t\t\t\t\t      *****\n");
    printf(" *****\t\t\t\t\t\t\t      *****\n");
    printf("  ***\t\t\t\t\t\t\t       ***\n");
    printf("   *\t\t#### Flower Shop Management System ####\t\t*\n");
    printf("** * **\t\t\t\t\t\t\t     ** * **\n");
    printf("** * **\t\t\t\t\t\t\t     ** * **\n");
    printf("   *\t\t\t\t\t\t\t        *\n");
    printf("   *\t\t\t\t\t\t\t        *\n\n\n");
}
int main()
{
    int a;
    system("cls");
    welcome();
    printf("\t1. User Panal\t\t\t2.Admin Panal\n");
    printf("\n\t\t    Enter your choice: ");
    scanf("%d",&a);
    switch (a)
        {
        case 1:
            system("cls");
            printf("\n\t\t\tWelcome to the User Panal!\n");
            userchoice();
            userchoicelist();
            break;

        case 2:
            system("cls");
            printf("\n\t\t\tWelcome to the Admin Panal!\n");
            adminv();
            adminchoicelist();
            break;

        case 3:
            exit(0);
        default:
            printf("Invalid Choice! \n");
            break;
        }
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
            printf("Invalid Choice! ");
            break;
        }


}

int menu()
{
    int ch;
    printf("\n\n\t1. Create Account\n");
    printf("\t2. Login\n");
    printf("\t3. Exit to main\n");
    printf("\n\t\t    Enter your choice :  ");
    scanf("%d",&ch);
    return ch;
}
void createaccount()
{
    struct user U;
    FILE *fp;
    system("cls");
    printf("\n\t\t\t<--<<Create Account>>-->");
    printf("\n\n");
    printf("    Enter First Name: ");
    fflush(stdin);
    gets(U.fname);
    printf("\n");
    printf("    Enter Last Name: ");
    gets(U.lname);
    printf("\n");
    printf("    Enter Username: ");
    scanf("%s",U.username);
    printf("\n");
    printf("    Enter Password: ");
    scanf("%s",U.pass);
    fp = fopen ("username.txt", "wb+");
    if (fp == NULL)
    {
        printf("\nError opened file\n");
        exit (1);
    }
    fwrite(&U, sizeof(struct user), 1, fp);
    fclose (fp);
    system("cls");
    printf("\n\t\t\tAccount Created Successfully.");
    printf("\n\n\t\t\t\t\t\t\tPress any key to continue...");
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
    printf("\n\t\t\t<<LOGIN TO YOUR ACCOUNT>>\n\n");
    printf(" Enter Username: ");
    scanf("%s",uname);
    printf("\n");
    printf(" Enter Password: ");
    scanf("%s",pss);
    fp=fopen("username.txt","rb+");
    if(fp==NULL)
    {
        printf("\"File not found\"");
        return 1;
    }
    while(fread(&u, sizeof(struct user), 1, fp)){
        if(strcmp(uname,u.username) == 0 && strcmp(pss,u.pass)==0)
        {
            printf(" \n Username And Password is Correct.\n");
            printf(" Press any key to continue...");
            getch();
            printf("\n\n\t\t\t\t Welcome %s %s ", u.fname,u.lname);
            getch();
        }
        else
        {
            printf("\n Username And Password is Incorrect.\n\n");
            printf(" Press any key to continue...");
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
    printf("\t\t\t* MAIN MENU *\n\n");
    printf("\t1. Flower List\n\t2. Search Flower\n\t3. Add to Cart\n\t4. Place Order\n\t5. Payment Gateway\n\t6. About Us\n\t7. Exist Program\n");
    printf("\n\nEnter your choice between 1 to 7: ");
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
        exit(0);
        break;
    default:
        printf("Invalid Choice!");
        getch();
    }
}
void adminv()
{
    userchoice();
    printf("Give the pin code of the shop to verify yourself!\n");
    int a=0,i=0;
    char c=' ',code[10],pass[10]="3091014";
    do
    {

        printf("\n\t\tPin Code: ");
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
            printf("\nWelcome to the information editing panal!!!!");
            printf("\nPress enter to continue...");
            getch();
            break;
        }
        else
        {
            printf("\nSorry!!!! You entry is denied.");
            a++;
            getch();

        }
    } while(a<=2);
    if (a>2)
    {
        printf("\nSorry you have entered the wrong pin code for four times!!!");

        getch();

    }
    system("cls");
}
void adminchoicelist()
{
    system("cls");
    int choice;
    printf("\n");
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
    printf("\n\t1. Add Items");
    printf("\n\t2. Delete Items");
    printf("\n\t3. View Items");
    printf("\n\t4. Edit Items");
    printf("\n\t5. Exit");
    printf("\n\nEnter your choice between 1 to 5: ");
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
        edit_item();
        adminchoicelist();
        break;
    case 5:
        main();
        break;
    default:
        printf("Invalid Choice!");
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
		for(i=0;i<12;i++)
        {
            printf("\xdb");
        }
		printf(" Enter Item Details ");
		for(i=0;i<12;i++)
        {
            printf("\xdb");
        }
		int ID;
		fp = fopen("item.txt","a+");

		if((fp = fopen("item.txt","a+"))!=NULL)
		{
			I:
			printf("\nCode\t : ");
			scanf("%i",&ID);
			while(fscanf(fp,"%s %s %i %i %i", st.name, st.color, &st.price, &st.productid,&st.qnt)!=EOF)
			{
				if(ID == st.productid)
				{
					printf("\n\tTHE PRODUCT CODE ALREADY EXIST.\n");
					goto I;
				}
			}
			st.productid = ID;
		}
		else
		{
			printf("\nCode\t : ");
			scanf("%i",&st.productid);
		}
		do
		{
			fflush(stdin);
			printf("\nFlower's Name\t : ");
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
				printf("\n Name contain invalid character. Please 'Enter' again");
				getch();


			}
		}while(!valid);



			do
		{
			char color[40];
			fflush(stdin);
			printf("\nColor\t : ");
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
				printf("\n Name contain invalid character. Please 'Enter' again");
				getch();


			}
		}while(!valid);
		do
			{
				printf("\nPrice per stick or branch: ");
				scanf("%i",&st.price);
				if(st.price<10 || st.price>5000)
				{
					printf("\n\tDecrease the price.");
				}
			}while(st.price<10 || st.price>5000);
            printf("\nQuantity available \t: ");
            scanf("%i",&st.qnt);

		fp=fopen("item.txt","a");
		fprintf(fp,"\n%s %s %i %i %i", st.name, st.color,st.price, st.productid,st.qnt);
		fclose(fp);
		printf("\nPress 'Enter' to add more item and any other key to go to back to editing panal");

	}
	while((c = getch()) =='\r');
	adminchoicelist();
}
void Search_Flower()
{
	char target[40];
	int found=0;
	FILE *sfile;
	sfile=fopen("item.txt","r");
	printf("\nEnter flower name to search: ");
	fflush(stdin);
	gets(target);
	target[0]=toupper(target[0]);
	while (!feof(sfile) && found==0)
	{
		fscanf(sfile,"%s %s %i %i %i", st.name, st.color, &st.price, &st.productid,&st.qnt);
		if(strcmp(target, st.name)==0)
		{
			found=1;
		}
	}

	if(found)
	{
		printf("\n Record found");
		printf("\nFlower's Name\t:%s  \nColor\t\t:%s \nPrice\t\t:%i \nID\t\t:%i \nQuantity\t:%i", st.name, st.color, st.price, st.productid, st.qnt);

	}
	else
		printf("No Record found");
		fclose(sfile);
		printf("\n\nPress enter to go back to Main Menu!");
		getch();
		userchoicelist();

}
void delete_product()
{
    char target[40];
    int found=0;
    FILE *sfile, *tfile;
    sfile=fopen("item.txt","r");
    tfile=fopen("temp.txt","w+");
    printf("\n Enter name to Delete: ");
    fflush(stdin);
    scanf("%s",target);
    target[0]=toupper(target[0]);
    while (fscanf(sfile,"%s %s %i %i %i\n",st.name,st.color, &st.price,&st.productid,&st.qnt)!=EOF)
    {
        if(strcmp(target,st.name)==0)
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
        printf("\n Record not Found");
        getch();
        menu();
    }
    else
    {
        printf("\n Record deleted");
    }
    fclose(sfile);
    fclose(tfile);
    remove("item.txt");
    rename("temp.txt","item.txt");

    printf("\nPress any key to go back to editing panal!");
    getch();
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
		printf("NO RECORDS");
		printf("\n\t\tPress any key to go back to Menu.");
		getch();
		menu();


	}
	else
	{
	    printf("\n\n");
	    printf("\t\t");
        for(i=0;i<10;i++)
		{
			printf("*");
		}
        for(i=0;i<10;i++)
		{
			printf("\xdb");
		}
		printf("\tFLOWER LIST\t");
		for(i=0;i<10;i++)
		{
			printf("\xdb");
		}
		for(i=0;i<10;i++)
		{
			printf("*");
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
	printf("\nPress any key to continue...");
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
		printf("NO RECORD ADDED.");
		menu();
	}
	else
	{
		rp = fopen("temp.txt","a");
		system("cls");
		printf("Enter Flower's Code for edit:");
		scanf("%i",&id);
		fflush(stdin);
		while(fscanf(fp,"%s %s %i %i %i\n", st.name,st.color, &st.price, &st.productid,&st.qnt)!=EOF)
		{
			if(id==st.productid)
			{

				a=1;
				printf("\n\t\xdb\xdb\xdb\xdb\xdb Record Found \xdb\xdb\xdb\xdb\xdb");
				printf("\nItem's Name\t\t: %s",st.name);
				printf("\nItems's Color\t\t: %s",st.color);
				printf("\nPrice\t\t\t: %i",st.price);
				printf("\nItem's Code\t\t: %i",st.productid);
				printf("\nItem's Quantity\t\t:%i",st.qnt);

				printf("\n\n\t*** New Record ***");
			do
				{

					fflush(stdin);
					printf("\nNew Item's Name\t\t: ");
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
						printf("\n Name contain invalid character. Please 'Enter' again");
						getch();


					}
				}while(!valid);
				do
				{
					char color[40];
					fflush(stdin);
					printf("\nNew Item's Color\t:");
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
						printf("\n Name contain invalid character. Please 'Enter' again");
						getch();


					}
				}while(!valid);

					do
			{
				printf("\nNew Price :\t");
				scanf("%i",&st.price);
				if(st.price<10 || st.price>5000)
				{
					printf("\n\tDecrease the price and re-Enter.");
				}
			}while(st.price<10 || st.price>5000);

				printf("\nEnter New Item's Code\t:");
				scanf("%i",&st.productid);

				printf("\nNew Quantity :\t");
				scanf("%i",&st.qnt);

				printf("Press 'y' to edit the existing record or any key to cancel...");
				edit=getche();
				if(edit=='y' || edit=='Y')
				{
					fprintf(rp,"%s %s %i %i %i\n", st.name, st.color, st.price, st.productid,st.qnt);
					fflush(stdin);
					printf("\n\n\t\tYOUR RECORD IS SUCCESSFULLY EDITED!!!");
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
			printf("\n\nTHIS ITEM DOESN'T EXIST!!!!");
		}
		fclose(rp);
		fclose(fp);
		remove("item.txt");
		rename("temp.txt","item.txt");
		getch();
	}
	adminchoicelist();
}
void Add_to_Cart(){}
void Place_Order(){}
void Payment_Getaway(){}
void About_Us()
{
    system("cls");
    printf("\n\t\t\t--<<About us>>--\n\n");
    printf("Name:\t\t\t\t\tEmail:");
    printf("\nTamima Nishat\t\t\t\tnisattamima44cse@gmail.com");
    printf("\nAfrina Akter Mim\t\t\tafrina141mim@gmail.com");
    printf("\nMd. Hasibul Islam\t\t\thasibislam2k18@gmail.com");
    printf("\n\nAddress: \nRupnagar, Mirpur, Dhaka-1216\n");
    printf("Contact Number: +8801744253687\n\n");
    printf("Press any key to continue...");
    getch();
}

