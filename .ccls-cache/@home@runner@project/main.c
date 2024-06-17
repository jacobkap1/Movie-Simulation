#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define MAXLINE 15
#define MAXCHAR 100
#define MAXDIGIT 5

int main(void) {
  int scenario, moivechoice,i=0, j=4,k,c=1,r,m=1, adt, kid, tictotal, tickets[MAXDIGIT], seat[MAXLINE], n=1,decline=1, onlinecard[MAXDIGIT], security, expermonth,experyear, zip, confirm, hour, minute, day,month, screen, payment,approved, randrow, pin, reciept;
  
  float hundred,fifty, twenty,ten, five, one,coins, total, cost, tax, fee, change, cash,owe, charge;
  
  char Cinema, Online, movie[MAXLINE][MAXCHAR], soon[MAXLINE][MAXCHAR], row, monthname[MAXLINE][MAXCHAR];

srand(time(NULL));

   FILE*fp;
  if((fp=fopen("movies.txt","r"))==NULL)
  {
    printf("File Not Found");
  }
    
  else
  {
    while(!feof(fp))
      {
      fscanf(fp,"%s", movie[i]);
        i++;
      }  
    fclose(fp);
  }
  
  FILE*fps;
  if((fps=fopen("soon.txt","r"))==NULL)
  {
    printf("File Not Found");
  }
    
  else
  {
    while(!feof(fps))
      {
        
      fscanf(fps,"%s", soon[j]);
        j++;
      }  
    fclose(fps);
    
  }




  scenarios:
  printf("Which scenario would you like?\n");
  printf("Scenario 1: Purchasing ticket at Cinema\n");
  printf("Scenario 2: Reserving ticket online\n");
  printf("1 or 2?:");
  scanf("%d", &scenario);
  
   if(scenario==1 || scenario == 2)
    {
  switch (scenario) {
    
   
  case 1:
    goto Cinema;

  case 2:
    goto Online;
  }
    }
     
    else 
    {
         printf("\nInvalid! Try again.\n\n");
      goto scenarios;
    }
 
    
  

Cinema:
  system("clear");
 
  printf("%18s", "AMC Theaters\n");
  for(i=1;i<=5;i++)
    {
      printf("\n(%d) %s\n",i, movie[i]);
    }
  
  printf("\nAdult Tickets(13+): $18.07 \n");
  printf("\nChildren Ticket: $14.86\n");
  
printf("\n Welcome to AMC Theaters. What movie would you like to watch?\n");
  redo1:
  printf("Enter the movie number:");
  scanf("%d",&k);
  
 if(k<1 || k>5)
  {
   printf("\nPlease tell me an actual movie number.\n");
    goto redo1;
  }

  printf("\nHow many adults today? ");
scanf("%d", &adt);
  
  printf("\nHow many kids today? ");
scanf("%d", &kid);
tictotal=adt+kid;

      system("clear");
  
cost= 18.07*(adt)+14.86*(kid); 
  tax=cost*(0.07);
charge=cost+tax;
  
printf("\nSo, it'll be $%.2f in total. %d tickets in total. %d adult(s) and %d kid(s).\n", charge, tictotal, adt, kid);

printf("How would you like to pay?\n");
  payment_method:
  printf("\nEnter: 1 for cash; 2 for debit; 3 for credit: ");
  scanf("%d", &payment);
  switch(payment)
  {
    case 1:
      
      pay:
      printf("\nHow much money are you giving (Ex. $19.84): $");
      scanf("%f", &cash);
      

      
if(cash<charge)
{
  owe=charge-cash; //money you still need to pay
    charge=owe;
  printf("\nYou still owe $%.2f\n\n",owe);
    goto pay;
}
   else if(cash>charge)
      {
        change=charge-cash;
        printf("\nYour change is $%.2f\n",fabs(change));
        
      }

break;

    
    case 2:
      invalid:
      printf("\n\nENTER PIN: ");
    scanf("%d", &pin); // for convience only pins that work are 4 number leap years

      if (pin % 400 == 0)
      {
      goto valid;
   }
  
   else if (pin % 100 == 0)
   {
     
     goto wrong;
   }
   
   else if (pin % 4 == 0) 
   {
     goto valid;
   }
   else 
   {
     wrong:
     printf("INVALID PIN! TRY AGAIN!\n");
     goto invalid;
     
   }
      valid:
printf("\nAPPROVED\n");
    break;





    case 3:
      
     
      tryagain:
      for(int g=0;g<=10;g++)
        {
       approved=rand()%9+1;
        }
      if(approved%2!=0)
      {
        printf("\nCARD DECLINED");
          
        if(decline>=4)
        {
          printf("\nSeems your card has declined more than four times, please use a different payment method.\n");
          decline=0;
          goto payment_method;
        }
        decline++;
        goto tryagain;
        
      }
      else if(approved%2==0)
{
  printf("\nCARD APPROVED\n");
  break;
}
      
        

    
    default:
      printf("\nAnytime now.\n");
    goto payment_method;
  }



printf("\n\nHere are your tickets. I hope you enjoy the moive.\n\n");


printf("Enter any key to view Ticket.");
scanf("%d", &reciept);

  
  system("clear");
    
printf("%18s", "Ticket");
printf("\n\nMovie: %s\n", movie[k]);

  printf("\nScreen %d\n", rand()%5+1);
  
  

  printf("\nRow %c  ", rand()%6 + 65);

  printf("Seat(s):");
  

    for(n=1;n<=tictotal;n++)
      {  
        
      tickets[n]=rand()%14+1;
          printf(" %d ", tickets[n]);
      }

printf("\nEnjoy the Movie!");


  
  if (scenario == 1) {
    return 0;
  }














  




  

  
Online:
  system("clear");
  reenter:
  printf("  %4s", "AMC Theaters, these are the movies available:\n");

 
  for(i=1;i<=3;i++)
    {
      printf("\n(%d) %s\n",i, movie[i]);
    }
  
  for(j=4;j<=6;j++)
    {
      printf("\n(%d) %s (COMMING SOON)\n",j, soon[j]);
    }
k=i=j;
  
  printf("\nAdult Tickets(13+): $18.07 \n");
  printf("\nChildren Ticket: $14.86\n");
  
    redo2:
  printf("\nEnter the corresponding movie number that\n you would like to reserve tickets for:");
  scanf("%d",&k);
  if(k<1 || k>6)
  {
    printf("\nEnter a valid number!\n");
    goto redo2;
  }

  printf("\nHow many adult tickets?:");
  scanf("%d", &adt);
printf("\nHow many childern tickets?:");
scanf("%d", &kid);
  tictotal=adt+kid;
  system("clear");
  printf("%24s", "Screen\n");
  printf("\nA        O O O O O O O O O O O O\n");
  printf("\nB       O O O O O O O O O O O O O\n");
  printf("\nC      O O O O O O O O O O O O O O\n");
  printf("\nD     OO  OO  OO  OO  OO  OO  OO  OO\n");
  printf("\nE     OO  OO  OO  OO  OO  OO  OO  OO\n");
  printf("\nF     O O O O O O O O O O O O O O O O\n");
  printf("\n    (Seats work from left to right)\n ");
  printf("      Amount of seats in each row\n ");
  printf("      A:12 ; B:13 ; C:14; D-F:16 \n");

  letter:
    printf("\nEnter the row you would like:");
  row=getchar();
  scanf("%c",&row);
    
  while(n<=tictotal)
    {
      printf("\nChoose your seats:");
      scanf("%d", &seat[n]);
      n++;
    }

  
system("clear");
  
cost= 18.07*(adt)+14.86*(kid);
  fee= tictotal*2.39;
  
  
printf("\nTicket(s) Sum: $%.2f\n",cost);
  printf("\nConvenience Fee: $%.2f\n", fee);
  printf("\nTotal: $%.2f\n", cost+fee);

  
   printf("\nPlease enter card information.\n\n");

  for(c=1;c<MAXDIGIT;c++)
    { 
        entervalid:
    printf("Section %d of Card number (####):", c);
  scanf("%d",&onlinecard[c]);
      if(onlinecard[c]>9999||onlinecard[c]<1000)
      {
        printf("\nInvalid! Enter 4-digit number!\n");
  
        goto entervalid;
      }
  }
  
  date:
  printf("Experation date (mm/yy):");
scanf("%d/%d",&expermonth, &experyear);
  if((expermonth<01 || expermonth>12) || (experyear<=23))
  {
    printf("Invalid date\n");
    goto date;
  }
  fix:
  printf("CVV (###):");
  scanf("%d", &security);
  if(security>999||security<100)
  {
    printf("\nInvalid! Enter 3-digit number!\n");
    goto fix;
  }
   printf("Enter any key to view Confirmation Page.");
scanf("%d", &reciept);
  system("clear");

 printf("                  Confirmation Page\n");

  if(k>=1&&k<=3)
  {
  printf("\nMovie:   %s\n",movie[k]);
  }
  else if(k>=4 && k<=6)
  {
    printf("\nMovie: %s (COMMING SOON)\n",soon[k]);
  }
    printf("\nScreen %d\n", rand()%5+1);

 
  FILE*fpm;
  if((fpm=fopen("months.txt","r"))==NULL)
  {
    printf("File Not Found");
  }
    
  else
  {
    while(!feof(fpm))
      {
        
      fscanf(fpm,"%s", monthname[m]);
        m++;
      }
    fclose(fpm);
  }
    
    hour=rand()%12+1;
    minute=rand()%61;
  month=rand()%12+1;
  day=rand()%28+1;

  printf("\n%s: %s %d\n", "Date", monthname[month], day);
  printf("\n%s: %d:%d p.m.\n","Time", hour,minute);
  printf("\nRow %c ", toupper(row));
  for(r=1;r<=tictotal;r++)
    {
      printf(" Seat %d", seat[r]);
    }
  printf("\n");

  printf("\n%s %d\n","Card Number:**** **** **** " ,onlinecard[4]);
  
  printf("\n%s", "Enter 1 to confirm and 2 to reenter information:\n");
  scanf("%d", &confirm);
  if(confirm==2)
  {
    system("clear");
    goto reenter;
  }
  else
  {
    printf("\nThank You, can't wait to see you.");
  }
  return 0;
}