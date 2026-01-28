
//#define CHECK1(x, ...) if (!(x)) { printf(__VA_ARGS__); }
//#define CHECK2(x, ...) if ((x)) { printf(__VA_ARGS__); }
//#define CHECK3(...) { printf(__VA_ARGS__); }
//#define MACRO(s, ...) printf(s, __VA_ARGS__)
#define LOG(...) cout
#define FOO(...) printf(__VA_ARGS__)
#define Print(...) printf(__VA_ARGS__)
#define EMPTY

#include <iostream>
#include <stdio.h>
#include <array>
#include <vector>
#include <algorithm>    // std::random_shuffle
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std;

#include "ArrayLife.h"

//* Declerations !! */
ArrayLife arraylife;
ArrayLife::VecArr veclife;
ArrayLife::Numbs numbs;
ArrayLife::UserInput userinput;
///*************************/

//************VARS****************/
//static const int zero = 0;
//int zeroAdd = 0;
//const int ten = 10;
////*Arr init
//int arr[ten];
///************Vars****************/

// Build arr statically - boring ! */
void ArrayLife::buildArr()
{
    arr[0] = 1;
    arr[1] = 4;
    arr[2] = 3;
    arr[3] = 2;
    arr[4] = 1;
    arr[5] = 4;
    arr[6] = 3;
    arr[7] = 2;
    arr[8] = 1;
    arr[9] = 4;
    //arr[10] = 3;
}
/* Build array chronilogically with for loop */
void ArrayLife::buildArrChronilogical()
{
    int one = 1; int zero = 0; int nine = 9; int x = 0;
    for (zero; zero <= nine; zero++)
    {
        arr[x++] = x + 1;
    }

}
//*Print arr only first 3 index(s)/ndices */
void ArrayLife::printArr3()
{
    for (int x = 0; x <= 3; x++)
    {
        std::cout << ArrayLife::arr[x] << ' ';
    }
}
//*Print arr */
// -> calling buildArr (static) // 1 , 4 , 3 , 2
void ArrayLife::printArr()
{   
    for (int x = 0; x <= 9; x++)
    {      
        //printf("this is the arr index [%i]\n" , x);             // calls index         
        printf(" arr[%i] " , x); printf("Index value is :%i\n", arr[x]);
    }
}
//*Fuck arr */
void ArrayLife::printArrFuckery()
{
    int three = 3;
    int x = 0;
    int num;
    for (x; x <= 10; x++)
    {
        arr[x];
    
        switch (x)
        {
        case 5:
            arr[5] = 5;
            printf("arr[5] changed from arr[%i]", arr[x]);
            break;
        case 7:
            arr[7] = 7;
            break;
        case 8:         
            arr[x - 3] = 12;   // 8 - 3 = 5 arr[5] == 12 now.
            // have to subtract 3 regarding -> arr[x - 3] <-, 
            // x is counting up via for loop ,
            // x == 8 atm , 
            // x - 3 ,
            // (8 - 3) == 5 ,
            // x = 5 ,
            // arr[5] 
            printf(" to arr[%i]\n" , arr[x - 3]); 
            break;
        case 9:
            arr[9] = x * 3;
            printf("arr[9] = %i\n", arr[9]);
            break;
        }
    }



}
//* Print arr backwards */
void ArrayLife::printArrBackwards()
{
    int ten = 10; int zero = 0; int nine = 9;
    for (nine; nine >= zero; nine--)
    {
        std::cout << arr[nine] << ' ';
    }

}
//* VectorArrPrint */
void ArrayLife::VectorArrInit()
{
    for(numbs.zero; numbs.zero <= numbs.five; numbs.zero++)
    {
        veclife.Numbers.push_back(numbs.zero);
        cout << numbs.zero << ' ';
    }
}
//* Vector Arr Print _> rem Numbers vec array won't print if its not initialized , 
// either populate the Vec array , 
// or run the VectorArrInit to populate Numbers vector array.
void ArrayLife::VectorArrPrint()
{
    int x = 0;
    for (x; x < veclife.Numbers.size(); x++)
    {
        printf("Numbers_Index[%i]: ", x);
        cout << veclife.Numbers[x] << ' ';
        cout << endl;
    }
}
///* Vector Arr User input 
// -> User inputs numbers , 
// numbs are placed into a vec array , 
// the numbs are printed on console with the associated array index followed by the user input(ed) value
// Notes.. Yeah I noticed the time too , time for a break !! .... 0_<
/// _________> working as of 4:20 April 3 , 2024 *///
void ArrayLife::VectorArrInput()
{
    cout << "Enter an int:";
    cin >> userinput.userInInt;
    veclife.Numbers.push_back(userinput.userInInt);

    char yes = 'y';
    char no = 'n';

    cout << "Do you wish to continue?";
    cin >> userinput.userInChar;

    switch (userinput.userInChar)
    {
    case'y':
        arraylife.VectorArrInput();
        break;

    case 'n':
        arraylife.VectorArrPrint();
        break;
       
    default: 
            { 
                    
                    
                        cout << "enter a char!" << endl;
                        // It is what it is ! ,
                        // if you put it into a function seperately then yeah ,
                        // maybe you can recurse back to the _> "Do you wish to continue" ,
                        // for now It is what it is !! 
                        arraylife.VectorArrInput();
            }
    
    }


}
///* This functions is unfinished, its supposed to be recursive ,
// so if the user inputs an int instead of a char it will return an error ,
// saying input a char! ,
// and then go back to asking the user if they are finished
void ArrayLife::Finished()
{
    cout << "Are you finished?" << endl;
    cin >> userinput.userInChar;
    if (userinput.userInChar == 'n')
    {
        arraylife.VectorArrInput();
    }
    if (userinput.userInChar == 'y')
    {
    arraylife.VectorArrPrint();
    }


    //std::cout << inputYes << std::endl;
    //std::cout << inputNo << std::endl;
}

//* Dec Notes....!! DO NOT UNCOMMENT*/
//ArrayLife arraylife;
//ArrayLife::VecArr veclife;
//ArrayLife::Numbs numbs;
//ArrayLife::UserInput userinput;
///*************************/
//int main()
//{
    //arraylife.VectorArrInput();
    //arraylife.VectorArrInit();
    //arraylife.VectorArrPrint();
    //veclife.Numbers.push_back(20);
    //arraylife.VectorArrInit(); 
    //cout << endl;

///************* Array Shuffle ********************************
    //vector<int> vec = { 1,2,3,4,5,6,7,8,9 };
    //random_shuffle(vec.begin(), vec.end());
    //cout << "Updated vector: ";
    //for (int x : vec)
    //    cout << x << " ";
///*************************************************************

//    ArrayLife AL;
//    //buildArr();
//    AL.buildArrChronilogical();
//    //printArrFuckery();
//    AL.printArrBackwards();
//    cout << endl;
//    AL.printArr();
//    std::cout << std::endl;
    //std::cout << "printArr3" << " : ";  printArr3(); 
    //std::cout << std::endl;
    //std::cout << "printArrFuckery" << " : ";   printArrFuckery();

///******************************************************************************/
    //FOO("Hello from #define land !!\n");
    //Print("STD Test - Yeah I hear the name !\n");
    

    //CHECK1(0, "here %s %s %s", "are", "some", "varargs1(1)\n");
    //CHECK1(0, "here %s %s %s", "are", "some", "varargs1(2)\n");   // won't print
    //CHECK2(0, "here %s %s %s", "are", "some", "varargs2(3)\n");   // won't print
    //CHECK2(1, "here %s %s %s", "are", "some", "varargs2(4)\n");
    //// always invokes printf in the macro
    //CHECK3("here %s %s %s", "are", "some", "varargs3(5)\n");
    //MACRO("hello, world\n");
///******************************************************************************/



//}