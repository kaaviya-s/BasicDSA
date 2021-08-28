#include<stdio.h>
#include<dos.h>
struct employee
{
    int NO;
    char NAME[10];
    int DESIGN_CODE;
    int DAYS_WORKED;
}EMP[12]={
         {1,"GANESH",1,25},
         {2,"MAHESH",1,30},
         {3,"SURESH",2,28},
         {4,"KALPESH",2,26},
         {5,"RAHUL",2,24},
         {6,"SUBBU",2,25},
         {7,"RAKESH",2,23},
         {8,"ATUL",2,22},
         {9,"DHARMESH",3,26},
         {10,"AJAY",3,26},
         {11,"ABDUL",3,27},
         {12,"RASHMI",4,29}
     };
void main()
{
int EMPNO;
    void gen_payslip(int);
    clrscr();

    printf("ENTER THE EMPLOYEE NO TO GENERATE PAYSLIP : ");
    scanf("%d",&EMPNO);
if(EMPNO>0 && EMPNO<13)
        gen_payslip(EMPNO);
    else
        printf("\nYOU HAVE ENTERED WRONG EMP NO. !!");
    getch();
}
void gen_payslip(int EMPNO)
{
 struct date D;
 char DESG[10];
 float NETPAY,BASIC,PF,PAYRATE,PTAX=200;
 getdate(&D);
printf("\n\n\t\t\tANNA UNIVERSITY BIT CAMPUS TIRUCHIRAPALLI");
printf("\n\t\t\t\tSALARY MONTH %d %d\n",D.da_mon,D.da_year);
printf("\n\n\tEMP.NO.: %d\t\tEMP.NAME: %s",EMPNO,EMP[EMPNO-1].NAME);
switch(EMP[EMPNO-1].DESIGN_CODE)
{
   case 1: PAYRATE=400;
       printf("\tDESIGNATION: PROFESSOR");
       break;
case 2: PAYRATE=350;
       printf("\tDESIGNATION: ASSOCIATE PROFESSOR");
       break;
case 3: PAYRATE=300;
       printf("\tDESIGNATION: ASSISTANT PROFESSOR");
       break;
case 4: PAYRATE=250;
       printf("\tDESIGNATION: LECTURE");
       break;
}
BASIC=PAYRATE*EMP[EMPNO-1].DAYS_WORKED;
 PF=BASIC/10;
 printf("\n\n\tDAYS WORKED: %d",EMP[EMPNO-1].DAYS_WORKED);
 printf("\t\tPAY RATE: %.0f\t\tGEN.DATE:%d/%d/%d ",PAYRATE,D.da_day,D.da_mon,D.da_year);
 printf("\n\t________________________");
 printf("\n\n\tEARNINGS\tAMOUNT(RS.)\t\tDEDUCTIONS\tAMOUNT(RS.)");
 printf("\n\t________________________");
 printf("\n\n\tBASIC PAY\t%.0f\t\t\tP.F.\t\t%.0f",BASIC,PF);
 printf("\n\n\t\t\t\t\t\tPROF.TAX\t%.0f",PTAX);
 printf("\n\n\t________________________");
 printf("\n\n\tGROSS EARN.\t%.0f\t\t\tTOTAL DEDUCT.\t%.0f",BASIC,PF+PTAX);
 NETPAY=BASIC-(PF+PTAX);
 printf("\n\t\t\t\t\t\tNET PAY\t\t%.0f",NETPAY);
 printf("\n\t________________________");

}