#include<iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <sstream>
#include <cctype>

using namespace std;

#define ld long double
#define ll long long



int getkey(int &k) {
    while (true) {
        if (!(cin >> k)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Enter a number:     \n";
            continue;
        }
        if (k % 26 == 0) {
            cout << "Try another key, no multiples of 26 allowed: \n";
            continue;
        }
        return k;
    }
}

int tolower2(char c) {
    if (c>='A' && c<='Z') {
        return tolower(c);
    }
    else if (c>='a' && c<='z') {
        return toupper(c);
    }
    else {
        return c;
    }
}



int send_signal() {
    cout << "Enter the text you want to encrypt: " << endl;
    string s1;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin,s1);
    for (int i=0;i<s1.length();i++) {
         s1[i]= tolower2(s1[i]);
    }
    cout << "Enter your key to encrypt: " << endl;
    int k;
    k=getkey(k);
    for (int i=0;i<s1.length();i++) {
        if (s1[i]>='a' && s1[i]<='z') {
            s1[i]= (s1[i]-'a'+((k%26)+26))%26+'a';
        }
        else if (s1[i]>='A' && s1[i]<='Z') {
            s1[i]= (s1[i]-'A'+((k%26)+26))%26+'A';
        }
    }
    cout << s1 << endl;
    return 0;
}




int recieve_signal() {
    cout << "Enter the text you want to decrypt: " << endl;
    string s2;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin,s2);
    for (int i=0;i<s2.length();i++) {
         s2[i]= tolower2(s2[i]);
    }
    cout << "Enter your key to decrypt: " << endl;
    int k=0;
    k=getkey(k);
    k=-k;
    for (int i=0;i<s2.length();i++) {
        if (s2[i]>='a' && s2[i]<='z') {
            s2[i]= (s2[i]-'a'+((k%26)+26))%26+'a';
        }
        else if (s2[i]>='A' && s2[i]<='Z') {
            s2[i]= (s2[i]-'A'+((k%26)+26))%26+'A';
        }
    }
    cout << s2 << endl;
    return 0;
}




int choosing() {
    int summm=1;
    string oper;
    while (true) {
        cout<<"For encrypting enter 1, and for decrypting press 0: " << "\n Note : The first char is only considered!!\n" << endl;
        cin>>oper;
        if (oper=="1") {
            send_signal();
        }
        else if (oper=="0"){
            recieve_signal();
        }
        else {
            continue;
        }
        cout << endl;
        string x;
        cout << "Do you want to continue? (y/n): \n only one char is allowed\n";
        while (true) {
            cin >> x;
            if (x=="y" || x=="Y") {
                summm=0;
                break;
            }
            else if (x=="n" || x=="N") {
                return 0;
            }
            else {
                cout<<"only one char (y/n) is allowed!!!!!\n";
            }
        }
    }
    return 0;
}




int main() {
    return choosing();
}