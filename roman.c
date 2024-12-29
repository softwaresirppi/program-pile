#include <stdio.h>
#include <stdint.h>

#define length(arr) (sizeof(arr) / sizeof(arr[0]))

typedef struct {
	char symbol;
	int16_t value;
} Symbol;
 
Symbol digits[] = {
	{'M', 1000},
	{'D', 500},
	{'C', 100},
	{'L', 50},
	{'X', 10},
	{'V', 5},
	{'I', 1},
};

int valueOf(char symbol){
	for(int i = 0; i < length(digits); i++)
		if(digits[i].symbol == symbol)
			return digits[i].value;
	return 0;
}


char symbolOf(int value){
	for(int i = 0; i < length(digits); i++)
		if(digits[i].value == value)
			return digits[i].symbol;
}

// Decodes the roman numeral and returns the value
int decode(char *roman){
	int total = 0;
	for(int i = 0; roman[i]; i++){
		int value = valueOf(roman[i]);
		if(value < valueOf(roman[i + 1])) value *= -1;
		total += value;
	}
	return total;

}

// Encodes a normal number into roman number and writes to [output]
char* encode(int value, char* output){
	char* writer = output;
	for(int i = 0; i < length(digits); i++){
		while(value >= digits[i].value){
			value -= digits[i].value;
			*writer++ = digits[i].symbol;
		}
		for(int another = i + 1; another < length(digits) ; another++){
			// Arbitrary standard rules
			if(another % 2) continue;
			if(digits[i].value > 10 && digits[another].value == 1) continue;
			// Checking negative parts
			if(value >= digits[i].value - digits[another].value){
				value -= digits[i].value - digits[another].value;
				*writer++ = digits[another].symbol;
				*writer++ = digits[i].symbol;
			}
		}
	}
	*writer = 0;
	return output;
}

int main(){
	char roman[32];
	int value;
	for(int i = 0; i < 1000; i++){
		encode(i, roman);
		value = decode(roman);
		printf("%8d\t%16s\n", value, roman);
	}
}
