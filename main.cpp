#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <cmath>

using namespace std;

//Printing which table from our additional table is greater or printing both if there are equal
void DefineMultiple(int highest_arr[3], int lowest_arr[3]){
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
}

//Presenting Array function
void showArray( int arr[], int leangth_of_the_array){
    cout<<endl<<"[ ";
    for(int i=0;i<leangth_of_the_array;i++){
        cout<<arr[i]<<", ";
    }
    cout<<"]"<<endl<<endl;
}

//Whole function with working algorithm and reference to DefineMultiple function
void Algorithm( int arr[], int leangth_of_the_array, int highest_arr[3], int lowest_arr[3])
{

    for(int i=0; i<leangth_of_the_array;i++)
    {
        if(arr[i] == highest_arr[0] && i != 0){
            highest_arr[1] = arr[i];
        }
        else if(arr[i] > highest_arr[0]){
            highest_arr[1] = highest_arr[0];
            highest_arr[0] = arr[i];
        }
        else if(arr[i] < highest_arr[0] && arr[i] > highest_arr[1]){
            highest_arr[1] = arr[i];
        }
    }
    for(int i=0;i<leangth_of_the_array;i++){
        if(arr[i] == lowest_arr[0] && i != 0){
            lowest_arr[1] = arr[i];
        }
        else if(arr[i] < lowest_arr[0]){
            lowest_arr[1] = lowest_arr[0];
            lowest_arr[0] = arr[i];
        }
        else if(arr[i] > lowest_arr[0] && arr[i] < lowest_arr[1]){
            lowest_arr[1] = arr[i];
        }
    }

    highest_arr[2] = highest_arr[0]*highest_arr[1];
    lowest_arr[2] = lowest_arr[0]*lowest_arr[1];

    cout<<"Factors which make maximum product:"<<endl;

    DefineMultiple(highest_arr, lowest_arr);
}
//Menu - Listing of available function and table options
void StartingText(){
    cout<<"Which operation take (Type S,D or R) : "<<endl;
    cout<<"S - static - table initialized directly from code."<<endl;
    cout<<"D - dynamic - make your own table."<<endl;
    cout<<"R - 'random' - take random random table range (from 3 to 30) with random elements (from -50 to 50)."<<endl;
    cout<<endl;
    cout<<"Choose your option: ";
}

char whichOperationToTake;

int main()
{
    srand (( unsigned ) time ( NULL ) ) ;
    while(true){
        //clear console view depending on your OS
        #if __linux__
          system("clear");
        #elif _WIN32
          system("cls");
        #else
          system("clear");
        #endif
        StartingText();
        cin.get(whichOperationToTake);
        //Depending on your which option you took, the future action will take place
        switch(whichOperationToTake)
        {
            case 'S':{
                int arr_static[5] = { -10, 8, 5, -4, 1};
                int size_of_our_array = sizeof(arr_static)/sizeof(int);
                if(size_of_our_array >= 2){

                    int highest_arr[3] = {arr_static[0],arr_static[1],0};
                    int lowest_arr[3] = {arr_static[0],arr_static[1],0};

                    showArray(arr_static, size_of_our_array);

                    auto start = chrono::steady_clock::now();
                    Algorithm(arr_static, size_of_our_array, highest_arr, lowest_arr);
                    auto stop = chrono::steady_clock::now();

                    chrono::duration<double> time_of_algorithm = stop-start;

                    cout<<"Time of algorithm: "<<time_of_algorithm.count()*1000<<"ms"<<endl;
                }

                break;
            }
            case 'D':{
                int elementsInDynamicArray;
                cout<<"How many elements: ";
                cin>>elementsInDynamicArray;

                if(elementsInDynamicArray >=  2){

                    int *dynamicArray = new int[elementsInDynamicArray];

                    for(int i=0;i<elementsInDynamicArray;i++){
                        cout<<i<<": ";
                        cin>>dynamicArray[i];
                    }

                    int highest_arr[3] = {dynamicArray[0],dynamicArray[1],0};
                    int lowest_arr[3] = {dynamicArray[0],dynamicArray[1],0};


                    showArray(dynamicArray, elementsInDynamicArray);

                    auto start = chrono::steady_clock::now();
                    Algorithm(dynamicArray, elementsInDynamicArray, highest_arr, lowest_arr);
                    auto stop = chrono::steady_clock::now();

                    chrono::duration<double> time_of_algorithm = stop-start;

                    cout<<"Time of algorithm: "<<time_of_algorithm.count()*1000<<"ms"<<endl;

                    delete dynamicArray;

                }

                break;
            }
            case 'R':{
                //int randomRange = 10000; Using for algorithm time calculation
                int randomRange = 3 + (rand() % 28);
                int *randomArray = new int[randomRange];
                for(int i=0;i<randomRange;i++){
                    randomArray[i] = -20 + (rand() % 41);
                }

                int highest_arr[3] = {randomArray[0],randomArray[1],0};
                int lowest_arr[3] = {randomArray[0],randomArray[1],0};

                showArray(randomArray, randomRange);

                auto start = chrono::steady_clock::now();
                Algorithm(randomArray, randomRange, highest_arr, lowest_arr);
                auto stop = chrono::steady_clock::now();

                chrono::duration<double> time_of_algorithm = stop-start;

                cout<<"Time of algorithm: "<<time_of_algorithm.count()*1000<<"ms"<<endl;
                delete randomArray;
                break;
            }
            default:{
                cout<<endl<<"Action with this letter is not created."<<endl;
                break;
            }
        }
        getchar();
        getchar();
    }
    return 0;
}
