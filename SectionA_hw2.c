/*
 * Jason Pae
 * jnpbpc
 * 10/11/16
 * CS 1050 HW2
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 6    //for row length
#define COL 4    //for column length
#define MAX 25  //for strings

void displayMenu(); //displays the menu options
int loginMatch(int passcode, int adminPasscode); // log in authentication
void initialSeats (char flight[][COL], int count);//fill in seats with O and X
void printFlightMap(char flight[][COL]); //Prints current flight map
void flightmenu();
int getTotalRevenue(char fl1[][COL], char fl2[][COL], char fl3 [][COL]);//Calculates total revenue from each flight
void seatReservation(char flight[][COL]);
void printMessage(char name[], char num[]);
int start;


int costMatrix[ROW][COL]={ {500, 200, 200, 500},
                            {500, 200, 200, 500},
                            {500, 200, 200, 500},
                            {500, 200, 200, 500},
                            {500, 200, 200, 500},
                            {500, 200, 200, 500}};  //Global Array Prices
int main (void)
{
  char fl1[ROW][COL], fl2[ROW][COL], fl3[ROW][COL];

  int passcode;
  int adminPasscode = 105016;
  int option=0;
  int choice = 0;


  char flight1[]="MIA1050";
  char flight2[]="BNA1050";
  char flight3[]="LAS1050";
  

  int count = rand()%5 +1;
  srand(time(NULL));
  initialSeats(fl1, count);
  initialSeats(fl2, count);
  initialSeats(fl3, count);

printf("***********Welcome to JASON'S AIRLINE BOOKING SYSTEM*************\n\n");
while(start==0)
{
//Menu Display
displayMenu();
//Admin Passcode or Option Number 1
  printf("Choose an option: ");
  scanf("%d", &option);

      while (option<1 || option>3)
      {
        printf("Wrong option! Choose a right option again:");
        scanf("%d", &option );
      }

    


  switch(option)
  {
//Admin Log in
      case 1:
         printf("\nEnter a login passcode to log in as admin: ");
         scanf("%d", &passcode);

          while (loginMatch(passcode, adminPasscode) == 0)
      {

          printf("Invalid Passcode combination\n\n");

          printf("Enter a login passcode to log in as admin: ");
          scanf("%d", &passcode);
      }

      printf("\n Printing the Flight Map for Columbia to Miami...\n");
      printFlightMap(fl1);

      printf("\n Printing the Flight Map for Columbia to Nashville...\n");
      printFlightMap(fl2);

      printf("\n Printing the Flight Map for Columbia to Las Vegas...\n");
      printFlightMap(fl3);

      printf("\n\nThe total revenue of from all flights is $%d\n\n", getTotalRevenue(fl1, fl2, fl3));
      printf("You are logged out\n");
      break;
    



 //Seat Reservation   
      case 2:
      
      flightmenu();
      char name[20];

      printf("Choose a flight: ");
      scanf("%d", &choice);

      while ( 1>choice || 3<choice)
      {
        printf("\nInvalid choice. Choose a number from the choices\n\n");
        printf("Choose a flight: ");
        scanf("%d", &choice);
      }
      printf("Enter your first name: ");
      scanf("%s", name);
  

       switch(choice)
        {
         case 1:
         seatReservation(fl1);
         printf("Congrats %s , your flight MIA1050 is booked, enjoy your trip.\n\n", name);
         printMessage(name, flight1);
         break;


          case 2:
          
          seatReservation(fl2);
          
          printf("Congrats %s , your flight BNA1050 is booked, enjoy your trip.\n\n", name);
          printMessage(name, flight2);
          break;

          case 3:
          seatReservation(fl3);
          printf("Congrats %s , your flight LAS1050 is booked, enjoy your trip.\n\n", name);
          printMessage(name, flight3);
          break;
        
        }
        break;
      
//Exit
      case 3:
      printf("Terminating the program\n\n");
      printf("Thank you for using Jason's Airline Booking System\n");
      return start==0;
      break;

    }



  }
  return 0;
}



void displayMenu()
{
  //displayMenu
    printf("1.) Admin Log-in\n");
    printf("2.) Reserve a seat\n");
    printf("3.) Exit\n");

}


//Passcode
int loginMatch(int passcode, int adminPasscode)
{

  if (passcode == adminPasscode)
    return 1;
  else
    return 0;
}




//Initial Seats
void initialSeats(char flight[][COL], int count)
{
  int i, j;
  for(i=0;i<ROW;i++)
  {
    for(j=0;j<COL;j++)
    {
      flight[i][j]='O';
    }
  }

  for(i=0;i<=count;i++)
  {
    int row =rand()%ROW;
    int col=rand()%COL;
    while(flight[row][col]=='X')
    {
      row =rand()%ROW;
      col=rand()%COL;
    }
    flight[row][col]='X';
  }

}




void printFlightMap(char flight[][COL])
{
    int i, j;
    for(i=0;i<ROW;i++)
    {
      for(j=0;j<COL;j++)
      {
        printf("%c ", flight[i][j]);
      }
      if(j+=6)
      printf("\n");
    }

}




void flightmenu()
{
  printf("1)COU----->MIA\n\n");
  printf("2)COU----->BNA\n\n");
  printf("3)COU----->LAS\n\n");
}



 
int getTotalRevenue(char f1 [][COL], char f2[][COL], char f3 [][COL])
{
  int i, j, total;

  for(i=0;i<ROW;i++)
  {
    for(j=0;j<COL;j++)
    {
      if(f1 [i][j] == 'X')
        total+= costMatrix[i][j];
      if(f2 [i][j] == 'X')
        total+= costMatrix[i][j];
      if(f3 [i][j] == 'X')
        total+= costMatrix[i][j];
    }
  }
  return total;
}




void seatReservation(char flight[][COL])
{
  int row, col, restart;
  while(restart==0)
  {
    printFlightMap(flight);

   printf("Which seat row do you want?");
   scanf("%d", &row);

   while(row<0 || row >6)
   {
     printf("Please choose any row between 0 and 5");
     scanf("%d", &row);
   }

    printf("Which seat column do you want?");
    scanf("%d", &col);

    while(col<0 || col >4)
   {
      printf("Please choose any column between 0 and 3");
      scanf("%d", &col);
   }
  
  if (flight[row][col] == 'X')
  {
    printf("\nSorry! Someone has reserved that seat. Please Try Again.\n");
    restart=0;
  }
  else
      restart=1;
  }
  if (flight[row][col] == 'O')
  {
    flight[row][col] = 'X';
    printf("\n Your requested seat has been reserved \n");
  }
    printFlightMap(flight);
}


void printMessage(char name[], char num[])
{
    char arr[MAX];
    int i=0, j=0;
    while (name[i] != '\0' && num[i] != '\0')
    {
        arr[j]=name[i];
        j++;
        arr[j]=num[i];
        i++;
        j++;
    }
    if (name[i]=='\0')
    {
        while( num[i] != '\0')
        {
            arr[j]=num[i];
            i++;
            j++;
        }
    }
    if (num[i]=='\0')
    {
        while(name[i]!='\0')
        {
            arr[j]=name[i];
            i++;
            j++;
        }
    }
    arr[j]= '\0';
    printf("\n Your e-ticket number is: %s\n", arr);
}




















