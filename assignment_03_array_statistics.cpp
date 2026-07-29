// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 3
// =============================================================================
//
// TASK: Array Statistics Calculator
//
// Write a C++ program that reads a collection of numbers from the user
// and computes key statistical values using separate functions.
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLE
// -----------------------------------------------------------------------------
//
//   How many numbers? 5
//   Enter number 1: 4
//   Enter number 2: 7
//   Enter number 3: 2
//   Enter number 4: 9
//   Enter number 5: 1
//
//   Results:
//   Sum:     23
//   Average: 4.6
//   Maximum: 9
//   Minimum: 1
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement each calculation in its own function (see scaffold).
// - You may NOT use any standard library functions like accumulate(), max(),
//   or min(). Implement the logic yourself using loops.
// - N must be a positive integer. If the user enters 0 or a negative number,
//   print an error message and stop.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

double calculateSum(double arr[], int size) {
    double total = 0.0;
    for (int i = 0; i < size; i++) {
        total += arr[i];
    }
    return total;
}

// Function to calculate the average
double calculateAverage(double sum, int size) {
    return sum / size;
}

// Function to find the maximum value
double findMax(double arr[], int size) {
    double maxVal = arr[0]; // Start by assuming the first element is the largest
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i]; // Update maxVal if a bigger number is found
        }
    }
    return maxVal;
}

// Function to find the minimum value
double findMin(double arr[], int size) {
    double minVal = arr[0]; // Start by assuming the first element is the smallest
    for (int i = 1; i < size; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i]; // Update minVal if a smaller number is found
        }
    }
    return minVal;
}

int main() {
    int n;

    // Prompt for array size
    cout << "How many numbers? ";
    cin >> n;

    // Requirement: N must be a positive integer
    if (n <= 0) {
        cout << "Error: Please enter a positive number greater than 0." << endl;
        return 1; // Exit the program early on error
    }

    // Declare an array to hold N numbers
    double numbers[n];

    // Read the numbers from the user
    for (int i = 0; i < n; i++) {
        cout << "Enter number " << (i + 1) << ": ";
        cin >> numbers[i];
    }

    // Perform calculations using our custom functions
    double sum = calculateSum(numbers, n);
    double avg = calculateAverage(sum, n);
    double maxVal = findMax(numbers, n);
    double minVal = findMin(numbers, n);

    // Display the results exactly as formatted in the example
    cout << "\nResults:" << endl;
    cout << "Sum:     " << sum << endl;
    cout << "Average: " << avg << endl;
    cout << "Maximum: " << maxVal << endl;
    cout << "Minimum: " << minVal << endl;

    return 0;
}

