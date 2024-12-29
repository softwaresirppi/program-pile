#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

typedef unsigned int Year;
typedef uint8_t Month;
typedef uint8_t Day;

char* dayOfWeekNames[] = {
	"Monday",
	"Tuesday",
	"Wednesday",
	"Thursday",
	"Friday",
	"Saturday",
	"Sunday"
};

typedef struct {
	Year year; // RANGE: 0 - 2,147,483,647 
	Month month; // RANGE: 0 - 255
	Day day; // 0..6 sat, sun, mon, tue, wed, thu, fri
} Date;

bool isLeapYear(Year year) {
	return (year%4==0) && (year%100!=0) || (year%400==0);
}

uint8_t findTotalDaysInMonth(Month month, bool isLeapYear){
	return 30 + ((month + (month > 7)) % 2 == 1) - (month == 2) * (2 - isLeapYear);
}

uint16_t findTotalDaysInYear(Year year){
	if(isLeapYear(year)) return 366;
	else return 365;
}

uint8_t findDayOfWeek(Date date){
	// days elapsed from 0001/01/01
	printf("Date: %u/%hhu/%hhu\n", date.year, date.month, date.day);
	unsigned long long int daysElapsed = date.day - 1;
	//printf("D%lld", daysElapsed);
	for(Year i = 1; i < date.year; i++){
		daysElapsed += findTotalDaysInYear(date.year);
	}
	for(Month i = 1; i < date.month; i++){
		//printf(" M%hhu", findTotalDaysInMonth(i, isLeapYear(date.year)));
		daysElapsed += findTotalDaysInMonth(i, isLeapYear(date.year));
	}
	//printf("\nDays Elapsed: %lld\n", daysElapsed);
	// 0001/01/01 was a saturday ()
	return daysElapsed % 7;
}

int main(){
	Date date;
	//scanf("%u %hhu %hhu", &date.year, &date.month, &date.day);
	for(int i = 1; i < 10; i++){
		for(int j = 1; j < 10; j++){
			date = (Date){1, i, j};
			uint8_t dayOfWeek = findDayOfWeek(date);
      printf("Its the %hhuth day of week!\n", dayOfWeek + 1);
		}
	}
	//printf("%s", dayOfWeekNames[dayOfWeek]);
}
