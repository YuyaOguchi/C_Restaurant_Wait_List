//  Yuya Oguchi
//  COEN11L     Lab2
//  10/03/2014
//  restaurantwaitlist
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main()
{
    int flag = 0; //To decide when to quit the application
    int command;//response on what user wants to do

    int i;
    int x;
    int temp2;
    int temp;
    char *ntemp2 = NULL;
    char *ntemp = NULL;
    int j = 0;
    int k;
    int counter; //size of array
    char tempname[50];//name to add to list
    char tempname2[50];
    char tempname3[50];
    int tempnumber;//#to add to list
    int tempnumber2;
    int tempnumber3;
    int seatsize;//seatsize available
    int seatfound = 0;//0 unless seat found 1 seatnot found 2

    char *name[10]= { "Nick","Matt","Sean","Fredrick","Tasmine","Chisei","Alex","Chris"};
    int number[10] = {2,4,1,6,3,4,2,5};

    printf("Welcome to Yuya's Restaurant what would you like to do?\n\n");
    printf("Type 1 to add waitlist\n");
    printf("Type 2 to eliminate an entry that fits the table\n");
    printf("Type 3 to show all Waitlist\n");
    printf("Type 4 to quit\n");
    printf("----------------------------\n\n\n");
    counter = 8;//take number of array in the group

    while (flag == 0) {


        scanf("%d", &command); // read in the user input

        if (command == 1)//add one entry
        {

            if (counter < 10){

                if (counter == 8){
                    printf("Please specify your name\n");
                    scanf("%s",tempname); //read in new entry

                    printf("\nPlease specify your group size\n");
                    scanf("%d", &tempnumber); //read in new entry

                    counter += 1;
                    name[counter-1] = tempname;//add in the actual name in array
                    number[counter-1] = tempnumber;//add in the actual numnber in array
                }
                else if (counter == 9){
                    printf("Please specify your name\n");
                    scanf("%s",tempname2); //read in new entry

                    printf("\nPlease specify your group size\n");
                    scanf("%d", &tempnumber2); //read in new entry

                    counter += 1;
                    name[counter-1] = tempname2;//add in the actual name in array
                    number[counter-1] = tempnumber2;//add in the actual numnber in array
                }
                else if (counter == 7){
                    printf("Please specify your name\n");
                    scanf("%s",tempname3); //read in new entry

                    printf("\nPlease specify your group size\n");
                    scanf("%d", &tempnumber3); //read in new entry

                    counter += 1;
                    name[counter-1] = tempname3;//add in the actual name in array
                    number[counter-1] = tempnumber3;//add in the actual numnber in array
                }


                for (x = 0; x < counter - 1; x ++)
                {
                    if (name[counter - 1] == name[x])//check for duplicate name and blocl if there is one
                    {
                        counter -= 1;
                        printf("Duplicate name, please retry!");
                    }
                }

            }
            else if (counter >= 10)
            {
                printf("Que for waitlist is full."); // if the que is up to 10, do not add to list
            }

            printf("\n\nWhat would you like to do?\n");
        }




        else if (command == 2)//delete one of the list
        {
            printf("What is the open seat size?\n");
            scanf("%d", &seatsize);

            for (i = 0; i < counter; i ++)//check all list
            {

                if (seatfound == 0){//if seat is still not found


                    if (number[i] <= seatsize)
                    {
                        /*For Number*/
                        for(k = i;k < counter - 1; k++){
                        temp2 = number[counter - 1];//keep what is going to be thrown out
                        temp = number[k];//temp keep next number
                        number[k] = number[k+1];//swap the order with next one
                        number[k + 1] = temp;
                        }
                        number[i] = temp2;

                        /*For Name*/
                        for(k = i;k < counter - 1; k++){
                            ntemp2 = name[0];//keep what is going to be thrown out
                            ntemp = name[k];//temp keep next number
                            name[k] = name[k+1];//swap the order with next one
                            name[k + 1] = ntemp;
                        }

                        name[0] = ntemp2;
                        counter -= 1;
                        seatfound = 1;
                        printf("Seat found!");
                    }
                }
            }

            if (seatfound == 0){
                printf("No waitlist matches table size");
            }
            seatfound = 0;
            printf("\n\nWhat would you like to do?\n");
        }





        else if (command == 3)//show all array
        {
            printf("Current wait list:\n");
            while (j < counter) {
                printf("Name: %s\t # of people: %d",name[j], number[j]);
                printf("\n");
                j+= 1;
            }
            j = 0;

        printf("\n\nWhat would you like to do?\n");
        }

        else if (command == 4){ //quit
        flag = 1;
        }

    }
    return 0;

}
