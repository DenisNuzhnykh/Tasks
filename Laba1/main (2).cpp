#include <iostream>

using namespace std;

void Fibonachi(int n) {
    int tmp = 1;
    int res = 0;
    for (int i = 0; i < n; i++) {
        res = res + tmp;
        tmp = res - tmp;
        cout << res << " ";
    }
    cout << "\n";
}

int Calculator(int a,int b, char operation) {
    switch(operation) {
    case '+':
        return a + b;
        break;
    case '-':
        return a - b;
        break;
    case '*':
        return a * b;
        break;
    case '/':
        if(b!=0)
        return a / b;
        break;
    default:
        cout << "Invalid operation" << endl;
        break;
    }
}

int main() {
    int n;
    cin >> n;
    Fibonachi(n);
    int a, b;
    char operation;
    cin >> a >> operation >> b;
    cout << Calculator(a, b, operation) << endl;
}