// HOLLOW HALF PYRAMID

// #include <iostream>
// using namespace std;

// int main()
// {

//     int n;
//     cout << "Enter value of n: ";
//     cin >> n;

//     for (int row = 0; row < n; row++)
//     {

//         int totalColumns = row + 1;

//         for (int col = 0; col < totalColumns; col++)
//         {
//             if (row == 0 || row == 1 || row == n - 1)
//             {
//                 cout << "* ";
//             }
//             else
//             {
//                 // middle rows
//                 if (col == 0 || col == totalColumns - 1)
//                 {
//                     cout << "* ";
//                 }
//                 else
//                 {
//                     // middle columns
//                     cout << "  ";
//                 }
//             }
//         }
//         cout << endl;
//     }
//     return 0;
// }




// Simpler logic

#include <iostream>
using namespace std;

int main()
{

    int n;
    cout << "Enter value of n: ";
    cin >> n;

    for (int row = 0; row < n; row++)
    {

        int totalColumns = row + 1;

        for (int col = 0; col < totalColumns; col++)
        {
            if (row == 0 || row == n - 1 || col == 0 || col == row)
            {
                cout << "* ";
            }
            else
            {
                    cout << "  ";
               
            }
        }
        cout << endl;
    }
    return 0;
}