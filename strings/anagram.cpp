#include<iostream>
#include<cstring>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool anagram(string s1, string s2) {
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	return s1 == s2;
}

bool anagram_II(string s1, string s2) {
	if(s1.length() != s2.length()) {
		return false;
	}
	int n = s1.length();
	int freq[26] = {0};

	for(int i =0; i< n; i++) {
		freq[s1[i] - 'a']++;
		freq[s2[i] - 'a']--;
	}
	for(int i=0; i< 26; i++) {
		if(freq[i]) return false;
	}
	return true;
}

bool anagram_III(string s1, string s2) {
	if(s1.length() != s2.length()) {
		return false;
	}
	int n = s1.length();
	unordered_map<char, int> counts;
	for(int i =0; i< n; i++) {
		counts[s1[i]]++;
		counts[s2[i]]--;
	}
	for(auto count: counts) {
		if(count.second) return false;
	}
	return true;
}

int main() {

	string s1 = "123";
	string s2 = "123";

	if(anagram(s1, s2)) {
		cout<<"yes";
	}else {
		cout<<"No";
	}

	return 0;
}