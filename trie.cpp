#include <bits/stdc++.h>
using namespace std;

template<typename T>
void repeat(T c, int n){
	for(int i = 0; i < n; i++)
		cout << c;
}

struct Trie {
	static const int characters = 26;

	Trie* kids[characters] = {};
	int references;
	bool complete = false;

	~Trie(){
		erase();
	}
	void erase(){
		for(int i = 0; i < characters; i++)
			if(kids[i]){
				kids[i]->erase();
				kids[i] = 0;
				free(kids[i]);
			}
	}

	int code(char x){ 
		return (x & 0b11111) - 1;
	}

	char decode(int code){
		return (code | 0b01100000) + 1;
	}

	int ways(){
		int count = 0;
		for(int i = 0; i < characters; i++)
			if(kids[i])
				count++;
		return count;
	}

	void insert(string x, int i = 0){
		if(x.size() == i && (complete = true))
			return;
		int pos = code(x[i]);
		references++;
		Trie* curr = this;
		if(!kids[pos]) {
			kids[pos] = new Trie();
		}
		kids[pos]->insert(x, i + 1);
	}


	void remove(string x, int i = 0){ 
		if(x.size() == i) return; 
		int pos = code(x[i]);
		references--;
		if(references)
			kids[pos]->remove(x, i + 1);
		else kids[pos]->erase();
	}
	
	bool search(string x, int i = 0){
		if(x.size() == i) return complete;
		int pos = code(x[i]);
		if(!kids[pos]) return false;
		return kids[pos]->search(x, i + 1);
	}

	Trie* prefix(string x, int i = 0){
		if(x.size() == i) return this;
		int pos = code(x[i]);
		if(!kids[pos]) return 0;
		return kids[pos]->prefix(x, i + 1);
	}

	vector<string> words(vector<string>& collector, string prefix = ""){
		if(complete) collector.push_back(prefix);
		for(int i = 0; i < characters; i++)
			if(kids[i])
				kids[i]->words(collector, prefix + decode(i));
		return collector;
	}

	vector<string> words(){
		vector<string> vec;
		return words(vec);
	}

	void print(int depth = 0){
		for(int i = 0; i < characters; i++)
			if(kids[i]){
				repeat("| ", depth);
				if(kids[i]->complete)
					cout << "\e[1m";
				cout << decode(i) << endl;
				if(kids[i]->complete)
					cout << "\e[0m";
				kids[i]->print(depth + 1);
			}
	}
};

int main(){
	Trie trie;
	trie.insert("flower");
	trie.insert("flour");
	trie.insert("flow");
	trie.insert("flask");
	trie.insert("flammingo");
	trie.insert("flames");
	trie.insert("flame");
	trie.insert("flaminamina");
	trie.remove("flaminamina");
	cout << "Is flame in the trie? " << trie.search("flame") << endl;
	cout << "Is flower in the trie? " << trie.search("flower") << endl;
	cout << "Is flow in the trie? " << trie.search("flow") << endl;
	cout << "Is flam in the trie? " << trie.search("flam") << endl;
	cout << "Is foe in the trie? " << trie.search("foe") << endl;
	cout << "Does something start with fl in the trie? " << trie.prefix("fl") << endl;
	cout << "Does something start with flow in the trie? " << trie.prefix("flow") << endl;
	cout << "Does something start with flam in the trie? " << trie.prefix("flam") << endl;
	cout << "Does something start with flame in the trie? " << trie.prefix("flame") << endl;
	cout << "Does something start with f in the trie? " << trie.prefix("f") << endl;
	cout << "Does something start with fa in the trie? " << trie.prefix("fa") << endl;
	cout << "Does something start with frick in the trie? " << trie.prefix("frick") << endl;
	cout << "Words that start with flam" << endl;
	for(auto word: trie.prefix("flam")->words()){
		cout << " - " << ("flam" + word) << endl;
	}
	cout << "Representation of the Trie" << endl;
	trie.print();
}
