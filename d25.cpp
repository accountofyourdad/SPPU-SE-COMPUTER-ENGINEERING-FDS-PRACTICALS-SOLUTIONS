
/*

A palindrome is a string of character that‘s the same forward and backward. Typically, punctuation, capitalization,
and spaces are ignored. For example, “Poor Dan is in a droop” is a palindrome, as can be seen by examining the characters
“poor danisina droop” and observing that they are the same forward and backward. One way to check for a palindrome is to reverse
the characters in the string and then compare with them the original-in a palindrome, the sequence will be identical. Write C++ program
with functions-
a) To print original string followed by reversed string using stack
b) To check whether given string is palindrome or not

*/

#include <iostream>
#include <string.h>
#define max 50 // defined	max 50 for using it for stack size
using namespace std;

class STACK
{
private:
	char a[max];
	int top;

public:
	STACK()
	{
		top = -1;
	}

	void push(char);
	void reverse();
	void convert(char[]);
	void palindrome();
};

void STACK::push(char c)
{
	top++; // to be incremented first as if used this fn in empty condition of stack -1 index will get the input value so increment so that it will become 0
	a[top] = c;
	a[top + 1] = '\0'; // making the next element of the top null of the stack ias nothing yet inserted there

	cout << endl
		 << c << " is pushed on stack ...";
}

void STACK::reverse()
{
	cout << "\n\nReverse string is : ";
	for (int i = top; i >= 0; i--)
	{
		cout << a[i];
	}
	cout << endl;
}

void STACK::convert(char str[]) // str is taken as argument
{
	int j, k, len = strlen(str);

	for (j = 0, k = 0; j < len; j++)
	{ // any of this ----|---------------condition------------|----------- true than go in if as used or and need to be in the range of the numbers as is && if any is zero ans is zero
		if (((int)str[j] >= 97 && (int)str[j] <= 122) || ((int)str[j] >= 65 && (int)str[j] <= 90))
		{//    ^--------------------^-----------------------^--------------------^--------------- typecasting from char to int for further process
			if ((int)str[j] <= 90) // smaller than or equal to 90 means they are capital letters
			{
				str[k] = (char)((int)str[j] + 32); // if my letter is "A" than its int is 65 if i add 32 it will become 97 that is "a"
			} // 			^----type casting done from int to agin char
			else
			{
				str[k] = str[j]; // here it means that the elements are already in small letters so no need to do any thing
			}

			k++; // if this if condition satisfy than only we are gona add it in that position of j note that our input willonly be alphabet so "k" will be with "j"
			// when space comes than j goes ahead and k is that much spaces(areas) behind and at final we will have string without spaces for checking is it palendrome
		}
	}
	str[k] = '\0'; // this to be like this only			at end initialize top ele to "\0" 	as some element i.e the spaces have been removed so make it null

	cout << endl
		 << "Converted String : " << str << "\n"; // here original string is modified so no need to return
}

void STACK::palindrome()
{
	char str[max];
	int i, j;

	for (i = top, j = 0; i >= 0; i--, j++)
	{
		str[j] = a[i];
	}
	str[j] = '\0'; // this to be like this only

	if (strcmp(str, a) == 0) // strcmp returns 0 if two string are same
		cout << "\n\nString is palindrome...";
	else
		cout << "\n\nString is not palindrome...";
}

int main()
{
	STACK stack;

	char str[max]; // this is for operation purpose 		main string is inside STACK class
	int i = 0;

	cout << "\nEnter string to be reversed and check is it palindrome or not : \n\n";

	cin.getline(str, 50); // generally while taking input in char arrey we tale cin.getline(str_array_name,length)

	stack.convert(str); // now this got string eill de pudhed in the main string(a) inside the class

	while (str[i] != '\0')	//got converteg string(all we have is in small letter)
	{
		stack.push(str[i]); // single single letter pushed to main arrey(string(a))
		i++;
	}

	stack.palindrome(); // check palendrome

	stack.reverse(); // reverse function for printing
}
