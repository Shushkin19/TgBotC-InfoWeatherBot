#pragma once
#include<string>
#define MAX 15
class InfoOut
{
	char* jsonarray;
	int lenght;
	char tmp[MAX];

public:
	InfoOut(std::string arr,int len);
	~InfoOut();
	float tempnow();
	float tempmin();
	float tempmax();
	double fells_like();
	char* mainweather();
	int pressure();
	int wind();
	friend int cmpstr(char* arr,int len, const char* a);
};


 int cmpstr(char* arr,int len, const char* a);
 void clear(char* arr);