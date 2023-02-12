/*````````````````````````````````````````````````````````````````````````````````````````````
Program Name: Bi-weekly Payroll
Date Created: May 30,2021
This program calculates the salary of workers from the data given by the user
which are the following:worker's ID and name, the date of entry,the vehicle serviced
```````````````````````````````````````````````````````````````````````````````````````````````
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

const int payday=14;

//structure for the date of entry
struct date{
    int day;
    int month;
    int yr;
};

//structure for the worker details
struct worker{
    char fname[20];
    char lname[30];
    int pay;
    int ID;
    int entry;
    struct date time;
}W;

int entry=0;
//function prototypes
void EnterWorker();

int VehicleMenu();

void EditWorker();

void DeleteWorker();

void ViewWorker();

void ViewAllWorkers();/**/

int StartMenu();


int main (void){
    int choice;

    system("color 09"); //Changes background and foreground color of the program

    while ((choice= StartMenu())!=0){
        switch (choice){
            case 1:
                EnterWorker(); //Allows user to enter a record
            break;

            case 2:
                EditWorker(); //Allows user to edit a record
            break;

            case 3:
                DeleteWorker(); //Allows user to delete a record
            break;

            case 4:
                ViewWorker(); //Allows the user to veiw the record of a single worker
            break;

            case 5:
                ViewAllWorkers(); //Allows user to veiw all records entered
            break;

            default:
                printf("\n\n\t\tI N V A L I D  R E -E N T E R  C H O I C E\n\n");//if the choice entered is not equal to the option above, error message displayed
                system("pause");
                printf("\n\nRETURNING TO MENU...");
                sleep(1);
                system ("cls");
            break;
        }

    }
    printf("\n\t\tALIGNTEK PAYROLL CLOSED\n\n PRESS ANY KEY TO EXIT PROGRAM ");

return 0;
}


int StartMenu() {
    int choice;

    system("color 09");
    printf("\t\t~W E L C O M E  T O  A L I G N T E K  P A Y R O L L~\n\n");
    printf("S E L E C T  A  C H O I C E  T O  P R O C E E D\n");

    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("0 --> \t EXIT PROGRAM\n\n");
    printf("1 --> \t Enter Worker Details\n\n");
    printf("2 --> \t Edit Worker Details\n\n");
    printf("3 --> \t Delete Worker Details\n\n");
    printf("4 --> \t View Worker\n\n");
    printf("5 --> \t View all Workers\n");
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n ");

    printf("\nSelct any choice by entering a number from the options above\n");
    scanf("%d",&choice);
    system ("cls");

    return choice;

}

void EnterWorker(){
    char response;
    int size;
    time_t dt;
    time(&dt);
    system("color 06");

    FILE * wfp;

    if ((wfp=fopen("WorkerPayroll.txt","a"))==NULL) { //opens worker file and checks if it exits
        printf ("FAILED TO OPEN FILE\n");  //error message if file can't be opened
    }
    else {

        do {
            printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
            printf("\t\t\tENTER WORKER DETAILS\n");
            printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");

            printf("Enter Worker's first name\n");
            scanf("%s", W.fname);

            printf("\nEnter Worker's last name\n");
            scanf("%s", W.lname);

            printf("\nEnter Worker's ID\n ");
            scanf("%d", &W.ID);

            printf("\t\t\t*Today's Date and Time*: %s",ctime(&dt));

            printf("\nEnter the date of entry\n");
            printf("day: ");
            scanf("%d", &W.time.day);
            printf("month: ");
            scanf("%d", &W.time.month);
            printf("year: ");
            scanf("%d", &W.time.yr);

            size=VehicleMenu();
            do {
                switch (size){ //worker is payed based on the size of the vehicle
                    case 1:
                        W.pay=125;
                    break;

                    case 2:
                        W.pay=125;
                    break;

                    case 3:
                        W.pay=150;
                    break;

                    case 4:
                        W.pay=175;
                    break;

                    case 5:
                        W.pay=175;
                    break;

                    case 6:
                        W.pay=1000;
                    break;

                    case 7:
                        W.pay=250;
                    break;

                    case 8:
                        W.pay=300;
                    break;

                    case 9:
                        W.pay=1000;
                    break;

                    default:
                        printf("I N V A L I D  R E -E N T E R  C H O I C E\n");
                        scanf("%d",&size);
                        break;

                }

        }while ((size>9)||(size==0));

            sleep(1);
            entry++;

            W.entry=entry;

            fwrite (&W, sizeof(struct worker),1,wfp); // one worker at a time is written to the file
            printf("\n\t\tRECORD ADDED!\n");
            system("pause");
            system("cls");
            fflush(stdin);
            printf("\nDo you wish to enter another record? Y for yes, N for no\n");
            scanf("%c",&response);
            system("cls");

        } while ((response == 'Y')||(response=='y')); //As long as response is equal to yes, this function will keep accepting records before returning to menu
        printf("Returning to Menu...");
        sleep(1);
        system("cls");
        fclose (wfp); //closes file
    }

}

int VehicleMenu() {
    int size;

    printf("\n\nLoading Vehicle Menu...\n");
    sleep(1);

            system ("cls");
            printf("Enter Size of Vehicle Worked On By Selecting a Number From The List Below\n\n");
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
            printf("\t1 --> \t CAR\n\n");
            printf("\t2 --> \t STREAM\n\n");
            printf("\t3 --> \t SMALL SUV\n\n");
            printf("\t4 --> \t LARGE SUV\n\n");
            printf("\t5 --> \t SMALL TRUCK\n\n");
            printf("\t6 --> \t LARGE TRUCK\n\n");
            printf("\t7 --> \t SMALL BUS\n\n");
            printf("\t8 --> \t LARGE BUS\n\n");
            printf("\t9 --> \t TRACTOR\n\n");
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
            printf("choice: ");
            scanf("%d",&size);

return size;
}

void EditWorker() {
    system("color 05");

    int ID;
    int response, size;
    int Enum;
    int found=0;

    FILE * wfp;
    FILE *cfp;

    printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
    printf("\t\t\tEDIT WORKER DETAILS\n");
    printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");

    cfp=fopen("copy.txt","a");

    if ((wfp=fopen("WorkerPayroll.txt","r+"))==NULL) {
        printf ("FAILED TO OPEN FILE\n");
        printf("\n\t\tRETURNING TO MENU.....");
        sleep(1);
        system("cls");

    } else  {
        printf("Enter The ID of The Worker You Wish to Edit\n");
        scanf("%d",&ID);

        printf("Enter The Entry Number of The Worker You Wish to Edit\n");
        scanf("%d",&Enum);

        while (fread(&W,sizeof(struct worker),1,wfp)){ //Reads the worker's ID from WorkerPayroll.txt
            if ((W.ID==ID)&&(Enum==W.entry)){
                found=1;

            printf("\nWhat Do You Wish To Edit?\n\tChoose From The List Below:\n\n");//user chooses which record they wish to edit
            printf("\t1---->\tWorker's Name\n\n");
            printf("\t2---->\tSize of Vehicle Worked On\n");

            printf("\nchoice: ");
            scanf("%d",&response);
            printf("******************************************************************\n");

            if (response==1){
                printf("\nEnter Worker's First Name\n");
                scanf("%s", W.fname); //overwrites what was previously entered

                printf("\nEnter Worker's Last Name\n");
                scanf("%s", W.lname);
            }
            else if(response==2){

                size=VehicleMenu();
                do {
                    switch (size){ //worker is payed based on the size of the vehicle
                        case 1:
                            W.pay=125;
                        break;

                        case 2:
                            W.pay=125;
                        break;

                        case 3:
                            W.pay=150;
                        break;

                        case 4:
                            W.pay=175;
                        break;

                        case 5:
                            W.pay=175;
                        break;

                        case 6:
                            W.pay=1000;
                        break;

                        case 7:
                            W.pay=250;
                        break;

                        case 8:
                            W.pay=300;
                        break;

                        case 9:
                            W.pay=1000;
                        break;

                        default:
                            printf("I N V A L I D  R E -E N T E R  C H O I C E\n");
                            scanf("%d",&size);
                        break;
                    }
                }while ((size>9)||(size==0));
            }
            printf("PROCESSING....\n");
            sleep(1);
            printf("\n\tRECORD EDITED!\n");
            sleep(1);
            }
        fwrite (&W, sizeof(struct worker),1,cfp);
        }
        while (fread(&W,sizeof(struct worker),1,wfp)){
            if ((W.ID!=ID)||(Enum!=W.entry)){//copies all records except the one the user wishes to delete to another file
                fwrite (&W, sizeof(struct worker),1,cfp);
            }
        }

        if(found==0){
            printf("Record not found");
            getch();
        }
    }
    fclose (wfp);
    remove ("WorkerPayroll.txt");
    fclose(cfp);
    rename("copy.txt","WorkerPayroll.txt");
    system ("cls");
}


 void DeleteWorker(){
    system("color 04");

    int ID;
    char response;
    int Enum;
    int found=0;

    FILE*wfp;
    FILE*cfp;
    printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
    printf("\t\t\tDELETE A WORKER'S RECORD\n");
    printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");

    cfp= fopen("copy.txt","w+");

    if ((wfp=fopen("WorkerPayroll.txt","r+"))==NULL) {
        printf ("FAILED TO OPEN FILE\n");
        printf("\n\t\tRETURNING TO MENU.....");
        sleep(1);
        system("cls");
    }
    else  {
        printf("Enter the ID of the worker's record you want to delete\n");
        scanf("%d",&ID);

        printf("Enter The Entry Number of The Worker You Wish to delete\n");
        scanf("%d",&Enum);

        while (!feof(wfp)){
            fread(&W,sizeof(struct worker),1,wfp);

            if ((W.ID!=ID)||(Enum!=W.entry)){//copies all records except the one the user wishes to delete to another file
                found=1;
                fwrite (&W, sizeof(struct worker),1,cfp);
                sleep(1);
                }
        }
            if(found==0){
            printf("Record Not Found");
            sleep(1);
            system("cls");
            }

        fclose (wfp);
        fclose(cfp);
        remove ("WorkerPayroll.txt");//file is deleted
        rename("copy.txt","WorkerPayroll.txt");
        printf("RECORD DELETED");
        sleep(1);
        system("cls");
    }
}

void ViewWorker(){
    system("color 02");

    int ID;
    float total;

    FILE *wfp;
    total=0;

    printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
    printf("\t\t\tVIEW A WORKER \n");
    printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");

    if ((wfp=fopen("WorkerPayroll.txt","r"))==NULL) {
        printf ("FAILED TO OPEN FILE\n");
        printf("\n\t\tRETURNING TO MENU.....");
        sleep(1);
        system("cls");
    }
     else{
        printf("Enter the ID of the worker you would like to view\n");//Views one worker's record
        scanf("%d",&ID);

        while (fread(&W,sizeof(struct worker),1,wfp)){
            if (W.ID==ID){
                total=total+W.pay;
                printf(":::::::::::::::::::::::::::::::::::\n");
                printf("\n\tID: %d\n",W.ID);
                printf("\tEntry: %d\n",W.entry);
                printf("\tDate: %d / %d / %d\n", W.time.day,W.time.month,W.time.yr);
                printf("\tWorker's Name: %s %s\n",W.fname,W.lname);
                printf("\tWorker's Pay: %.2f\n\n",total);
                printf(":::::::::::::::::::::::::::::::::::\n\n");
                system ("pause");

                if (W.time.day% payday==0){//if 2 weeks has passed this shows the final pay for the worker
                    printf("***************************\n");
                    printf("\n\tID: %d\n",W.ID);
                    printf("\tEntry: %d\n",W.entry);
                    printf("\tDate: %d / %d / %d\n", W.time.day,W.time.month,W.time.yr);
                    printf("\tWorker's Name: %s %s\n",W.fname,W.lname);
                    printf("\tFINAL PAY: %.2f\n\n",total);
                    printf("***************************\n");
                    system("pause");
                }
            }
        }
        if (W.ID!=ID){
                printf("Record Not Found\n");
                sleep(1);
                printf("\n\tReturning To Menu...\n");
                sleep(1);
                system("cls");
        }
    system("cls");
    fclose (wfp);
    }
}


void ViewAllWorkers(){
    system("color 79");
    FILE *wfp;

    float total;
    total=0;

    printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
    printf("\t\t\tVIEW ALL WORKERS \n");
    printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");

    if ((wfp=fopen("WorkerPayroll.txt","r"))==NULL) {
        printf ("FAILED TO OPEN FILE\n");
        printf("\n\t\tRETURNING TO MENU.....");
        sleep(1);
        system("cls");
    }
    else{

        while(fread(&W,sizeof(struct worker),1,wfp)){
            total=total+W.pay;
            printf("----------------------------------\n");
            printf("\tID: %d\n",W.ID);
            printf("\tEntry: %d\n",W.entry);
            printf("\tDate: %d / %d / %d\n", W.time.day,W.time.month,W.time.yr);
            printf("\tWorker's Name: %s %s\n",W.fname,W.lname);
            printf("\tWorker's Pay: %.2f\n",total);
            printf("----------------------------------\n");
            printf("\n");
            printf("Press any key to see the next worker\n\n");
            getch();

            if (W.time.day% payday==0){//if 2 weeks has passed this shows the final pay for the worker
                printf("*********************************\n");
                printf("\n\tID: %d\n",W.ID);
                printf("\tEntry: %d\n",W.entry);
                printf("\tDate: %d / %d / %d\n", W.time.day,W.time.month,W.time.yr);
                printf("\tWorker's Name: %s %s\n",W.fname,W.lname);
                printf("\tFINAL PAY: %.2f\n\n",total);
                printf("*********************************\n");
                system("pause");
            }
        }
        printf("\t\tEND OF FILE, NO MORE DOCUMENTED WORKERS\n");//No more records found
        system("pause");
        system ("cls");
        fclose (wfp);
    }
}

