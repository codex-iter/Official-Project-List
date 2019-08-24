#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int arr[4][4];//4X4 board
int checkblankblock();//checks whether the space is empty or filled
void cursor(char);//cursor control
void display();// displays the result after the move and the score
int score1=0;//displays the initial score
int score2=0;//displays the final score after each round
int flag2=1;//condition to check whether the game has been started or not ie if flag==1 game not started and if flag==0 game has been started.
void fillthespace_countscore();//fills the blank space with a random of 2 or 4 and increments the score
int CheckForZeroBeforeMove();//checking before pressing any cursor key
char wannacontinue;

//main function starts**************************************************************************************************************************
int main(void)
{
    int i;
    int j;
    for(i=0;i<=3;i++)//row
    {
        for(j=0;j<=3;j++)//column
        {
            arr[i][j]=0;//initializing all the blanks as "ZERO"
        }
    }

 //char choice;//Selecting the cursor movement...'w','s','a','d'.


 while(checkblankblock())//checking whether the condition is true or false
 {
  printf("\n=====================================================2048 Game==========================================================");
  printf("\t\t\t\t\t\t\t\t\t\t\t\t\t Sudeep Swain");
  printf("\n\t\t\t\t\t\tSlno  Movements  Keys");
  printf("\n\t\t\t\t\t\t 1.    Upward:    W");
  printf("\n\t\t\t\t\t\t 2.    Downward:  S");
  printf("\n\t\t\t\t\t\t 3.    Left:      A");
  printf("\n\t\t\t\t\t\t 4.    Right:     D");
  fillthespace_countscore();//accessing the fillthespace_countscore function,fills the blank space with a random of 2 or 4 and increments the score
  display();//accessing the display function, displays the result after the move and the score
  printf("\n\t\t\t\t\t\t\t\t\t\t\tPress the key for a move:");

  char choice;
  choice=getche();

  //scanf("%c",&choice);//inputting the choice
  fflush(stdin);//clear the buffer
  if(choice=='d'||choice=='D'||choice=='a'||choice=='A'||choice=='w'||choice=='W'||choice=='s'||choice=='S')
  {
    cursor(choice);//accessing the cursor function with tallying the input choice
    system("cls");
  }

  else
   {
        printf("\n\t\t\t\t\t\t***INVALID MOVE!!!***");
        printf("\n\n\t\t\t\t\t     \"Sorry! No moves anymore.\"");
        printf("\n\n\t\t\t\t\t     \"Need to Restart the Game.\"\n");
        printf("\n\n\t\t\t\t\t\t                                        Final score:%d\n\n",score2);//when the condition goes false, it displays the final score
        return;
   }

 }
 printf("\n\n\t\t\t\t\t\tSorry! No moves anymore. ");
 printf("\n\n\t\t\t\t\t\t\t\t\t\tFinal score:%d",score2);//when the condition goes false, it displays the final score
 getch();

}
//main function ends********************************************************************************************************************************

int checkblankblock()//checking whether the space is blank or not--------------------------------------------------
{
    int i;
    int j;
    int flag=1;
    for(i=0;i<=3;i++)
    {
        for(j=0;j<=3;j++)
        {
            if(arr[i][j]==0)//checks whether the space contains some value or not.
            {
                flag=0;
            }
        }
    }
     if(flag==0)
     {
        return 1;//returns 1 for true, 0 for false...goes straightly to access the while loop in the main function if the condition is false.
     }
     else
     {
         return 0;
     }

}


void fillthespace_countscore()
{
     int i;
     int j;
     int temp;

     do
     {
        temp=rand()%5;//stores number ranging from to 0 to 4;a reminder cann't ever be more than divisor.
     }
     while(temp==0||temp==1||temp==3);//as we need 2 or 4;so if the value of temp is other than 2 or 4...the while loop will continue till we get 2 o 4.

         if(flag2==1)//for the time when the program is not started
         {
            score1=0;
            flag2=0;
         }

         else//after the program is started
         {
             score2=10*temp+score2;//counting the score to be displayed
         }

    do
     {
          i=rand()%4;//for the random row
          j=rand()%4;//for the random column

     }
     while(arr[i][j]!=0);//checks whether the space is empty or not

     arr[i][j]=temp;//stores the value of 2 or 4 in the region

}

void cursor(char choise)
{
     int i;
     int j;
     int k;
     int temp;
     int x;
     int y;

     if(choise=='d'|| choise=='D')//row increases and column pointer moves from right to left in decreasing order
     {
          for(i=0;i<=3;i++)
          {
            temp=arr[i][3];
           for(j=2;j>=0;j--)//checking and addition of same number loop
            {
                if(arr[i][j]==temp)
                {
                   arr[i][j+1]=2*temp;
                   arr[i][j]=0;
                }

             temp=arr[i][j];

           }
           for(j=2;j>=0;j--)
            {
                k=j;
                while(CheckForZeroBeforeMove(i,k+1)&&(k+1)<=3)//shifting the numbers if the space is blank loop
                {
                 arr[i][k+1]=arr[i][k];
                 arr[i][k]=0;
                 k++;
                }
            }
        }

     }



     else if(choise=='a' || choise=='A')//row increases and column pointer moves from left to right in decreasing order
     {
          for(i=0;i<=3;i++)
          {
               temp=arr[i][0];
               for(j=1;j<=3;j++)
               {
                    if(arr[i][j]==temp)
                    {
                     arr[i][j-1]=2*temp;
                     arr[i][j]=0;

                    }
                    temp=arr[i][j];

               }
               for(j=1;j<=3;j++)
               {
                    k=j;
                    while(CheckForZeroBeforeMove(i,k-1)&&(k-1)>=0)
                    {
                         arr[i][k-1]=arr[i][k];
                         arr[i][k]=0;
                         k--;
                    }
                }
          }
     }



     else if(choise=='w' || choise=='W')
     {
          for(j=0;j<=3;j++)
          {
               temp=arr[0][j];
               for(i=1;i<=3;i++)
               {
                    if(arr[i][j]==temp)
                    {
                     arr[i-1][j]=2*temp;
                     arr[i][j]=0;

                    }
                   temp=arr[i][j];
               }
               for(i=1;i<=3;i++)
               {
                    k=i;
                    while(CheckForZeroBeforeMove(k-1,j)&&(k-1)>=0)
                    {
                     arr[k-1][j]=arr[k][j];
                     arr[k][j]=0;
                     k--;
                    }
               }

          }
     }



     else if(choise=='s' || choise=='S')
     {
        for(j=0;j<=3;j++)
          {
               temp=arr[3][j];
               for(i=2;i>=0;i--)
               {
                    if(arr[i][j]==temp)
                    {
                     arr[i+1][j]=2*temp;
                     arr[i][j]=0;

                    }

                     temp=arr[i][j];

               }
               for(i=2;i>=0;i--)
               {
                    k=i;
                    while(CheckForZeroBeforeMove(k+1,j)&&(k+1)<=3)
                    {
                     arr[k+1][j]=arr[k][j];
                     arr[k][j]=0;
                     k++;
                    }
               }

          }

     }
        if(flag2==0 && arr[i][j]==2048)//If the slab already have a 2048, it would ask the user whether to continue or not.
         {
             printf("\n\n\t\t\t\tYou have got a 2048 slab.Do you still want to continue");
             printf("\n\t\t\t\t\tPress 'y' to continue or 'n' to quit.");
             fflush(stdin);
             scanf("%c",&wannacontinue);
         }

         if(wannacontinue=='y' || wannacontinue=='Y')//On pressing y the program will continue executing.
         {
             main();
         }

         else if(wannacontinue=='n' || wannacontinue=='N')//On pressing n the program will terminate.
         {
             printf("\n\t\t\t\t\t\t\t\t\t\tFinal Score=%d",score2);
             exit(0);
         }

}

int CheckForZeroBeforeMove(int q,int w)//re-checking whether the the space is blank or not;before evaluating
{
     if(arr[q][w]==0)
      {
        return 1;
      }
     else
      {
         return 0;
      }
}



void display()
{
  int i;
  int j;
  int k=0;
  printf("\n\t\t\t\t\t\t\t\t\t\t\tScore=%d",score2);
  printf("\n\n");
  printf("\t\t\t\t\t\t ----------------------------------");
  for(i=0;i<=3;i++)
   {
      printf("\n");
      printf("\t\t\t\t\t\t | ");

      for(j=0;j<=3;j++)
      {
           if(arr[i][j]==0)
           {
             printf("\t  |");
           }

           else
           {
               printf("%d\t |",arr[i][j]);
           }

           printf(" ");

      }

      if(i<=3)
      {
          printf("\n");
          printf("\t\t\t\t\t\t ----------------------------------");
      }

   }

}
