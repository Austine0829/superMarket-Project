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
     void editFunction();
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

    case 2:

        editFunction();
    
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

void superMarket :: editFunction(){
    
    fstream productFile, productFile2;

    int tempProductNumber;

    productFile.open("productFile.txt", ios::in);
    productFile >> *unpProductNumber >> *unpProductName >> *unpProductPrice;

    cout << "Enter The Number Of The You Want To Edit: ";
    cin >> tempProductNumber;

    if (productFile.is_open())
    {   
        do
        {
            if (tempProductNumber == *unpProductNumber)
            {
                 productFile2.open("productFile2.txt", ios::out | ios::app);

                 cout << "Enter New Product Number: ";
                 cin >> *unpProductNumber;

                 cout << "Enter New Product Name: ";
                 cin >> *unpProductName;

                 cout << "Enter New Product Price: ";
                 cin >> *unpProductPrice;

                 productFile2 << *unpProductNumber << " " << *unpProductName << " " << *unpProductPrice << "\n";

                 cout << "Product Details Has Been Change\n";
            }

            else
            {
                 productFile2 << *unpProductNumber << " " << *unpProductName << " " << *unpProductPrice << "\n";
            }

            productFile >> *unpProductNumber >> *unpProductName >> *unpProductPrice;

        } 
        
        while (productFile.eof());        
    }

    else
    {
        cout << "Error Has Ocured In Edit Function\n";
    }

    productFile.close();
    productFile2.close();

    remove("productFile.txt");
    rename("productFile2.txt", "productFile.txt");
   
}