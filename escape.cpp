#include <bits/stdc++.h>
using namespace std;

#define HEX "0123456789abcdef"
#define OCTAL "01234567"
#define DECIMAL "0123456789"

int parseNumber(string source, int& i, string base, int limit=-1){
	int value = 0;
	int baseN = base.size();
	int sourceN = source.size();
	while(i < sourceN && find(base.begin(), base.end(), source[i]) == base.end())
		i++;
	int begin = i;
	while(i < sourceN && find(base.begin(), base.end(), source[i]) != base.end())
		i++;
	int end = i - 1;
	if(limit > 0)
		end = min(end, begin + limit - 1);
	for(int pos = end; pos >= begin; pos--){
		int digit = (find(base.begin(), base.end(), source[pos]) - base.begin());
		value += pow(baseN, end - pos) * digit;
	}
	return value;
}

int parseEscapeSequence(string source, int& i){
	if(source[i] == 'a' && ++i) 
		return '\a';
	if(source[i] == 'b' && ++i) 
		return '\b';
	if(source[i] == 'f' && ++i) 
		return '\f';
	if(source[i] == 'n' && ++i) 
		return '\n';
	if(source[i] == 'r' && ++i) 
		return '\r';
	if(source[i] == 't' && ++i) 
		return '\t';
	if(source[i] == 'v' && ++i) 
		return '\v';
	if(source[i] == '\\' && ++i) 
		return '\\';
	if(source[i] == '\'' && ++i) 
		return '\'';
	if(source[i] == '\"' && ++i) 
		return '\"';
	if(source[i] == '\?' && ++i) 
		return '\?';
	if(source[i] == 'x' && ++i)
		return parseNumber(source, i, HEX);
	if(source[i] == 'u' && ++i)
		return parseNumber(source, i, HEX, 4);
	if(source[i] == 'U' && ++i)
		return parseNumber(source, i, HEX, 8);
	int octal = parseNumber(source, i, OCTAL, 3);
	return octal;
}


wstring escape(string source){
	wstring escaped;
	int i = 0;
	while(i < source.size()){
		char letter;
		if(source[i] == '\\' && ++i)
			letter = parseEscapeSequence(source, i);
		else
			letter = source[i++];
		escaped.push_back(letter);
	}
	return escaped;
}

int main(){
	string x = R"(WHut da fuq\'s rong with yu\?\n:\\)";
	wcout << escape(x) << endl;
}
