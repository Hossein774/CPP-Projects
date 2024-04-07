#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <fstream>

using namespace std;

class brtf {

public:

    vector <string> lastPasses;
    string numSet = "12345678901234567890";
    string charSet = "abcdefghijklmnopqrstuvwxyz";
    string defPass;
    string pass = "";
    bool canReturn = false;
    bool isOk = false;

    int length = 0;
    int tries = 0;

    void passMaker();
    void setLength();
    int getRandom(int input);
    void setDefPass(string input);
    string getPass();

};

string brtf::getPass() {
    string temp2;

    while (!canReturn) {

        
        setLength();

        while (!isOk) {

            pass = "";
            passMaker();

        }
        isOk = false;

        string temp = pass;

        if (temp == defPass) {

            temp2 = temp;
            canReturn = true;

        }
        else {

            lastPasses.push_back(pass);
            tries++;
            cout << "password not found : " << pass << endl << endl;

        }


    }
    canReturn = false;
    return temp2;

}

void brtf::setDefPass(string input) {

    defPass = input;

}

void brtf::setLength() {

    length = getRandom(3) + 1;

}

int brtf::getRandom(int input) {

    return rand() % input;

}

void brtf::passMaker() {

    
    string temp, temp2;
    setLength();
    int count = 0;

    while (count < length) {
        int tempos = getRandom(5);

        if (tempos <= 1 ) {

            temp = numSet[getRandom(20)];
            pass.append(temp);

        }
        else if (tempos > 1) {

            temp = charSet[getRandom(26)];
            pass.append(temp);

        }

        count++;
    }

    bool isTested = false;

    for (int i = 0; i < lastPasses.size(); i++) {

        if (pass == lastPasses[i]) {

            isTested = true;

        }

    }

    if (isTested) {

        isTested = false;
        count = 0;
        isOk = false;
        return;

    }

    isOk = true;

}

int main()
{
    srand(time(0));


    string input, result;

    cout << "Enter Pass to BRUTE FORCE!" << endl;
    cin >> input;

    brtf BF;

    BF.setLength();
    BF.passMaker();
    BF.setDefPass(input);
    result = BF.getPass();

    cout << "Your password is : " << result << endl;

    cout << "Number of tries is: " << BF.tries;

}


