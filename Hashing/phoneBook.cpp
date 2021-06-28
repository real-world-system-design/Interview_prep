#include<iostream>
#include<map>
#include<list>
#include<string>
using namespace std;

int main() {
	map<string, list<string> > phonebook;

	phonebook["prateek"].push_back("112224");
	phonebook["prateek"].push_back("112225");
	phonebook["prateek"].push_back("112226");
	phonebook["prateek"].push_back("112227");

	//print the hash map

	return 0;
}