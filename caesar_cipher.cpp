#include<iostream>
#include <string>
//#include <iomanip>
//#include <vector>
//#include <algorithm>
//#include <numeric>
#include <limits>
//#include <cmath>
//#include <sstream>
#include <cctype>

using namespace std;//i know it is a beginner method!!just leave it as it is!!


void caesar(std::string& s, int k) {    for (int i=0;i<s.length();i++) {
        if (s[i]>='a' && s[i]<='z') {
            s[i]= (s[i]-'a'+((k%26)+26))%26+'a';
        }
        else if (s[i]>='A' && s[i]<='Z') {
            s[i]= (s[i]-'A'+((k%26)+26))%26+'A';
        }
    }
}


int getkey(int &k, const int &opp) {
    while (true) {
        if (!(cin >> k)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Enter a number:     \n";
            continue;
        }
        if (cin.peek() != '\n') {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // FIX: reject mixed input like "1abcd"
            cout << "Invalid input! Enter a number:\n";
            continue;
        }

        if (k % 26 == 0) {
            cout << "Try another key, no multiples of 26 allowed: \n";
            continue;
        }
        if (opp==0)k=-k;//for decrypting
        return k;
    }
}

int convert(char c) {//for converting small to capital and capital to small
    unsigned char uc = static_cast<unsigned char>(c);//for removing anything other
    if (uc>='A' && uc<='Z') {
        return tolower(c);
    }
    else if (uc>='a' && uc<='z') {
        return toupper(uc);
    }
    else {
        return uc;
    }
}



int send_signal() {
    int opp=1;
    cout << "Enter the text you want to encrypt: " << endl;
    string s1;
    getline(cin >> ws, s1);

    for (int i=0;i<s1.length();i++) {
         s1[i]= convert(s1[i]);
    }
    cout << "Enter your key to encrypt: " << endl;
    int k;
    k=getkey(k,opp);
    caesar(s1,k);
    cout << s1 << endl;
    return 0;
}




int receive_signal() {
    int opp=0;
    cout << "Enter the text you want to decrypt: " << endl;
    string s2;
    getline(cin >> ws, s2);
    for (int i=0;i<s2.length();i++) {
         s2[i]= convert(s2[i]);
    }
    cout << "Enter your key to decrypt: " << endl;
    int k=0;
    k=getkey(k,opp);
    caesar(s2,k);
    cout << s2 << endl;
    return 0;
}




int choosing() {
    string oper;
    while (true) {
        cout<<"For encrypting enter 1, and for decrypting press 0: " << "\n Note : Only one char is allowed!!\n" << endl;
        cin>>oper;
        if (oper=="1") {
            send_signal();
        }
        else if (oper=="0"){
            receive_signal();
        }
        else {
            if (cin.peek() != '\n') {
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // FIX: reject mixed input like "1abcd"
                cout << "Invalid input! \n For encrypting enter 1, and for decrypting press 0: " << "\n Note : Only one char is allowed!!\n";
                continue;
            }

            continue;
        }
        cout << endl;
        string x;
        cout << "Do you want to continue? (y/n): \n only one char is allowed\n";
        while (true) {
            cin >> x;
            if (x=="y" || x=="Y") {
                break;
            }
            else if (x=="n" || x=="N") {
                return 0;
            }
            else {
                cout<<"only one char (y/n) is allowed!!!!!\n";
            }
            if (cin.peek() != '\n') {
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // FIX: reject mixed input like "1abcd"
                cout << "only one char (y/n) is allowed!!!!!\n";
                continue;
            }

        }
    }
    return 0;
}




int main() {
    return choosing();
}