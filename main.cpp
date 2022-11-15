#include <iostream>

using namespace std;

char whichOperationToTake;

void StartingText(){
    cout<<"Which operation take (1/2) : "<<endl;
    cout<<"1. static - table initialized directly from code."<<endl;
    cout<<"2. dynamic - make your own table."<<endl;
    cout<<endl;
}

int main()
{
    StartingText();

    int arr_static[5] = {-10, 5, 8, -4, 1};

    int highest_arr[3] = {arr_static[0],arr_static[1],0};
    int lowest_arr[3] = {arr_static[0],arr_static[1],0};

    int size_of_our_array = sizeof(arr_static)/sizeof(int);

    for(int i=0; i<size_of_our_array;i++){
        if(arr_static[i] > highest_arr[0]){
            highest_arr[0] = arr_static[i];
        }
        else if(arr_static[i] <= highest_arr[0] && arr_static[i] > highest_arr[1]){
            highest_arr[1] = arr_static[i];
        }
    }
    for(int i=0; i<size_of_our_array;i++){
        if(arr_static[i] == lowest_arr[0] && i != 0){
            lowest_arr[1] = arr_static[i];
        }
        if(arr_static[i] < lowest_arr[0]){
            lowest_arr[1] = lowest_arr[0];
            lowest_arr[0] = arr_static[i];
        }
        if(arr_static[i] > lowest_arr[0] && arr_static[i] < lowest_arr[1]){
            lowest_arr[1] = arr_static[i];
        }
    }


    highest_arr[2] = highest_arr[0]*highest_arr[1];
    lowest_arr[2] = lowest_arr[0]*lowest_arr[1];


    cout<<"["<<highest_arr[0]<<", "<<highest_arr[1]<<"] - "<<highest_arr[2]<<endl;
    cout<<"["<<lowest_arr[0]<<", "<<lowest_arr[1]<<"] - "<<lowest_arr[2]<<endl;
    cout<<"Factors which make maximum product:"<<endl;

    if(highest_arr[2] == lowest_arr[2]){
        cout<<"["<<highest_arr[0]<<", "<<highest_arr[1]<<"] - "<<highest_arr[2]<<endl;
        cout<<"["<<lowest_arr[0]<<", "<<lowest_arr[1]<<"] - "<<lowest_arr[2]<<endl;
    }else{
        if(highest_arr[2] > lowest_arr[2]){
            cout<<"["<<highest_arr[0]<<", "<<highest_arr[1]<<"] - "<<highest_arr[2]<<endl;
        }else{
            cout<<"["<<lowest_arr[0]<<", "<<lowest_arr[1]<<"] - "<<lowest_arr[2]<<endl;
        }
    }

    return 0;
}
