#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <conio.h>

#define MAX_LEN 100

using namespace std;

vector<string>Extractions;
void Extractor(char input[MAX_LEN]) {
	string null = "";
	string temp = "";
	for (int i = 0; i < MAX_LEN; i++) {
		if (input[i] == ' ' || input[i] == null[0]) {
			Extractions.push_back(temp);
			temp = "";
		}
		else {
			temp += input[i];
		}
	}
}

int main()
{
	char input[MAX_LEN];
	cin.getline(input, MAX_LEN);
	char input2[MAX_LEN];
	
	Extractor(input);
	for (int i = 0; i < Extractions.size(); i++)
		cout << Extractions[i] << "   ";

}

