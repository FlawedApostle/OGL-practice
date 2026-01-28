#pragma once
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

//* Declerations !! */
//ArrayLife arraylife;
//ArrayLife::VecArr veclife;
//ArrayLife::Numbs numbs;


class ArrayLife
{
private:
	bool inputYes = true;
	bool inputNo = false;

public:
	
	// ************* constructs ****************/
	//ArrayLife();
///**************************************************
	//* Statics
	static const int zeroStatic = 0;
	static const int ten = 10;
	//bool input_ = input;
	//*Arr init
	int arr[ten];		// this should be a struct the amount of errs tho i would get to move it is.... just, just... its not funny so we leave it here !!

	struct Numbs
	{	
		int zero = 0;
		int one = 1;
		int five = 5;
	};

	struct VecArr
	{
		vector<int> Numbers{};

	};
	
	struct UserInput
	{
		char userInChar;
		int userInInt;
		std::string userInString;
	};


	void buildArr();

	void buildArrChronilogical();

	void printArr3();
	void printArr();
	void printArrFuckery();
	void printArrBackwards();
	void VectorArrInit();
	void VectorArrPrint();
	void VectorArrInput();
	void Finished();





};
