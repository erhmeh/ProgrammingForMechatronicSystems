#include <iostream>
using namespace std;

int main(){
    int number = 88;
    int* pNumber = &number;
    cout << pNumber << endl;
    cout << *pNumber << endl;
    *pNumber = 99;
    cout << *pNumber << endl;
    cout << number << endl;
    return 0;
}
