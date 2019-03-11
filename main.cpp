/*	Project:    P1
	Name:       Kat Ottman
    Partner:    Darryl McCottrell
    Class:      CSC 1820 Section 1
*/

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <list>

using namespace std;

int main(int argc, char *argv[])
{
	cout << "Argc: " << argc << endl; //checking argc for "right" value
	for (int index = 0; index < argc; index++)
		cout << "Index: " << index << " value: " << argv[index] << endl;

	if (argc < 2)
	{
		cerr << "Must provide a file name" << endl;
		return 0;
	}

	ifstream infile(argv[1]); //getting the filename from argv[1], opening the file and checking that it opened
	if (infile.is_open())
	{
		list<list<int> *> outer_list;
		list<int> *L = new list<int>();
		string line; //reading the input from filename, skipping blank lines and creating lists of integers dynamically created
		int sum = 0;
		int sumOfInnerLists = 0;

		while (getline(infile, line))
		{
			if (line == "")
				continue;
			stringstream ss(line);
			do
			{
				int integer;
				ss >> integer;
				(*L).push_back(integer);
			} while (!ss.eof());
			sum++;
			outer_list.push_back(L);
		}

		//printing out the size/line checks and ensuring they agree
		cout << "List counter: " << sum << endl;
		cout << "Size of outer list: " << outer_list.size() << endl;

		int count = 1;
		for (auto it = outer_list.begin(); it != outer_list.end(); ++it) //looping through outer_list to access inner lists
		{
			//printing the number of elements in each list and printing their sum
			list<int> listNum(*(*it));

			for (auto iter = listNum.begin(); iter != listNum.end(); ++iter) //looping through inner lists to get integers
			{
				sumOfInnerLists += (*iter);
			}

			cout << "List " << count << " has " << listNum.size() << " element(s) and sums to " << sumOfInnerLists << endl;
			sumOfInnerLists = 0; //attempt to clear sumOfInnerLists so it doesn't keep adding onto itself, this doesn't work
			count++;
			listNum.clear(); //attempt to clear listNum so it doesn't keep adding onto itself, this doesn't work
		}
		delete L;			//deallocating memory from pointers
		outer_list.clear(); //deallocating memory from list of pointers to lists

		infile.close(); //closing the input file
	}
	else
	{
		cerr << "Unable to open file: " << argv[1] << endl;
	}

	return 0;
}