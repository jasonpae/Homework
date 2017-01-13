/* jnpbpc
 * Jason Pae 
 * 9/5/16
 * Homework 1
 * Section A
 */

#include <stdio.h>
#include <math.h>


#define PI 3.14159

int main(void)
{
    int number1;
    float circle;
    float radius;
    float rectangle;
    float length;
    float width;
    float triangle;
    float base;
    float height;
    float trapezoid;
    float base2;
    float sphere;
    int bonus;


    printf( "GEOMETRY CALCULATOR\n"); //printing what the program does

    printf( "1.)Calculate the Area of a Circle\n");     //Order of telling what the user can use
    printf( "2.)Calculate the Area of a Rectangle\n");
    printf( "3.)Calculate the Area of a Triangle\n");
    printf( "4.)Calculate the Area of a Trapezoid\n");
    printf( "5.)Calculate the Area of a Sphere\n");
    printf( "6.)Exit\n");  //Telling the user to pick 6 to exit

    printf("Please enter a choice (1-6): ");  //Tells the user to enter a number and make a choice
    scanf("%d", &number1);

        while ( number1<=0 || number1>=7 )
        {
            printf("Invalid value. Enter a valid choice within the interval:");
            scanf("%d", &number1);
        } 
    
//The function of Area of a Circle



        if ( number1 == 1 )
        {
            printf("Area of a Circle\n");
            printf("Please enter the radius of the circle:");
            scanf("%f", &radius);
          
            while ( radius <= 0)  // To keep repeating until user puts in positive number
            {
                printf ("Invalid value. Enter a positive value only: ");
                scanf ("%f", &radius);
            }
    circle =  PI * pow ( radius, 2 );

    printf("\nThe area is %.3f units\n",circle);
        }
        
     


//The function of Area of a Rectangle


    if ( number1 == 2 )  
    {
        printf("Area of a Rectangle\n");
//Length
        printf("Please enter a length:");
        scanf("%f", &length);
        
            while( length <= 0 )
            {
                printf("Invalid value. Enter a positive value for length:");
                scanf("%f", &length);
            }
//Width  
        printf("Please enter a width:");
        scanf("%f", &width);
    
             while (width <= 0)
              {
               printf("Invalid value. Enter a positive value for width:");
               scanf ("%f", &width);
              }
//Rectangle
    rectangle = length *  width ;

    printf("The area is %f units\n", rectangle);
    }



  //The function of Area of a Triangle


    if ( number1 == 3) //Area of a Triangle
    {
        printf("Area of a Triangle\n");
//Base
        printf("Please enter a base:");
        scanf("%f", &base);
    
        while( base <= 0)
        {
            printf("Invalid value. Enter a positive value for base:");
            scanf("%f", &base);
        }
    }
//Height
    if ( number1 == 3)
    {
        printf("Please enter a height:");
        scanf("%f", &height);
    
        while( base <= 0)
        {
            printf("Invalid value. Enter a positive value for base:");
            scanf("%f", &height);
        }
    }
//Triangle
    if ( number1==3)
    { 
         triangle = (base * height) /2 ;

        printf("The area is %f units\n", triangle);
    }



//The area of a Trapezoid


    if ( number1 == 4)
    {
        printf("Area of a Trapezoid\n");
//Base 1        
        printf("Please enter a Base 1:");
        scanf("%f", &base);


        while( base<= 0)
        {
            printf("Invalid value. Enter a positive value for Base 1:");
            scanf("%f", &base);
        }
//Base 2
        printf("Please enter Base 2:");
        scanf("%f", &base2);

        while ( base2 <= 0)
        {
            printf("Invalid value. Enter a positive value for Base 2:");
            scanf("%f", &base2);
        }
//Height
        printf("Please enter a height:");
        scanf("%f", &height);

        while( height <= 0)
        {
            printf("Invalid value. Enter a positive value for Height:");
            scanf("%f", &height);
        }
    
//Trapezoid
    trapezoid = ((base + base2)/2)*height ;

    printf("The area is %f units\n", trapezoid);
    }



//The area of a Sphere


    if (number1 == 5)
    {
        printf("Area of a Sphere\n");
//Radius
        printf("Please enter a Radius:");
        scanf("%f", &radius);

//Radius cannot be negative
        while ( radius <= 0 )
        {
            printf("Invalid value. Enter a positive value for Radius:");
            scanf("%f", &radius);
        }

//Sphere

    sphere = 4*PI* pow(radius,2);
    printf("The area is %f units \n", sphere);

    }

//Exit
    if (number1 == 6 )
    {
        return 0;
    }




    printf("Do you want to run Calulator again? If yes hit 1, if no hit 0:");
    scanf("%d", &bonus);
    if ( bonus == 1 )
    {
        return main();
    }
    else if (bonus == 0)
        return 0;
    



   return 0;
}




    
