#include <iostream>
#include <map>
#include <chrono>
#include <vector>


using namespace std;

int main() {

    vector<string> time;
    vector<string> memory;
    for (int i = 10; i <= 100000000; i *= 10) {
        vector<int> vc;
        auto t1 = chrono::high_resolution_clock::now();
        map<int, int> mp;
        for (int j = 0; j < i; ++j) {
            mp[j] = j;
        }
        auto t2 = chrono::high_resolution_clock::now();
        chrono::duration<double, milli > elapsed = t2 - t1;
        string string1 = to_string(i) + " " + to_string(elapsed.count());
        time.push_back(string1);
        int size = sizeof(map<int, int>) + sizeof(int) * 2;
        for (int j = 1; ; j *= 2) {
            if (i <= j) {
                size += j;
                break;
            }
        }
        string1 = to_string(i) + " " + to_string(size);
        memory.push_back(string1);
    }
    
    cout << "TIME:" << endl;
    for (vector<string>::iterator i = time.begin();i != time.end(); i++) {
        cout << *i << endl;
    }
    cout << endl;
    cout << "MEMORY:" << endl;
    for (vector<string>::iterator i = memory.begin();i != memory.end(); i++) {
        cout << *i << endl;
    }
    return 0;
}
