#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string fname = "INPUT.TXT";
    string oname = "OUTPUT.TXT";
    int size, maxMas, value;
    vector<int> arr;
    arr.reserve(15000);
    ifstream fileInput(fname);
    if (fileInput.is_open()) {
        fileInput >> size;
        if (size < 1 || size > 15000)
            return 0;
        fileInput >> maxMas;
        if (maxMas < 1 || maxMas > 15000)
            return 0;
        for (int i = 0; !fileInput.eof() && i < size; i++) {
            fileInput >> value;
            if (value < 1 || value > maxMas)
                return 0;
            arr.push_back(value);
        }
    }
    fileInput.close();

    //sort(arr.begin(), arr.end());

    //bool flag = false;
    //int count = 0;
    //while (arr.size() != 0) {
    //    for (int i = 0; i < arr.size();) {
    //        for (int j = arr.size() - 1; j > 0; j--) {
    //            if ((arr[i] + arr[j]) < maxMas) {
    //                count++;
    //                arr.erase(arr.begin() + j);
    //                arr.erase(arr.begin() + i);
    //                flag = true;
    //                break;
    //            }
    //        }
    //        if (flag == false) {
    //            count++;
    //            arr.erase(arr.begin() + i);
    //        }
    //        flag = false;
    //    }
    //}

    sort(arr.begin(), arr.end(), greater<int>());

    /*int count = 0;
    while (arr.size() != 0) {
        for (int i = 0; i < arr.size();) {
            for (int j = arr.size() - 1; j > 0; j--) {
                if (arr[i] + arr[j] > maxMas) {
                    count++;
                    arr.erase(arr.begin() + i);
                    break;
                }
                else {
                    count++;
                    arr.erase(arr.begin() + j);
                    arr.erase(arr.begin() + i);
                    break;
                }
            }
        }
    }*/

    int count = 0, countZero = 0;
    bool flag = false;
    while (flag == false) {
        for (int i = 0; i < arr.size(); ) {
            if (flag == false) {
                for (int j = arr.size() - 1; j > 0; j--) {
                    if (arr[i] == 0)
                        i++;
                    if (arr[j] == 0) {
                        j--;
                    }
                    if (arr[i] + arr[j] > maxMas) {
                        count++;
                        arr[i] = 0;
                        countZero++;
                        if (countZero == size)
                            flag = true;
                        break;
                    }
                    else {
                        count++;
                        arr[i] = 0;
                        arr[j] = 0;
                        countZero += 2;
                        if (countZero == size)
                            flag = true;
                        break;
                    }
                }
            }
            else
                break;
        }
    }

    ofstream fileOutput(oname);
    if (fileOutput.is_open()) {
        fileOutput << count;
    }
    fileOutput.close();

    return 0;
}
