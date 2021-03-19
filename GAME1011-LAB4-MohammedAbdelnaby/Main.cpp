#include <iostream>
#include <string>
#include <vector>
using namespace std;

void reverseString(string string);
void quickSort(int array[],int start, int end);
bool palindromeString(string string, int start, int end);
int partition(int array[], int low, int high);

int main()
{
	unsigned short int userInput;
	string a;
	string stringInput;
	int test[5] = { 3,4 ,5,1,2 };
	cout << "Choose one of the options:" << endl;
	cout << "1) Palindrome" << endl;
	cout << "2) Quicksort" << endl;
	cout << "3) Reverse" << endl;
	cout << "4) Exit" << endl;
	cin >> userInput;
	system("CLS");
	switch (userInput)
	{
	case 1:
		cout << "Enter a word that you want to check if its a palindrome: ";
		cin >> stringInput;
		if (palindromeString(stringInput, 0, stringInput.size() - 1))
		{
			cout << stringInput << " is a palindrome" << endl;
		}
		else
		{
			cout << stringInput << " is NOT a palindrome" << endl;
		}
		break;
	case 2:
		cout << "Enter a list of numbers(space between each number): " << endl;
		quickSort(test, 0, 5 - 1);
		for (int i = 0; i < 5; i++)
		{
			cout << test[i] << " ";
		}
		break;
	case 3:
		cout << "Enter a string to be reversed:" << endl;
		cin >> stringInput;
		reverseString(stringInput);
		break;
	case 4:
		return 0;
	default:
		break;
	}
	return 0;
}

void reverseString(string stringp)
{
	char temp = stringp[0];
	if (stringp.size() == 0)
	{
		return;
	}
	stringp.erase(stringp.begin());
	reverseString(stringp);
	stringp = "";
	stringp.push_back(temp);
	cout << stringp;
}
void quickSort(int array[], int start, int end)
{
	if (start < end)
	{
		int partitionIndex = partition(array, start, end);
		quickSort(array, start, partitionIndex - 1);
		quickSort(array, partitionIndex + 1, end);
	}
}
int partition(int array[], int low, int high) 
{
	int pivot = array[high];
	int index = (low - 1);
	for (int j = low; j <= (high - 1); j++)
	{
		if (array[j] <= pivot)
		{
			index++;
			swap(array[index], array[j]);
		}
	}
	swap(array[index + 1], array[high]);
	return (index + 1);
}
bool palindromeString(string string, int start, int end)
{
	if (start == end || start > end)
	{
		return true;
	}
	if (string[start] == string[end])
	{
		return palindromeString(string, start + 1, end - 1);
	}
	else
	{
		return false;
	}
}
