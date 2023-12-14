#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

vector<string> passenger;
vector<vector<string>> passengers;

bool comp(vector<string> fir, vector<string> sec) {
	if (stoi(fir[3]) > stoi(sec[3])) {
		return false;
	}
	else {
		if (stoi(fir[3]) < stoi(sec[3])) {
			return true;
		}
		else {
			return fir[1] < sec[1];
		}
	}
}

int main() {
	string line, temp;
	ifstream text("train.csv");
	int ind = 0, age, pclass;
	bool brackets = false;
	cin >> pclass >> age;
	getline(text, line, '\r');
	while (getline(text, line, '\r')) {
		ind = 0;
		passenger.clear();
		for (int i = 0; i < line.length(); i++) {
			if ((line[i] == ',' && !brackets) || size_t(i+1) == line.length()) {
				if (ind == 2) {
					if (temp != "") {
						passenger.push_back(temp);
					}
					else {
						passenger.push_back("0");
					}
					if (stoi(passenger[0]) != pclass) {
						passenger.clear();
						break;
					}
				}
				if (ind == 3) {
					passenger.push_back(temp);
				}
				if (ind == 4) {
					if (temp == "female") {
						passenger.push_back(temp);
					}
					else {
						passenger.clear();
						break;
					}
				}
				if (ind == 5) {
					if (temp != "") {
						passenger.push_back(temp);
					}
					else {
						passenger.push_back("0");
					}
					if (stoi(passenger[3]) <= age) {
						passenger.clear();
					}
					break;
				}
				ind++;
				temp = "";
			}
			else {
				if (line[i] == '"' && line[size_t(i + 1)] == '"') {
					temp += line[i];
					i++;
				}
				else {
					if (line[i] == '"') {
						if (brackets) {
							brackets = false;
						}
						else {
							brackets = true;
						}
					}
					else {
						temp += line[i];
					}
				}
			}
		}
		if (passenger.size() != 0) {
			passengers.push_back(passenger);
		}
	}
	std::sort(passengers.begin(), passengers.end(), comp);
	for (int i = 0; i < passengers.size(); i++) {
		cout << passengers[i][1] << endl;
	}
}