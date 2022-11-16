#ifndef ALGORITHM_H_INCLUDED
#define ALGORITHM_H_INCLUDED

using namespace std;

    int* algorithm(int arr[] ,int highest_arr[3], int lowest_arr[3])
    {
        int size_of_our_array = sizeof(arr)/sizeof(int);
        for(int i=0; i<size_of_our_array;i++)
        {
            cout<<arr[i];
            if(arr[i] > highest_arr[0]){
                highest_arr[0] = arr[i];
            }
            if(arr[i] <= highest_arr[0] && arr[i] > highest_arr[1] && i !=0){
                highest_arr[1] = arr[i];
            }
            if(arr[i] == lowest_arr[0] && i != 0){
                lowest_arr[1] = arr[i];
            }
            if(arr[i] < lowest_arr[0]){
                lowest_arr[1] = lowest_arr[0];
                lowest_arr[0] = arr[i];
            }
            if(arr[i] > lowest_arr[0] && arr[i] < lowest_arr[1]){
                lowest_arr[1] = arr[i];
            }
        }

        int result[6] = {highest_arr[0], highest_arr[1], highest_arr[2], lowest_arr[0], lowest_arr[1], lowest_arr[2]};

        return result;
    }



#endif // ALGORITHM_H_INCLUDED
