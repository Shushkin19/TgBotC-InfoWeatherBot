#pragma once
#include<string>
#define MAX 25
class InfoOut
{
	char* jsonarray;
	int lenght;
	char tmp[MAX];

public:
	InfoOut();
	InfoOut(std::string arr,int len);
	~InfoOut();
	int tempnow();
	int tempmin();
	int tempmax();
	int fells_like();
	std::string mainweather();
	int pressure();
	int wind();
	friend int cmpstr(char* arr,int len, const char* a);
};


 int cmpstr(char* arr,int len, const char* a);
 void clear(char* arr);