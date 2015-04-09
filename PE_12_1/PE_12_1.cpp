#include "stdafx.h"
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::swap;

// ** CONSTANTS ** //
const int MAX_STRING_SIZE = 100;


// ** FORWARD DECLARATION ** //
void print_menu();
void menu_string_rev(char * _str);
void menu_string_delete(char * _str);
void menu_string_insert(char * _str);
void menu_string_to_substring(char * _str);
void menu_string_comp(char * _str);

void string_copy(char * _dest, char * _src);
void string_copy(char * _dest, char * _src, int _numchars);
int string_len(char * _str);
bool string_cat(char * _dest, char * _src);
void string_rev(char * _str);
void string_delete(char * _str, int _start, int _numchars);
bool string_insert(char * _str1, char * _str2, int _pos);
void string_to_substring(char * _str, int _start, int _numchars);
bool string_comp(char * _str1, char * _str2, bool _sensitive);

char to_upper(char _chr);
void get_input(char *_input, int _size = MAX_STRING_SIZE);
void get_input(int *_input, int _default = 0);
void wait_for_input();
void clean_input();



int _tmain(int argc, _TCHAR* argv[])
{
	bool done = false;
	int input;

	char str_main[MAX_STRING_SIZE] = "Bob*";//"may a moody baby doom a yam"; //"never odd or even";//"senile felines";//"no x in nixon";//"too bad i hid a boot";

	while (!done)
	{
		print_menu();
		get_input(&input);

		//string_copy(str_main, "rats live on no evil star");
		switch (int(input))
		{
			case 1:
				cout << "\nEnter a string to manipulate:";
				get_input(str_main);
			break;
			case 2:

			break;
			case 3:

			break;
			case 4:

			break;
			case 5:

			break;
			case 6:
				menu_string_rev(str_main);
			break;
			case 7:
				menu_string_comp(str_main);
			break;
			case 8:
				menu_string_delete(str_main);
			break;
			case 9:
				menu_string_insert(str_main);
			break;
			case 10:
				menu_string_to_substring(str_main);
			break;
			case 11:

			break;
			case 12:
				cout << "\nGoodbye!" << endl;
				done = true;
			break;

			default:
				cout << "\nInvalid Input! Please enter a number from 1-12." << endl;
			break;
		}

		wait_for_input();
	}
	
	return 0;
}

// ** MENU FUNCTIONS ** //
void print_menu()
{
	cout << "\n\t\tString Manipulation\n---------------------------------------------------------"
		<< "\n1. Input String"
		<< "\n2. Copy" 
		<< "\n3. Concatenate" 
		<< "\n4. Find Length" 
		<< "\n5. Find Substring"
		<< "\n6. Reverse"
		<< "\n7. Case Insensitive Compare"
		<< "\n8. Delete Portion"
		<< "\n9. Insert"
		<< "\n10. Create Substring"
		<< "\n11. Find Index"
		<< "\n12. Quit" << endl;
}

void menu_string_rev(char * _str)
{
	cout << "\nReversing:\t" << _str;
	string_rev(_str);
	cout << "\nResult:\t\t" << _str << endl;
}

void menu_string_delete(char * _str)
{
	int start = 0;
	int numchars = 0;

	cout << "\n" << _str;
	cout << "\n\nDelete portion starting at position: ";
	cin >> start;
	clean_input();

	cout << "\nDelete how many characters after? ";
	cin >> numchars;
	clean_input();

	string_delete(_str, start-1, numchars);

	cout << "\nResult: " << _str << endl;
}
void menu_string_insert(char * _str)
{
	int pos = 0;
	char insert[MAX_STRING_SIZE] = { '\0' };

	cout << "\n" << _str
		<< "\n\nInsert a string into position: ";
	cin >> pos;
	clean_input();

	cout << "\nString to insert? ";
	get_input(insert);

	string_insert(_str, insert, pos - 1);

	cout << "\nResult: " << _str << endl;
}

void menu_string_to_substring(char * _str)
{
	int start = 0;
	int numchars = 0;

	cout << "\n" << _str;
	cout << "\n\nTurn string into a substring starting at position: ";
	cin >> start;
	clean_input();

	cout << "\nContinuing till how many characters after? ";
	cin >> numchars;
	clean_input();

	string_copy(_str, _str + (start - 1), numchars);

	cout << "\nResult: " << _str << endl;
}

void menu_string_comp(char * _str)
{
	char compare[MAX_STRING_SIZE] = { '\0' };
	get_input(compare);

	cout << "\n" << ((string_comp(_str, compare, false)) ? "Equal!" : "Not Equal!");
}

// ** PROGRAM FUNCTIONS ** //


// ** string manipulation ** //
void string_copy(char * _dest, char * _src)
{
	while (*_dest++ = *_src++);
}
void string_copy(char * _dest, char * _src, int _numchars)
{
	int counter = 0;
	while ((counter++ <_numchars) && (*_dest++ = *_src++));
	*_dest = '\0';
}

int string_len(char * _str)
{
	char * strlen = _str;

	while (*strlen++ != '\0');

	return (strlen - _str - 1);
}

bool string_cat(char * _dest, char * _src)
{
	char * last_char = _dest + string_len(_dest);							//holds the position of the last char ('\0') in _dest
	int remaining_chars = (MAX_STRING_SIZE - string_len(_dest)) - 1;		//holds the max number of chars that can be added to _dest.

	if (remaining_chars < string_len(_src))
		return false;

	string_copy(last_char, _src);
	return true;
}

void string_rev(char * _str)
{
	char * end = _str + string_len(_str) - 1;
	int mid = string_len(_str) / 2;
	

	for (int i = 0; i < mid; i++)
		swap(*(_str + i), *(end - i));
}

void string_delete(char * _str, int _start, int _numchars)
{
	string_copy(_str + _start, _str + _start + _numchars);
}

bool string_insert(char * _str1, char * _str2, int _pos)
{
	if ((string_len(_str1) + string_len(_str2)) > MAX_STRING_SIZE)
		return false;

	char endstring[MAX_STRING_SIZE] = { '\0' };
	string_copy(endstring, _str1 + _pos);

	string_copy(_str1 + _pos, _str2);
	string_cat(_str1, endstring);
	return true;
}

void string_to_substring(char * _str, int _start, int _numchars)
{
	string_copy(_str, _str + _start, _numchars);
}

bool string_comp(char * _str1, char * _str2, bool _sensitive)
{
	if (string_len(_str1) != string_len(_str2))
		return false;

	int length = string_len(_str1);
	int counter = 0;
	if (_sensitive)
		while ((counter++ < length) && (*_str1++ == *_str2++));
	else
		while ((counter++ < length) && (to_upper(*_str1++) == to_upper(*_str2++)));

	return ((counter - 1) == length);
}


// ** UTILITY FUNCTIONS ** //
char to_upper(char _chr)
{
	return ((_chr >= 'a' && _chr <= 'z') ? char(_chr + ('A'-'a')) : _chr);
}

void get_input(char *_input, int _size)
{
	//int size = int(sizeof(_input) / sizeof(char));

	cout << "\nInput: ";
	cin.getline(_input, _size, '\n');
	clean_input();
}
void get_input(int *_input, int _default)
{
	//in case user enters char instead of int
	*_input = _default;

	cout << "\nInput: ";
	cin >> *_input;
	clean_input();
}

void wait_for_input()
{
	clean_input();

	cout << endl << "Press \"Enter\" to continue...";
	char str[2];
	cin.getline(str, 1, '\n');
	cout << endl;

	clean_input();
}

void clean_input()
{
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
}