#include "InfoOut.h"
#include<iostream>
#include<string>


int cmpstr(char* arr,int len, const char* a) {
	int ln_cnstch = 0;
	while (a[ln_cnstch] != '\0') {
		ln_cnstch++;
	}
	for (int i = 0; i < len; i++) {
		if (arr[i] == a[0]) {
			int j = 0;
			while (arr[i + j] == a[j] && (i + j) < len); {
				j++;
			}
			if (j == ln_cnstch) {
				return i;
			}
		}
	}
}



InfoOut::InfoOut(char* arr, int len) {
	jsonarray = new char[len];
	for (int i = 0; i < len; len++) {
		jsonarray[i] = arr[i];
	}
	lenght = len;
	memset(tmp, 0, sizeof(char));
}

InfoOut::~InfoOut() {
	delete[] jsonarray;
}

int InfoOut::fells_like() {
	int indf = cmpstr(jsonarray, lenght, "fells_like");
	indf += 2;
	int i, j;
	i = j = 0;
	while (jsonarray[indf + i] != ',') {
		tmp[i] = jsonarray[indf + i];
	}
	float fl_lk = atof(tmp);
	std::cout << "\n" << fl_lk;
	return (int)fl_lk;
}

//char* InfoOut::mainweather() {
//
//}
//int InfoOut::pressure() {
//
//}
//int InfoOut::tempmax() {
//
//}
//int InfoOut::tempmin() {
//
//}
//int InfoOut::tempnow() {
//
//}
//int InfoOut::wind() {
//
//}