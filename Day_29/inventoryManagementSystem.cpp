#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#include<limits>
#include<cmath>
#include<fstream>
using namespace std;
int main(){
    int productID[100];
    string productName[100];
    int productQuantity[100];
    float productPrice[100];
    string category[100];
    bool productAvailability[100];
    int totalProducts = 0;
    int choice;
    do{
        cout<<"==== INVENTORY MANAGEMENT SYSTEM ===="<<endl;
        cout<<"1. Add Product"<<endl;
        cout<<"2. Display Products"<<endl;
        cout<<"3. Search Product"<<endl;
        cout<<"4. Update Product"<<endl;
        cout<<"5. Delete Product"<<endl;
        cout<<"6. Restock Product"<<endl;
        cout<<"7. Sell Product"<<endl;
        cout<<"8. Calculate Total Inventory Value"<<endl;
        cout<<"9. Find Most Expensive Product"<<endl;
        cout<<"10. Find Cheapest Product"<<endl;
        cout<<"11. Sort Products by Price"<<endl;
        cout<<"12. Sort Products by Quantity"<<endl;
        cout<<"13. Low stock Alert"<<endl;
        cout<<"14. Total Number of Products"<<endl;
        cout<<"15.Exit"<<endl;
        cout<<"Enter Your Choice : "<<endl;
        cin>>choice;
        switch(choice){
            case 1: {
                cout<<"==== ADD PRODUCT ===="<<endl;
                if(totalProducts >= 100){
                    cout<<"Inventory Full! Cannot add more products."<<endl;
                }
                else{
                    cout<<"Enter Product ID: ";
                    cin>>productID[totalProducts];
                    bool idExists = false;
                    for(int i = 0; i < totalProducts; i++){
                        if(productID[i] == productID[totalProducts]){
                            idExists = true;
                            break;
                        }
                    }
                    if(idExists){
                        cout<<"Product with ID "<<productID[totalProducts]<<" already exists!"<<endl;
                        break;
                    }
                    cin.ignore(); // To ignore the newline character after product ID input
                    cout<<"Enter Product Name: ";
                    getline(cin, productName[totalProducts]);
                    cout<<"Enter Product Quantity: ";
                    cin>>productQuantity[totalProducts];
                    if(productQuantity[totalProducts] < 0){
                        cout<<"Invalid Quantity! Cannot be negative."<<endl;
                        break;
                    }
                    cout<<"Enter Product Price: ";
                    cin>>productPrice[totalProducts];
                    if(productPrice[totalProducts] < 0){
                        cout<<"Invalid Price! Cannot be negative."<<endl;
                        break;
                    }
                    cin.ignore(); // To ignore the newline character after product price input
                    cout<<"Enter Product Category: ";
                    getline(cin, category[totalProducts]);
                    productAvailability[totalProducts] = (productQuantity[totalProducts] > 0);
                    totalProducts++;
                    cout<<"Product Added Successfully!"<<endl;
                }
                break;
            }
            case 2: {
                cout<<"==== DISPLAY PRODUCTS ===="<<endl;
                if(totalProducts == 0){
                    cout<<"No products in inventory!"<<endl;
                }
                else{
                    for(int i = 0; i < totalProducts; i++){
                        cout<<"Product ID: "<<productID[i]<<endl;
                        cout<<"Product Name: "<<productName[i]<<endl;
                        cout<<"Product Quantity: "<<productQuantity[i]<<endl;
                        cout<<"Product Price: "<<productPrice[i]<<endl;
                        cout<<"Product Category: "<<category[i]<<endl;
                        cout<<"Product Availability: "<<(productAvailability[i] ? "Available" : "Out of Stock")<<endl;
                        cout<<"-----------------------------"<<endl;
                    }
                }
                break;
            }
            case 3: {
                cout<<"==== SEARCH PRODUCT ===="<<endl;
                if(totalProducts == 0){
                    cout<<"No products in inventory!"<<endl;
                }
                else{
                    int searchID;
                    cout<<"Enter Product ID to search: ";
                    cin>>searchID;
                    bool found = false;
                    for(int i = 0; i < totalProducts; i++){
                        if(productID[i] == searchID){
                            cout<<"Product Found!"<<endl;
                            cout<<"Product ID: "<<productID[i]<<endl;
                            cout<<"Product Name: "<<productName[i]<<endl;
                            cout<<"Product Quantity: "<<productQuantity[i]<<endl;
                            cout<<"Product Price: "<<productPrice[i]<<endl;
                            cout<<"Product Category: "<<category[i]<<endl;
                            cout<<"Product Availability: "<<(productAvailability[i] ? "Available" : "Out of Stock")<<endl;
                            found = true;
                            break;
                        }
                    }
                    if(!found){
                        cout<<"Product Not Found!"<<endl;
                    }
                }
                break;
            }
            case 4: {
                cout<<"==== UPDATE PRODUCT ===="<<endl;
                if(totalProducts == 0){
                    cout<<"No products in inventory!"<<endl;
                }
                else{
                    int updateID;
                    cout<<"Enter Product ID to update: ";
                    cin>>updateID;
                    bool found = false;
                    for(int i = 0; i < totalProducts; i++){
                        if(productID[i] == updateID){
                            cout<<"Product Found! Enter new details."<<endl;
                            cin.ignore(); // To ignore the newline character after product ID input
                            cout<<"Enter New Product Name: ";
                            getline(cin, productName[i]);
                            cout<<"Enter New Product Quantity: ";
                            cin>>productQuantity[i];
                            if(productQuantity[i] < 0){
                                cout<<"Invalid Quantity! Cannot be negative."<<endl;
                                break;
                            }
                            cout<<"Enter New Product Price: ";
                            cin>>productPrice[i];
                            if(productPrice[i] < 0){
                                cout<<"Invalid Price! Cannot be negative."<<endl;
                                break;
                            }
                            cin.ignore(); // To ignore the newline character after product price input
                            cout<<"Enter New Product Category: ";
                            getline(cin, category[i]);
                            productAvailability[i] = (productQuantity[i] > 0);
                            cout<<"Product Updated Successfully!"<<endl;
                            found = true;
                            break;
                        }
                    }
                    if(!found){
                        cout<<"Product Not Found!"<<endl;
                    }
                }
                break;
            }
            case 5: {
                cout<<"==== DELETE PRODUCT ===="<<endl;
                if(totalProducts == 0){
                    cout<<"No products in inventory!"<<endl;
                }
                else{
                    int deleteID;
                    cout<<"Enter Product ID to delete: ";
                    cin>>deleteID;
                    bool found = false;
                    for(int i = 0; i < totalProducts; i++){
                        if(productID[i] == deleteID){
                            for(int j = i; j < totalProducts - 1; j++){
                                productID[j] = productID[j + 1];
                                productName[j] = productName[j + 1];
                                productQuantity[j] = productQuantity[j + 1];
                                productPrice[j] = productPrice[j + 1];
                                category[j] = category[j + 1];
                                productAvailability[j] = productAvailability[j + 1];
                            }
                            totalProducts--;
                            cout<<"Product Deleted Successfully!"<<endl;
                            found = true;
                            break;
                        }
                    }
                    if(!found){
                        cout<<"Product Not Found!"<<endl;
                    }
                }
                break;
            }
            case 6: {
                cout<<"==== RESTOCK PRODUCT ===="<<endl;
                if(totalProducts == 0){
                    cout<<"No products in inventory!"<<endl;
                }
                else{
                    int restockID, restockQuantity;
                    cout<<"Enter Product ID to restock: ";
                    cin>>restockID;
                    bool found = false;
                    for(int i = 0; i < totalProducts; i++){
                        if(productID[i] == restockID){
                            cout<<"Enter Quantity to Restock: ";
                            cin>>restockQuantity;
                            if(restockQuantity <= 0){
                                cout<<"Invalid Quantity! Cannot be zero or negative."<<endl;
                                break;
                            }
                            productQuantity[i] += restockQuantity;
                            productAvailability[i] = (productQuantity[i] > 0);
                            cout<<"Product Restocked Successfully!"<<endl;
                            found = true;
                            break;
                        }
                    }
                    if(!found){
                        cout<<"Product Not Found!"<<endl;
                    }
                }
                break;
            }
            case 7: {
                cout<<"==== SELL PRODUCT ===="<<endl;
                if(totalProducts == 0){
                    cout<<"No products in inventory!"<<endl;
                }
                else{
                    int sellID, sellQuantity;
                    cout<<"Enter Product ID to sell: ";
                    cin>>sellID;
                    bool found = false;
                    for(int i = 0; i < totalProducts; i++){
                        if(productID[i] == sellID){
                            cout<<"Enter Quantity to Sell: ";
                            cin>>sellQuantity;
                            if(sellQuantity <= 0){
                                cout<<"Invalid Quantity! Cannot be zero or negative."<<endl;
                                break;
                            }
                            if(sellQuantity > productQuantity[i]){
                                cout<<"Insufficient Stock! Cannot sell."<<endl;
                            }
                            else{
                                productQuantity[i] -= sellQuantity;
                                productAvailability[i] = (productQuantity[i] > 0);
                                cout<<"Product Sold Successfully!"<<endl;
                            }
                            found = true;
                            break;
                        }
                    }
                    if(!found){
                        cout<<"Product Not Found!"<<endl;
                    }
                }
                break;
            }
            case 8: {
                cout<<"==== CALCULATE TOTAL INVENTORY VALUE ===="<<endl;
                if(totalProducts == 0){
                    cout<<"No products in inventory!"<<endl;
                }
                else{
                    float totalValue = 0;
                    for(int i = 0; i < totalProducts; i++){
                        totalValue += productQuantity[i] * productPrice[i];
                    }
                    cout<<"Total Inventory Value: $"<<totalValue<<endl;
                }
                break;
            }
            case 9: {
                cout<<"==== FIND MOST EXPENSIVE PRODUCT ===="<<endl;
                if(totalProducts == 0){
                    cout<<"No products in inventory!"<<endl;
                }
                else{
                    int maxIndex = 0;
                    for(int i = 1; i < totalProducts; i++){
                        if(productPrice[i] > productPrice[maxIndex]){
                            maxIndex = i;
                        }
                    }
                    cout<<"Most Expensive Product:"<<endl;
                    cout<<"Product ID: "<<productID[maxIndex]<<endl;
                    cout<<"Product Name: "<<productName[maxIndex]<<endl;
                    cout<<"Product Price: $"<<productPrice[maxIndex]<<endl;
                }
                break;
            }
            case 10: {
                cout<<"==== FIND CHEAPEST PRODUCT ===="<<endl;
                if(totalProducts == 0){
                    cout<<"No products in inventory!"<<endl;
                }
                else{
                    int minIndex = 0;
                    for(int i = 1; i < totalProducts; i++){
                        if(productPrice[i] < productPrice[minIndex]){
                            minIndex = i;
                        }
                    }
                    cout<<"Cheapest Product:"<<endl;
                    cout<<"Product ID: "<<productID[minIndex]<<endl;
                    cout<<"Product Name: "<<productName[minIndex]<<endl;
                    cout<<"Product Price: $"<<productPrice[minIndex]<<endl;
                }
                break;
            }
            case 11: {
                cout<<"==== SORT PRODUCTS BY PRICE ===="<<endl;
                if(totalProducts == 0){
                    cout<<"No products in inventory!"<<endl;
                }
                else{
                    for(int i = 0; i < totalProducts - 1; i++){
                        for(int j = 0; j < totalProducts - i - 1; j++){
                            if(productPrice[j] > productPrice[j + 1]){
                                swap(productID[j], productID[j + 1]);
                                swap(productName[j], productName[j + 1]);
                                swap(productQuantity[j], productQuantity[j + 1]);
                                swap(productPrice[j], productPrice[j + 1]);
                                swap(category[j], category[j + 1]);
                                swap(productAvailability[j], productAvailability[j + 1]);
                            }
                        }
                    }
                    cout<<"Products Sorted by Price Successfully!"<<endl;
                }
                break;
            }
            case 12: {
                cout<<"==== SORT PRODUCTS BY QUANTITY ===="<<endl;
                if(totalProducts == 0){
                    cout<<"No products in inventory!"<<endl;
                }
                else{
                    for(int i = 0; i < totalProducts - 1; i++){
                        for(int j = 0; j < totalProducts - i - 1; j++){
                            if(productQuantity[j] > productQuantity[j + 1]){
                                swap(productID[j], productID[j + 1]);
                                swap(productName[j], productName[j + 1]);
                                swap(productQuantity[j], productQuantity[j + 1]);
                                swap(productPrice[j], productPrice[j + 1]);
                                swap(category[j], category[j + 1]);
                                swap(productAvailability[j], productAvailability[j + 1]);
                            }
                        }
                    }
                    cout<<"Products Sorted by Quantity Successfully!"<<endl;
                }
                break;
            }
            case 13: {
                cout<<"==== LOW STOCK ALERT ===="<<endl;
                if(totalProducts == 0){
                    cout<<"No products in inventory!"<<endl;
                }
                else{
                    bool lowStockFound = false;
                    for(int i = 0; i < totalProducts; i++){
                        if(productQuantity[i] < 5){
                            cout<<"Low Stock Product:"<<endl;
                            cout<<"Product ID: "<<productID[i]<<endl;
                            cout<<"Product Name: "<<productName[i]<<endl;
                            cout<<"Product Quantity: "<<productQuantity[i]<<endl;
                            cout<<"------------------------------"<<endl;
                            lowStockFound = true;
                        }
                    }
                    if(!lowStockFound){
                        cout<<"No Low Stock Products!"<<endl;
                    }
                }
                break;
            }
            case 14: {
                cout<<"==== TOTAL NUMBER OF PRODUCTS ===="<<endl;
                cout<<"Total Products in Inventory: "<<totalProducts<<endl;
                int availableProducts = 0;
                int outOfStockProducts = 0;
                for(int i = 0; i < totalProducts; i++){
                    if(productAvailability[i]){
                        availableProducts++;
                    }
                    else{
                        outOfStockProducts++;
                    }
                }
                cout<<"Available Products: "<<availableProducts<<endl;
                cout<<"Out of Stock Products: "<<outOfStockProducts<<endl;
                break;
            }
            case 15: {
                cout<<"==================================="<<endl;
                cout<<"==== THANK YOU FOR USING THE SYSTEM ===="<<endl;
                cout<<"Inventory Management System"<<endl;
                break;
            }
            default: {
                cout<<"Invalid Choice! Please try again."<<endl;
                break;
            }
        }
        
    }while(choice != 15);
    return 0;


}