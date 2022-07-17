#include "ParseJson.h"
#include<string>
#include<iostream>
#include<nlohmann/json.hpp>

void insertion_sort(int* arr, int n) {
	int i, key, j;
	for (i = 1; i < n; i++) {
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

int ParseJson::tempmaxday() {


    int  m[10];
    auto& myma = arr["list"];
    int i = 0;
    for (auto& myma : myma) {
        m[i] = myma["main"]["temp_max"].get<int>();
        i++;
    }
	insertion_sort(m, i);


	return m[i-1];
}

int ParseJson::tempminday() {

	int  m[10];
	auto& myma = arr["list"];
	int i = 0;
	for (auto& myma : myma) {
		m[i] = myma["main"]["temp_min"].get<int>();
		i++;
	}
	insertion_sort(m, i);


	return m[0];
}

double ParseJson::ValueEUR() {
	return   arr["Valute"]["EUR"]["Value"].get<double>();
}

double ParseJson::ValueUSD() {
	
	return   arr["Valute"]["USD"]["Value"].get<double>();
}

