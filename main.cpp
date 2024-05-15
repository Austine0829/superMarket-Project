#include <iostream>
#include <fstream>
#include <memory>

using namespace std;

class superMarket{
    public:
     unique_ptr<string>unpProductName = make_unique<string>();
     unique_ptr<int>unpProductPrice = make_unique<int>();
     unique_ptr<int>unpProductNumber = make_unique<int>();

    public:
     void menuFunc();
     void addProductFunc();
};

int main (){



    return 0;
}

void superMarket :: menuFunc(){

    int choice;

    cout << "Enter Choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        
        addProductFunc();

        break;
    
    default:
        break;
    }
}