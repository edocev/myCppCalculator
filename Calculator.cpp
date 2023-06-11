#include <iostream>
#include <string>

using namespace std;

/**
* Operations class
* This class contains the implementation of the basic arithmetic operations
*
*/
class Operations {
public:
    int add(int a, int b) {
        return a + b;
    }

    int subtract(int a, int b) {
        return a - b;
    }

    int multiply(int a, int b) {
        return a * b;
    }

    float divide(int a, int b) {
        if (b != 0) {
            return static_cast<float>(a) / b;
        } else {
            std::cout << "Error: Division by zero is undefined." << std::endl;
            return 0.0f;
        }
    }

    int fibonacci(int n) {
        if (n <= 0) {
            std::cout << "Error: Invalid input for Fibonacci calculation." << std::endl;
            return 0;
        } else if (n == 1 || n == 2) {
            //Little hack as the first two nums of fibonacci are both one and my recursive function won't really work for them
            return 1;
        } else {
            return fibonacci(n - 1) + fibonacci(n - 2);
        }
    }

    int factoriel( int n ) {
        if ( n <= 0 ) {
            std::cout << "Error: Invalid input for factorial calculation." << std::endl;
            return 0;
        } else if ( n == 1 ) {
            //Same as with fibonacci, the first number is one
            return 1;
        } else {
            return n * factoriel( n - 1 );
        }
    }
};


/**
* Paint class
* This class contains the implementation of the ASCII art for the prompts and results
*/
class Paint {

// Let's overload this to be able to handle both float and int results.
public:
    void resultsPaint(int result) {
        string resultStr = to_string(result);
        paintBox(resultStr);
    }

    void resultsPaint(float result) {
        string resultStr = to_string(result);
        paintBox(resultStr);
    }

private:
    void paintBox(const string& resultStr) {
        int boxWidth = resultStr.length() + 4;

        // Print the top border
        for (int i = 0; i < boxWidth; i++) {
            cout << "—";
        }
        cout << endl;

        // Print the result line
        cout << "| " << resultStr << " |" << endl;

        // Print the bottom border
        for (int i = 0; i < boxWidth; i++) {
            cout << "—";
        }
        cout << endl;
    }
};

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

    //TO DO: Quick refactor would be to have the default string for the first prompt and then this one on count more than one, as this is hard to read. Might fix after I have all the functionalities I plan to have
    std::string operation_prompt = "Please choose another operation or quit the programm:\n";

    //Loop the program until the user chooses to quit
    while (true) {

        if( count == 0 ) {
            operation_prompt = "Please choose an operation:\n";
        }

        std::cout << operation_prompt << std::endl;
        std::cout << "1. Basic Arithmetic" << std::endl;
        std::cout << "2. Fibonacci Calculation" << std::endl;
        std::cout << "3. Factoriel" << std::endl;
        std::cout << "4. Quit" << std::endl;
        std::cout << "Enter your choice (1-4):";
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
        } else if (choice == 2) {
            int n;
            std::cout << "Enter the fibonachi number you want to know: ";
            std::cin >> n;

            int result = operations.fibonacci(n);

            paint.resultsPaint(result);

        } else if (choice == 3) {
            int n;
            std::cout << "Enter the number you want to know the factoriel of: ";
            std::cin >> n;

            int result = operations.factoriel(n);

            paint.resultsPaint(result);

        } else if (choice == 4) {
            break;
        } else {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }

        std::cout << std::endl;
        count += 1;
    }

    return 0;
}
