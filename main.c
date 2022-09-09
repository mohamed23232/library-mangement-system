#include <stdio.h>
#include <stdlib.h>
#include <conio.h> // STL to use getch function

typedef enum {false, true} bool;  // definition that allows us to use booleans

int i =0;
int choise; // int the menu function
int NoPatients; // in the add new patient function
int numbers; // indexing of the patients
int service[500] , age [500] , room[500],sex [500],deposit[500],totalCharge[500],moneyReturn[500]; // arrays to store numbers in the records of the patients;
char name [500][100], address [500][500], disease [500][500], sort [500][100]; // arrays to store strings


void menu(); // display function
void US(); // info about us

void AddNewPatient();
void View();
void Search();
void Edit();
void deletePatient();

void display(int p); //to view the data of the patient

int main()
{
    bool isNotFinished = true;
    US();
do{
        menu();
    switch(choise){
case 1:
    system("cls");
    AddNewPatient();
    break;
case 2:
    system("cls");
    View();
    break;

case 3:
    system("cls");
    Search();
    break;

case 4:
    system("cls");
    Edit();
    break;

case 5:
    system("cls");
    deletePatient();
    break;
case 6:
     isNotFinished = false;
    break;
default:
    printf("INVALID CHOISE, TRY AGAIN\n");
    }
}while(isNotFinished);
}

void US (){
  printf("**********************SUBMITTED BY***********************\n\n");
  printf("Mohamed Ahmed Rabea Mahrous\n");
  printf("Eman Mohamed Abdelhamid Abdelwahab\n");
  printf("Bassmala Yousef Ismail Ahmed\n");
  printf("Dalia Khaled Mohamed Hanafy\n");
  printf("Mario Mafdy Habib Beshoy\n\n");
  printf("*********************************************************\n");
  printf("\nPress any key to continue...................");
  getch();
  system("cls");
}


void menu(void){
    printf("*****************WELCOME TO OUR HOSPITAL*****************\n");
    printf("***HERE IS OUR MENU PLEASE CHOOSE WHAT YOU WANT TO DO****\n\n");

    printf("1.ADD NEW PATIENTS\n");
    printf("2.VIEW LIST OF OUR PATIENTS\n");
    printf("3.SEARCH\n");
    printf("4.EDIT INFORMATION\n");
    printf("5.DELETE PATIENTS\n");
    printf("6.EXIT\n\n");

    printf("YOUR CHOISE :: ");
    scanf("%d",&choise);
}



void AddNewPatient(void){
    printf("HOW MANY PATIENTS DO YOU WANT TO ADD?\n YOUR CHOISE :: ");
    scanf("%d",&NoPatients);
    system("cls");
    for(int j = 0; j < NoPatients;j++){
            printf("PATIENT NUMBER :: %d\n\n",j+1);
  do{
    printf("SERVICE ::  \n 1- Neurologist \n 2- psychiatrist \n 3- surgeon \n 4- internist\n\nYOUR CHOISE :: ");
    scanf("%d",&service[i]);
    }while (!(service[i] > 0 && service[i] < 5));
   printf("\nNAME :: ");
   scanf("\n %[^\n]s",name[i]);

   printf("ADDRESS :: ");
   scanf("\n %[^\n]s",address[i]);
   do{
   printf("AGE :: ");
   scanf("%d",&age[i]);
   }while(!(age[i] > 0 && age[i] < 120));
   printf("DISEASE DESCRIPTION :: ");
   scanf("\n %[^\n]s",disease[i]);
   do{
   printf("DEPOSIT AMOUNT :: ");
   scanf("%d",&deposit[i]);
   }while(!(deposit > 0));
   do{
   printf("TOTAL CHARGE :: ");
   scanf("%d",&totalCharge[i]);
   }while(!(totalCharge > 0));
   moneyReturn[i] = deposit[i] - totalCharge[i];


    printf("SEX :: \n 1- MALE \n 2- FEMALE \n::: ");
  do{  scanf("\n%d",&sex[i]);
   } while (sex[i]!=1 && sex[i]!=2);
   room[i]=i+1;
   i++;
   numbers = i;
   system("cls");
    }
};

void Search(void)
{
    int s,h,i,pos,c=0;
     // s is variable of serial number ........ h refer to way of searching ....... pos and c are used as checkers
    char array[100]={0};
    do{
    printf("GET YOUR PATIENT BY :: \n 1.SERIAL NO.\n 2.NAME\n::: ");
    scanf("%d",&h);
    }while(!(h == 1 || h == 2));
    if(h==1)
    {
        printf("ENTER SERIAL NUMBER OF THE PATIENT :: ");
        scanf("%d",&s);
        pos=-1;
        for(i=0;i<numbers;i++)
       {
           if(s==room[i])
        {
            pos=i;
            break;
        }
       } if(pos==-1)
       printf("\nTHE SERIAL NUMBER OF %d IS NOT FOUND", s);
        else
           {
            display(i);
           }
    }
  else  {
     printf("\n NAME :: ");
    scanf("\n%[^\n]s",array);
    for(i=0;i<numbers;i++)
    {
        if(strcmp(name[i],array)==0)
        {
            c=1;
            pos=i;
            break;
        }
    }
    if(c==1)
    {
          display(i);
    }
    else
        printf("\n%s IS NOT FOUND",array);
  }

    printf("\n\nPress any key to continue.........");
    getch();
    system("cls");
}

void Edit(void)
{
    int s,h,i,pos,c=0,ch,newService,check;
    // s is variable of serial number ........ h refer to way of searching ....... pos and c are used as checkers
    char array[100]={0};
    do{
    printf("GET YOUR PATIENT BY :: \n 1.SERIAL NO.\n 2.NAME\n::: ");
    scanf("%d",&h);
    }while(!(h == 1 || h == 2));
    if(h==1)
    {
        printf("ENTER SERIAL NUMBER OF THE PATIENT :: ");
        scanf("%d",&s);
        pos=-1;
        for(i=0;i<numbers;i++)
       {
           if(s==room[i])
        {
            pos=i;
            break;
        }
       } if(pos==-1)
       printf("\nTHE SERIAL NUMBER OF %d IS NOT FOUND", s);
        else
           {
               do{
               printf("\nNAME :: %s\n\nWHAT DO YOU WANT TO EDIT?\n\n 1.SERVICE \n 2.NAME \n 3.ADDRESS \n 4.AGE \n 5.DISEASE\n 6.DEPOSIT \n 7.TOTAL CHARGE \n\nYOUR CHOISE :: ",name[i]);
               do{
               scanf("%d",&ch);
               }while(!(ch > 0 && ch < 8));
               if(ch == 1){
                printf("SERVICE :: \n 1- Neurologist \n 2- psychiatrist \n 3- surgeon \n 4- internist\n ");
                do{
                scanf("%d",&newService);
                }while(!(newService > 0 && newService < 5));
                service[i] = newService;
               }
               else if(ch == 2){
                printf("NEW NAME :: ");
                scanf("\n %[^\n]s",name[i]);
               }
               else if(ch == 3){
                printf("NEW ADDRESS :: ");
                scanf("\n %[^\n]s",address[i]);
               }
               else if(ch == 4){
                printf("NEW AGE :: ");
                scanf("%d",&age[i]);
               }
               else if(ch == 5){
                printf("NEW DISEASE DESCRIPTION :: ");
                scanf("\n %[^\n]s",disease[i]);
               }
               else if(ch == 6){
                do{
                printf("NEW AMOUNT TO DEPOSIT :: ");
                scanf("%d",&deposit[i]);
                }while(!(deposit > 0));
                moneyReturn[i] = deposit[i] - totalCharge[i];
               }
               else {
                do{
                printf("NEW TOTAL CHARGE :: ");
                scanf("%d",&totalCharge[i]);
                }while(!(totalCharge > 0));
                moneyReturn[i] = deposit[i] - totalCharge[i];
               }
               system("cls");
               do{
               printf("DO YOU WANT TO EDIT SOMETING ELSE ?? \n 1.YES \n 2. NO \n ENTER YOUR CHOISE :: ");
               scanf("%d",&check);
               }while(!(check == 1 || check == 2));
               }while(!(check == 2));
           }
    }
  else  {
     printf("\n NAME :: ");
    scanf("\n%[^\n]s",array);
    for(i=0;i<numbers;i++)
    {
        if(strcmp(name[i],array)==0)
        {
            c=1;
            pos=i;
            break;
        }
    }
    if(c==1)
    {
               do{
               printf("WHAT DO YOU WANT TO EDIT?\n\n 1.SERVICE \n 2.NAME \n 3.ADDRESS \n 4.AGE \n 5.DISEASE\n 6.DEPOSIT \n 7.TOTAL CHARGE \n\nYOUR CHOISE :: ");
               do{
               scanf("%d",&ch);
               }while(!(ch > 0 && ch < 8));
               if(ch == 1){
                printf("SERVICE :: \n 1- Neurologist \n 2- psychiatrist \n 3- surgeon \n 4- internist\n ");
                do{
                scanf("%d",&newService);
                }while(!(newService > 0 && newService < 5));
                service[i] = newService;
               }
               else if(ch == 2){
                printf("NEW NAME :: ");
                scanf("\n %[^\n]s",name[i]);
               }
               else if(ch == 3){
                printf("NEW ADDRESS :: ");
                scanf("\n %[^\n]s",address[i]);
               }
               else if(ch == 4){
                printf("NEW AGE :: ");
                scanf("%d",&age[i]);
               }
               else if(ch == 5){
                printf("NEW DISEASE DESCRIPTION :: ");
                scanf("\n %[^\n]s",disease[i]);
               }
               else if(ch == 6){
                do{
                printf("NEW AMOUNT TO DEPOSIT :: ");
                scanf("%d",&deposit[i]);
                }while(!(deposit > 0));
                moneyReturn[i] = deposit[i] - totalCharge[i];
               }
               else {
                do{
                printf("NEW TOTAL CHARGE :: ");
                scanf("%d",&totalCharge[i]);
                }while(!(totalCharge > 0));
                moneyReturn[i] = deposit[i] - totalCharge[i];
               }
               system("cls");
               do{
               printf("DO YOU WANT TO EDIT SOMETHING ELSE ?? \n 1.YES \n 2. NO \n\nYOUR CHOISE :: ");
               scanf("%d",&check);
               }while(!(check == 1 || check == 2));
               }while(!(check == 2));
    }
    else
        printf("\n%s IS NOT FOUND",array);
  }
  printf("\n\nPress any key to continue.........");
    getch();
    system("cls");
}





void View (void)
{int j=0, count,cnt = 0 ;
char tmp[100];
int tempC[500],tempD[500],tempR[500];

    for (j=0;j<numbers;j++)
    {
        strcpy(sort[j],name[j]);
    }
    for (count =0;count <numbers;count++){
    for (j=0;j<numbers-count-1;j++)
    {
        if (strcmp(sort[j],sort[j+1])>0)
        {
            strcpy(tmp,sort[j]);
            strcpy(sort[j],sort[j+1]);
            strcpy(sort[j+1],tmp);


        }
    }}

    for(int k = 0; k < numbers;k++){
    for(int t=0;t<numbers;t++)
    {
        if(strcmp(name[t],sort[k])==0)
        {
            tempC[cnt] = totalCharge[t];
            tempD[cnt] = deposit[t];
            tempR[cnt] = moneyReturn[t];
            cnt++;
            break;
        }
    }
    }

    printf("*****************NAMES OF PATIENTS SORTED****************\n");
    for(j=0;j<numbers;j++)
    {
        printf("\n NAME :: %s",sort[j]);
        printf("\n TOTAL CHARGE :: %d",tempC[j]);
        printf("\n DEPOSIT AMOUNT :: %d",tempD[j]);
        if(tempR[j] < 0)
        printf("\n MONEY TO GET FROM THE PATIENT :: %d\n", - 1 * tempR[j]);
        else
        printf("\n MONEY TO GIVE TO THE PATIENT :: %d\n",tempR[j]);

    }

    printf("\n\nPress any key to continue.........");
    getch();
    system("cls");
}

void deletePatient (void)

{
int s,h,i,pos,c=0,sure;
 // s is variable of serial number ........ h refer to way of searching ....... pos and c are used as checkers ....... sure is used as a checker aswell
    char array[100]={0};
    do{
    printf("GET YOUR PATIENT BY \n 1.SERIAL NO.\n 2.NAME\n::: ");
    scanf("%d",&h);
    }while(!(h == 1 || h == 2));
    if(h==1)
    {
        printf("ENTER SERIAL NUMBER OF THE PATIENT :: ");
        scanf("%d",&s);
        pos=-1;
        for(i=0;i<numbers;i++)
       {
           if(s==room[i])
        {
            pos=i;
            break;
        }
       } if(pos==-1)
       printf("\nTHE SERIAL NUMBER OF %d IS NOT FOUND", s);
        else
           {
       display(i);
            printf("*************DELETING THE PATIENT*************\n");

            do{
                    printf("\n**ARE YOU SURE??** \n1.YES\n2.NO\nYOUR CHOISE :: ");
                    scanf("%d",&sure);
                 }   while(!(sure == 1 || sure == 2));
            if(sure == 1){
            printf("\nPress any key to CONFIRM......\n");
            getch();
            for(int h = i; h < numbers - 1;h++){
           age[h]=age[h+1];
           service[h]=service[h+1];
           room[h]=room[h+1];
           sex[h]=sex[h+1];
           strcpy(name[h],name[h+1]);
           strcpy(address[h],address[h+1]);
           strcpy(disease[h],disease[h+1]);
            }
            numbers -= 1;
            system("cls");
            printf("YOUR PATIENT IS DELETED");
            }
            else{
                    system("cls");
                printf("YOUR PATIENT IS NOT DELETED\n\n");
            }
           }
    }
    else  {
     printf("\n please Enter Name to be Searched: ");
    scanf("\n%[^\n]s",array);
    for(i=0;i<numbers;i++)
    {
        if(strcmp(name[i],array)==0)
        {
            c=1;
            pos=i;
            break;
        }
    }
    if(c==1)
    {
         display(i);

            printf("*************DELETING THE PATIENT*************\n");
             do{
                    printf("\n**ARE YOU SURE??** \n1.YES\n2.NO\nYOUR CHOISE :: ");
                    scanf("%d",&sure);
                  }  while(!(sure == 1 || sure == 2));
                  if(sure == 1){
            printf("\nPress any key to CONFIRM......\n");
            getch();
            for(int h = i; h < numbers - 1;h++){
           age[h]=age[h+1];
           service[h]=service[h+1];
           room[h]=room[h+1];
           sex[h]=sex[h+1];
           strcpy(name[h],name[h+1]);
           strcpy(address[h],address[h+1]);
           strcpy(disease[h],disease[h+1]);
            }
            numbers -= 1;
            system("cls");
            printf("YOUR PATIENT IS DELETED");
                  }
                  else{
                    system("cls");
                    printf("YOUR PATIENT IS NOT DELETED");
                  }
    }
    else
        printf("\n%s IS NOT FOUND",array);
  }
  printf("\n\nPress any key to continue.........");
    getch();
    system("cls");
}

void display(int p){
          printf("\n");
          printf("NAME :: %s\n",name[p]);
            printf("AGE :: %d\n",age[p]);
            printf("ROOM NO. :: %d\n",room[p]);
            if(service[p]==1)
            printf("SERVICE :: Neurologist\n");
            else if(service[p]==2)
              printf("SERVICE :: psychiatrist\n");
              else if (service[p]==3)
                printf("SERVICE :: surgeon\n");
            else
                printf("SERVICE :: internist\n");
                if(sex[p]==1)
                  printf("SEX :: male\n");
                else
                printf("SEX :: female\n");
                printf("ADDRESS :: %s\n",address[p]);
                printf("DISEASE DESCRIPTION :: %s\n",disease[p]);
                printf("TOTAL CHARGE :: %d\n",totalCharge[p]);
                printf("DEPOSIT AMOUNT :: %d\n",deposit[p]);
                if(moneyReturn[p] < 0)
        printf("MONEY TO GET FROM THE PATIENT :: %d\n", -1 * moneyReturn[p]);
        else
        printf("MONEY TO GIVE TO THE PATIENT :: %d",moneyReturn[p]);

            printf("\n\n");
}
