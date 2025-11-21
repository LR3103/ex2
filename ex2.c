/******************
Name: Lior Rogov
ID: 215303207
Assignment: 2
*******************/

#include <stdio.h>

int main()
{
    // MAIN MENU LOOP
    int flag = 1, task;
    do {
        printf("Welcome to our games, please choose an option:\n");
        printf("1. Ducky's Unity Game\n");
        printf("2. The Memory Game\n");
        printf("3. Professor Pat's Power Calculation\n");
        printf("4. The Duck Parade\n");
        printf("5. The Mystery of the Repeated Digits\n");
        printf("6. Good Night Ducks\n");

        scanf(" %d", &task);

        switch (task){
            case 1:
                // TASK 1: Ducky's Unity Game
                int input;
                //Check if the number is positive
                do {
                    printf("please enter a positive number: \n");
                    scanf(" %d", &input);
                }
                while (input <= 0);

                //convert the number to binary (the number is already in binary)
                //count how many bits are 1.
                const int totalBitsInTypeInt = 32;
                int counter = 0;
                for (int i = 0; i < totalBitsInTypeInt; i++){
                    //shift input for every i between 0 and 32 (non included) check if the LSB is equal to one, if it does add 1 to the counter. 
                    //if it is one it just add one, in any other case it is zero. 
                    counter += ((input >> i) & 1); 
                }
                printf("Ducky earns %d corns\n", counter);

                break;
            case 2:
                // TASK 2: The Memory Game
                //Get number of ducks
                int numberOfDucks;
                long long int actionStore = 0;
                do {
                    printf("please enter a number of Ducks: \n");
                    scanf(" %d", &numberOfDucks);
                }
                while (numberOfDucks <= 0);
                //ask user what the duck did 0 or 1, if other number ask to enter a number again
                printf("you entered %d ducks\n", numberOfDucks);
                int singleDuckAction; 
                for (int i = 0; i < numberOfDucks; i++){
                    do{
                        printf("duck %d do QUAK? 1 for yes, 0 for no\n", i + 1);
                        scanf(" %d", &singleDuckAction);
                    }
                    while ((singleDuckAction != 0) && (singleDuckAction != 1));
                    //add number to store, the first duck is in the LSB and the last duck is in the MSB
                    actionStore = actionStore | ((long long int)singleDuckAction << i);
                }
                //now iterate in the store and print what each did
                for (int i = 0; i < numberOfDucks; i++){
                    printf("duck number %d do %s \n", i + 1, ((actionStore >> i) & 1) ? "Quak" : "SH...");
                }

                break;
            case 3:
                // TASK 3: Professor Pat's Power Calculation
                int base, exponent; 
                do {
                    printf("Please enter the number \n");
                    scanf(" %d", &base);

                    printf("Please enter the exponent \n");
                    scanf(" %d", &exponent);
                }
                while (base < 0 || exponent < 0);
                
                if (base == 0)
                    printf("your power is: 0");
                
                else if (base == 1 || exponent == 0){
                    printf("your power is: 1");
                }

                else {  
                    long long int tempSum = 0;
                    long long int trueSum = base;
                    for (int i = 0; i < exponent - 1; i++){
                        for(int j = 0; j < base; j++){
                            tempSum += trueSum;
                        }
                        trueSum = tempSum;
                        tempSum = 0;
                    }

                    printf("your power is: %lld\n", trueSum);
                } 
                break;
            case 4:
                // TASK 4: The Duck Parade
                int numberOfDucksToPrint, ducksRows, maxDucksInRow = 10;
                do{
                    printf("please enter number of ducks:\n");
                    scanf(" %d", &numberOfDucksToPrint);
                }
                while (numberOfDucksToPrint <= 0);
                int quotient = numberOfDucksToPrint / maxDucksInRow;
                ducksRows = quotient + 1; // get the number of rows
                for (int i = 0; i < ducksRows; i++){
                    if (ducksRows - 1 == i){
                        //last row (or only if there is one row)
                        //script to print (x) num of ducks we will duplicate it because we don't have functions yet.
                        int ducksToPrintInRow = numberOfDucksToPrint % maxDucksInRow;
                        if (ducksToPrintInRow == 0)
                            ducksToPrintInRow = maxDucksInRow;
                        
                        for (int i = 0; i < ducksToPrintInRow; i++){
                            //print ducksToPrintInRow times the top part of the duck
                            if (ducksToPrintInRow - 1 == i)
                                printf("   _");
                            else
                                printf("   _            ");
                        }
                        printf("\n");
                        for (int i = 0; i < ducksToPrintInRow; i++){
                            //print ducksToPrintInRow times the middle part of the duck
                            if (ducksToPrintInRow - 1 == i)
                                printf("__(o)>");
                            else
                                printf("__(o)>          ");
                        }
                        printf("\n");
                        for (int i = 0; i < ducksToPrintInRow; i++){
                            //print ducksToPrintInRow times the bottom part of the duck
                            if (ducksToPrintInRow - 1 == i)
                                printf("\\___)");
                            else
                                printf("\\___)           ");
                        }
                        printf("\n");
                    }
                    else{
                        for (int i = 0; i < maxDucksInRow; i++){
                            //print maxDucksInRow times the top part of the duck
                            if (maxDucksInRow - 1 == i)
                                printf("   _");
                            else
                                printf("   _            ");
                        }
                        printf("\n");
                        for (int i = 0; i < maxDucksInRow; i++){
                            //print maxDucksInRow times the middle part of the duck
                            if (maxDucksInRow - 1 == i)
                                printf("__(o)>");
                            else
                                printf("__(o)>          ");
                        }
                        printf("\n");
                        for (int i = 0; i < maxDucksInRow; i++){
                            //print maxDucksInRow times the bottom part of the duck
                            if (maxDucksInRow - 1 == i)
                                printf("\\___)");
                            else
                                printf("\\___)           ");
                        }
                        printf("\n");
                    }
                    //all the rows that have 10 ducks
                }
                break;
            case 5:
                // TASK 5: The Mystery of the Repeated Digits
                int inputNumber;
                do {
                    printf("please enter a number\n");
                    scanf(" %d", &inputNumber);
                }
                while (inputNumber < 0);

                //After the user inserted the number we are going to count how many digits it has.
                int temp = inputNumber;
                int digitCount = 0;
                short int digitStore = 0;
                do {
                    temp = temp / 10;
                    digitCount++;
                }
                while (temp > 0);

                for (int i = digitCount - 1; i > 0; i--){
                    temp = inputNumber;
                    int tempCounter = i;
                    //iterating on the number to digit x from the left to right in order to see what numbers appears before the desired number.
                    //writing what digits appeared in digitStore.
                    do {
                        int modulo = temp % 10;
                        //add mdulo to the digit store (we leave the LSB for 0 in the store)
                        digitStore = digitStore | ((short int)1 << (modulo));
                        temp = temp / 10;
                        tempCounter--;
                    }
                    while (tempCounter > 0);
                    
                    //make sure we have single digit number in a certain position from the right.
                    temp = temp % 10;
                    //Now we have the digit, lets see if we found it in the store
                    if ((digitStore >> temp) & 1){
                        printf("digit %d appears later\n", temp);
                    }
                    //clear store for the next iteration 
                    digitStore = digitStore & 0;
                }

                break;
            case 6:
                // TASK 6: EXIT
                flag = 0;
                break;
            default:
                printf("Invaild option, please try again\n");
        }
    }
    while (flag);
    printf("Good night! See you at the pond tomorrow.\n");
    return 0;
}
