//MUHAMMAD FASEEH
//l215357@lhr.nu.edu.pk
//Assignment 4


#include <iostream>
#include <fstream>
using namespace std;


void palindrome(char word[])
{
	int c = 0;//counter
	int d = 0;//counter
	//for finding length
	int l = 0;
	for (int i = 0; word[i] != '\0'; i++)
	{
		l++;
	}
		for (int i = 0; i < l/2; i++)
		{
			if (word[i] == word[l - i - 1])
			{
				c++;
			}
			else
				d+=2;
		}
		if (c == l / 2)
		{
			cout << "No ";//yhn no aye ga..palindrome
		}	 
		else if (c != l / 2 && d <= 2)
		{
			cout << "Yes ";//yhn yes aye ga imperfect
		}
		else
			cout << "No ";//yhn no aye ga not palindrome
}

void superanagrams(char word1[], char word2[])
{
	int length1, length2,flag = 0, count = 0;
	length1 = strlen(word1);
	length2 = strlen(word2);
	if (length1 == length2)
	{
		for (int i = 0; i < length1; i++)
		{
			for (int j = 0; j < length2; j++)
			{
				if (word1[i] == word2[j])
				{
					count++;
					break;
				}
			}
		}

		if (count != length1 )
		{
			cout << "No";
			flag = 0;
		}
		else
		{
			flag = 1;
		}
	}
	else if (length2 - length1 > 2 || length1 - length2 > 2)
	{
		cout << " NO";
	}

	//separating------------------------------
	char visited[20]; int v = 0;//count for visit array
	char separted[20]; int s = 0;//count for seprated array
	if (flag==1 || length1!=length2)
	{
		for (int i = 0; i < length1; i++)
		{
			if (i == 0)
			{
				visited[v] = word1[i]; v++;
				separted[s] = word1[i];
				s++;
			}
			else if (i != 0)
			{
				visited[v] = word1[i];
				v++;
				//back checking
				int c = 0;
				for (int j = 0; j < v - 1; j++)
				{
					if (word1[i] == visited[j])
					{
						c++;
					}
				}
				if (c == 0)
				{
					separted[s] = word1[i];
					s++;
				}
			}
		}
		separted[s] = '\0';
		s++;
		//separating end-------------------------------------
		//frequency check
		int a = 0;
		unsigned int f1 = 0, f2 = 0, diff = 0;
		int sum = 0;
		for (int i = 0; i < s; i++)
		{
			f1 = 0, f2 = 0, diff = 0;
			//chhecking frequency of word 1
			for (int j = 0; j < length1; j++)
			{
				if (separted[i] == word1[j])
				{
					f1++;
				}
			}
			//chhecking frequency of word 2
			for (int k = 0; k < length2; k++)
			{
				if (separted[i] == word2[k])
				{
					f2++;
				}
			}
			if (f2 > f1)
			{
				diff = f2 - f1;
			}
			else if (f1 > f2)
			{
				diff = f1 - f2;

			}
			sum = sum + diff;
			if (sum > 2)
			{
				a++;
			}
		
		}
		if (a == 0)
		{
			cout << "Yes";
		}
		else
			cout << "No";
	}
	
}


int main()
{
	char word[50];
	char word1[20];
	char word2[20];
	ifstream fin("Input.txt");
	while (!fin.eof()) {
		fin.getline(word, 50);
		//separating
		int indexspace = 0;
		for (int i = 0; word[i] != ' '; i++)
		{
			word1[i] = word[i];
			indexspace++;
		}
		word1[indexspace] = '\0';
		int index = 0;
		for (int i = indexspace+1; word[i] !='\0'; i++)
		{
			word2[index] = word[i];
			index++;
			//indexspace++;
		}
		word2[index] = '\0';
		palindrome(word1);
		palindrome(word2);
		superanagrams(word1, word2);
		cout<<endl;

	}
	system("pause");
	return 0;
}