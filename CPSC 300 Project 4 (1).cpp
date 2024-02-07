//Don Parker
//CPSC 300 Project 4
//A program that creates a hash table and allows adding, deleting, and looking up records.
//Functions and code that affect hash table size as the smallest prime greater than or equal to requested hash table size written by Dr. Robinson.

#include <iostream>
#include <fstream>
#include <String>
#include <cstdlib>
using namespace std;

//Global
int hashTableSize;

struct bucket
{
	string login;
	string uid;
	string name;
	string status;
};

//Primary hashing function. Returns the remainder after division of a given string key and int divisor.
int h(string k, int divisor)
{
	int mod = 0;
	
	for (int i = 0; i < k.length(); i++)
		{
			mod = mod + k[i];
			mod = mod % divisor;
			
			if ( i < (k.length() - 1) )
			{
				mod = mod * 256;
			}
			else
			{
				return mod;
			}
		}
}

//Secondary hashing function. Returns number of buckets to skip when looking for next empty or available bucket. 
int h2(string k)
{
	int mod = 7 - h(k,7);
	return mod;
}

//Adds a key and all of its fields to a bucket found by the Primary and Secondary Hashing Functions. Outputs number of collisions if any.
void add(string login, string uid, string name, bucket Table[])
{	

	bool found = false;
	
	int index = h(login,hashTableSize); 
	
	int collisions = 0;
	
	if (login.length() > 8)
	{
		cout << "Add-->: " << login << " h=" << h(login,hashTableSize) << " did not occur. Login must not exceed 8 characters! " << endl;
		found = true;
	}
	
	while (found == false)
	{
		
		if (login == Table[index].login)
		{
			cout << "Add-->: " << login << " h=" << h(login,hashTableSize) << " did not occur. No duplicate logins allowed! " << endl;
			found = true;
		}
		else
		{
			if ( Table[index].status != "Full")
			{
				Table[index].login = login;
				Table[index].uid = uid;
				Table[index].name = name;
				Table[index].status = "Full";
				found = true;
				
				cout << "Add-->: " << login << " h=" << h(login,hashTableSize);
				cout << " Final_bucket=" << index;
				
				if (collisions != 0)
				{
					cout << " Collisions_occured=" << collisions << " h2=" << h2(login) << endl;
				}
				else
				{
					cout << endl;
				}
			}
			else
			{
				collisions++;
				index = (index + h2(login)) % hashTableSize;
			}
		}
		
	}
}

//Deletes a given key from the hash table if key exists. Also makes a deleted key's bucket available to be used again. Outputs number of probes to find key.
void del(string login,bucket Table[])
{
	bool found = false;
	
	int index = h(login,hashTableSize); 
	
	int probes = 0;
	
	while (found == false)
	{
		probes++;
		if ( Table[index].status == "Full" && login == Table[index].login)
		{
			Table[index].login = " ";
			Table[index].uid = " ";
			Table[index].name = " ";
			Table[index].status = "Available";
			found = true;
			cout << "Delete: " << login << " Probes=" << probes << endl;
		}
		else
		{
			index = (index + h2(login))%hashTableSize;
			if (index == h(login,hashTableSize) || Table[index].status == "Empty" )
			{
				probes++;
				cout << "Delete: " << login << " Entry not found. " << "Probes=" << probes << endl;
				found = true;
			}
			
		}
	}
}

//Looks up the location of a given key and returns the login, user id, and name fields. Outputs number of probes to find key.
void lookup(string login,bucket Table[])
{
	bool found = false;
	
	int index = h(login,hashTableSize); 
	
	int probes = 0;
	
	while (found == false)
	{
		probes++;
		if ( Table[index].status == "Full" && login == Table[index].login)
		{

			cout << "Lookup: "
			<< Table[index].login << " " 
			<< Table[index].uid << " " 
			<< Table[index].name << " "
			<< "Probes=" << probes << endl;
			found = true;
			
		}
		else
		{
			index = (index + h2(login))%hashTableSize;
			if (index == h(login,hashTableSize) || Table[index].status == "Empty" )
			{
				probes++;
				cout << "Lookup: " << login << " " << "h1=" << h(login,hashTableSize) << " " << "h2=" << h2(login) << " " "Entry not found. " << "Probes=" << probes << endl;
				found = true;
			}
		}
	}
} 
 
// Returns true iff p is prime
bool is_prime (unsigned long p)
    {
    unsigned long d;
    if (p>=2)
        {
        for (d=2; d*d<=p; ++d)
            if (p%d == 0)
                return false;
        return true;
        }
    else
        return false;
    }
    
// Returns the smallest prime p such that p>=n
unsigned long next_prime (unsigned long n)
    {
    unsigned long p;
    for (p=n; !is_prime(p); ++p)
        ; // do nothing
    return p;
    }


int main()
{
	
	fstream input;
	string file_name;
	string line;
	
	cout << "Enter name of file: ";
	cin >> file_name; 
	
	cout << "Enter requested hash table size: ";
	cin >> hashTableSize;
	
	hashTableSize = next_prime(hashTableSize);
	
	cout << "Actual hash table size: " << hashTableSize << endl << endl;
	
	bucket Table[hashTableSize];
	
	for (int i = 0; i < hashTableSize; i++)
	{
		Table[i].status = "Empty";
	}
	
	input.open(file_name);
	
	if (input.fail())
	{
		cout << "Couldn't open file\n'";
		exit(1);	
	}
	
	while(input >> line)
	{
		string userName;
		string idNumber;
		string fullName;
		
		if (line[0] == 'a')
		{	
			input >> userName;
			input >> idNumber;
			
			getline(input,fullName);
		
			//Removing white spaces in front of name. (spaces and tabs)
			int i = 0;
			while (fullName[i] == ' ' || fullName[i] == '	')
			{
				i++;
			}
			fullName = fullName.substr(i,-1);
			
			add(userName,idNumber,fullName,Table);
		}
		if (line[0] == 'd')
		{
			input >> userName;
			del(userName,Table);
		}
		if (line[0] == 'l')
		{
			input >> userName;
			lookup(userName,Table);
		}
	}
	
	return 0;
}
