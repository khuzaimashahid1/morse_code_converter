// ConsoleApplication12.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "string"
using namespace std;
char arr[64] = {'%','%','t','e','m','n','a','i','o','g','k','d','w','r','u','s','%','%','q','z','y','c','x','b','j','p','%','l','%','f','v','h','0','9','%','8','%','%','%','7','%','%','%','%','%','%','%','6','1','%','%','%','%','%','%','%' ,'2','%','%','%','3','%','4','5' };
int parent(int i)
{
	int p = i / 2;
	return floor(p);
}
int rightChild(int i)
{
	int rc = 2 * i + 1;
	return rc;
}
int leftChild(int i)
{
	int lc = 2 * i;
	return lc;
}
string enchar(int index)
{
	int temp;
	string output = "";
	while (true)
	{
		temp = parent(index);
		if (temp == 0 )
			break;
		else
		{
			if (rightChild(temp) == index)
				output = "." + output;
			else if (leftChild(temp) == index)
				output = "-" + output;
		}
		index = temp;
	}
	return (output+" ");
}
void encode()
{
	string input, output="";
	char temp;
	int i = 0;
	cout << "Enter what you wish to convert to Morse : " ;
	cin.ignore();
	getline(cin, input);
	while ((unsigned)i < (unsigned)input.length())
	{
		temp=input.at(i);
		temp=tolower(temp);
		if (temp == ' ')
		{
			output=output + "/ ";
		}
		else
		{
			for (int j = 2; j <= 64; j++)
			{
			if (arr[j] == temp)
				{
					output = output + enchar(j);
				}
			}
		}
		i++;
		}
	cout << "Encoded Text is : " << output << endl;
}

void decode()
{
	string input, output="";
	char temp;
	int index=1, i = 0;
	cout << "Enter the morse code which You wish to decode" << endl<<"Kindly put one space between morse code of each character, "<<endl<<"Use slash(/) to seperate words"<<endl<<"Your Input : ";
	cin.ignore();
	getline(cin, input);
	input = input + " ";
	while ((unsigned)i < (unsigned)input.length())
	{
		temp = input.at(i);
		switch (temp)
		{
		case '-':
			index = leftChild(index);
			break;
		case '.':
			index = rightChild(index);
			break;
		case ' ':
			output = output + arr[index];
			index = 1;
			break;
		case '/':
			output = output + ' ';
			i++;
			break;
		default:
			cout << "Wrong INPUT, Please try again"<<endl;
			decode();
			break;
        }
		i++;
	}
	cout << "The decoded Text is : " << output<<endl;
}
void display()
{
	string temp = "";
	for (int i = 1; i < 65; i++)
	{
		if (arr[i] == '%')
			continue;
		else
		{
			temp = enchar(i);
			cout << arr[i] << " : " << temp << endl;
		}

	}
}

void searchAndDelete()
{
	char key;
	cout << "Enter the element you wish to delete from the tree : ";
	cin.ignore();
	cin>>key;
	for (int i = 0; i < 65; i++)
	{
		if (arr[i] == '%')
			continue;
		else if (arr[i] == key)
		{
			arr[i] = '%';
			cout << endl << "Item deleted Successfully"<<endl;
			return;
		}
    }
	cout << "Item not found in the tree"<<endl;

}
void searchAndReplace()
{
	char key,replacement;
	cout << "Enter the element you wish to replace : ";
	cin.ignore();
	cin >> key;
	key = tolower(key);
	for (int i = 0; i < 65; i++)
	{
		if (arr[i] == '%')
			continue;
		else if (arr[i] == key)
		{
			cout <<"Item Found in tree"<<endl<< "Enter the element you wish to replace it with : ";
			cin.ignore();
			cin >> replacement;
			replacement = tolower(replacement);
			for (int i = 2; i < 65; i++)
			{
				if (arr[i] == replacement)
				{
					cout << "Element Already present in tree and was not replaced"<<endl;
					return;
				}
			}
			arr[i] = replacement;
			cout << endl << "Item Replaced Successfully" << endl;
			cout  << "The morse code of replaced item is : " << enchar(i) <<endl;
			return;
		}
	}
	cout << "Item not found in the tree" << endl;
}
void insert()
{
	char key;
	int index = 0;
	cout << "Enter the element you wish to insert in the tree : ";
	cin.ignore();
	cin >> key;
	key = tolower(key);
	for (int i = 2; i < 65; i++)
	{
		if (arr[i] == key)
		{
			cout << "Element Already present in tree and was not inserted" << endl;
			return;
		}
	}
	cout << "Enter the index at which you wish to insert : ";
	cin >> index;
	if (index <= 1)
	{
		cout << "You are trying to insert on root or before root. Please Try Again."<<endl;
		insert();
	}
	else if (index >= 65)
	{
		cout << "You are exceeding the height of tree. Please Try Again."<<endl;
		insert();
	}
	else
	{
		if (arr[index] == '%')
		{
			arr[index] = key;
			cout << endl << "Item Inserted Successfully" << endl;
			cout << "The morse code of Inserted item is : " << enchar(index);
		}
		else
		{
			int choice;
			cout << "There is an item already present at given index." << endl << "If you wish to replace the item, Press 1" << endl << "If you wish to change the index, Press 2"<<endl;
			cin >> choice;
			if (choice == 1)
			{
				arr[index] = key;
				cout << endl << "Item Replaced Successfully" << endl;
				cout << "The morse code of replaced item is : " << enchar(index);
			}
			else if (choice == 2)
			{
				insert();
			}

		}
	}
	
}
int main()
{
	int choice=0;
	
	do {
		cout << "IF you wish to decode from Morse Code to English,Press 1" << endl << "IF you wish to encode English to Morse Code,Press 2" <<  endl << "IF you wish to Search and Replace,Press 3" << endl  << "IF you wish to insert in the tree,Press 4" << endl << "IF you wish to search and delete in the tree,Press 5" << endl<<"If you wish to Display the tree,Press 6"<<endl<<  "If You wish to exit, Press 7" << endl << "Kindly Enter your choice : ";
		cin >> choice;
		if (choice == 1)
		{
			decode();
		}
		else if (choice == 2)
		{
			encode();
		}
		else if (choice == 3)
		{
			searchAndReplace();
		}
		else if (choice == 4)
		{
			insert();
		}
		else if (choice == 5)
		{
			searchAndDelete();
		}
		else if (choice == 6)
			display();
		else
			cout << endl << "Enter Appropriate input" << endl;
		} while (choice !=7);
	system("pause");
    return 0;
}

