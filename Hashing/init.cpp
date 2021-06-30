#include <iostream>
#include <unordered_map>
using namespace std;


int main() {

	//if you want a shorted output you can use map datastructure
	//where all the functions are going to same expects the time complexity 
	//lexicographic ordering based on the keys
	//internally implemantes a balances binary tree so all the implementations
	//now becom shifts to O(1) to O(logn) time complexity .
	// map<string, int> map;

	//internal implemantaion is hashing with separate chainging
	unordered_map<string, int> menu;

	menu["dsalgo"] = 20;
	menu["hello"] = 10;
	menu["devops"] = 10;
	menu["linux"] = 10;

	//price of dosa was incremented by a factor of 10%
	//update query O(1)
	//take the old query and increment th price by a factor of 1
	menu["hello"] = (1 + 0.1);*menu["hello"];
	//searching
	string item;
	cin>>item;

	menu.erase("maggi");

	//iterate over all the key value pairs that are present inside the hash table
	for(pair<string, int> item: menu) {
		cout<<item.first<<"--"<<item.second<<endl;
	}
	cout<<endl;

	//if and 
	if(menu.count(item) == 0) {
		cout<< "not present";
	}else{
		cout<<"present and cost is"<< menu[item];
	}

	return 0;
}