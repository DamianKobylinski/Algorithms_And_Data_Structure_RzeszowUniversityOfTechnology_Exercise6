#include <iostream>

using namespace std;

int main()
{

    int arr[13] = {4,3,2,-10,4,5,2,4,7,3,2,6,7};

    int highest_arr[3] = {arr[0],arr[1],0};
    int lowest_arr[3] = {arr[0],arr[1],0};

    int size_of_our_array = sizeof(arr)/sizeof(int);

    for(int i=0; i<size_of_our_array;i++){
        if(arr[i] > highest_arr[0]){
            highest_arr[0] = arr[i];
        }
        if(arr[i] <= highest_arr[0] && arr[i] > highest_arr[1]){
            highest_arr[1] = arr[i];
        }
        if(arr[i] < lowest_arr[0]){
            lowest_arr[0] = arr[i];
        }
        if(arr[i] > lowest_arr[0] && arr[i] < lowest_arr[1]){
            lowest_arr[1] = arr[i];
        }
    }

    highest_arr[2] = highest_arr[0]*highest_arr[1];
    lowest_arr[2] = lowest_arr[0]*lowest_arr[1];


    cout<<highest_arr[0]<<highest_arr[1]<<" - "<<highest_arr[2]<<endl;
    cout<<lowest_arr[0]<<lowest_arr[1]<<" - "<<lowest_arr[2]<<endl;
    return 0;
}
