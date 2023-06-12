#include <iostream>
#include "Operations.h"
#include "Paint.h"
#include "History.h"
/**
* Main function
*/
int main() {

    // Create an instance of the Operations class
    Operations operations;
    int choice;
    int count = 0;

    // Create an instance of the Paint class
    Paint paint;

    // Create an instance of the History class
    History history;

    //TO DO: Quick refactor would be to have the default string for the first prompt and then this one on count more than one, as this is hard to read. Might fix after I have all the functionalities I plan to have
    std::string operationPrompt = "Please choose another operation or quit the program:\n";

    //Loop the program until the user chooses to quit
    while (true) {

        if( count == 0 ) {
            operationPrompt = "Please choose an operation:\n";
        }

        std::cout << operationPrompt << std::endl;
        std::cout << "1. Basic Arithmetic" << std::endl;
        std::cout << "2. Fibonacci Calculation" << std::endl;
        std::cout << "3. Factoriel" << std::endl;
        std::cout << "4. Read History" << std::endl;
        std::cout << "5. Delete History ;)" << std::endl;
        std::cout << "6. Quit" << std::endl;
        std::cout << "Enter your choice (1-6):";
        std::cin >> choice;

        if (choice == 1) {
            int a, b;
            std::string operatorSymbol;

            std::cout << "Enter the first number: ";
            std::cin >> a;
            std::cout << "Enter the operator (+, -, *, /): ";
            std::cin >> operatorSymbol;
            std::cout << "Enter the second number: ";
            std::cin >> b;

            int result;

            //This string compare should cover the string operations funcionality
            //Why does this return 0 when it's true? I would expect it to return 1.
            if (operatorSymbol.compare("+") == 0) {
                result = operations.add(a, b);
                paint.resultsPaint(result);
            } else if (operatorSymbol.compare("-") == 0) {
                result = operations.subtract(a, b);
                paint.resultsPaint(result);
            } else if (operatorSymbol.compare("*") == 0) {
                result = operations.multiply(a, b);
                paint.resultsPaint(result);
            } else if (operatorSymbol.compare("/") == 0) {
                float divisionResult = operations.divide(a, b);
                if (divisionResult != 0.0f) {
                    paint.resultsPaint(divisionResult);
                }
            } else {
                std::cout << "Invalid operator entered." << std::endl;
            }
            history.saveHistory( std::to_string(a) + " " + operatorSymbol + " " + std::to_string(b), result );
        } else if (choice == 2) {
            int n;
            std::cout << "Enter the fibonachi number you want to know: ";
            std::cin >> n;

            int result = operations.fibonacci(n);

            paint.resultsPaint(result);

            history.saveHistory( "Fibonacci number " + std::to_string(n), result );

        } else if (choice == 3) {
            int n;
            std::cout << "Enter the number you want to know the factoriel of: ";
            std::cin >> n;

            int result = operations.factoriel(n);

            paint.resultsPaint(result);

            history.saveHistory( "Factoriel of " + std::to_string(n), result );

        } else if(choice == 4) {
            history.readHistory();
        } else if(choice == 5) {
            history.deleteHistory();
        } else if (choice == 6) {
            break;
        } else {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }

        std::cout << std::endl;
        count += 1;
    }

    return 0;
}
