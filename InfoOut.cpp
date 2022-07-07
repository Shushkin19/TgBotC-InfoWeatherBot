#include "InfoOut.h"
#include<iostream>
#include<string>
//#define MAX 25


void clear(char* arr) {
	for (int i = 0; i < MAX; i++) {
		arr[i] = 0;
	}
}

int cmpstr(char* arr,int len, const char* a) {
	int ln_cnstch = 0;
			int j = 0;
	while (a[ln_cnstch] != '\0') {
		ln_cnstch++;
	}

	for (int i = 0; i < len; i++) {
		if (arr[i] == a[0]) {
			j = 0;
			while (arr[i + j] == a[j]) {
				j++;
			}

			/*while ((arr[i + j] == a[j])); {
				j++;
			}*/
			if (j == ln_cnstch) {
				return i;
			}
		}
	}
}

InfoOut::InfoOut() {
	jsonarray = NULL;
	lenght = 0;
	clear(tmp);
}

InfoOut::InfoOut(std::string arr, int len) {
	jsonarray = new char[len];
	for (int i = 0; i < len; i++) {
		jsonarray[i] = arr[i];
	}
	lenght = len;
	clear(tmp);
}

InfoOut::~InfoOut() {
	delete[] jsonarray;
}

int InfoOut::fells_like() {
	clear(tmp);
	int indf = cmpstr(jsonarray, lenght, "feels_like");
	int ln = strlen("feels_like");
	indf += 2;
	int i, j;
	i = j = 0;
	while (jsonarray[indf + i + ln] != ',') {
		tmp[i] = jsonarray[indf + ln + i];
		i++;
	}
	/*for (int y = 0; y < i; y++) {
		std::cout << tmp[y];
	}*/
	double fl_lk = atof(tmp);
	fl_lk -= (double)273;
	//std::cout << "\n" << fl_lk;
	return fl_lk;
}

int InfoOut::pressure() {
	clear(tmp);
	int indf = cmpstr(jsonarray, lenght, "pressure");
	int ln = strlen("pressure");
	indf += 2;
	int i, j;
	i = j = 0;
	while (jsonarray[indf + i + ln] != ',') {
		tmp[i] = jsonarray[indf + ln + i];
		i++;
	}
	/*for (int y = 0; y < i; y++) {
		std::cout << tmp[y];
	}*/
	float fl_lk = atof(tmp);
	//std::cout << fl_lk;
	fl_lk /= 133,3;
	//std::cout << fl_lk;
	fl_lk *= 100;
	//std::cout << "\n" << fl_lk;
	return fl_lk;
}

int InfoOut::tempmax() {
	clear(tmp);
	int indf = cmpstr(jsonarray, lenght, "temp_max");
	int ln = strlen("temp_max");
	indf += 2;
	int i, j;
	i = j = 0;
	while (jsonarray[indf + i + ln] != ',') {
		tmp[i] = jsonarray[indf + ln + i];
		i++;
	}
	/*for (int y = 0; y < i; y++) {
		std::cout << tmp[y];
	}*/
	float fl_lk = atof(tmp);
	fl_lk -= (double)273;
	//std::cout << "\n" << fl_lk;
	return fl_lk;
}

int InfoOut::tempmin() {
	clear(tmp);
int indf = cmpstr(jsonarray, lenght, "temp_min");
int ln = strlen("temp_min");
indf += 2;
int i, j;
i = j = 0;
while (jsonarray[indf + i + ln] != ',') {
	tmp[i] = jsonarray[indf + ln + i];
	i++;
}
/*for (int y = 0; y < i; y++) {
	std::cout << tmp[y];
}*/
float fl_lk = atof(tmp);
fl_lk -= (double)273;
//std::cout << "\n" << fl_lk;
return fl_lk;
}

int InfoOut::tempnow() {
	clear(tmp);
	int indf = cmpstr(jsonarray, lenght, "temp");
	int ln = strlen("temp");
	indf += 2;
	int i, j;
	i = j = 0;
	while (jsonarray[indf + i + ln] != ',') {
		tmp[i] = jsonarray[indf + ln + i];
		i++;
	}
	/*for (int y = 0; y < i; y++) {
		std::cout << tmp[y];
	}*/
	
	double fl_lk = atof(tmp);
	fl_lk -= (double)273;
	//std::cout << "\n" << fl_lk;
	return fl_lk;
}
 
 
int InfoOut::wind() {
	clear(tmp);
	int indf = cmpstr(jsonarray, lenght, "wind");
	int ln = strlen("wind");
	indf += 2;
	int i, j;
	i = j = 0;
	while (jsonarray[indf + i + ln] != ',') {
		tmp[i] = jsonarray[indf + ln + i];
		i++;
	}
	/*for (int y = 0; y < i; y++) {
		std::cout << tmp[y];
	}*/
	int fl_lk = atoi(tmp);
	//std::cout << "\n" << fl_lk;
	return fl_lk;
}
 

std::string InfoOut::mainweather() {
	clear(tmp);
	int indf = cmpstr(jsonarray, lenght, "description");
	int ln = strlen("description");
	indf += 2;
	int i, j;
	i = j = 0;
	while (jsonarray[indf + i + ln] != ',') {
		tmp[i] = jsonarray[indf + ln + i];
		i++;
	}
	tmp[i + 1] = '\0';
	std::string arr;

	/*for (int p = 0; p < 14; p++) {
		std::cout << tmp[p] << std::endl;
	}*/
	return tmp;
}
