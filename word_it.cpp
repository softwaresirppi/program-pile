#include <bits/stdc++.h>
using namespace std;

map<int, string> numbers = {
        {0, "Zero"},
        {1, "One"},
        {2, "Two"},
        {3, "Three"},
        {4, "Four"},
        {5, "Five"},
        {6, "Six"},
        {7, "Seven"},
        {8, "Eight"},
        {9, "Nine"},
        {10, "Ten"},
        {11, "Eleven"},
        {12, "Twelve"},
        {13, "Thirteen"},
        {14, "Fourteen"},
        {15, "Fifteen"},
        {16, "Sixteen"},
        {17, "Seventeen"},
        {18, "Eighteen"},
        {19, "Nineteen"},
        {20, "Twenty"},
        {30, "Thirty"},
        {40, "Forty"},
        {50, "Fifty"},
        {60, "Sixty"},
        {70, "Seventy"},
        {80, "Eighty"},
        {90, "Ninety"},
};

string word(int x){
	if(numbers.count(x))
		return numbers[x];
	else if(x < 100)
		return word((x / 10) * 10) + " " + word(x % 10);
	else if(x < 1000)
		return word(x / 100) + " Hundred " + word(x % 100);
	else if(x < 1000000)
		return word(x / 1000) + " Thousand " + word(x % 1000);
	else if(x < 1000000000)
		return word(x / 1000000) + " Million " + word(x % 1000000);
	else 
		return word(x / 1000000000) + " Billion " + word(x % 1000000000);
}

int main(){
		cout << word(1234567890) << endl;
}
