#include <stdio.h>
//#pragma warning (disable: 4996)

//Keren Kalif
//ex1.1
/*
int main() {
    float num;
    int roundedNumber;
    printf("Please enter a float number:\n");
    scanf("%f", &num);
    roundedNumber = (int)num;
    printf("The int number is: %d\n", (int)num);
    printf("The int number is: %d\n", roundedNumber);

    return 0;
}
*/
//ex1.2
/*
int main() {
        int count = 'Z'-'A' + 1 ;
        printf("There are %d English letters\n", count);

    return 0;
}
 */
//ex1.3
/*
#define TICKET_PRICE 35

int main() {
    int tickets, totalPrice;

    printf("One ticket's price is: %d ILS\nHow many tickets would you like to buy?\n", TICKET_PRICE);
    scanf("%d", &tickets);

    totalPrice = tickets * TICKET_PRICE;

    printf("Total price is: %d ILS\n", totalPrice);

    return 0;
}
 */
//ex1.4
/*
#define startFare 10.20
#define kmFare 1.30
#define luggageFare 2.00

int main() {
    int km, luggage;
    float priceRide;
    printf("Taxi fare calculation - please insert how many km's and how many luggages: \n");
    scanf("%d %d", &km, &luggage);
    priceRide = startFare + km * kmFare + luggage * luggageFare;
    printf("Your price ride will be: %.2f ILS\n", priceRide);


    return 0;
}
*/
//ex1.5
/*
#define SWIM_KM 1.5
#define CYCLE_KM 40
#define RUN_KM 10

int main() {

    float swimSpeed, cyclingSpeed, runSpeed;
    float swimTime, cyclingTime, runTime, totalTime;

    printf("Please insert swimming speed:\n");
    scanf("%f", &swimSpeed);

    printf("Please insert cycling speed:\n");
    scanf("%f", &cyclingSpeed);

    printf("Please insert running speed:\n");
    scanf("%f", &runSpeed);

    swimTime = SWIM_KM /swimSpeed;
    cyclingTime = CYCLE_KM /cyclingSpeed;
    runTime = RUN_KM /runSpeed;
    totalTime = (swimTime + cyclingTime + runTime);

    printf("Swimming part time: %.2f\nCycling part time: %.2f\nRunning speed time: %.2f\n", swimTime, cyclingTime,
           runTime);
    printf("Total time: %.2f\n", totalTime);

    return 0;
}
 */
//ex1.6
//---------
// Mispar Rishoni
/*
int main() {

    int n, i, flag = 0;
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    // 0 and 1 are not prime numbers
    // change flag to 1 for non-prime number
    if (n == 0 || n == 1)
        flag = 1;

    for (i = 2; i <= n - 1; ++i) {

        // if n is divisible by i, then n is not prime
        // change flag to 1 for non-prime number
        if (n % i == 0) {
            flag = 1;
            break;
        }
    }

    // flag is 0 for prime numbers
    if (flag == 0)
        printf("%d is a prime number.", n);
    else
        printf("%d is not a prime number.", n);

    return 0;
}

 */
//lab3.1
/*
int main() {
    int num1, num2, res;

    printf("enter two numbers:\n");
    scanf("%d%d", &num1, &num2);

    if (num1 % num2 == 0) {
        res = num1 / num2;
        printf("%d", res);
    } else {
        res = num1 % num2;
        printf("%d", res);
    }
    return 0;
}
*/
//lab3.2
/*
int main() {
    int num1, num2, num3, max = 0, min = 0;
    printf("enter three numbers:\n");
    scanf("%d%d%d", &num1, &num2, &num3);

    if (num1 > num2 && num2 > num3) {
        printf("Descending");

    } else if (num1 < num2 && num2 < num3) {
        printf("Ascending");
    } else printf("Not sorted");


    return 0;
}
*/
//lab3.3
/*
int main() {

    int num;
    printf("enter a 4 digit number: \n");
    scanf("%d", &num);
    if (!(num >= 1000 && num <= 9999)) {
        printf("Error!");
    } else if (num % 10 == num / 1000 && num / 10 % 10 == num / 100 % 10) {

        printf("Symmetrical/Palindrome");

    } else printf("Non symmetrical/Non Palindrome");

    return 0;
}
*/
//lab3.4 part1
/*
int main() {
    int num1, num2, num3;
    printf("Enter 3 digits each one at a time and enter: \n");
    scanf("%d%d%d", &num1, &num2, &num3); // 654 456 564 465 645 546

    if (num1 >= num2 && num2 >= num3) {       //num1 > num2 > num3  654
        printf("%d %d %d", num3, num2, num1);
    } else if (num3 >= num2 && num2 >= num1) { //num3 > num2 > num1  456
        printf("%d %d %d", num1, num2, num3);
    } else if (num2 >= num1 && num1 >= num3) { //num2 > num1 > num3  564
        printf("%d %d %d", num3, num1, num2);
    } else if (num2 >= num3 && num3 >= num1) { // num2 > num3 > num1 465
        printf("%d %d %d", num1, num3, num2);
    } else if (num1 >= num3 && num3 >= num2) { //num1 > num3 > num2  645
        printf("%d %d %d", num2, num3, num1);
    } else if (num3 >= num1 && num1 >= num2) { // num3 > num1 > num2 546
        printf("%d %d %d", num2, num1, num3);
    } else printf("Error!\n");
    return 0;
}
*/
//ex3.4 part2
/*
int main() {
    int num1, num2, num3, temp;
    printf("Enter 3 digits each one at a time and enter: \n");
    scanf("%d%d%d", &num1, &num2, &num3);
    if (num1 >= num2 && num2 >= num3) {       //num1 > num2 > num3  654
        temp = num3;
        num3 = num1;
        num1 = temp;
        printf("%d %d %d", num1, num2, num3);
    } else if (num3 >= num2 && num2 >= num1) { //num3 > num2 > num1  456
        printf("%d %d %d", num1, num2, num3);
    } else if (num2 >= num1 && num1 >= num3) { //num2 > num1 > num3  564
        temp = num3;
        num3 = num2;
        num2 = num1;
        num1 = temp;
        printf("%d %d %d", num1, num2, num3);
    } else if (num2 >= num3 && num3 >= num1) { // num2 > num3 > num1 465
        temp = num3;
        num3 = num2;
        num2 = temp;
        printf("%d %d %d", num1, num2, num3);
    } else if (num1 >= num3 && num3 >= num2) { //num1 > num3 > num2  645
        temp = num3;
        num3 = num1;
        num1 = num2;
        num2 = temp;
        printf("%d %d %d", num1, num2, num3);
    } else if (num3 >= num1 && num1 >= num2) { // num3 > num1 > num2 546
        temp = num2;
        num2 = num1;
        num1 = temp;
        printf("%d %d %d", num1, num2, num3);
    } else printf("Error!\n");

    return 0;
}
*/
//lab3.5
/*
int main() {
    float num1, num2, num3;
    printf("Enter 3 float numbers to check if it's a triangle:\n");
    scanf("%d%d%d", &num1, &num2, &num3);

    if ((num1 > 0) && (num2 > 0) && (num3 > 0) && ((num1 + num2) > num3) && ((num2 + num3) > num1) &&
        ((num1 + num3) > num2)) {
        printf("Triangle");
    } else printf("Not Triangle");


    return 0;
}
*/
//lab3.6
/*
int main() {
    int digit;
    printf("Enter a digit:\n");
    scanf("%d", &digit);

    switch (digit) {
        case 0:
            printf("-----\n");
            break;
        case 1:
            printf(".----\n");
            break;
        case 2:
            printf("..---\n");
            break;
        case 3:
            printf("...--\n");
            break;
        case 4:
            printf("....-\n");
            break;
        case 5:
            printf(".....\n");
            break;
        case 6:
            printf("-....\n");
            break;
        case 7:
            printf("--...\n");
            break;
        case 8:
            printf("---..\n");
            break;
        case 9:
            printf("----.\n");
            break;
        default:
            printf("Error input\n");
            break;
    }


    return 0;
}

 */
//lab3.7
/*
int main() {
    int day;
    printf("Enter a day between 1-7 to see the working hours:\n");
    scanf("%d", &day);

    switch (day) {
        case 1:
            printf("8:00-18:00\n");
            break;
        case 2:
            printf("8:00-18:00\n");
            break;
        case 3:
            printf("8:00-16:00\n");
            break;
        case 4:
            printf("8:00-18:00\n");
            break;
        case 5:
            printf("8:00-18:00\n");
            break;
        case 6:
            printf("8:00-13:00\n");
            break;
        case 7:
            printf("Holiday!\n");
            break;
        defualt:
            printf("Error input\n");
            break;
    }

    return 0;
}
 */
//---------
//lab4.1
/*
int main(){
    int num1, num2, res=1;

    printf("Enter two numbers to calculate the power:\n");
    scanf("%d%d", &num1, &num2);
    for(int i=0; i<num2; i++){ //2 3 = 8 2*2*2
        res*=num1;
    }
    printf("%d^%d=%d",num1, num2, res);

    return 0;
}
 */
//lab4.2
/*
int main() {
    float num, max = 0, min = 0;
    int firstInput = 1;
    printf("Enter float numbers to find min and max, 0 to exit: \n");

    do {
        scanf("%f", &num);

        if (firstInput) {
            if (num != 0) {
                min = num;
                firstInput = 0;
            }

        } else {

            if (num > max) {
                max = num;
            } else if (num < min && num != 0) {
                min = num;
            }
        }
    } while (num != 0);
    printf("Max: %.2f\n", max);
    printf("Min: %.2f\n", min);


    return 0;
}
 */
//lab4.3
/*
int main() {
    int count = 0;

    for (int i = 1000; i < 10000; i++) {

        if ((i % 7 == 0) && (i % 11 == 2 || i % 11 == 3) && (i % 10 != 8)) {
            count++;
        }
    }

    printf("%d", count);

    return 0;
}
 */
//lab4.4
/*
int main() {
    int num, a1 = 1, a2 = 1, a3;

    printf("Enter the number of elements:\n");
    scanf("%d", &num);
    printf("\n%d %d", a1, a2);

    for (int i = 2; i < num; i++) {
        a3 = a1 + a2;
        printf(" %d", a3);
        a1 = a2;
        a2 = a3;

    }

    return 0;
}
 */
//lab4.5
/*
int main() {
    int pre, num, count = 0, sum = 0;

    scanf("%d", &num);  //2
    pre = num - 1;

    while (num > pre){
    count++;
    sum += num;
    pre = num;
    scanf("%d", &num);
}


    printf("%d %.3f", count, (sum / (float)count));
return 0;
}
*/
//lab4.6
/*
int main() {
    int grade, counter = 0, sum = 0;

    printf("Enter grades:\n");
    scanf("%d", &grade);

    if (!((100 > grade) && (0 < grade))) {
        printf("Invalid grade\n");
    } else {

        while (((100 > grade) && (0 < grade))) {
            counter++;
            sum += grade;
            printf("Enter grades:\n");
            scanf("%d", &grade);

        }
        printf("Test!\n");
        printf("the average=%d\n", (sum / counter));
    }


    return 0;
}

*/
//lab4.7
/*
int main() {

    int i;
    for(i = 1; i<=100; i++){
        if(i%7==0){
            printf("BOOM\n");
        }
        else
            printf("%d ", i);
    }

    return 0;
}
*/
//lab4.8
/*
int main() {
    float money, products, price,sum, left;
    printf("Enter how much money you have:\n");
    scanf("%f", &money);
    printf("Enter how many products you want to buy:\n");
    scanf("%f", &products);

    for(int i = 0; i<products; i++){ //3

        printf("Insert product number %d price please:\n", i+1);
        scanf("%f", &price);
        sum += price;

    }
    left = money - sum;
    printf("Your left money: %.2f", left);



    return 0;
}
*/
//lab4.9
/*
int main() {
    int i;
    for (i = 0; i < 100; i++) {
        if (i % 6 == 0) {
            printf("%d ", i);
        }

    }


    return 0;
}
*/
//lab4.10
/*
int main() {
    char choice;
    scanf("%c", &choice);

    switch (choice) {
        case 'a':
            for (int i = 0; i <= 20; i++) {
                if (i % 2 == 0) {
                    printf("%d ", i);
                }
            }
            break;
        case 'b':
            for (int i = 20; i >= 0; i--) {
                if (i % 2 == 0) {
                    printf("%d ", i);
                }
            }
            break;
    }

    return 0;
}
*/
//---------
//lab5.1 MaxFinder
/*
int MaxFinder(int a, int b, int c) {
    int max = a;
    if (b > max) max = b;
    if (c > max) max = c;
    return max;

}

int main() {
    int a, b, c;
    printf("Enter 3 numbers to find the max:\n");
    scanf("%d%d%d", &a, &b, &c);
    printf("%d", MaxFinder(a, b, c));


    return 0;
}
 */
//lab5.2 Power
/*
int Power(int base, int exponent) {
    int power = 1;
    for (int i = 0; i < exponent; i++) {
        power *= base;
    }
    return power;

}

int main() {
    int a, b;
    printf("Enter two positive int nums:\n");
    scanf("%d%d", &a, &b);
    if (a >= 0 && b >= 0) {
        Power(a, b);
        printf("Power(%d,%d)=>%d\n", a, b, Power(a, b));
    } else
        printf("error invalid input!\n");


    return 0;
}
 */
//lab5.3 CountDigits
/*
int CountDigits(int long num) {
    int count = 0;

    while (num != 0) {

        num /= 10;
        count++;
    }
    return count;

}

int main() {
    int long num;
    printf("Enter a positive int num:\n");
    scanf("%ld", &num);
    if (num < 0) {
        printf("invalidate input\n");
    } else {
        CountDigits(num);
        long int digits = CountDigits(num);
        if (digits % 2 == 0) {
            printf("CountDigits(%ld)=>""even""\n", digits);
        } else
            printf("CountDigits(%ld)=>""odd""\n", digits);
    }

    return 0;
}

 */
//lab5.4 prime
/*
int isPrime(int num) {
    int count = 0;
    for (int i = 1; i <= num; i++) {
        if (num % i == 0) {
            count++;
        }
    }
    if (count == 2) {
        return 1;
    } else return 0;
}

int main() {
    int num;
    printf("Enter a positive integer num:\n");
    scanf("%d", &num);

    isPrime(num);

    printf("IsPrime(%d)=>%d", num, isPrime(num));

    return 0;
}
 */
//lab5.5 Calculator
/*
int Calculator(int a, int b, char c) {
    if (b == 0 && c == '/') {
    printf("can't divide by 0!\n");}
    else {
    int res;
    switch (c) {
        case '+':
            res = a + b;
            break;
        case '-':
            res = a - b;
            break;
        case '*':
            res = a * b;
            break;
        case '/':
            res = a / b;
            break;
        default:
            printf("invalid operand!!!\n");
            return 0;
    }
    return res;
}
}


int main() {
    int a, b;
    char c;
    printf("Calculator\ninsert a number an operand and a number:\n");
    scanf("%d%c%d", &a, &c, &b);

    Calculator(a, b, c);

    printf("Calculator(%d,%d,%c)=>%d", a, b, c, Calculator(a, b, c));

    return 0;
}
 */
//lab5.6 isPalindrome
/*
int isPalindrome(int num) {
    int remainder, reversed = 0;
    int original = num;

    while (num != 0) {
        remainder = num % 10;
        reversed = reversed * 10 + remainder;
        num /= 10;
    }
    if (original == reversed) {
        return 1;
    } else return 0;

}

int main() {
    int num;
    printf("Enter a number to find if it's a palindrome:\n");
    scanf("%d", &num);

    isPalindrome(num);

    printf("IsPalindrome(%d)=>%d", num, isPalindrome(num));

    return 0;
}
 */
//lab6.1
/*
long Sum(int number) {
    int power = 1, sum = 0;
    for (int i = 1; i <= number; ++i) { //2
    power = 1;
        for (int j = 1; j <= i; j++) {
            power *= i;
        }
        sum+=power;
    }
    return sum;
}
int main(){
    int num;
    scanf("%d",&num);
    printf("%d",Sum(num));
    return 0;
}
*/
//lab6.2
/*
int AscendingDigits(){
    int flag, num,count =0;
    for (int i = 10000; i < 100000; ++i) {
        flag = 1;
        num = i;
        while(num!=0){
            if(num%10<=num/10%10){
                flag = 0;
                break;
            }
            num/=10;
        }
        count+=flag;
    }
    return count;

}
int main(){

    printf("%d", AscendingDigits());
}
 */
//lab6.3
//      *
//     ***
//    *****
//   *******
/*
void PrintTriangle(int rows) {

    int row = 0, col = 0;

    printf("Enter the number of rows = ");
    scanf("%u", &rows);
    for (int row = 1; row <= rows; ++row) {
        // Print spaces
        for (int col = row; col <= rows; ++col) {
            printf(" ");
        }
        // Print star/
        for (int col = 1; col <= 2 * row - 1; ++col) {
            printf("*");
        }
        // Print new line
        printf("\n");
    }

}

int main() {

    PrintTriangle(3);


}
 */
//lab6.3
/*
void PrintDiamonds(int number) {
    int rows = number;
    for (int row = 1; row < rows; ++row) {

        for (int col = row; col <= rows; ++col) {
            printf(" ");
        }
        
    }


}

int main() {
    int number;
    PrintDiamonds(number);

    return 0;
}
 */

/*
#include <stdio.h>
#include <stdlib.h>

int isPrime(int num) {
    int count = 0;
    for (int i = 1; i <= num; i++) {
        if (num % i == 0) {
            count++;
        }
    }
    if (count == 2) {
        return 1;
    } else return 0;
}


int* Primes(int* ar, int size, int* pSize) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (isPrime(ar[i]))
            count++;
    }
    *pSize = count;
    if (count == 0) {
        *pSize = 0;
        return NULL;
    }

    int* primes = malloc(count * sizeof(int));
    if (primes == NULL) {
        *pSize = 0;
        return NULL;
    }

    int index = 0;
    for (int i = 0; i < size; ++i) {
        if (isPrime(ar[i]))
            primes[index++] = ar[i];
    }


    return primes;
}

int main() {
    int arr1[] = {3, 7, 89, 33, 4, 7, 888, 32, 6, 3};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int* pSize1 = malloc(sizeof(int));
    int* primes1 = Primes(arr1, size1, pSize1);
    printf("Prime numbers in arr1: ");
    for (int i = 0; i < *pSize1; i++) {
        printf("%d ", primes1[i]);
    }
    printf("\n");
    free(pSize1);
    free(primes1);

    int arr2[] = {280, 8, 348, 90, 4, 22, 888, 40, 6, 10};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int* pSize2 = malloc(sizeof(int));
    int* primes2 = Primes(arr2, size2, pSize2);
    if (primes2 == NULL) {
        printf("No prime numbers found in arr2.\n");
    } else {
        printf("Prime numbers in arr2: ");
        for (int i = 0; i < *pSize2; i++) {
            printf("%d ", primes2[i]);
        }
        printf("\n");
        free(primes2);
    }
    free(pSize2);

    return 0;
}
*/
/*
#include <stdio.h>
#include <stdlib.h>

int* Reduce(int* arr, int size, int* newSize) {
    int* reducedArr = malloc(size * sizeof(int));
    if (reducedArr == NULL) {
        *newSize = 0;
        return NULL;
    }

    int count = 0;
    for (int i = 0; i < size; i++) {
        int isUnique = 1;
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                isUnique = 0;
                break;
            }
        }
        if (isUnique) {
            reducedArr[count++] = arr[i];
        }
    }

    *newSize = count;
    return realloc(reducedArr, count * sizeof(int));
}

int main() {
    int arr[] = {7, 8, 16, 3, 7, 16, 8, 7, 16};
    int size = sizeof(arr) / sizeof(arr[0]);

    int newSize;
    int* reducedArr = Reduce(arr, size, &newSize);

    if (reducedArr != NULL) {
        printf("Reduced array: ");
        for (int i = 0; i < newSize; i++) {
            printf("%d ", reducedArr[i]);
        }
        printf("\n");
        free(reducedArr);
    } else {
        printf("Memory allocation failed.\n");
    }

    return 0;
}


int *GreaterVal(int *ar, int size, int value, int*pSize){
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (ar[i] > value)
            count++;
    }
    *pSize = count;

    if (count == 0) {
        *pSize = 0;
        return NULL;
    }

    int* newArr = malloc(count * sizeof(int));
    if (newArr == NULL) {
        *pSize = 0;
        return NULL;
    }

    int index = 0;
    for (int i = 0; i < size; ++i) {
        if ((ar[i])>value)
            newArr[index++] = i;
    }


    return newArr;
}
*/
/*
#include <stdio.h>
#include <stdlib.h>

int* Reduce(int* arr, int size, int* newSize) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        int isUnique = 1;
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                isUnique = 0;
                break;
            }
        }
        if (isUnique) {
            count++;
        }
    }
    *newSize = count;
    if (count == 0) {
        *newSize = 0;
        return NULL;
    }


    int* reducedArr = malloc(count * sizeof(int));
    if (reducedArr == NULL) {
        *newSize = 0;
        return NULL;
    }

    int index = 0;
    for (int i = 0; i < size; i++) {
        int isUnique = 1;
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                isUnique = 0;
                break;
            }
        }
        if (isUnique) {
            reducedArr[index++] = arr[i];
        }
    }


    return reducedArr;
}

int main() {
    int arr[] = {7, 8, 16, 3, 7, 16, 8, 7, 16};
    int size = sizeof(arr) / sizeof(arr[0]);

    int newSize;
    int* reducedArr = Reduce(arr, size, &newSize);

    if (reducedArr != NULL) {
        printf("Reduced array: ");
        for (int i = 0; i < newSize; i++) {
            printf("%d ", reducedArr[i]);
        }
        printf("\n");
        free(reducedArr);
    } else {
        printf("Memory allocation failed.\n");
    }

    return 0;
}
*/
/*
#include <stdio.h>
#include <stdlib.h>

int* DividedByValue(int* ar, int size, int value, int* pSize) {
    int count = 0;

    for (int i = 0; i < size; ++i) {
        if (ar[i] % value == 0)
            count++;
    }
    *pSize = count;

    if (count == 0) {
        *pSize = 0;
        return NULL;
    }

    int* newArr = malloc(count * sizeof(int));
    if (newArr == NULL) {
        *pSize = 0;
        return NULL;
    }

    int index = 0;
    for (int i = 0; i < size; ++i) {
        if (ar[i] % value == 0)
            newArr[index++] = i;
    }

    return newArr;
}

int main() {
    int arr[] = {49, 70, 125, 35, 27, 6, 50, 14};
    int size = sizeof(arr) / sizeof(arr[0]);
    int pSize = 0;

    int* result = DividedByValue(arr, size, 7, &pSize);

    printf("Indices divisible by 7: ");
    for (int i = 0; i < pSize; ++i) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);

    return 0;
}
*/
/*
#include <stdio.h>
#include <stdlib.h>

int* CommonIndexes(int* ar, int size, int* pSize) {
    int count[10] = {0}; // Assuming elements are between 0-9

    // Count the occurrences of each element
    for (int i = 0; i < size; ++i) {
        count[ar[i]]++;
    }

    // Find the maximum count
    int maxCount = 0;
    for (int i = 0; i < size; ++i) {
        if (count[i] > maxCount) {
            maxCount = count[i];
        }
    }
    *pSize = maxCount;
    if(maxCount==0){
        *pSize = 0;
        return NULL;
    }

    // Find the indices where the most common element occurs
    int* newArr = malloc(maxCount * sizeof(int));
    if (newArr == NULL) {
        *pSize = 0;
        return NULL;
    }

    int index = 0;
    for (int i = 0; i < size; ++i) {
        if (count[ar[i]] == maxCount) {
            newArr[index++] = i;
        }
    }

    return newArr;
}

int main() {
    int arr[] = {7, 8, 7, 3, 7, 7, 8, 3, 6, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    int pSize = 0;

    int* result = CommonIndexes(arr, size, &pSize);

    printf("Indices of the most common element: ");
    for (int i = 0; i < pSize; ++i) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);

    return 0;
}
*/


/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 4

int Unique(int mat[SIZE][SIZE], int num) {
    int count = 0;
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            if (mat[i][j] == num)
                count++;
}


int SumUpDown(int mat[SIZE][SIZE]) {
    int sumUp = 0, sumDown = 0;


    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i < j) {
                sumUp += mat[i][j];
            }
            if (i > j) {
                sumDown += mat[i][j];
            }
        }
    }

    printf("%d %d\n", sumUp, sumDown);

    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (Unique(mat, mat[i][j]) != 1)
                return 0;
    return 1;

}

int main() {
    int mat[SIZE][SIZE] = {
            {5,  7,  14, 33},
            {4,  3,  12, 1},
            {11, 22, 43, 44},
            {10, 6,  15, 2}
    };
    SumUpDown(mat);
    if(SumUpDown(mat)){
        printf("1");}
    else
        printf("0");



    return 0;
}
*/

/*
#include <stdio.h>

#define SIZE 4

int MinMax(int mat[SIZE][SIZE]) {
    int minLine = 0, maxColumn = 0, sumLine = 0, sumColumn = 0;

    // Calculate minimum sum of lines
    for (int i = 0; i < SIZE; i++) {
        sumLine = 0;
        for (int j = 0; j < SIZE; j++) {
            sumLine += mat[i][j];
        }
        if (minLine > sumLine || i == 0) {
            minLine = sumLine;
        }
    }

    // Calculate maximum sum of columns
    for (int j = 0; j < SIZE; j++) {
        sumColumn = 0;
        for (int i = 0; i < SIZE; i++) {
            sumColumn += mat[i][j];
        }
        if (maxColumn < sumColumn || j == 0) {
            maxColumn = sumColumn;
        }
    }
    printf("%d %d\n", minLine, maxColumn);
    return minLine + maxColumn;
}

int main() {
    int mat[SIZE][SIZE] = {
            {5, 7, 4, 33},
            {4, 3, 2, 1},
            {11, 22, 33, 44},
            {10, 6, 5, 2}
    };

    int result = MinMax(mat);

    printf("Result: %d\n", result);

    return 0;
}
*/
/*
#include <stdio.h>

#define SIZE 5

int Range(int mat[][SIZE], int low, int high) {
    int count = 0;
    int lineCount = 0, columnCount = 0;

    // Count numbers and check lines and columns in range
    for (int i = 0; i < SIZE; i++) {
        int lineInRange = 1;
        int columnInRange = 1;

        for (int j = 0; j < SIZE; j++) {
            int num = mat[i][j];

            if (num >= low && num <= high) {
                count++;
            }

            if (lineInRange && (num < low || num > high)) {
                lineInRange = 0;
            }

            if (columnInRange && (mat[j][i] < low || mat[j][i] > high)) {
                columnInRange = 0;
            }
        }

        if (lineInRange) {
            lineCount++;
        }

        if (columnInRange) {
            columnCount++;
        }
    }

    // Print number of lines and columns in range
    printf("Number of lines in range (%d - %d): %d\n", low, high, lineCount);
    printf("Number of columns in range (%d - %d): %d\n", low, high, columnCount);

    return count;
}

int main() {
    int mat[SIZE][SIZE] = {
            {23, 26, 34, 30, 22},
            {87, 47, 36, 32, 77},
            {11, 12, 31, 66, 15},
            {61, 17, 22, 44, 20},
            {21, 33, 23, 24, 34},
    };

    int low = 20, high = 40;
    int count = Range(mat, low, high);

    printf("Count of numbers in range (%d - %d): %d\n", low, high, count);

    return 0;
}
*/
/*
#define SIZE 5

int SumMaxInRow(int mat[][SIZE]){
    int sumMax = 0;

    for (int i = 0; i < SIZE; ++i) {
        int max = 0;
        for (int j = 0; j < SIZE; ++j) {
            max = mat[i][j];

            if(max<mat[i][j])
                max = mat[i][j];
        }
        sumMax+=max;
    }
    return sumMax;


}

 */

/*
#include <stdio.h>

#define SIZE 5

int SumMaxInRow(int mat[][SIZE]) {
    int sumMax = 0;

    for (int i = 0; i < SIZE; ++i) {
        int max = mat[i][0]; // Initialize max with the first element in the row

        for (int j = 1; j < SIZE; ++j) {
            if (mat[i][j] > max) {
                max = mat[i][j]; // Update max if a greater element is found
            }
        }

        sumMax += max;
    }

    return sumMax;
}

int main() {
    int mat[SIZE][SIZE] = {
            {30, 20, 65, 62, 13},
            {100, 77, 23, 90, 9},
            {70, 20, 30, 30, 44},
            {10, 93, 7, 12, 44},
            {40, 50, 39, 50, 90},
    };

    int result = SumMaxInRow(mat);
    printf("Sum of maximum elements in each row: %d\n", result);

    return 0;
}
*/
/*
#define SIZE 4

int g(int mat[][SIZE]) {
    int sumCol = 0, sumDesDiag = 0, sumAscDiag = 0;

    for (int i = 0; i < SIZE; ++i) {
        int sumRow = 0;
        for (int j = 0; j < SIZE; ++j) {
            int num = mat[i][j];
            if (num == 0)
                sumRow += num;

            if (mat[j][i] == 0)
                sumCol += mat[j][i];

            if (num == 0 && i == j)
                sumDesDiag += num;

            if (i + j == (SIZE - 1) && num == 0)
                sumAscDiag += num;
        }
        if (sumRow == 0) return 1;
        else if (sumCol == 0) return 1;
        else if (sumAscDiag == 0) return 1;
        else if (sumDesDiag == 0) return 1;

    }


}

*/
/*
#include <stdio.h>

#define SIZE 4

int g(int mat[][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        int rowZeros = 1;  // Assume the current row contains only zeros
        int colZeros = 1;  // Assume the current column contains only zeros
        int ascDiagZeros = 1;  // Assume the ascending diagonal contains only zeros
        int desDiagZeros = 1;  // Assume the descending diagonal contains only zeros

        for (int j = 0; j < SIZE; ++j) {
            // Check the current row
            if (mat[i][j] != 0) {
                rowZeros = 0;  // Found a non-zero element in the row
                break;
            }

            // Check the current column
            if (mat[j][i] != 0) {
                colZeros = 0;  // Found a non-zero element in the column
                break;
            }

            // Check the ascending diagonal
            if (i == j && mat[i][j] != 0) {
                ascDiagZeros = 0;  // Found a non-zero element in the ascending diagonal
                break;
            }

            // Check the descending diagonal
            if (i + j == SIZE - 1 && mat[i][j] != 0) {
                desDiagZeros = 0;  // Found a non-zero element in the descending diagonal
                break;
            }
        }

        // If any of the checks fail, return 0
        if (!rowZeros || !colZeros || !ascDiagZeros || !desDiagZeros) {
            return 0;
        }
    }

    // If no row, column, or diagonal contains only zeros, return 1
    return 1;
}

int main() {
    int mat[SIZE][SIZE] = {
            {0, 1, 0, 1},
            {1, 0, 0, 0},
            {1, 0, 0, 0},
            {1, 1, 1, 0}
    };

    int result = g(mat);
    printf("Result: %d\n", result);

}
 */
/*
#include <stdio.h>

#define N 4


int CheckRow(int mat[N][N]) {
    int flag = 0;
    for (int i = 0; i < N; i++) {
        flag = 0;
        for (int j = 0; j < N; ++j) {
            if (mat[i][j] != 0)
                flag = 1;
        }
        if (!(flag))
            return 1;
    }
    return 0;
}

int CheckColumn(int mat[N][N]) {
    int flag = 0;
    for (int i = 0; i < N; ++i) {
        flag = 0;
        for (int j = 0; j < N; ++j) {
            if (mat[j][i] != 0)
                flag = 1;
        }
        if (!flag)
            return 1;
    }
    return 0;
}

int CheckDiagonal(int mat[][N]) {
    for (int i = 0; i < N; ++i) {
        if (mat[i][i] != 0)
            return 0;
    }
    return 1;
}

int CheckReverseDiagonal(int mat[][N]) {
    for (int i = N - 1; i > 0; --i) {
        if (mat[i][N - i - 1] != 0)
            return 0;
    }
    return 1;
}

int CheckMat(int mat[N][N]) {
    if (CheckRow(mat))
        return 1;
    if (CheckColumn(mat))
        return 1;
    if (CheckDiagonal(mat))
        return 1;
    if (CheckReverseDiagonal(mat))
        return 1;

    return 0;
}

int main() {
    int mat[N][N] = {
            {0, 1, 0, 1},
            {1, 0, 0, 0},
            {1, 0, 0, 0},
            {1, 1, 1, 1}
    };

    int result = CheckMat(mat);
    printf("Result: %d\n", result);

}
*/

#include <stdio.h>

void Encode(const char source[], char destination[]) {
    int i = 0;
    while (source[i] != '\0') {


        // Encrypt uppercase letters
        if (source[i] >= 'A' && source[i] <= 'Z') {
            destination[i] = (source[i]+ 1) ;
        }
            // Encrypt lowercase letters
        else if (source[i] >= 'a' && source[i] <= 'z') {
            destination[i] = (source[i]  + 1);
        }
            // Copy non-letter characters as is
        else {
            destination[i] = source[i];
        }

        i++;
    }

    destination[i] = '\0';  // Add null terminator to the destination string
}

int main() {
    const char source[] = "CProgrammingLanguage";
    char destination[50];  // Assuming destination has enough space to hold the encrypted string

    Encode(source, destination);
    printf("Encrypted string: %s\n", destination);

    return 0;
}
