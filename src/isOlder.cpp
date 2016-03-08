/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/

int isOlder(char *dob1, char *dob2) {
	int i, yr1 = 0, c=0, month1 = 0, day1 = 0, yr2 = 0, k=0, month2 = 0, day2 = 0, count1 = 0, count2 = 0, temp = 0, a;

	for (i = 0; i <= 1; i++){
		a = dob1[i] - '0';
		day1 = day1 * 10 + a;
	}
	for (i = 3; i <= 4; i++){
		a = dob1[i] - '0';
		month1 = month1 * 10 + a;
	}
	for (i = 6; i <= 9; i++){
		a = dob1[i] - '0';
		yr1 = yr1 * 10 + a;
	}

	for (i = 0; i <= 1; i++){
		a = dob2[i] - '0';
		day2 = day2 * 10 + a;
	}

	for (i = 3; i <= 4; i++){
		a = dob2[i] - '0';
		month2 = month2 * 10 + a;
	}
	for (i = 6; i <= 9; i++){
		a = dob2[i] - '0';
		yr2 = yr2 * 10 + a;
	}
	/* if (month1 == 2){
		if (yr1 % 4 == 0 && day1>28 )day1 = 29;
		else day1 = day1;
		}
		if (month2 == 2){
		if (yr2 % 4 == 0 && day1>28)day2 = 29;
		else day2 = 28;
		}*/
	for (count1 = 0; dob1[count1] != '\0'; count1++){
		if (dob1[count1] >= 65 && dob1[count1] <= 90) c = 1;
	}
	for (count2 = 0; dob2[count2] != '\0'; count2++) {
		if (dob2[count2] >= 65 && dob2[count2] <= 90)  k = 1;
	}
	if (month1 > 12 || month2 > 12 || day1 > 31 || day2 > 31 || count1<9 || (yr1 % 4 != 0 && day1 == 29) || (yr2 % 4 != 0 && day2 == 29)|| count2<9 || k == 1 || c == 1)return -1;
	if ((yr1 > yr2 || month1 > month2 || day1 > day2) || (month1 == month2 && yr1 > yr2 && day2 == day1) || (month1 > month2 && yr1 == yr2 && day2 == day1) || (month1 == month2 && yr1 == yr2 && day1 > day2)) return 2;
	if ((yr2 > yr1 || month2 > month1 || day2 > day1) || (month1 == month2 && yr1 == yr2 && day2 > day1) || (month1 < month2 && yr1 == yr2 && day2 == day1) || (month1 == month2 && yr1 < yr2 && day2 == day1))return 1;
	if (yr2 == yr1 && month2 == month1 && day2 == day1)return 0;
}
