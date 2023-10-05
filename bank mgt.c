#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
#include<dos.h>
#include<ctype.h>
#include<time.h>
void createacc();
void cashdep();
void cashwithdrawal();
void fundtrnfr();
void accinf();
void password();
void delay();
void mainpgm();

int l=11,c=0;
struct customer
{
   char name[25],acctype[10],phno[15],dob[10];
   int accno,l;
   float amount,balance;
}cd[100];
void main()
{
    password();
    mainpgm();
}
void mainpgm()
{
    int n,k;
    system("cls");
    FILE *customerdetail;
    customerdetail=fopen("csdtl.txt","a+");
    {
        strcpy(cd[1].name,"Alan");
        strcpy(cd[1].acctype,"Savings");
        strcpy(cd[1].phno,"8943963650");
        strcpy(cd[1].dob,"24/09/2002");
        cd[1].accno=4121;
        cd[1].balance=25860;
        strcpy(cd[2].name,"Alvin");
        strcpy(cd[2].acctype,"Savings");
        strcpy(cd[2].phno,"9865423017");
        strcpy(cd[2].dob,"28/12/2002");
        cd[2].accno=4122;
        cd[2].balance=16866;
        strcpy(cd[3].name,"kevin");
        strcpy(cd[3].acctype,"Savings");
        strcpy(cd[3].phno,"7736282696");
        strcpy(cd[3].dob,"17/06/2003");
        cd[3].accno=4123;
        cd[3].balance=15000;
        strcpy(cd[4].name,"Gopika");
        strcpy(cd[4].acctype,"Savings");
        strcpy(cd[4].phno,"9856636503");
        strcpy(cd[4].dob,"24/09/2003");
        cd[4].accno=4124;
        cd[4].balance=36547;
        strcpy(cd[5].name,"Joan");
        strcpy(cd[5].acctype,"Savings");
        strcpy(cd[5].phno,"9589396365");
        strcpy(cd[5].dob,"4/03/2003");
        cd[5].accno=4125;
        cd[5].balance=45368;
        strcpy(cd[6].name,"Aya");
        strcpy(cd[6].acctype,"Savings");
        strcpy(cd[6].phno,"8586146328");
        strcpy(cd[6].dob,"25/02/2003");
        cd[6].accno=4126;
        cd[6].balance=12562;
        strcpy(cd[7].name,"Anna");
        strcpy(cd[7].acctype,"Savings");
        strcpy(cd[7].phno,"9860146759");
        strcpy(cd[7].dob,"24/09/2003");
        cd[7].accno=4127;
        cd[7].balance=25863;
        strcpy(cd[8].name,"Malavika");
        strcpy(cd[8].acctype,"Savings");
        strcpy(cd[8].phno,"8458963210");
        strcpy(cd[8].dob,"18/03/2003");
        cd[8].accno=4128;
        cd[8].balance=2060;
        strcpy(cd[9].name,"Edwin");
        strcpy(cd[9].acctype,"Savings");
        strcpy(cd[9].phno,"9864263650");
        strcpy(cd[9].dob,"06/04/2003");
        cd[9].accno=4129;
        cd[9].balance=25540;
        strcpy(cd[10].name,"Shreya");
        strcpy(cd[10].acctype,"Savings");
        strcpy(cd[10].phno,"9856471231");
        strcpy(cd[10].dob,"30/11/2002");
        cd[10].accno=4130;
        cd[10].balance=37540;

    fwrite(&cd,sizeof(cd),1,customerdetail);
    fclose(customerdetail);
    }


    menu:
    printf("\n________________________________________________________________________________\n\t\t\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\tMAIN MENU\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\n________________________________________________________________________________\n");
    printf("1.Create Account\n2.Cash Deposit\n3.Cash Withdrawal\n4.Fund Transfer\n5.Account Information\n6.Exit\n________________________________________________________________________________\nChoose Option: ");
    scanf("%d",&n);
    printf("________________________________________________________________________________\n");
    switch(n)
    {
    case 1:
        {
            createacc();
            break;
        }
    case 2:
        {
            cashdep();
            break;
        }
    case 3:
        {
            cashwithdrawal();
            break;

        }
    case 4:
        {
            fundtrnfr();
            break;
        }
    case 5:
        {
            accinf();
            break;
        }

    case 6:
        {
            system("cls");
            exit(0);
        }
    default:
        {
            system("cls");
            goto menu;
        }
    }
}
void createacc()
{
    int k,i,repeat;
    rept:
    system("cls");
    printf("________________________________________________________________________________\n\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1 CREATE ACCOUNT \xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\t\n________________________________________________________________________________\n");
    FILE *customerdetail;
    customerdetail=fopen("csdtl.txt","a+");
    customerdetail=fopen("csdtl.txt","r");
    for(i=l;repeat=13;i++)
    {
        printf("Enter your name       :            ");
        fflush(stdin);
        scanf("%s",&cd[i].name);
        printf("Phone Number          :            ");
        fflush(stdin);
        gets(cd[i].phno);
        printf("Account type          :            ");
        fflush(stdin);
        scanf("%s",&cd[i].acctype);
        printf("DOB                   :            ");
        fflush(stdin);
        for(k=0;k<10;k++)
        {
            if(k==2||k==5)
            {
                printf("/");
            }
            else
            {
                cd[i].dob[k]=getche();
            }
        }
        l++;
        printf("\nAccount Balance       :            ");
        fflush(stdin);
        scanf("%f",&cd[i].balance);
        if((cd[i].balance)<100)
        {

           printf("\n\nMinimum balance of 100 required!!\n\n \n\n\n\t\t\t\tTRY AGAIN in 3 secs") ;
            delay(3);
            system("cls");
            goto rept;

        }

        cd[i].accno=cd[i-1].accno+42;
        fwrite(&cd,sizeof(struct customer),1,customerdetail);
        fclose(customerdetail);
        printf("\n________________________________________________________________________________\nYour Account has been created:)\n\nYour Account number is %d",cd[i].accno);
        printf("\n________________________________________________________________________________\n\n\n\nEnter to add another customer or Esc to exit\n\n");
        repeat=getch();
        if(repeat==13)
        {
            system("cls");
            goto rept;
        }
        else if(repeat==27)
        {
            system("cls");
            mainpgm();
        }
        else
        {
            exit(0);
        }

    }

}
void cashdep()
{
    system("cls");
    printf("________________________________________________________________________________\n\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\tCASH DEPOSIT\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\t\n________________________________________________________________________________\n");
    FILE *customerdetail;
    customerdetail=fopen("csdtl.txt","a+");
    int accnum,i,accno,k;
    float bal;
    accnumber:
    printf("Enter the Account number of the customer: ");
    scanf("%d",&accnum);
    for(i=1;i<=l;i++)
    {
        if(cd[i].accno==accnum)
        {
            ca_dep:
            system("cls");
             printf("________________________________________________________________________________\n\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\tCASH DEPOSIT\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\t\n");
            printf("________________________________________________________________________________\n\t\t\t\tCUSTOMER DETAILS\n________________________________________________________________________________\nName                 :      %s\n",cd[i].name);
            printf("Account Number       :      %ld\n",cd[i].accno);
            printf("Account type         :      %s\n",cd[i].acctype);
            printf("Available Balance    :      Rs.%0.2f\n________________________________________________________________________________\n",cd[i].balance);
            printf("Enter the amount you want to add: ");
            scanf("%f",&bal);
            cd[i].balance=cd[i].balance+bal;
            printf("________________________________________________________________________________\nProcess completed successfully.\n\nAmount of Rs.%0.2f deposited to %s's account.\n",bal,cd[i].name);
            printf("\nAvailable balance: Rs.%0.2f.\n\n",cd[i].balance);
            fflush(stdin);
            printf("\n________________________________________________________________________________\nEnter ESC to exit.\n________________________________________________________________________________");
            k=getch();
            if(k==27)
            {
                system("cls");
                mainpgm();
            }
            else
            {
                system("cls");
                goto ca_dep;
            }
            break;
        }
         fwrite(&cd,sizeof(struct customer),1,customerdetail);
        fclose(customerdetail);
    }
    if(i>l)
    {
        cash_dep:
        printf("Customer not found.\n");
        fflush(stdin);
        Sleep(1000);
        system("cls");
        goto accnumber;
    }
}
void cashwithdrawal()
{
    system("cls");
    printf("________________________________________________________________________________\n\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\tCASH WITHDRAWAL\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\t\n________________________________________________________________________________\n");
    FILE *customerdetail;
    customerdetail=fopen("csdtl.txt","a+");
    int accnum,i,accno,k;
    float withdw;
    accnumber:
    printf("Enter the Account number of the customer: ");
    scanf("%d",&accnum);
    for(i=1;i<=l;i++)
    {
        if(cd[i].accno==accnum)
        {
            ca_withdrl:
            system("cls");
            printf("________________________________________________________________________________\n\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\tCASH WITHDRAWAL\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\t\n________________________________________________________________________________");
            printf("\n\t\t\t\tCUSTOMER DETAILS\n________________________________________________________________________________\nName                 :      %s\n",cd[i].name);
            printf("Account Number       :      %ld\n",cd[i].accno);
            printf("Account type         :      %s\n",cd[i].acctype);
            printf("Available Balance    :      Rs.%0.2f\n________________________________________________________________________________\n",cd[i].balance);
            printf("Enter the amount you want to withdraw: ");
            scanf("%f",&withdw);
            cd[i].balance=cd[i].balance-withdw;
            printf("________________________________________________________________________________\nProcess completed successfully.\n\nAmount of Rs.%0.2f is withdrawn from %s's account.\n",withdw,cd[i].name);
            printf("\nAvailable balance: Rs.%0.2f.\n\n",cd[i].balance);
            fflush(stdin);
            printf("\n________________________________________________________________________________\nEnter ESC to exit.\n________________________________________________________________________________");
            k=getch();
            if(k==27)
            {
                system("cls");
                mainpgm();
            }
            else
            {
                system("cls");
                goto ca_withdrl;
            }
            break;
        }
        fwrite(&cd,sizeof(struct customer),1,customerdetail);
        fclose(customerdetail);
    }
    if(i>l)
    {
        cash_withdrl:
        printf("Customer not found.\n");
        fflush(stdin);
        Sleep(1000);
        system("cls");
        goto accnumber;
    }
}
void fundtrnfr()
{
   system("cls");
    printf("________________________________________________________________________________\n\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\tFUND TRANSFER\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\t\n________________________________________________________________________________\n");
    int accnum,i,accno,k,useraccnum,h;
    FILE *customerdetail;
    customerdetail=fopen("csdtl.txt","r");
    float transfer;
    printf("Enter the Account number of the customer: ");
    scanf("%d",&accnum);
    for(i=1;i<=l;i++)
    {
        if(accnum==cd[i].accno)
        {
            ca_trnsfr:
            system("cls");
            printf("________________________________________________________________________________\n\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\tFUND TRANSFER\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\t\n________________________________________________________________________________");
            printf("\n\t\t\t\tCUSTOMER DETAILS\n________________________________________________________________________________\nName                 :      %s\n",cd[i].name);
            printf("Account Number       :      %ld\n",cd[i].accno);
            printf("Account type         :      %s\n",cd[i].acctype);
            printf("Available Balance    :      Rs.%0.2f\n________________________________________________________________________________\n",cd[i].balance);
            printf("Enter the amount you want to transfer: ");
            scanf("%f",&transfer);
            cd[i].balance=cd[i].balance-transfer;
            printf("Available Balance:%.2f",cd[i].balance);
            printf("\n________________________________________________________________________________\n\nAmount of Rs.%0.2f is transfered from %s's account.\n",transfer,cd[i].name);
            h=i;
        }
    }
        printf("\n\nEnter the account number of the user you want to transfer money to:     ");
        scanf("%d",&useraccnum);
        if(useraccnum!=accnum)
        {
            for(i=0;i<=l;i++)
            {
                if(useraccnum==cd[i].accno)
                {
                    system("cls");
                    printf("SENDER'S NAME\n________________________________________________________________________________\nName                 :      %s\n",cd[i].name);
                    cd[i].balance=cd[i].balance+transfer;
                    printf("________________________________________________________________________________\nProcess completed successfully.\n\n Amount of Rs.%0.2f deposited to %s's account.\n",transfer,cd[i].name);
                    printf("\nAvailable Balance:%.2f\n",cd[i].balance);
                    printf("\n________________________________________________________________________________\n\nAmount of Rs.%0.2f is transfered from %s's account.\n",transfer,cd[h].name);
                }
            }
        }
        else
        {
            system("cls");
             printf("\n\n\n\n\t\t\tSELF TRANFER IS NOT ALLOWED!!\n\n\t\t\tTRANSACTION FAILED!!");
        }

        fwrite(&cd,sizeof(struct customer),1,customerdetail);
        fclose(customerdetail);
         fflush(stdin);
            printf("\n________________________________________________________________________________\nEnter ESC to exit.\n________________________________________________________________________________");
            k=getch();
            if(k==27)
            {
                system("cls");
                mainpgm();
            }
            else
            {
                system("cls");
                goto ca_trnsfr;
            }
}

void accinf()

{
    system("cls");
    printf("________________________________________________________________________________\n\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\tACCOUNT INFORMATION\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\t\n________________________________________________________________________________\n");
    int accno,accnum,i,k;
    FILE *customerdetail;
    customerdetail=fopen("csdtl.txt","r");
    printf("Enter the Account number of the customer:  ");
    scanf("%d",&accnum);
    for(i=1;i<=l;i++)
    {
        if(accnum==cd[i].accno)
        {
            printf("\nName                :      %s\n",cd[i].name);
            printf("Account Number       :      %ld\n",cd[i].accno);
            printf("Account type         :      %s\n",cd[i].acctype);
            printf("DOB                  :      %s\n",cd[i].dob);
            printf("Available Balance    :      Rs.%0.2f\n",cd[i].balance);


        }
        fclose(customerdetail);
    }
    fflush(stdin);
    printf("\n________________________________________________________________________________\nEnter ESC to exit.\n________________________________________________________________________________");
    k=getch();
    if(k==27)
        {
            system("cls");
            mainpgm();
        }

}

void password()
{
    char psswd[30]={"pass"};
    system("cls");
    char ch,pass[10];
    int i=0;
    printf("\n\n\t\tENTER PASSWORD:  ");
    ch=getch();
    while(ch!=13)
    {
    ch=getch();
        if(ch!=13 && ch!=8)
            {
            putch('*');
            pass[i] = ch;
            i++;
            }
    }
    pass[i] = '\0';
    if(strcmp(pass,psswd)==0)
        {
        system("cls");
        printf("\n\n\n\n\n\t\t\t\tLOADING....");
        for (i=0; i < 1; i++)
            {
            delay(3);
            system("cls");
            printf("\n\n\n\n\t\t\t\tPASSWORD MATCHED");
            }
        }
    else
        {
        system("cls");
        printf("\n\n\n\n\n\t\t\tLOADING...");
        for(i=0;i<1;i++)
            {
            printf("\n\n\n\n\n\t\t\tPASSWORD DIDN'T MATCH!!!");
            }
        for(i=0;i<1;i++)
            {
            delay(1);
            printf("\nPress any key to try again...");
            }
        getch();
        password();
        }
}

void delay (int number_of_seconds)
{
    int milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}