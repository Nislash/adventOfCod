#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int arraycheck2(vector<int> preset){
    for (auto n : preset){
            for (auto n2 : preset){
                if(n + n2 == 2020){
                    cout << "entry " << n << " and " << n2 << endl;
                    return n*n2;
                }
                    
            }
        }
    return -1;
}

int arraycheck3(vector<int> preset){
    for (auto n : preset){
            for (auto n2 : preset){
                for(auto n3 : preset){
                    if(n + n2 + n3 == 2020){
                        cout << "entry " << n << " and " << n2 << " and " << n3 << endl;
                        return n*n2*n3;
                    }
                }
            }
        }
    return -1;
}

int main() {

    vector<int> listNum;
    string num_tmp;
    ifstream file("presetDay1.txt");

    if(file)
    {
        while(getline(file,num_tmp))
        {
            listNum.push_back(stoi(num_tmp));
        }
        cout << arraycheck3(listNum) << endl;

        
    }else{
        cout << "damn" <<endl;
    } 

    return 0;
}