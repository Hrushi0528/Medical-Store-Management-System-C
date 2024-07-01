#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include<time.h>
int medid[1000];
void gotoxy(int ,int );
void menu();
void add();
void view();
void search();
void modify();
void deletemed();
int generateid();
void buy();
struct medicine
{
    char name[20],mfd[10],exd[10];
    int quantity,id;
    float cost,cost_tab1;
};
struct sell_history
{
 	   char name[20],address[20],time[10],date[15],day[10];
 	   long int phno;
};
int main()
{
    char uname[12],pass[16];
    gotoxy(15,8);
    printf("<--:Medical Store Management System:-->");
   	gotoxy(19,15);
    printf("Enter username:");
    scanf("%s",uname);
    gotoxy(19,18);
    printf("Enter password:");
    scanf("%s",pass);
    if(strcmp(uname,"Hrushi")==0 && strcmp(pass,"Qwerty@1309")==0)
    {
        menu();
        }
    else
    {	gotoxy(23,23);
    	printf("Incorrect Credentials.Try Again !!!!!");
    	for(int i=0;i<=400000000;i++);
        system("cls");
        main();
        }
     menu();
    return 0;
}
void menu()
{
    int choice;
    system("cls"); //clrscr()
    gotoxy(10,3);
    printf("<--:MENU:-->");
    gotoxy(10,5);
    printf("Enter appropriate number to perform following task.");
    gotoxy(10,7);
    printf("1 : Add Medicines.");
    gotoxy(10,8);
    printf("2 : View Medicines.");
    gotoxy(10,9);
    printf("3 : Search Medicines.");
    gotoxy(10,10);
    printf("4 : Modify Medicines Information.");
    gotoxy(10,11);
    printf("5 : Delete Medicines ");
    gotoxy(10,12);
    printf("6 : Exit");
    gotoxy(10,13);
    printf("Enter your choice.");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        add();
        break;

    case 2:
        view();
        break;

    case 3:
        search();
        break;

    case 4:
        modify();
        break;

    case 5:
        deletemed();
        break;

    case 6:
       exit(1);
        break;

    default:
        gotoxy(10,17);
        printf("Invalid Choice.");
    }
}
void add()
{
    FILE *fp;
    struct medicine med,medpre;
    char another ='y';
    system("cls");
    fp = fopen("medicine.txt","ab+");
    if(fp == NULL){
        gotoxy(10,5);
        printf("Error opening file");
        exit(1);
    }
    fflush(stdin);
    while(another == 'y')
    {
        gotoxy(10,3);
        printf("<--:ADD MEDICINE:-->");
        gotoxy(10,5);
        printf("Enter details of medicine.");
        gotoxy(10,7);
        med.id=generateid();
        printf("Enter Medicine Name : ");
        gets(med.name);
        gotoxy(10,8);
        printf("Enter Manufacture date of medicine : ");
        gets(med.mfd);
        gotoxy(10,9);
        printf("Enter Expiry date of medicine : ");
        gets(med.exd);
        gotoxy(10,10);
        printf("Enter Sheets of Medicines added : ");
        scanf("%d",&med.quantity);
        gotoxy(10,11);
        printf("Enter Cost of each Sheet : ");
        scanf("%f",&med.cost);
        med.cost_tab1=med.cost/10.0;
        gotoxy(10,12);
        fflush(stdin);
  		fwrite(&med,sizeof(med),1,fp);
        printf("Medicine successfully added!!");
        gotoxy(10,17);
        printf("Want to add of another record? Then press 'y' else 'n'.");
        fflush(stdin);
//        another = getch();///???
        another = getch();
        system("cls");
        fflush(stdin);
    }
    fclose(fp);
    gotoxy(10,18);
    printf("Press any key to continue.");
    getch();
    menu();
}
void view()
{
    FILE *fp;
    int i=1,j;
    struct medicine med;
    system("cls");
    gotoxy(10,3);
    printf("<--:VIEW MEDICINE:-->");
    gotoxy(10,5);
    printf("S.No     ID      Name of Medicine        MFD          EXD         Quantity       Cost      Cost of 1tab");
    gotoxy(10,6);
    printf("----------------------------------------------------------------------------------------------------------");
    fp = fopen("medicine.txt","rb+");
    if(fp == NULL){
        gotoxy(10,8);
        printf("Error opening file.");
        exit(1);
    }
    j=8;
    while(fread(&med,sizeof(med),1,fp)== 1){
        gotoxy(10,j);
        printf("%-7d%-12d%-21s%-13s%-15s%-12d%-12.2f%-9.2f",i,med.id,med.name,med.mfd,med.exd,med.quantity,med.cost,med.cost_tab1);
        i++;
        j++;
    }
    fclose(fp);
    gotoxy(10,j+3);
    printf("Press any key to continue.");
    getch();
    menu();
}
void search()
{
    FILE *fp;
    struct medicine med;
    char stname[20];
    int id,opt;
    system("cls");
    gotoxy(10,2);
    printf("<--:SEARCH MEDICINE:-->");
    gotoxy(10,4);
    printf("<--Search by Id(0) or Name(1)-->");
    gotoxy(10,5);
    printf("Enter suitable option : ");
    scanf("%d",&opt);
    gotoxy(10,6);
    if(opt==1){
		  printf("Enter name of Medicine : ");
    	  fflush(stdin);
    	  gets(stname);
	 }
	 else if(opt==0){
	 	  printf("Enter id of Medicine : ");
    	  fflush(stdin);
    	  scanf("%d",&id);
	 }
	 else{
	 	  printf("Invalid Option.Try Again");
	 	  gotoxy(10,7);
	 	  printf("Press any key to continue.");
    	  getch();
    	  system("cls");
    	  fflush(stdin);
    	  search();
		  } 	  
    fp = fopen("medicine.txt","rb+");
    if(fp == NULL){
        gotoxy(10,7);
        printf("Error opening file");
        exit(1);
    }
    int i=1,j=12,flag=0;
    gotoxy(10,9);
    printf("S.No     ID      Name of Medicine        MFD          EXD         Quantity       Cost      Cost of 1tab");
    gotoxy(10,10);
    printf("----------------------------------------------------------------------------------------------------------");
	gotoxy(10,11);
    while(fread(&med,sizeof(med),1,fp ) == 1){
        if(strcmp(stname,med.name) == 0 ||(id==med.id)){
            printf("%-7d%-12d%-21s%-13s%-15s%-12d%-12.2f%-9.2f",i,med.id,med.name,med.mfd,med.exd,med.quantity,med.cost,med.cost_tab1);
            gotoxy(10,j);
            i++;j++;flag=1;
        }}
        if(flag==0)
       	{
		 	gotoxy(15,13);
		 	printf("Sorry !!! No Medicines are found.");
			}
    
    fclose(fp);
    gotoxy(10,17);
    printf("Press any key to continue.");
    getch();
    menu();
}
void modify()
{
    int id,flag=0;
    FILE *fp;
    struct medicine med;
    char opt='y';
    system("cls");
    gotoxy(10,3);
    printf("<--:MODIFY MEDICINE DATA:-->");
    gotoxy(10,5);
    printf("Enter id of the medicine to modify: ");
    fflush(stdin);
    scanf("%d",&id);
    fp = fopen("medicine.txt","rb+");
    if(fp == NULL){
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    rewind(fp);
    fflush(stdin);
    while(fread(&med,sizeof(med),1,fp) == 1)
    {
        if(id==med.id){
            gotoxy(10,7);
            printf("Enter new name: ");
            gets(med.name);
            gotoxy(10,8);
            printf("Enter new mfd : ");
            gets(med.mfd);
            gotoxy(10,9);
            printf("Enter new exd : ");
            gets(med.exd);
            gotoxy(10,10);
            printf("Enter new Cost : ");
            scanf("%f",&med.cost);
            med.cost_tab1=med.cost/10.0;
            fflush(stdin);
            fseek(fp ,-sizeof(med),SEEK_CUR);
            fwrite(&med,sizeof(med),1,fp);
            flag=1;
            gotoxy(10,11);
            printf("Information updated successfully !!!");
            break;
        }
    }
    fclose(fp);
    gotoxy(10,13);
    if(flag==0){
	    printf("No Medicine is found with the id:%d",id,".Try Again !!!");
	    gotoxy(10,14);
	    printf("Press any key to continue.");
    	getch();
    	menu();
		}
    printf("Want to update another medicine info? Then press 'y' else 'n'.");
    fflush(stdin);
	scanf("%c",&opt);
	if(opt=='y')
	{
	     fflush(stdin);
	     modify();
		 }
	system("cls");
 	fflush(stdin);
    gotoxy(10,16);
    printf("Press any key to continue.");
    getch();
    menu();
}
void deletemed()
{
    char stname[20];
    FILE *fp,*ft;
    int id,flag=0;
    struct medicine med;
    system("cls");
    gotoxy(10,3);
    printf("<--:DELETE MEDICINE:-->");
    gotoxy(10,5);
    printf("Enter id of the medicine : ");
    fflush(stdin);
    scanf("%d",&id);
    fp = fopen("medicine.txt","rb+");
    if(fp == NULL){
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    ft = fopen("temp.txt","wb+");
    if(ft == NULL){
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    while(fread(&med,sizeof(med),1,fp) == 1){
        if(id!=med.id)
            fwrite(&med,sizeof(med),1,ft);
        else
        	flag=1;
    }
    fclose(fp);
    fclose(ft);
    gotoxy(10,7);
    if(flag==1){
			remove("medicine.txt");
    		rename("temp.txt","medicine.txt");
			printf("Medicine is Successfully Deleted.");
			}
	else
		printf("No Medicine is Associated with the id %d.",id);	   
    gotoxy(10,10);
    printf("Press any key to continue.");
    getch();
    menu();
}
void gotoxy(int x,int y)
{
        COORD c;
        c.X=x;
        c.Y=y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
int generateid()
{
 	 int id,flag=0;
 	 srand(time(0));
 	 id=rand() % (999999 + 1 - 912345) + 912345;
 	 for(int i=0;medid[i]!=0;i++){
	 		 if(id==medid[i])
				 flag=1;
		 }
     if(flag==0)
     return id;
     else
     generateid();
}
	 			 
