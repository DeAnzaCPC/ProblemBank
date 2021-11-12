#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> m1;
unordered_map<int, string> m2;
map<string, int> m3 = {
    {"+", 1},
    {"-", -1},
    {"=", 0}
};

void calc(stringstream & ss){
    int curr = 0, op = 1;
    bool known = true;
    string next;
    while(known){
        ss >> next;
        if(m3.count(next)){
            if(next == "=") break;
            op = m3[next];
            continue;
        }
        if(!m1.count(next)){
            known = false;
            break;
        }
        curr += m1[next] * op;
    }
    if(known && m2.count(curr)){
        cout << m2[curr] << '\n';
        return;
    }
    cout << "unknown\n";
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string s;
    while(getline(cin, s)){
        stringstream ss(s);
        string command; ss >> command;
        if(command == "def"){
            string nextWord; int nextVal;
            ss >> nextWord >> nextVal;
            if(m1.count(nextWord)){
                m2.erase(m1[nextWord]);
            }
            m1[nextWord] = nextVal;
            m2[nextVal] = nextWord;
        } else if(command == "clear"){
            m1.clear();
            m2.clear();
        } else {
            cout << s.substr(5) << ' ';
            calc(ss);
        }
    }
}