#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    // ʹ�� std::getline ��ȡ����
    getline(cin, str);
    int n = str.length();
    for(int i = 0; i < n; i++){
        int j = i;
        while(j < n && str[j] != ' '){
            j++;
        }
        for(int k = i; k < j; k++) cout << str[k];
        cout << endl;
        i = j;
    }
    return 0;
}
