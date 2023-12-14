#include <iostream>
#include <fstream>
#include "json.hpp"
using namespace std;
using json = nlohmann::json;

int main()
{
    int result = 0, id;
    cin >> id;
    ifstream file("data.json");
    json js = file;
    for (json::iterator it = js.begin(); it != js.end(); ++it) {
        for (int i = 0; i < it.value()["tasks"].size(); ++i) {
            if (it.value()["tasks"][i]["user_id"] == id && it.value()["tasks"][i]["completed"]) {
                result++;
            }
        }
    }
    cout << result;
}