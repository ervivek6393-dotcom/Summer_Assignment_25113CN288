#include<iostream>
#include<climits>
using namespace std;
int main(){
    int arr[100];
    int size = 0;
    int choice;
    do{
        cout<<"==== MENU DRIVEN ARRAY OPERATIONS SYSTEM ===="<<endl;
        cout<<"1. Enter Array Elements"<<endl;
        cout<<"2. Diplay Array Elements"<<endl;
        cout<<"3. Insert Element"<<endl;
        cout<<"4. Delete Element"<<endl;
        cout<<"5. Update Element"<<endl;
        cout<<"6. Search Element"<<endl;
        cout<<"7. Find Maximum Element"<<endl;
        cout<<"8. Find Minimum Element"<<endl;
        cout<<"9. Calculate Sum of Elements"<<endl;
        cout<<"10. Calculate Average of Elements"<<endl;
        cout<<"11. Reverse Array"<<endl;
        cout<<"12. Sort Ascending Order"<<endl;
        cout<<"13. Sort Descending Order"<<endl;
        cout<<"14. Count Even and Odd Elements"<<endl;
        cout<<"15. Count Positive and Negative Elements"<<endl;
        cout<<"16. Find Second Largest Element"<<endl;
        cout<<"17. Find Second Smallest Element"<<endl;
        cout<<"18. Remove Duplicate Elements"<<endl;
        cout<<"19. Merge Two Arrays"<<endl;
        cout<<"20. Copy Array"<<endl;
        cout<<"21. Exit"<<endl;
        cout<<"Enter Your Choice : "<<endl;
        cin>>choice;
        switch(choice){
            case 1: {
                cout<<"==== ENTER ARRAY ELEMENTS ===="<<endl;
                cout<<"Enter the size of the array (max 100): ";
                cin>>size;
                if(size < 1 || size > 100){
                    cout<<"Invalid Size!"<<endl;
                    size = 0; // Reset size to 0 if invalid
                }
                else{
                    cout<<"Enter "<<size<<" elements: ";
                    for(int i = 0; i < size; i++){
                        cin>>arr[i];
                    }
                }
                break;
            }
            case 2: {
                cout<<"==== DISPLAY ARRAY ELEMENTs ===="<<endl;
                if(size == 0){
                    cout<<"Array is empty!"<<endl;
                }
                else{
                    cout<<"Array Elements: ";
                    for(int i =0; i < size; i++){
                        cout<<arr[i]<<" ";

                    }
                
                }
                break;
            }
            case 3: {
                cout<<"==== INSERT ELEMENT ===="<<endl;
                if(size == 100){
                    cout<<"Array is full! Cannot insert new element."<<endl;
                }
                else{
                    int element, position;
                    cout<<"Enter the position to insert the element (1 to "<<size + 1<<"): "<<endl;
                    cin>>position;
                    if(position < 1 || position > size + 1){
                        cout<<"Invalid Position!"<<endl;
                        break;
                    }
                     cout<<"Enter the element to insert: ";
                cin>>element;
                for(int i = size; i >= position; i--){
                    arr[i] = arr[i - 1];
                }
                arr[position - 1] = element;
                size++;
                cout<<"Element Inserted Successfully!"<<endl;
                
                }
                break;
               
            }
            case 4: {
                cout<<"==== DELETE ELEMENT ===="<<endl;
                if(size == 0){
                    cout<<"Array is empty! Cannot delete element."<<endl;
                }
                else{
                    int position;
                    cout<<"Enter the position of the element to delete (1 to "<<size<<"): "<<endl;
                    cin>>position;
                    if(position < 1 || position > size){
                        cout<<"Invalid Position!"<<endl;
                    }
                    else{
                        for(int i = position - 1; i < size - 1; i++){
                            arr[i] = arr[i + 1];
                        }
                        size--;
                        cout<<"Element Deleted Successfully!"<<endl;
                    }
                }
                break;
            }
            case 5: {
                cout<<"==== UPDATE ELEMENT ===="<<endl;
                if(size == 0){
                    cout<<"Array is empty! Cannot update element."<<endl;
                }
                else{
                    int position, newValue;
                    cout<<"Enter the position of the element to update (1 to "<<size<<"): "<<endl;
                    cin>>position;
                    cout<<"Enter the new value: ";
                    cin>>newValue;
                    if(position < 1 || position > size){
                        cout<<"Invalid Position!"<<endl;
                    }
                    else{
                        arr[position - 1] = newValue;
                        cout<<"Element Updated Successfully!"<<endl;
                    }
                }
                break;
            }
            case 6: {
                cout<<"==== SEARCH ELEMENT ===="<<endl;
                if(size == 0){
                    cout<<"Array is empty! Cannot search element."<<endl;
                }
                else{
                    int element;
                    cout<<"Enter the element to search: ";
                    cin>>element;
                    bool found = false;
                    for(int i = 0; i < size; i++){
                        if(arr[i] == element){
                            cout<<"Element found at position: "<<i + 1<<endl;
                            found = true;
                            break;
                        }
                    }
                    if(!found){
                        cout<<"Element not found!"<<endl;
                    }
                }
                break;
            }
            case 7: {
                cout<<"==== FIND MAXIMUM ELEMENT ===="<<endl;
                if(size == 0){
                    cout<<"Array is empty! Cannot find maximum element."<<endl;
                }
                else{
                    int maxElement = arr[0];
                    for(int i = 1; i < size; i++){
                        if(arr[i] > maxElement){
                            maxElement = arr[i];
                        }
                    }
                    cout<<"Maximum Element: "<<maxElement<<endl;
                }
                break;
            }
            case 8: {
                cout<<"==== FIND MINIMUM ELEMENT ===="<<endl;
                if(size == 0){
                    cout<<"Array is empty! Cannot find minimum element."<<endl;
                }
                else{
                    int minElement = arr[0];
                    for(int i = 1; i < size; i++){
                        if(arr[i] < minElement){
                            minElement = arr[i];
                        }
                    }
                    cout<<"Minimum Element: "<<minElement<<endl;
                }
                break;
            }
            case 9: {
                cout<<"==== CALCULATE SUM OF ELEMENTS ===="<<endl;
                if(size == 0){
                    cout<<"Array is empty! Cannot calculate sum."<<endl;
                }
                else{
                    int sum = 0;
                    for(int i = 0; i < size; i++){
                        sum += arr[i];
                    }
                    cout<<"Sum of Elements: "<<sum<<endl;
                }
                break;
            }
            case 10: {
                cout<<"==== CALCULATE AVERAGE OF ELEMENTS ===="<<endl;
                if(size == 0){
                    cout<<"Array is empty! Cannot calculate average."<<endl;
                }
                else{
                    int sum = 0;
                    for(int i = 0; i < size; i++){
                        sum += arr[i];
                    }
                    double average = static_cast<double>(sum) / size;
                    cout<<"Average of Elements: "<<average<<endl;
                }
                break;
            }
            case 11: {
                cout<<"==== REVERSE ARRAY ===="<<endl;
                if(size == 0){
                    cout<<"Array is empty! Cannot reverse."<<endl;
                }
                else{
                    for(int i = 0; i < size / 2; i++){
                        swap(arr[i], arr[size - i - 1]);
                    }
                    cout<<"Array Reversed Successfully!"<<endl;
                }
                break;
            }
            case 12: {
                cout<<"==== SORT ASCENDING ORDER ===="<<endl;
                if(size == 0){
                    cout<<"Array is empty! Cannot sort."<<endl;
                }
                else{
                    for(int i = 0; i < size - 1; i++){
                        for(int j = 0; j < size - i - 1; j++){
                            if(arr[j] > arr[j + 1]){
                                swap(arr[j], arr[j + 1]);
                            }
                        }
                    }
                    cout<<"Array Sorted in Ascending Order!"<<endl;
                }
                break;
            }
            case 13: {
                cout<<"==== SORT DESCENDING ORDER ===="<<endl;
                if(size == 0){
                    cout<<"Array is empty! Cannot sort."<<endl;
                }
                else{
                    for(int i = 0; i < size - 1; i++){
                        for(int j = 0; j < size - i - 1; j++){
                            if(arr[j] < arr[j + 1]){
                                swap(arr[j], arr[j + 1]);
                            }
                        }
                    }
                    cout<<"Array Sorted in Descending Order!"<<endl;
                }
                break;
            }
            case 14: {
                cout<<"==== COUNT EVEN AND ODD ELEMENTS ===="<<endl;
                if(size == 0){
                    cout<<"Array is empty! Cannot count."<<endl;
                }
                else{
                    int evenCount = 0, oddCount = 0;
                    for(int i = 0; i < size; i++){
                        if(arr[i] % 2 == 0){
                            evenCount++;
                        }
                        else{
                            oddCount++;
                        }
                    }
                    cout<<"Even Elements Count: "<<evenCount<<endl;
                    cout<<"Odd Elements Count: "<<oddCount<<endl;
                }
                break;
            }
            case 15: {
                cout<<"==== COUNT POSITIVE AND NEGATIVE ELEMENTS ===="<<endl;
                if(size == 0){
                    cout<<"Array is empty! Cannot count."<<endl;
                }
                else{
                    int positiveCount = 0, negativeCount = 0;
                    for(int i = 0; i < size; i++){
                        if(arr[i] > 0){
                            positiveCount++;
                        }
                        else if(arr[i] < 0){
                            negativeCount++;
                        }
                    }
                    cout<<"Positive Elements Count: "<<positiveCount<<endl;
                    cout<<"Negative Elements Count: "<<negativeCount<<endl;
                }
                break;
            }
            case 16: {
                cout<<"==== FIND SECOND LARGEST ELEMENT ===="<<endl;
                if(size < 2){
                    cout<<"Array must have at least two elements to find the second largest."<<endl;
                }
                else{
                    int largest = arr[0], secondLargest = INT_MIN;
                    for(int i = 1; i < size; i++){
                        if(arr[i] > largest){
                            secondLargest = largest;
                            largest = arr[i];
                        }
                        else if(arr[i] > secondLargest && arr[i] != largest){
                            secondLargest = arr[i];
                        }
                    }
                    if(secondLargest == INT_MIN){
                        cout<<"There is no second largest element."<<endl;
                    }
                    else{
                        cout<<"Second Largest Element: "<<secondLargest<<endl;
                    }
                }
                break;
            }
            case 17: {
                cout<<"==== FIND SECOND SMALLEST ELEMENT ===="<<endl;
                if(size < 2){
                    cout<<"Array must have at least two elements to find the second smallest."<<endl;
                }
                else{
                    int smallest = arr[0], secondSmallest = INT_MAX;
                    for(int i = 1; i < size; i++){
                        if(arr[i] < smallest){
                            secondSmallest = smallest;
                            smallest = arr[i];
                        }
                        else if(arr[i] < secondSmallest && arr[i] != smallest){
                            secondSmallest = arr[i];
                        }
                    }
                    if(secondSmallest == INT_MAX){
                        cout<<"There is no second smallest element."<<endl;
                    }
                    else{
                        cout<<"Second Smallest Element: "<<secondSmallest<<endl;
                    }
                }
                break;
            }
            case 18: {
                cout<<"==== REMOVE DUPLICATE ELEMENTS ===="<<endl;
                if(size == 0){
                    cout<<"Array is empty! Cannot remove duplicates."<<endl;
                }
                else{
                    int newSize = size;
                    for(int i = 0; i < newSize; i++){
                        for(int j = i + 1; j < newSize; j++){
                            if(arr[i] == arr[j]){
                                for(int k = j; k < newSize - 1; k++){
                                    arr[k] = arr[k + 1];
                                }
                                newSize--;
                                j--;
                            }
                        }
                    }
                    size = newSize;
                    cout<<"Duplicates Removed! New Size: "<<size<<endl;
                }
                break;
            }
            case 19: {
                cout<<"==== MERGE TWO ARRAYS ===="<<endl;
                int arr2[100], size2;
                cout<<"Enter the size of the second array (max 100): ";
                cin>>size2;
                if(size2 < 1 || size2 > 100){
                    cout<<"Invalid Size!"<<endl;
                }
                else{
                    cout<<"Enter "<<size2<<" elements for the second array: ";
                    for(int i = 0; i < size2; i++){
                        cin>>arr2[i];
                    }
                    if(size + size2 > 100){
                        cout<<"Cannot merge! Total size exceeds 100."<<endl;
                    }
                    else{
                        for(int i = 0; i < size2; i++){
                            arr[size + i] = arr2[i];
                        }
                        size += size2;
                        cout<<"Arrays Merged Successfully! New Size: "<<size<<endl;
                    }
                }
                break;
            }
            case 20: {
                cout<<"==== COPY ARRAY ===="<<endl;
                int arrCopy[100];
                for(int i = 0; i < size; i++){
                    arrCopy[i] = arr[i];
                }
                cout<<"Array Copied Successfully!"<<endl;
                cout<<"Copied Array Elements: ";
                for(int i = 0; i < size; i++){
                    cout<<arrCopy[i]<<" ";
                }
                cout<<endl;
                break;
            }
            case 21: {
                cout<<"Exiting the program. Goodbye!"<<endl;
                break;
            }
            default: {
                cout<<"Invalid Choice! Please try again."<<endl;
                break;
            }
            
            
        }
      
    
    }
    while(choice != 21);
    return 0;

}