#include <iostream>

using namespace std;

// Callback function for success
void onSuccess() {
    cout << "Operation was successful!" << endl;
}

// Callback function for failure
void onFailure() {
    cout << "Operation failed!" << endl;
}

// Callback function for progress update
void onProgress() {
    cout << "Operation is in progress..." << endl;
}

// Function that accepts a callback function
void performOperation(void (*callback)()) {
    // Simulate some operations with conditions
    int status = rand() % 3;  // Random status: 0 = success, 1 = failure, 2 = progress

    if (status == 0) {
        callback = onSuccess;  // Set callback to onSuccess
    } else if (status == 1) {
        callback = onFailure;  // Set callback to onFailure
    } else {
        callback = onProgress;  // Set callback to onProgress
    }

    // Invoke the callback function
    callback();
}

int main() {
    // Random seed for simulating different outcomes
    srand(time(0));

    // Perform the operation multiple times to demonstrate different callbacks
    for (int i = 0; i < 5; ++i) {
        performOperation(nullptr);  // Pass a function pointer (nullptr initially)
    }

    return 0;
}
