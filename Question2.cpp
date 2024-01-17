// Including the header file
#include <iostream>
#include <unordered_map>
using namespace std;

// Main Function Start Here
int main()
{
    // Taking the size of array and create array according to the size
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];

    // Taking input element of array
    cout << "Enter the element of array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Taking the value of k
    int k;
    cout << "Enter the value of k: ";
    cin >> k;

    // creating the unordered_map
    unordered_map<int, int> umap;

    // Counting the element frequency
    for (int i = 0; i < n; i++)
    {
        umap[arr[i]]++;
    }

    // Create a condition that will match the frequency with k and return element
    for (auto x : umap)
    {
        if (x.second == k)
        {
            cout << x.first << " ";
        }
    }

    return 0;
}