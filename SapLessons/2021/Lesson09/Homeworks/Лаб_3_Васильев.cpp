//#include "stdafx.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    //���������� �������
    int rows = 3; int cols = 4;
    float** arr = new float* [rows];
    for (int i = 0; i < rows; i++)
    {
        arr[i] = new float[cols];
    }
    ///////////////////////////////

    //���������� ������� ���������� �� �����
    string path = "C:\\Users\\d.vasiLEV\\Desktop\\���-151\\3 �������\\���_3.txt";
    ifstream fin;
    fin.open(path);
    if (!fin.is_open())
    {
        cout << "������ �������� �����!" << endl;
    }
    else {
        cout << "���� ������" << endl;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                fin >> arr[i][j];
            }
        }
    }
    ///////////////////////////////

    //����� �������
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%10.3f", arr[i][j]);
        }
        cout << "\n";
    }
    ///////////////////////////////////

    system("pause");
    return 0;
}


    // 1
    //const int rows = 3; const int cols = 4;

    // 2
    //string path = "input3_4.txt";

    // 3
    // cout.setf(ios::fixed);
    // cout.precision(3);
    // for (int i = 0; i < rows; i++)
    // {
    //     for (int j = 0; j < cols; j++)
    //     {
    //         cout.width(10);
    //         cout << arr[i][j];
    //         //printf("%10.3f", arr[i][j]);
    //     }
    //     cout << "\n";
    // }
    
    // 4
    // for (int i = 0; i < rows; i++)
    // {
    //     delete[] arr[i];
    // }
    // delete[] arr;