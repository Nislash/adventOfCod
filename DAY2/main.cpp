#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int checkValidPSW2(string line){
    //10-13 w: kwtzpnzspwwwdz

    string minmaxdelimiter = "-";
    int pos1 = stoi(line.substr(0, line.find("-")));
    int pos2 = stoi(line.substr(line.find("-")+1, line.find(" ")));
    char charNeed = line.substr(line.find(":")-1, 1)[0];
    string psw = line.substr(line.find(":")+2);

    if((psw[pos1-1] == charNeed && psw[pos2-1] != charNeed) || (psw[pos2-1] == charNeed && psw[pos1-1] != charNeed))
        return 1;
    else
    {
        return 0;
    }
    
    
}
int checkValidPSW(string line){
    //10-13 w: kwtzpnzspwwwdz

    string minmaxdelimiter = "-";
    int min = stoi(line.substr(0, line.find("-")));
    int max = stoi(line.substr(line.find("-")+1, line.find(" ")));
    string charNeed = line.substr(line.find(":")-1, 1);
    string psw = line.substr(line.find(":")+2);

    cout << "min " << min << " max " << max << " char: " << charNeed << " psw: " << psw  ;
    int countLettre = count(psw.begin(), psw.end() , charNeed[0]) ;
    cout << "result : " << countLettre << endl ;

    if( countLettre < min || countLettre > max){
        return 0;
    } 
    else{
        return 1;
    }
        
}

int searchAllPreset(string path){
    ifstream file(path);
    vector<string> listNum;
    string num_tmp;

    while(getline(file,num_tmp))
    {
        listNum.push_back(num_tmp);
    }
    int total = 0;
    for(auto n : listNum){
        total += checkValidPSW2(n);
    }
    return total;
}

int main() {

    cout << "total:" << searchAllPreset("presetd2.txt") << endl ;

    return 0;
}