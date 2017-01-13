/*jnpbpc
 * Jason Pae
 * Section A
 * 11/16/16
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Prototypes
int load_data(char*, char**, int *, float *, int);
void print_data(char**, int *, float *, int);
int check_account(char**, int *, char *, int, int);
int highest_amount(float *, int);
int lowest_amount(float *, int);
float average_amount(float *, int);
void sort_data(char **, int *, float *, int);
void write_data(char *, char **,int *, float *, int);

int main(int argc, char** argv)
{

    int size;
    int question=1;
    size=atoi(*(argv+2));
    int i;
    char **name;
    name=malloc(sizeof(char*)*size);
    for(i = 0; i < size; i++)
    {
        *(name+i)=malloc(sizeof(char)*20);
    }
    int *accnumbers;
    accnumbers=malloc(sizeof(int)*size);
    float *accamount;
    accamount=malloc(sizeof(float)*size);

    int wd;
    float amount;
    int inputnumber;
    int check;
    char *inputname;
    inputname=malloc(sizeof(char)*20);


    //Correct arguments
    if (argc != 4)
    {
        printf("Insufficient arguments.Check your command line arguments\n");
        return 0;
    }
    //LOAD
    int error=load_data(*(argv+1), name, accnumbers, accamount, size); 

    if (error==0)
    {
        printf("Cannot open the file\n");
        return 0;
    }

    //Prints the data from files

    printf("%-10s %-13s %s\n", "Name", "Account No.", "Balance");
    print_data(name, accnumbers, accamount, size);

    
    printf("\n\n%s has the highest amount $%.2f in the account number %d\n", *(name+(highest_amount(accamount,size))), *(accamount +(highest_amount(accamount,size))), *(accnumbers+(highest_amount(accamount,size))));
    printf("%s has the lowest amount $%.2f in the account number %d\n", *(name+(lowest_amount(accamount,size))), *(accamount +(lowest_amount(accamount,size))), *(accnumbers+(lowest_amount(accamount,size))));
    printf("The average amount is $%.2f\n",(average_amount(accamount,size)));



    //LOOP Function
    int loop=1;
    while(loop==1)
    {
        while(question==1)
        {
            //INPUT NAME

            printf("Enter a name: ");
            scanf("%s", inputname);


            //ACCOUNT NUMBER
            printf("Enter an account number:" );
            scanf("%d", &inputnumber);

            //Check ACCOUNT

            check=check_account(name, accnumbers, inputname, inputnumber, size);

            if (check == -1)
            {
                printf("\nNo bank account with that name/number combination exists\n");
                printf("Do you want to update another account? Press 1 if Yes, 0 if N0:");
                scanf("%d", &question);
                if(question==0)
                    break;
            } 
            else
                break;
        }
        
        if (question==0)
            break;
        //DEPOSIT OR WITHDRAW
        printf("Do you want to (1) withdraw or (2) deposit?");
        scanf("%d", &wd);
        while(wd < 1 || wd > 2)
        {
            printf("Error. Enter (1) withdraw or (2) deposit:");
            scanf("%d", &wd);
        }


        if(wd==1)
        {
            //Withdraw
            printf("Enter an amount: ");
            scanf("%f", &amount);

            if(*(accamount+check)-amount <0)
            {   
                printf("Not enough in the account. Enter a new amount:");
                scanf("%f", &amount);
            }
            *(accamount+check) -= amount; 
        }
        else if(wd==2)
        {
            //Deposit
            printf("Enter an amount: ");
            scanf("%f", &amount);
            *(accamount+check) += amount;

        }
        printf("Do you want to update another account? Press 1 if Yes, 0 if No:");
        scanf("%d", &loop);
        if(loop==0)
            break;
    }





    //SORT
    sort_data(name, accnumbers, accamount,size);
    printf("%-10s %-13s %s\n", "Name", "Account No.", "Balance");
    print_data(name, accnumbers, accamount, size);




    //Write
    write_data(*(argv+3),name,accnumbers,accamount,size);

    printf("\n\n%s has the highest amount $%.2f in the account number %d\n", *(name+(highest_amount(accamount,size))), *(accamount +(highest_amount(accamount,size))), *(accnumbers+(highest_amount(accamount,size))));

    printf("%s has the lowest amount $%.2f in the account number %d\n", *(name+(lowest_amount(accamount,size))), *(accamount +(lowest_amount(accamount,size))), *(accnumbers+(lowest_amount(accamount,size))));

    printf("The average amount is $%.2f\n",(average_amount(accamount,size)));

    printf("\n\nThank you for using Mizzou Banking System.\n Happy Thanksgiving Break\n");


    //FREE MALLOC
    free(name);
    free(accnumbers);
    free(accamount);
    free(inputname);
    return 0;
}








//LOAD
int load_data(char *filename, char **name,int *accnumbers, float *accamount, int size)
{
    FILE *file;

    file = fopen(filename, "r");
    if(file==NULL)
    {
        return 0;
    }

    int i;
    for(i = 0; i < size; i++)
    {
        fscanf(file, "%s %d %f\n",*(name+i), accnumbers+i, accamount+i);
    }
    fclose(file);

    return 1;
}




//PRINT
void print_data(char **name, int *accnumbers, float *accamount, int size)
{
    int i;
    for (i=0; i<size; i++)
    {
        printf("%-10s %-13d %.2f\n",*(name+i), *(accnumbers+i), *(accamount+i));
    }


}






//CHECK

int check_account(char **name, int *accnumbers, char *inputname, int inputnumber, int size)
{
    int i;

    for (i=0;i<size;i++)
    {
        if( strcmp(*(name+i),inputname)==0 && *(accnumbers+i)==inputnumber)
        {
            return i;
        }

    }
    return -1;

}



//Highest
int highest_amount(float *amount, int size)
{
    int i;
    int highest=0;
    int locate=0;
    for (i=0; i<size; i++)
    {
        if (*(amount+i)>highest)
        {
            highest=*(amount+i);
            locate=i;
        }
    }
    return locate;
}



//Lowest
int lowest_amount(float *amount, int size)
{
    int i;
    int lowest=*(amount+0);
    int locate=0;

    for(i=0; i<size;i++)
    {

        if(*(amount+i)<lowest)
        {
            lowest=*(amount+i);
            locate=i;


        }
    }
    return locate;

}

//Average
float average_amount(float *amount, int size)
{
    int i;
    float sum=0;
    float average;
    for (i=0;i<size;i++)
    {
        sum+=*(amount+i);
    }
    average=sum/size;
    return average;


}


//SORT
void sort_data(char **name, int *accnumber, float *accamount, int size)
{
    int i, j;
    char *temp;
    temp=malloc(sizeof(char)*size);
    float amount;
    int num;
    for (i=0; i<size;i++)
    {
        for (j=i+1;j<size;j++)
        {
            if(strcmp(*(name+i),*(name+j))>0)
            {
                //Sort Name
                strcpy(temp,*(name+i));
                strcpy(*(name+i),*(name+j));
                strcpy(*(name+j),temp);
                //Number
                num=*(accnumber+i);
                *(accnumber+i)=*(accnumber+j);
                *(accnumber+j)=num;
                //Balance
                amount=*(accamount+i);
                *(accamount+i)=*(accamount+j);
                *(accamount+j)=amount;
            }
        }
    }
    free(temp);

}




//Print to FILE
void write_data(char *filename, char **name, int *accnumber, float *accamounts, int size)
{
    FILE *file;
    file=fopen(filename, "w");
    int i;
    fprintf(file,"%-10s %-13s %s\n", "Name", "Account No.", "Balance");
    for(i=0;i<size;i++)
    {
        fprintf(file, "%-10s %-13d %.2f\n", *(name+i),*( accnumber+i),*(accamounts+i));

    }

    fprintf(file, "\n%s has the highest amount $%.2f in the account number %d\n",*(name+(highest_amount(accamounts,size))), *(accamounts +(highest_amount(accamounts,size))), *(accnumber+(highest_amount(accamounts,size))));
    fprintf(file, "%s has the lowest amount $%.2f in the account number %d\n", *(name+(lowest_amount(accamounts,size))), *(accamounts+(lowest_amount(accamounts,size))),*(accnumber+(lowest_amount(accamounts,size))));
    fprintf(file, "The average amount is $%.2f\n", (average_amount(accamounts,size)));

    fclose(file);
    return;
}


