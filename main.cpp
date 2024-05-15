#include <iostream>
#include <fstream>
#include <memory>

using namespace std;
using std:: string, std:: cout, std:: cin;

class superMarket{
    public:
     unique_ptr<string>unpProductName = make_unique<string>();
     unique_ptr<int>unpProductPrice = make_unique<int>();
     unique_ptr<int>unpProductNumber = make_unique<int>();

    public:
     string productNameList[100];
     int productPriceList[100];
     int productNumberList[100];
     int arrSize = sizeof(productNameList)/sizeof(productNameList[0]);

    public:
     string orderProductList[100];
     int arrSizeTwo = sizeof(orderProductList)/sizeof(orderProductList[0]);
     int orderQuant[100];
     int totalBill = 0;


    public:
     void menuFunc();
     void adminFunc();
     void addProductFunc();
     void editFunction();
     void deleteProductFunc();
     void checkProductsFunc();
     void buyProductFunc();
     void receiptFunc();
};

int main (){
    
    superMarket out;
    out.menuFunc();


    return 0;
}

void superMarket :: menuFunc(){

    int choice;

    cout << "---------------------------------\n";
    cout << "|\t [1]Adminstrator        |\n";
    cout << "|\t [2]Buy Product         |\n";
    cout << "---------------------------------\n";
    
    cout << "Enter Choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        
        adminFunc();

        break;
    
    case 2:

        buyProductFunc();
    
    default:
        break;
    }
}

void superMarket :: adminFunc(){

    int choice;

    cout << "---------------------------------\n";
    cout << "|\t[1]Add Product          |\n";
    cout << "|\t[2]Edit Product         |\n";
    cout << "|\t[3]Delete Product       |\n";
    cout << "|\t[4]Check Products       |\n";
    cout << "---------------------------------\n";
    
    cout << "Enter Choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        
        addProductFunc();

        break;

    case 2:

        editFunction();

    case 3: 

        deleteProductFunc();

    case 4:

        checkProductsFunc();
    
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

         productFile << *unpProductNumber << " " << *unpProductName << " " << *unpProductPrice << "\n";
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
    string newProductName;
    int newProductPrice;
    int newProdcutNumber;

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
                 cin >> newProdcutNumber;

                 cout << "Enter New Product Name: ";
                 cin >> newProductName;

                 cout << "Enter New Product Price: ";
                 cin >> newProductPrice;

                 productFile2 << newProdcutNumber << " " << newProductName << " " << newProductPrice << "\n";

                 cout << "Product Details Has Been Change\n";
            }

            else
            {
                 productFile2 << newProdcutNumber << " " << newProductName << " " << newProductPrice << "\n";
            }

            productFile >> *unpProductNumber >> *unpProductName >> *unpProductPrice;

        } 
        
        while (!productFile.eof());        
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

void superMarket :: deleteProductFunc(){

    fstream productFile, productFile2;

    int tempProductNumber;

    productFile.open("productFile.txt", ios::in);
    productFile >> *unpProductNumber >> *unpProductName >> *unpProductPrice;

    cout << "Enter The Number Of The Product You Want To Delete: ";
    cin >> tempProductNumber;

    if (productFile.is_open())
    {   
        
        do
        {
            if (tempProductNumber == *unpProductNumber)
            { 
                 productFile2.open("productFile2.txt", ios::out | ios::app);

                 cout << "Product Details Has Been Deleted\n";   
            }

            productFile >> *unpProductNumber >> *unpProductName >> *unpProductPrice; 
        }   
        
        while (!productFile.eof());     
    }
    
    else
    {
        "Error Has Occured In Delete Function\n";
    }

    productFile.close();
    productFile2.close();

    remove("productFile.txt");
    rename("productFile2.txt", "productFile.txt");
}

void superMarket :: checkProductsFunc(){

    fstream productFile;

    productFile.open("productFile.txt", ios::in);

    cout << "------------------------------------------------------------------------------\n";
    cout << "|\t\t\t  SUPER MARKET PRODUCT LIST                          |\n";
    cout << "------------------------------------------------------------------------------\n";
    cout << "|Product Number           |" << "Product Name            |" << "Product Price            |\n";
    cout << "------------------------------------------------------------------------------\n";
    
    if (productFile.is_open())
    {
        for (int i = 0; i < arrSize; i++)
        {   
             productFile >> productNumberList[i] >> productNameList[i] >> productPriceList[i];

             if (!productNameList[i].empty())
             {
                 cout << "\t" << productNumberList[i] << "\t\t\t" << productNameList[i] << "\t\t\t" << productPriceList[i] << "\n";
             }        
        }    
    }
    
    else
    {
         "Error Has Occured In Check Products Function\n";
    }

    productFile.close();
}

void superMarket :: buyProductFunc(){

    fstream productFile;

    int number[100];
    int counter = 0;
    char choice;

    checkProductsFunc();

    do
    {   
        cout << "Enter Product Number: ";
        cin >> number[counter];

        cout << "Enter Quantity: ";
        cin >> orderQuant[counter];

        cout << "(y) To Order Again (n) To Print Receipt: ";
        cin >> choice;

        counter ++;
    } 
        
    while (choice == 'y');

    for (int i = 0; i < counter; i++)
    {
        productFile.open("productFile.txt", ios::in);
        productFile >> *unpProductNumber >> *unpProductName >> *unpProductPrice;
            
        do
        {   
            if (number[i] == *unpProductNumber)
            {
                 totalBill += *unpProductPrice * orderQuant[i];
                 orderProductList[i] += *unpProductName;
            }

            productFile >> *unpProductNumber >> *unpProductName >> *unpProductPrice;
        } 
            
        while (!productFile.eof());
    }

    productFile.close(); 

    receiptFunc();
}

void superMarket :: receiptFunc(){

    cout << "----------------------------------\n";
    cout << "|\tSUPER MARKET RECEIPT     |\n";
    cout << "----------------------------------\n";

    for (int i = 0; i < arrSizeTwo; i++)
    {
        if (!orderProductList[i].empty())
        {
            cout << orderProductList[i] << " " << orderQuant[i] << "x\n";
        }   
    }
    
    cout << "----------------------------------\n";
    cout << "Total Bill: " << totalBill << "\n";
    cout << "----------------------------------\n";

    menuFunc();
}