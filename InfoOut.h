#pragma once
class InfoOut
{
	char* jsonarray;
	int lenght;
	char tmp[15];

public:
	InfoOut(std::string arr,int len);
	~InfoOut();
	int tempnow();
	int tempmin();
	int tempmax();
	int fells_like();
	char* mainweather();
	int pressure();
	int wind();
	friend int cmpstr(char* arr,int len, const char* a);
};


 int cmpstr(char* arr,int len, const char* a);
