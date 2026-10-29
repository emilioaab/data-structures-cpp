/*#include <stdio.h>
#include <stdlib.h>

  ָ#define SIZE 7

int main() {
float temperature[SIZE];
int i;
float sum=0.0;
float averagetemp;
int hottestday=0, coldestday=0;

  for(i=0; i<SIZE; i++)
  {
      printf("Please insert a temperature in celsius for day %d: \n", i+1);
      scanf("%f", &temperature[i]);

  }

  for(i=0; i<SIZE; i++)
  {
     sum=sum+temperature[i];
     if(temperature[hottestday]<temperature[i]) {
         hottestday = i;
         continue;
     }
     if(temperature[coldestday]>temperature[i])
         coldestday=i;
  }
  averagetemp=sum/SIZE;
      printf("The average temp= %f \n", averagetemp);
         printf("The hottest day of the week was at day %d \n\n", hottestday+1);
    printf("The temp on the hottest day of the week was %.2f \n\n", temperature[hottestday]);
     printf("The Coldest day of the week was in day: %d \n\n", coldestday+1);
    printf("The temp on the coldest day of the week was %.2f \n\n", temperature[coldestday]);

    return 0;
}
*/
/*
#include <stdlib.h>
#include <stdio.h>
#define size 21


int main() {
    int i,j;
    int mat[size][size];

    for(i=0;i<size;i++)
        for(j=0;j<size;j++)
            mat[i][j] = i*j;

    for(i=1;i<size;i++){

        for(j=1;j<size;j++)
            printf(" %5d",mat[i][j]);
        printf(" \n");
    }

    return 0;
}


int main() {
    int i, j, mat[3][5];
    for(i=0;i<3;i++){
        for ( j = 0; j < 5; j++) {
            scanf("%d", &mat[i][j]);
        }
        printf("now print in a new row %d", i=+1);
    }
    for ( i = 0; i < 3; i++) {
        for(j=0; j<5; j++){

            printf("%5d", mat[i][j]);

        }
        printf("\n");
    }



    return 0;
}*/
/*
int main() {
    int a = 5;
    int *p;

    p = &a; //p holds the address of a

    printf("%p\n", &a); //prints the address of a
    printf("%p\n", p); //prints the address of p that is &a
    printf("%d\n",a);
    printf("%d\n", *p);
    return 0;
}

 */
/*
#include <stdlib.h>
#include <stdio.h>

void findMinMax();

int main() {
   int a, b, max, min;
    printf("Please insert 2 numbers to find min and max: \n");
    scanf("%d %d", &a, &b);

    findMinMax(a, b, &max, &min);

    printf("Max between %d and %d = %d \n", a, b, max);
    printf("Min between %d and %d = %d \n", a, b, min);

    return 0;

}

void findMinMax(int num1, int num2, int *pMax, *pMin)
    {
    if(num1>num2){
    *pMin = num2;
    *pMax = num1;
    }
    else {
    *pMin = num1;
    *pMax = num2;
    }
}

*/
/*
 #include <stdio.h>

void Min_Max();

int main() {
    int min, max, num;
    printf("Please enter a number: \n");
    scanf("%d", &num);

    Min_Max(num, &min, &max);

    printf("Min digit: %d \n", min);
    printf("Max digit: %d \n", max);

    return 0;
}

void Min_Max(int num, int *min, int *max){
    int rem;

    *min = 10;
    *max = 0;
     while(num>0){
         rem = num%10;
         if(rem<*min){
             *min = rem;
         }
        if(rem>*max) {
            *max = rem;
        }
        num/=10;

     }

}
 */
/*
#include <stdio.h>
#include <string.h>


void SizeOfString(char*str);

int main() {
    char str[5];
    printf("Please enter a string: \n");
    fgets(str, 5,stdin);
    //str[strlen(str)-1] = '\0';
    SizeOfString(str);
    return 0;
}

void SizeOfString(char*str){
        int count = 0;
        while (*str != '\0' && *str != '\n') {
            count++;
            str++;
        }
        printf("Length of string: %d\n", count);
    }



*/
/*

#include <stdio.h>

void Sort();

int main() {
    int x, y, z;
    printf("Please enter 3 numbers: \n");
    scanf("%d%d%d", &x, &y, &z);
    Sort(&x, &y, &z);
    printf("Sorted integeres are: %d %d %d\n", x, y, z);

    return 0;
}

void Sort(int *x, int *y, int *z){
int temp;
if(*x > *y){
    temp = *x;
    *x = *y;
    *y = temp;
}
if(*x > *z){
    temp = *x;
    *x = *z;
    *z = temp;
}
if(*y > *z){
    temp = *y;
    *y = *z;
    *z = temp;

    }
}
*/
/*
#include <stdio.h>
#include <string.h>


void MinMax();
void InsertMat();
#define N 3


int main() {
    int mat[N][N];
    InsertMat(mat);
    int equal, max, min;
    MinMax(mat, &equal, &max, &min);
    printf("Number of elements below average: %d\n", min);
    printf("Number of elements above average: %d\n", max);
    printf("Number of elements equal to average: %d\n", equal);

    return 0;
}

void InsertMat(int mat[][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("Enter element (%d,%d): ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}




void MinMax(int mat[][N], int *equal, int *max, int *min) {
    int sum = 0;
    int count = 0; // count = N*N
    *equal = 0;
    *max = 0;
    *min = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sum += mat[i][j];
            count++; // without "count++"
        }
    }
    int avg = sum / count;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (mat[i][j] < avg) {
                (*min)++;
            } else if (mat[i][j] > avg) {
                (*max)++;
            } else {
                (*equal)++;
            }
        }
    }
}

*/
/*
#include <stdio.h>
#include <string.h>

void Statistics();

int main(){


    return 0;
}

void Statistics(char str[], int *big, int *small, int *numbers) {
    printf("Enter a string and 3 numbers: \n");
    gets(str);
    scanf("%d", &numbers);


    for(int i = 0; i < )


}
 */
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void SumsFunc(float *arr, int size, int *SumIntReturn, float *SumFloatReturn) {
  int sumInt=0;
  float sumFloat = 0;
  int curInt;
  float curFloat;

    for (int i=0; i<size; i++) {
        //printf("%f", arr[i]);
        // arr[i] == *(arr+i)

        curInt = (int)(arr[i]);
        sumInt+=curInt;

        curFloat = arr[i]-curInt;
        sumFloat+=curFloat;

    }
    *SumIntReturn = sumInt;
    *SumFloatReturn = sumFloat;

}


int main(){
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    float array[size];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%f", &array[i]);
    }

    // Call the Sums function and store the result in two variables
    int int_part_sum = int_sum(array, size);
    float dec_part_sum = dec_sum(array, size);

    // Print the results
    printf("Sum of integer parts: %d\n", int_part_sum);
    printf("Sum of decimal parts: %f\n", dec_part_sum);

    return 0;

    // float test = 10.79;
    // int test_int = (int)(test);
    // float test2 = test-test_int;
    // float remainder = test % 1;
    // printf("%d, %.3f", test_int, test2);

    return 0;
}

*/
/*

#include <stdio.h>
#include <stdlib.h>

// Function to initialize the array
void insertArray(int *arr, int size) {
    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

// Function to build the limited array with only even numbers
void minimizeArray(int *arr, int size, int **new_arr_ptr) {
    // Count the number of even numbers in the array
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            count++;
        }
    }

    // Allocate memory for the new array
    *new_arr_ptr = malloc(count * sizeof(int));

    // Populate the new array with the even numbers
    int j = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            (*new_arr_ptr)[j] = arr[i];
            j++;
        }
    }
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Allocate memory for the array
    int *arr = malloc(size * sizeof(int));

    // Initialize the array
    insertArray(arr, size);

    // Build the limited array with only even numbers
    int *new_arr;
    minimizeArray(arr, size, &new_arr);

    // Print the new array
    printf("The new array is: [");
    for (int i = 0; i < size; i++) {
        printf("%d", new_arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    // Free the memory allocated for the arrays
    free(arr);
    free(new_arr);

    return 0;
}
*/
/*
#include <stdio.h>
#include <stdlib.h>

void insertArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

int* minimizeArray(int* arr, int* size) {
        int count = 0;
        for (int i = 0; 1 < *size; i++)
            if (arr[i] % 2 == 0)
                count++;
        int *temp = (int *) malloc(count * sizeof(int));
        int index = 0;
        for (int i = 0; i < *size; i++) {
            if (arr[i] % 2 == 0)
                temp[index++] = arr[i];
        }
        free(arr);
        arr = temp;
        *size = count;
        return arr;


    }



int main() {
    int N=5;
    int* arr = (int*) malloc(N*sizeof(int));
    insertArray(arr, N);
    arr= minimizeArray(arr, &N);
    for(int i=0; i <N; i++)
        printf("%d \n", arr[i]);

    return 0;
}
*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void str_cut(char** str1){
        char* str2 = "de";
        int len1 = strlen(*str1);
        *str1 = (char*) realloc(*str1, (len1+strlen(str2)+1)*sizeof(char));
        for (int i = strlen(*str1), j = 0; j<=strlen(str2); j++, i++)
            (*str1)[i] = str2[j];

}

int main(){
    char* str1=(char*)malloc(4);
    gets(str1);
    printf("%s", str1);
    str_cut(&str1);
    printf("%s", str1);


    return 0;
}

*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n1;
    char c1;

    printf("Please enter a number: ");
    scanf("%d", &n1);
    printf("Please enter a char: ");
    scanf("%c", &c1);
    flushall();
    printf("n1 = |%d|, c1 = |%c|", n1, c1);

    return 0;
}


*/
/*
#include <stdio.h>

int main() {


    printf("I've just wrote my first program! yaaaasss!!!");

    return 0;
}

*/
/*
#include <stdio.h>

int main() {
    int x;
    float y;
    char z;

    scanf("%d %f %c", &x, &y, &z);

    x = z;

    printf("x = %d  y = %.3f  z = %c", x, y, z);
    printf("\n17%%");

    return 0;
}

*/
/*
 #include <stdio.h>  //lab1.1
int main() {
    printf("\n\nLondon \nis \nthe \ncapital \nof \t\t\t\nGreat \nbritain\n");


    return 0;
}
*/
/*
#include <stdio.h>
#include <stdlib.h> //gool keren (1+2).1

int main() {
    double decimalNum;
    int roundedNumber;

    printf("Please enter a float number: \n");
    scanf("%lf", &decimalNum);
    roundedNumber=(int)decimalNum;
    printf("Your int number is %d", roundedNumber);
    system("pause");
    return 0;
}
*/
/*int main(){ //gool keren (1+2).1
    float decimalNum;
    int num;

    printf("Please enter a float number: \n");
    scanf("%f", &decimalNum);
    num = decimalNum;
    printf("Your int number is %d", num);

    return 0;
}
*/
/*
#include <stdio.h>
#include <stdlib.h>
//gool keren (1+2).1
int main() {
    double decimalNum;

    printf("Please enter a float number: \n");
    scanf("%lf", &decimalNum);
    printf("Your int number is %d", (int)decimalNum);
    return 0;
}
 */
/*
#include <stdio.h>
#include <stdlib.h>
//gool keren (1+2).2
int main() {
    int count;
    printf("There are %d English letters\n", 'z'-'a'+1);
    return 0; //there are 25+1=26 letters
}
 */
/*
#include <stdio.h>
#include <stdlib.h>
//lab1.2
int main() {
    int i;
    float f;
    double d;
    char c;
    long l;

    printf("Please enter and int, float, double, char, long!\n");
    scanf("%d %f %lf %c %ld", &i, &f, &d, &c, &l);
    printf("int: %d\nfloat: %f\ndouble: %lf\nchar: %c\nlong: %ld", i, f, d, c, l);

    return 0;
}
*/
/*
#include <stdio.h>
#include <stdlib.h>
//lab1.3
int main() {
int num1, num2, num3;
float avg;

printf("Please enter 3 integer numbers to calculate the average between them:");
scanf("%d %d %d", &num1, &num2, &num3);

printf("Your avg is: %.2f", avg=(((float)(num1+num2+num3))/3));

return 0;
}
*/
/*
#include <stdio.h>
#include <stdlib.h>
//lab 1.4
int main() {
    int num;

    printf("Please enter an integer number:\n");
    scanf("%d", &num);
    printf("%d*2 = %d\n", num, num*2);
    printf("%d-5 = %d\n", num, num-5);
    printf("%d/3 = %d\n", num, num/3);
    printf("%d%%3 = %d\n", num, num%3);

    return 0;
}
*/
/*
#include <stdio.h>
#include <stdlib.h>
//lab 1.5
int main() {
    int birthYear, currentYear;
    printf("Please enter your birth year and the current year: \n");
    scanf("%d %d", &birthYear, &currentYear);

    printf("The difference is: %d \n", currentYear-birthYear);


    return 0;
}
*/
/*
#include <stdio.h>
#include <stdlib.h>

//lab 1.6
int main() {
    float decimal;

    printf("Please enter a decimal number: \n");
    scanf("%f", &decimal);
    printf("The number is: %.2f, its integer part is: %d and its fraction is: %.2f", decimal, (int)decimal, decimal-(int)decimal);


    return 0;
}
*/
/*
#include <stdio.h>
#include <stdlib.h>
//lab 1.7

 int main() {
    int tripleDigits, hundreds, dozens, single;
    printf("Please enter a 3 digits number: \n");
    scanf("%d", &tripleDigits);
    single = tripleDigits % 10;
    dozens = tripleDigits / 10 % 10;
    hundreds = tripleDigits / 100;
    printf("%d\n%d\n%d", single, dozens, hundreds);

    return 0;
}
*/
/*
#include <stdio.h>
#include <stdlib.h>
//lab 1.8

int main() {
    float farenheit, celsius;
    printf("Please enter a temperature in Farenheit to convert to celsius: \n");
    scanf("%f", &farenheit);
    celsius = (5*(farenheit - 32)/9);
    printf("Your degrees in Celsius are: %f\n", celsius);

    return 0;
}
*/
/*
#include <stdio.h>
#include <stdlib.h>
//lab 1.9

int main() {
    int tripleDigit, oppositeNum2, num1, num2, num3;
    printf("Please enter a triple digits number: \n");
    scanf("%d", &tripleDigit);
    num1 =  tripleDigit % 10 ;
    num2 = tripleDigit / 10 % 10;
    num3 = tripleDigit / 100;
    printf("The opposite number in 1st way is: %d%d%d\n",num1, num2, num3);
    oppositeNum2 = (num1 * 100) + (num2*10) + (num3);
    printf("The opposite number in 2nd way is: %d\n",oppositeNum2);
    printf("Your sum is: %d\n", num1+num2+num3);
    return 0;
}
*/
/*
#include <stdio.h>
#include <stdlib.h>
//lab 1.10

int main() {
    float decimal = 1.61456;
    printf("%.3f, %f", decimal, decimal);

    return 0;
}
 */
/*
#include <stdio.h>
#include <stdlib.h>
//lab 2.1

int main() {
    int height, width;
    printf("Input the height of the Rectangle: \n");
    scanf("%d", &height);
    printf("Input the width of the Rectangle: \n");
    scanf("%d", &width);
    printf("Perimeter of the Rectangle is: %f", (float)(width*2+height*2));



    return 0;
}
 */
/*
#include <stdio.h>
#include <stdlib.h>
//lab 2.2

int main() {
    float kmh;
    printf("Input Kilometers per hour: \n");
    scanf("%f", &kmh);
    printf("%f miles per hour", kmh / 1.609344);


    return 0;


}
*/
/*
#include <stdio.h>
#include <stdlib.h>
//lab 2.3

int main() {
   int hours, mins;
   printf("Input hours: \n");
   scanf("%d", &hours);
   printf("Input minutes: \n");
   scanf("%d", &mins);
    printf("Total: %d", (hours*60)+mins);

    return 0;

}
 */
/*
#include <stdio.h>
#include <stdlib.h>
//lab 2.4

int main() {
    char ch;
    printf("Enter a character: \n");
    scanf("%c", &ch);
    printf("ASCII value is: %d", (int) ch);


    return 0;
}
*/
/*
#include <stdio.h>
#include <stdlib.h>
//lab 2.5

int main() {
    int days, years, weeks, leftDays;
    printf("Number of days: \n");
    scanf("%d", &days);
    years = days / 365 ;
    weeks = ((days - (years * 365)) / 7 ) ;
    leftDays = ( days - ((years * 365) + (7 * weeks)));
    printf("Years: %d\n", years);
    printf("Weeks: %d\n", weeks);
    printf("Days: %d\n", leftDays);
    return 0;
}
 */
/*
#include <stdio.h>
#include <stdlib.h>
//lab 2.6

int main() {
    int distance, fuel;
    printf("Input total distance in km: \n");
    scanf("%d", &distance);
    printf("Input total fuel spent in liters: \n");
    scanf("%d", &fuel);

    printf("Expected Output: \n");
    printf("Average consumption (km/lt) %.3f ",((float)distance/(float)fuel) );


    return 0;
}
*/
/*
#include <stdio.h>
#include <stdlib.h>
//lab 2.7

int main() {
    int amount;
    printf("Input the amount: \n");
    scanf("%d", &amount);
    printf("There are: \n");
    printf("%d Note(s) of 100.00\n", amount/100);
    printf("%d Note(s) of 50.00\n", (amount%100)/50);
    printf("%d Note(s) of 20.00\n", (amount%100)%50/20);
    printf("%d Note(s) of 10.00\n", (amount%100)%50%20/10);
    printf("%d Note(s) of 5.00\n", (amount%100)%50%20%10/5);
    printf("%d Note(s) of 2.00\n", (amount%100)%50%20%10%5/2);
    printf("%d Note(s) of 1.00\n", (amount%100)%50%20%10%5%2/1);


    return 0;
}
 */
/*
#include <stdio.h>
#include <stdlib.h>
//lab 2.8
#define minxhours 3600
int main() {
   int sec, hours, mins, seconds;
   printf("Input seconds: \n");
   scanf("%d", &sec);
   hours = sec/minxhours;
   mins = (sec - (hours*minxhours))/60;
   seconds = (sec - hours*minxhours)-mins*60;
   printf("Expected Output:\nThere are:\nH:M:S - %d:%d:%d", hours, mins, seconds);


    return 0;
}
 */
/*
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//lab 2.9

int main() {
    int x1, y1, x2, y2;
    double distance;
    printf("Input x1: \n");
    scanf("%d", &x1);
    printf("Input y1: \n");
    scanf("%d", &y1);
    printf("Input x2: \n");
    scanf("%d", &x2);
    printf("Input y2: \n");
    scanf("%d", &y2);
    distance = (pow((x2-x1),2)+pow((y2-y1),2));
    printf("Expected Output:\n");
    printf("Distance between the said points: %lf\n", sqrt(distance));


    return 0;
}
*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//lab 2.10

int main() {
    int num1, num2;
    float result;
    printf("Input two numbers: \n");
    printf("X: \n");
    scanf("%d", &num1);
    printf("Y: \n");
    scanf("%d", &num2);
    if (num2 != 0) {
        result = ((float) num1 / (float) num2);
        printf("Expected Output: %.1f\n", result);
    } else
        printf("Division is not possible\n");


    return 0;
}
*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//lab 2.11

int main() {
    int posNum1, posNum2;
    printf("Please input two positive integer numbers: \n");
    scanf("%d%d", &posNum1, &posNum2);

    if(posNum1%10 == posNum2%10)
        printf("Their last digit is the same \n");
    else
        printf("Their last digit is not the same \n");


    return 0;
}
*/
/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//gool keren 1+2.3

#define PRICE_PER_TICKET 35
int main() {
    int numOFtickets, pay;

    printf("How many tickets would you like to buy? (1 Ticket is %d ILS) \n", PRICE_PER_TICKET);
    scanf("%d", &numOFtickets);

    pay = numOFtickets * PRICE_PER_TICKET;

    printf("Your total price will be: %d ILS\n", pay);

    return 0;

}
 */
/*
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//gool keren 1+2.4

#define START_FEE 10.20
#define FEE_PER_KM 1.30
#define FEE_PER_LUGAGGE 2.00

int main() {
    double numOfKm, totalFee;
    int numOfLugagge;

    printf("Please insert the Kilometers you rode: \n");
    scanf("%lf", &numOfKm);
    printf("How many luggage(s) do you have with you: \n");
    scanf("%d", &numOfLugagge);

    totalFee = START_FEE + (FEE_PER_KM * numOfKm) + (FEE_PER_LUGAGGE * numOfLugagge);

    printf("Your total price is: %.2lf\n", totalFee);


    return 0;
}
*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//Gool keren 1+2.5

#define SWIM_LEN 1.5
#define RIDE_LEN 40
#define RUN_LEN 10

int main() {
    double swimSpeed, rideSpeed, runSpeed, swimTime, rideTime, runTime, total;

    printf("Please enter your swimming speed: \n");
    scanf("%lf", &swimSpeed);
    printf("Please enter your riding speed: \n");
    scanf("%lf", &rideSpeed);
    printf("Please enter your running speed: \n");
    scanf("%lf", &runSpeed);

    swimTime = (SWIM_LEN / swimSpeed) ;
    rideTime = (RIDE_LEN / rideSpeed) ;
    runTime = (RUN_LEN / runSpeed) ;
    total = swimTime + rideTime + runTime;

    printf("Your swimming time is %.2lf \n", swimTime);
    printf("Your riding time is %.2lf \n", rideTime);
    printf("Your running time is %.2lf \n", runTime);
    printf("Your total time is %.2lf \n", total);

    return 0;
}
*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//Gool keren 1+2.6

#define TAX 1.16
#define GIFT_DECOR 5
#define EXTRA_GIFT_DECOR 1.2

int main() {
    double height, width, depth, productPrice, packSize, priceGiftDecor;
    scanf("%lf %lf %lf %lf", &height, &width, &depth, &productPrice);

    packSize = EXTRA_GIFT_DECOR * 2 * ((width*height)+(width * depth) + (depth * height));
    priceGiftDecor = productPrice + (packSize * GIFT_DECOR * TAX);

    printf("Pay %lf ", priceGiftDecor);

    return 0;
}
 */
/*
#include <stdio.h>
// Gool keren 2
void main() {
    int num, absNum;

    printf("please enter a number: ");
    scanf("%d", &num);

    absNum = num >= 0 ? num: -num;  // shortened if

    printf("|%d| = %d\n", num, absNum);

}
 */
/*
#include <stdio.h>

#define ThreeRooms 120
#define FourRooms 150
#define FiveDup 200
#define FiveReg 180

// Gool keren 2.1
int main() {
    int rooms;
    char q, y = 1, n = 0;

    printf("House of 3 Rooms: %d ILS (for regular and for duplex)\n", ThreeRooms);
    printf("House of 4 Rooms: %d ILS (for regular and for duplex)\n", FourRooms);
    printf("House of 5 Rooms: if duplex %d ILS\nRegular is %d ILS\n", FiveDup, FiveReg);

    printf("How many rooms: \n");
    scanf("%d", &rooms);


    if (rooms == 3)
        printf("The price is %d", ThreeRooms);
    else if (rooms == 4)
        printf("The price is %d", FourRooms);
    else if (rooms == 5) {
        printf("Duplex?");
        scanf("%c", &q);
    }


    return 0;
}

 */
/*
#include <stdio.h>


// Gool keren 2.1
int main() {
    int numOfRooms, price, isDuplex;

    printf("Please enter num of rooms: \n");
    scanf("%d", &numOfRooms);

    switch (numOfRooms){
        case 3:
            price = 120;
            break;
        case 4:
            price = 150;
            break;
        case 5:
            printf("Is duplex? (1/0)\n");
            scanf("%d", &isDuplex);
            if(isDuplex)
                price = 200;
            else
                price = 180;

    }
    printf("Please pay %d ILS", price);

    return 0;
}
 */
/*

#include <stdio.h>


// Gool keren 2.2
int main() {
    int total, quantity, discount1, discount2;
    printf("Please insert total: \n");
    scanf("%d", &total);
    printf("Please insert quantity: \n");
    scanf("%d", &quantity);

    discount1 = total - (total / 300) * 50;

    if (quantity >= 3)
        discount2 = total - total * 0.2;
    else
        discount2 = total;

    if (discount1 < discount2)
        printf("Price after disc: %d", discount1);
    else printf("Price after disc: %d", discount2);

    return 0;
}
*/
/*
#include <stdio.h>

#define MAX 100
#define MIN 60
#define LESSONS 25
#define MiniExamPercantage 0.2
#define HWPercantage 0.1

// Gool keren 2.3
int main() {

    double attendance, examGrade, miniExamGrade, HWGrade, lessonQuantity, finalGrade, gradeAfterMini;

    printf("Please enter your attendance quantity out of %d lessons: \n", LESSONS);
    scanf("%lf", &lessonQuantity);

    attendance = lessonQuantity / LESSONS * MAX;

    if (attendance < 80) {
        finalGrade = 0;
        printf("Unfortunately You failed this course! Your grade is %lf. \n", finalGrade);
    } else {
        printf("Please input your exam grade: \n");
        scanf("%lf", &examGrade);

        if (examGrade >= MIN) {
            printf("Please input your mini exam grade: \n");
            scanf("%lf", &miniExamGrade);

            gradeAfterMini = 0.8 * examGrade + miniExamGrade * MiniExamPercantage;

            if (gradeAfterMini < examGrade)
                gradeAfterMini = examGrade;

            printf("Please input your Homework grade: \n");
            scanf("%lf", &HWGrade);

            finalGrade = 0.9 * gradeAfterMini + HWGrade * HWPercantage;

        } else {
            finalGrade = examGrade;
            printf("You will have to retake the course. %.2lf\n", examGrade);
        }
        printf("Your final grade for this course is: %.2lf \n", finalGrade);
    }
    return 0;
}
*/
/*
#include <stdio.h>

// Gool keren 2.4
int main() {
    int homeworkNum;
    double examGrade, homeworkAvg, finalGrade;

    printf("Please insert your exam grade: \n");
    scanf("%lf", &examGrade);
    printf("Please insert your homework quantity: \n");
    scanf("%d", &homeworkNum);
    printf("Please insert your homework average: \n");
    scanf("%lf", &homeworkAvg);

    if (homeworkNum <= 4)
        finalGrade = examGrade;

    else if (homeworkNum < 8 && homeworkNum > 4) {
        if (examGrade >= 60)
            finalGrade = examGrade * 0.8 + homeworkAvg * 0.2;
        else
            finalGrade = examGrade * 0.9 + homeworkAvg * 0.1;

    } else {
        if (examGrade >= 60)
            finalGrade = examGrade * 0.7 + homeworkAvg * 0.3;
        else
            finalGrade = examGrade * 0.6 + homeworkAvg * 0.4;
    }
    printf("Your final grade is %.2lf", finalGrade);


    return 0;
}
*/
/*
#include <stdio.h>

// Gool keren 3.1 loops

int main() {
    int newNum = 0, x = 0, temp = 0;

    scanf("%d", &x);

    temp = x;

    while (temp>0){

        newNum*=10;
        newNum += temp%10;
        temp /= 10;

    }
    printf("%d", newNum);

    return 0;
}

*/
/*
#include <stdio.h>

// Gool keren 3.2 loops

int main() {
    int newNum = 0, num, temp, location = 1;
    printf("bla bla\n");
    scanf("%d", &num);

    temp = num;
    while (temp > 0)
    {
        int digit = temp % 10;
        if (digit %2 == 0) {
            newNum += digit * location;
            location *= 10;
        }
        temp /= 10;

    }
    printf("%d", newNum);

    return 0;
}
*/
/*
#include <stdio.h>

// Gool keren 3.3 loops binary numbers

int main() {
    int num, binaryNum = 0, location = 1;

    printf("Please enter a number to convert to a binary number\n");
    scanf("%d", &num);


    while (num > 0) {
        int left = num % 2;
        num = num / 2;
        binaryNum = binaryNum+location*left;
        location = location * 10 ;

        }


    printf("%d", binaryNum);

    return 0;
}
*/
/*
 #include <stdio.h>

// Gool keren 3.4 loop in a loop

int main() {
    int i, j, base;

    printf("Please enter the base\n");
    scanf("%d", &base);


    for (i = 1; i <= base; i++) {
        for (j = 1; j <= i; j++)
            printf("*");
        printf("\n");
    }


    return 0;

}
 */
/*
#include <stdio.h>
#include <stdlib.h>

int even_uneven_difference(int num) {
    if (num == 0) return 0;
    int digit = num % 10;
    int difference = (digit % 2 == 0) ? digit : -digit;
    return difference + even_uneven_difference(num / 10);
}

void binaryreturn(int number, char *binary, int i) {
    if (number == 0) {
        binary[i] = '\0';
        return;
    }
    binary[i] = number % 2 + '0';
    binaryreturn(number / 2, binary, i + 1);
}

int all_even(int arr[], int size) {
    if (size == 0) {
        return 1;
    }
    if (arr[size-1] % 2 == 0) {
        return all_even(arr, size-1);
    }
    else {
        return 0;
    }
}

int has_uneven_digit(int n) {
    if (n < 10) {
        return n % 2 != 0;
    }
    else {
        if (n % 2 != 0) {
            return 1;
        }
        else {
            return has_uneven_digit(n / 10);
        }
    }
}

int passed_grades(int arr[], int size) {
    if (size == 0) {
        return 0;
    }
    else {
        if (arr[size-1] >= 56) {
            return 1 + passed_grades(arr, size-1);
        }
        else {
            return passed_grades(arr, size-1);
        }
    }
}

int count_char(char* str, char c, int i) {
    if (str[i] == '\0') {
        return 0;
    }
    else {
        if (str[i] == c) {
            return 1 + count_char(str, c, i+1);
        }
        else {
            return count_char(str, c, i+1);
        }
    }
}

int main() {

        char binary[100];
        binaryreturn(num, binary, 0);
        unsigned long len = 0;
        len = strlen(binary);
        for (int i = 0; i < len / 2; i++) {
            char temp = binary[i];
            binary[i] = binary[len - i - 1];
            binary[len - i - 1] = temp;
        }
        printf("Binary representation of %d is %s\n", num, binary);

        // function 3 code here
        int size;
        printf("Enter the size of the array: ");
        scanf("%d", &size);
        int arr[size];
        printf("Enter %d integer numbers:\n",size);
        for(int i=0; i<size; i++)
            scanf("%d", &arr[i]);
        int result = all_even(arr, size);
        printf("The result of function 3 is: %d\n", result);

        // function 4 code here
        int n;
        printf("Enter an integer number: ");
        scanf("%d", &n);
        result = has_uneven_digit(n);
        printf("The result of function 4 is: %d\n", result);

        // function 5 code here
        printf("Enter the size of the grades array: ");
        scanf("%d", &size);
        int grades[size];
        printf("Enter %d integer numbers:\n",size);
        for(int i=0; i<size; i++)
            scanf("%d", &grades[i]);
        result = passed_grades(grades, size);
        printf("The result of function 5 is: %d\n", result);

        // function 6 code here
        char str[100];
        char c;
        printf("Enter a string: ");
        scanf("%s", str);
        printf("Enter a character: ");
        scanf(" %c", &c);
        result = count_char(str, c, 0);
        printf("The result of function 6 is: %d\n", result);

        return 0;
    }
*/
/*

#include <stdio.h>
#include <stdlib.h>

int even_uneven_difference(int num) {
    if (num == 0) return 0;
    int digit = num % 10;
    int difference = (digit % 2 == 0) ? digit : -digit;
    return difference + even_uneven_difference(num / 10);
}

void binary_representation(int num, char *binary, int index) {
    if (num == 0) {
        binary[index] = '\0';
        return;
    }
    binary[index] = (num % 2) ? '1' : '0';
    binary_representation(num/2,binary,index+1);
}

int all_even(int arr[], int size) {
    if (size == 0) {
        return 1;
    }
    if (arr[size-1] % 2 == 0) {
        return all_even(arr, size-1);
    }
    else {
        return 0;
    }
}

int has_uneven_digit(int n) {
    if (n < 10) {
        return n % 2 != 0;
    }
    else {
        if (n % 2 != 0) {
            return 1;
        }
        else {
            return has_uneven_digit(n / 10);
        }
    }
}

int passed_grades(int arr[], int size) {
    if (size == 0) {
        return 0;
    }
    else {
        if (arr[size-1] >= 56) {
            return 1 + passed_grades(arr, size-1);
        }
        else {
            return passed_grades(arr, size-1);
        }
    }
}

int count_char(char* str, char c, int i) {
    if (str[i] == '\0') {
        return 0;
    }
    else {
        if (str[i] == c) {
            return 1 + count_char(str, c, i+1);
        }
        else {
            return count_char(str, c, i+1);
        }
    }
}

int main() {
    int choice;
    printf("Please enter a number between 1 and 6 to select the function you want to test: \n");
    scanf("%d", &choice);

    switch (choice) {
        case 1: {
            int num;
            printf("Please enter a positive integer number: ");
            scanf("%d", &num);
            printf("The sum of even digits minus uneven digits is: %d\n", even_uneven_difference(num));
            break;
        }
        case 2: {
            int num;
            char *binary;
            printf("Please enter a positive integer number: ");
            scanf("%d", &num);
            binary = (char *) malloc(sizeof(char) * 32);
            binary_representation(num, binary, 0);
            printf("The binary representation of %d is: %s\n", num, binary);
            free(binary);
            break;
        }
        case 3: {
            int size;
            int *arr;
            printf("Please enter the size of the array: ");
            scanf("%d", &size);
            arr = (int *)malloc(sizeof(int) * size);
            printf("Please enter the elements of the array: ");
            for (int i = 0; i < size; i++) {
                scanf("%d", &arr[i]);
            }
            if (all_even(arr, size)) {
                printf("All elements in the array are even\n");
            } else {
                printf("Not all elements in the array are even\n");
            }
            free(arr);
            break;
        }
        case 4: {
            int num;
            printf("Please enter a positive integer number: ");
            scanf("%d", &num);
            if (has_uneven_digit(num)) {
                printf("The number has an uneven digit '1'\n");
            } else {
                printf("The number does not have an uneven digit ""0""\n");
            }
            break;
        }
        case 5: {
            int size;
            int *arr;
            printf("Please enter the size of the array: ");
            scanf("%d", &size);
            arr = (int *)malloc(sizeof(int) * size);
            printf("Please enter the elements of the array: ");
            for (int i = 0; i < size; i++) {
                scanf("%d", &arr[i]);
            }
            printf("Number of passed grades: %d\n", passed_grades(arr, size));
            free(arr);
            break;
        }
        case 6: {
            char* str;
            char c;
            int i = 0;
            printf("Please enter a string: ");
            scanf("%s", str);
            printf("Please enter a character: ");
            scanf(" %c", &c);
            printf("Number of '%c' in the string: %d\n", c, count_char(str, c, i));
            break;
        }
    }
    return 0;
}

*/


#include <stdio.h>

// Gool keren 3.4 loop in a loop

int main() {
    int i, j, k, l, size;

    printf("Enter size -- >\n");
    scanf("%d", &size);


    for (l = 0; l < size; l++) {
        for (k = 0; k < size; k++){
            for (j = 0; j < size; j++){
                for (i = 0; i < size; i++){
                      printf("*");


                }
                printf(" ");

            }
            printf("\n");
        }
        printf("\n");
    }


    return 0;

}