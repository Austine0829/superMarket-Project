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
    
    superMarket out;
    out.menuFunc();


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

void superMarket :: addProductFunc(){

    fstream productFile;
    
    productFile.open("productFile.txt", ios::out | ios::app);

    if (productFile.is_open())
    {
        cout << "Enter Product Number: ";
        cin >> *unpProductNumber;

        cout << "Enter Product Name: ";
        cin >> *unpProductName;

        cout << "Enter Product Price: ";
        cin >> *unpProductPrice;

        productFile << *unpProductNumber << " " << *unpProductName << " " << *unpProductPrice;
    }

    else
    {
        cout << "Error Has Occured In Add Product Function\n";
    }

    productFile.close();   
}