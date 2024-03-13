//change.c level 2
#include <stdio.h>


int bills(int num) {
    int total;
    int remain;
    
    int bill100 = num / 100;
        remain = num % 100;
    
    int bill20 = remain / 20;
        remain %= 20;
    
    int bill10 = remain / 10;
        remain %= 10;
    
    int bill5 = remain / 5;
        remain %= 5;
    
    int bill1 = remain / 1;
        remain %= 1;
    

    total = bill100 + bill20 + bill10 + bill5 + bill1;
    return total;
}

int getAmount() {
    int result;

    for (;;) {
        printf("Enter a dollar amount: ");
        scanf("%d", &result);

    if (result <= 0) {
        printf("Please enter a psotive number.\n");
    } 
    else {
        break;
    }
    }

    return result;
}

int main() {
    int val = bills(getAmount());
    printf("You get %d bills back\n", val);
}



// sigmoid.c 
#include <stdio.h>
#include <math.h>

// using the sigmoid formula for the second column
float sigmoid (float x) {
    float sig;
    sig = (1/(1+exp(-x)));
    return sig;
}

// using for loop to starts at -5 and go to 5, going up by 1.
int main() {
    float x;
    for (x = -5.0; x <= 5.0; x+=1.0)

    // printing the results
    printf("%.3f %.3f\n", x, sigmoid(x));
}



// collatz.c warmup 2.1
#include <stdio.h>


// The variable for the number that is inputted
long int value;

// function to ask and get the number. Also checks for if a negative number is enetered. 
long int getStart() {

    for(;;) {
        printf("Enter the starting number: ");
        scanf("%ld", &value);
    
    if (value <= 0) {
        printf("The number should be a posotive integer.\n");
    }
    else {
        break;
    }
    }
    return value;
    
}

// second function. Collatz formula. 
long int nextCollatz(value) {
        if (value%2 == 0) {
            value = value / 2;
        }
        else {
            value = value * 3 + 1;

        }
    return value;
}

// main function. Printing the results.
int main () {

    // calling getStart and assigning starting length. 
    value = getStart();
    long int length = 1;

    // loops around nextCollatz until it reaches 1.
    printf("\nCollatz sequence is: ");
    while (value != 1) {
        printf(" %ld ,", value);
        value = nextCollatz(value);
        length++;

    }
    // printing the 1 at the end, and then length. 
    printf(" %ld", value);
    printf("\nlength: %ld\n", length); 
}






// fillArray.c 

#include <stdio.h>

    // formula from last assignment
    long int nextCollatz(value) {
            if (value%2 == 0) {
                value = value / 2;
            }
            else {
                value = value * 3 + 1;

            }
        return value;
    }

int main() {
    // setting up the array
    int array[40];

    // for loop for 0 - 9. 
    for (int i = 0; i < 10; i++) 
        array[i] = i;
    
    // for loop for 10 - 29. Multiply i by 10 so we get 100, 110, ....
    for (int i = 10; i < 20; i++) 
        array[i] = i * 10;

    // assigning numbers to each array selected below.
    array[20] = 4;
    array[21] = 8;
    array[22] = 15;
    array[23] = 16;
    array[24] = 23;
    array[25] = 42;

    // starting number is 7, then the rest of collatz numbers
    array[26] = 7;
    
    // uses collatz formula from above to get the rest of the numbers
    for (int i = 27; i < 40; i++) {
        array[i] = nextCollatz(array[i - 1]);
    }

    // prints out the results. 
    int output = 0;
    for(output = 0; output < 40; output++) {
        printf("%d\n",array[output]);
    }
    
}







// copyarray


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Change this constant to 1 to fill source array
// with random values.
#define RAND_ARR 1

#define SRC_SIZE 10

int main()
{
    // Declare source array
    int source[SRC_SIZE];
    
    // Fill array with random values or constant values
    if (RAND_ARR == 1)
    {
        // Seed random number generator
        srandom(time(NULL));
        
        // Fill array with random values
        for (int i = 0; i < SRC_SIZE; i++)
            source[i] = random() % 20 - 10;
    }
    else
    {
        // Fill array with constant values
        source[0] = 9;
        source[1] = 2;
        source[2] = 0;
        source[3] = -4;
        source[4] = 0;
        source[5] = 21;
        source[6] = -92;
        source[7] = 1;
        source[8] = 10;
        source[9] = 2;
    }
    
    // ADD YOUR CODE BELOW HERE
    
    // What to do:
    //   Determine the number of positive and number of negative
    //     values.
    int posLength = 0;
    int negLength = 0;

    for (int i =0; i < SRC_SIZE; i++) {
        if (source[i] > 0) {
            posLength++;
        }
        if (source[i] < 0) {
            negLength++;
        }
        
    }
    //   Declare the pos and neg arrays, sized correctly.
    int pos[posLength], p = 0;
    int neg[negLength], n = 0;
    //   Copy the values out of the source array into the pos or neg
    //      array, as appropriate.
    for (int i = 0; i < SRC_SIZE; i++) {
        if (source[i] > 0) {
            pos[p] = source[i];
            p++;
        }
        if (source[i] < 0) {
            neg[n] = source[i];
            n++;
        }
    }
    // You'll need to replace these two lines with some code to
    //    determine the correct values.
    

    
    // YOUR CODE ABOVE HERE
    
    // Display the contents of the pos array
    printf("pos: ");
    for (int i = 0; i < posLength; i++)
    {
        printf("%d ", pos[i]);
    }
    printf("\n");
    
    // TODO: Display contents of the neg array
    printf("neg: ");
    for (int i = 0; i < negLength; i++) {
        printf("%d ", neg[i]);
    }
    printf("\n");


}




//captialWord.c

#include <stdio.h>


void capitalize(char str[]) 
{
    for (int i = 0; str[i] != '\0'; i++)
{
    // Do something with str[i]
    if (str[0] >= 'a' && str[0] <= 'z') {
        str[i] -= 32;
    }
    if (str[i] >= 'a' && str[i -1] == ' ') {
        str[i] -= 32;
    }
}

}


int main() {
    char str[100];
    printf("Enter a word: ");
    fgets(str, 100, stdin);
    capitalize(str);
    printf("In caps: %s\n", str);

    return 0;
}









//reverse.c

  #include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
int getInt(char prompt[], int min, int max);
void fillBoard(int board[], int boardLength);
void printBoard(int board[], int boardLength);
void shuffleBoard(int board[], int boardLength);
void reverse(int board[], int boardLength, int amt2);
int isSorted(int board[], int boardLength);


int main()
{
    // Seed the random number generator
    srandom(time(NULL));
        
    // Ask user for length of game, from 3-20
    int boardLength = getInt("Enter size of board: ", 3, 20);
    
    // Create board. Shuffle numbers.
    int board[boardLength];
    
    // Fill board in order with numbers 1..boardLength.
    fillBoard(board, boardLength);
    
    // Shuffle board.
    // I recommend initially only uncommenting the shuffleBoard line
    // so it doesn't get stuck in an infinite loop. Once shuffleBoard
    // is working, uncomment the rest of the loop.
    while (isSorted(board, boardLength))
    {
        shuffleBoard(board, boardLength);
    }
    
    // Print board
    printBoard(board, boardLength);
    
    int gameOver = 0;
    int moves = 0;
    while (!gameOver)
    {
        // Ask user for amount to reverse
        int amt = getInt("How many to reverse? ", 2, boardLength);
        
        // Reverse the first (amt) numbers
        reverse(board, boardLength, amt);
        
        // Print the board
        printBoard(board, boardLength);
        
        // Check to see if the game is over
        gameOver = isSorted(board, boardLength);
        
        moves++;
    }
    printf("You won in %d moves!\n", moves);
}

// Get an integer from the user.
//   Display the prompt.
//   Get input from user.
//   Check that the input is between the min and max, inclusive.
//   If not, display error message that includes the min and max,
//     then loop back to get input again.
int getInt(char prompt[], int min, int max)
{
    int result;

    for (;;) {
        printf("%s", prompt);
        scanf("%d", &result);

    if (result < min || result > max) {
        printf("Please enter a integer between %d - %d\n", min, max);
    } 
    else {
        break;
    }
       // Remove this line and replace it with working code.
    }
    return result;
}

void fillBoard(int board[], int boardLength) {
	for(int i = 0; i < boardLength; i++) {
		board[i] = i + 1;
	}
}

void printBoard(int board[], int boardLength) {
	printf("Board: ");
	    for (int i = 0; i < boardLength; i++ ) {
		    printf("%d ", board[i]);
	    }
	printf("\n");
}


void shuffleBoard(int board[], int boardLength) {
	for (int i = boardLength - 1; i >= 1; i--) {
 		int j = random() % (i + 1);

		int shuff = board[i];
		board[i] = board[j];
		board[j] = shuff;
	}
}

void reverse(int board[], int boardLength, int amt2) {

	for (int i = 0; i < amt2 / 2; i++) {
		int rev = board[amt2 - 1 - i];
        board[amt2 - 1 - i] = board[i];
        board[i] = rev;
	}
}

int isSorted(int board[], int boardLength) {
	for (int i = 0; i < boardLength -1; i++) {
		if (board[i] > board[i+1]) {
			return 0;
		}
	}
	return 1;
}








//fillArray2.c warmup5

#include <stdio.h>

    // formula from last assignment
    long int nextCollatz(value) {
            if (value%2 == 0) {
                value = value / 2;
            }
            else {
                value = value * 3 + 1;

            }
        return value;
    }

    // loop for 0-9
void upTo9(int *array) {
    for (int i = 0; i < 10; i++) 
        array[i] = i;
}

    // loop for 9-19 using pointer
void upTo19(int *array) {
    for (int i = 0; i < 10; i++) 
        *(array + i) =  i * 10 + 100;
}

    // loop for 19-25 using pointer
void upTo25(int *array) {

    // first in the array
    *array = 4;
    // rest + 1 each time
    *(array + 1) = 8;
    *(array + 2) = 15;
    *(array + 3) = 16;
    *(array + 4) = 23;
    *(array + 5)= 42;
}

   // loop for 25-39 uisng pointer
void upTo39(int *array) {
	*array = 7;
	for(int i = 1; i < 14; i++)
		*(array + i) = nextCollatz(*(array + i - 1));
}

    // print array to print results
void printArray(int *array) {
    int output = 0;
    for(output = 0; output < 40; output++) {
        printf("%d\n",array[output]);
    }
}
int main() {
    // setting up the array size
    int array[40];

    // calling each function
    upTo9(array);
    upTo19(array + 10);
    upTo25(array + 20);
    upTo39(array + 26);
    printArray(array);

    return 0;
}  







// sort.c

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void swap(float *item1, float *item2) {
    float shuff = *item1;
	*item1 = *item2;
	*item2 = shuff;
}

void getPrices(float *item1, float *item2, float *item3) {

    printf("Enter the price of item 1: ");
    scanf("%f",item1);

    printf("Enter the price of item 2: ");
    scanf("%f",item2);

    printf("Enter the price of item 3: ");
    scanf("%f",item3);

    if (*item1 > *item2) {
        swap(item1, item2);
    }

    if (*item1 > *item3) {
        swap(item1, item3);
    }

    if (*item2 > *item3) {
        swap(item2, item3);
    }

}


int main() {
    float *price1;
    price1 = (float *)malloc(10 * sizeof(float));

    float *price2;
    price2 = (float *)malloc(10 * sizeof(float));
    
    float *price3;
    price3 = (float *)malloc(10 * sizeof(float));

    getPrices(price1, price2, price3);

    printf("The three price are: %.2f %.2f %.2f\n",*price1,*price2,*price3);

}








