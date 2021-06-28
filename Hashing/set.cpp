#include<iostream>
#include<unordered_set>
using namespace std;

int main() {

	//set is a collection of keys
	unordered_set<int> s{1, 2, 3, 4, 5, 6, 7};

	s.insert(111);

	s.erase(11);

	int key;
	cin>>key;

	//find function works in O(n) in avg 
	//if you go ahead and implemrnt this using a array takes O(logn)
	//s.end() wiill denote the point just after the ending of the list
	//it will return an iterator
	//Awsome right !!!!!!!!!!!!!!!
 	if(s.find(key) != s.end()) {
 		cout<<"key is present";
 	}else{
 		cout<<"key is not present";
 	}

 	//print all the elements of the list
 	for(auto x: s) {
 		cout<<x<<endl;
 	}	


	return 0;
}