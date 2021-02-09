#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
#include <windows.h>
int i;
void total_ammount()
{
    printf("Press any key to continue...");
    getch();
    system("cls");
    menu();
}

void menu()
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
    printf("\n\t4. Total Stock");
    printf("\n\t5. Edit Items");
    printf("\n\t6. Exit");
    printf("\n\nEnter your choice between 1 to 6: ");
    scanf("%d", &choice);
    system("cls");
    switch(choice)
    {
    case 1:
        add_item();
        break;
    case 2:
        delete_product();
        break;
    case 3:
        read_item();
        break;
    case 4:
        total_ammount();
        break;
    case 5:
        edit_item();
        break;
    case 6:
        main();
        break;
    default:
        printf("Invalid Choice! System Exit...");
        getch();
    }

}
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
int choicelist()
{
    printf("\t\t\t* MAIN MENU *\n\n");
    printf("\t1. User System\t\t\t2. Flower Category\n");
    printf("\t3. Search Flower\t\t4. Flower List\n");
    printf("\t5. Add to Cart\t\t\t6. Place Order\n");
    printf("\t7. Payment Gateway\t\t8. Information Edit\n");
    printf("\t9. About Us\t\t\t10. Exist Program\n");
}
int User_System()
{
    FILE *fl;
    fl = fopen("registration.txt", "w+");
    if (fl == NULL)
    {
        printf("File does not exists \n");
        return 0;
    }
    char c1;
    char name[30], password[30], address[100],number[15];
    printf("\na. Log in\nb. Registration\n");
    printf("Enter your choice: ");
    scanf("%c",&c1);
    getchar();
    if(c1=='a')
    {
        fprintf(fl, "Login:\n");
        printf("Enter Number: ");
        gets(number);
        fprintf(fl, "Number= %s\n", number);
        printf("Enter Password: ");
        gets(password);
        fprintf(fl, "Password= %s\n", password);
    }
    else if(c1=='b')
    {
        fprintf(fl, "Registration:\n");
        printf("Enter Name: ");
        gets(name);
        fprintf(fl, "Name= %s\n", name);
        printf("Enter Number: ");
        gets(number);
        fprintf(fl, "Number= %s\n", number);
        printf("Enter Password: ");
        gets(password);
        fprintf(fl, "Password= %s\n", password);
        printf("Enter Address: ");
        gets(address);
        fprintf(fl, "Address= %s\n", address);
    }
    else
        printf("Invalid command\n");
    main();
}
void admin()
{

    int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    char user[10]="admin";
    char pass[10]="entry";
    do
    {

        printf("\n\t--------------------LOGIN--------------------");
        printf("\n\n\t\tUSERNAME: ");
        scanf("%s", &uname);
        printf("\n\t\tPASSWORD: ");
        while(i<10)
        {
            pword[i]=getch();
            c=pword[i];
            if(c==13)
                break;
            else
                printf("*");
            i++;
        }
        pword[i]='\0';
        i=0;
        if(strcmp(uname,"admin")==0 && strcmp(pword,"entry")==0)
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
    }
    while(a<=2);
    if (a>2)
    {
        printf("\nSorry you have entered the wrong username and password for four times!!!");

        getch();

    }
    system("cls");
}
int Flower_Category()
{
    char ch, c2;
    FILE *season;
    season=fopen("season.txt","r");
    FILE *color;
    color=fopen("color.txt","r");
    printf("\na. Flowers\nb. Packaging type\n");
    printf("Enter your choice: ");
    scanf("%c",&c2);
    if(c2=='a')
    {
        read_item();
    }
    else if(c2=='b')
    {
        if(color==NULL)
            printf("File doesn't exist");
        else
        {
            printf("\n");
            while(!feof(color))
            {
                ch=fgetc(color);
                printf("%c",ch);
            }
        }
    }
    else
        printf("Invalid command\n");
    fclose(season);
    fclose(color);
    printf("\nClick enter to continue....");
    getch();
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
	menu();
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
}
void gotoxy(short x, short y)
{
	COORD pos ={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
void Search_Flower()
{
	char target[40];
	int found=0;
	FILE *sfile;
	sfile=fopen("item.txt","r");
	printf("\nEnter flower name to search:");
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
		main();

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
    menu();
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
				printf("\nItems's Brand\t\t: %s",st.color);
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
					printf("\nNew Item's Brand\t\t:");
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
				printf("\nNew Price :");
				scanf("%i",&st.price);
				if(st.price<10 || st.price>5000)
				{
					printf("\n\tDecrease the price and re-Enter.");
				}
			}while(st.price<10 || st.price>5000);

				printf("\nEnter New Item's Code\t\t:");
				scanf("%i",&st.productid);

				printf("\nNew Quantity \t:");
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
	menu();
}
int Add_to_Cart()
{

}
int Place_Order()
{

}
int Payment_Getaway()
{

}
int Information_Edit()
{
    admin();
    menu();
}

int About_Us()
{
    system("cls");
    printf("About us:\n\n");
    printf("Name: Tamima Nishat, Email: nisattamima44cse@gmail.com\n");
    printf("Afrina Akter Mim, Email: afrina141mim@gmail.com\n");
    printf("Md. Hasibul Islam, Email: hasibislam2k18@gmail.com\n\n");
    printf("Address: Rupnagar, Mirpur, Dhaka-1216\n");
    printf("Contact Number: +8801744253687\n\n");
    printf("Press enter to go back to Main Menu! ");
    getch();
}
int main()
{
    int c;
    system("cls");
    welcome();
    choicelist();
    printf("\nEnter your command: ");
    scanf("%d",&c);
    getchar();
    switch (c)
    {
    case 1:
        User_System();
        break;
    case 2:
        Flower_Category();
        break;
    case 3:
        Search_Flower();
        break;
    case 4:
        read_item();
        printf("\n\nPress enter to go back to Main Menu!");
        getch();
        main();
        break;
    case 5:
        Add_to_Cart();
        break;
    case 6:
        Place_Order();
        break;
    case 7:
        Payment_Getaway();
        break;
    case 8:
        system("cls");
        Information_Edit();
        menu();
        //system("cls");
        break;
    case 9:
        About_Us();
        main();
        break;
    case 10:
        break;
    default:
        printf("Please choose between 1 - 10.\n");
        break;
    }
    return 0;
}


