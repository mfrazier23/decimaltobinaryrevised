//Mikeina Frazier
//05/02/2024
//CSDP 250
//Project 2

#include <iostream>
#include <string>
#include "stack.h"
#include "queue.h"

using namespace std;


string integerToBinary(int number) {
    Stack<int> binaryStack;
    while (number > 0) {
        binaryStack.push(number % 2);
        number /= 2;
    }
    string binary = "";
    while (!binaryStack.isEmpty()) {
        binary += to_string(binaryStack.peek());
        binaryStack.pop();
    }
    return binary;
}


string decimalToBinary(double number) {
    Queue<int> binaryQueue;
    while (number > 0) {
        number *= 2;
        binaryQueue.enqueue(int(number));
        number -= int(number);
    }
    string binary = "";
    while (!binaryQueue.isEmpty()) {
        binary += to_string(binaryQueue.peek());
        binaryQueue.dequeue();
    }
    return binary;
}

int main() {
    // Step 1: Prompt the user to enter a decimal number
    double decimalNumber;
    cout << "Enter a decimal number: ";
    cin >> decimalNumber;

    // Split the number into integer and decimal parts
    int integerPart = int(decimalNumber);
    double decimalPart = decimalNumber - integerPart;

    // Step 2: Convert integer part to binary using stack
    string binaryInteger = integerToBinary(integerPart);

    // Step 3: Convert decimal part to binary using queue
    string binaryDecimal = decimalToBinary(decimalPart);

    // Step 4: Output the result
    cout << "Binary representation of the decimal number: " << binaryInteger << "." << binaryDecimal << endl;

    return 0;
}
