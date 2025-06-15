#include <iostream>
#include <string>
#include <map>
#include <cmath>
#include <cctype>
#include <stack>
#include <algorithm>

using namespace std;

// Function to evaluate the arithmetic expression
double evaluateExpression(const string& expr, const map<char, double>& vars) {
    stack<double> values;
    stack<char> ops;

    for (size_t i = 0; i < expr.length(); i++) {
        if (expr[i] == ' ') continue;

        if (isalpha(expr[i])) {
            values.push(vars.at(expr[i]));
        } else if (isdigit(expr[i])) {
            double val = 0;
            while (i < expr.length() && isdigit(expr[i])) {
                val = (val * 10) + (expr[i] - '0');
                i++;
            }
            i--;
            values.push(val);
        } else if (expr[i] == '(') {
            ops.push(expr[i]);
        } else if (expr[i] == ')') {
            while (!ops.empty() && ops.top() != '(') {
                double val2 = values.top(); values.pop();
                double val1 = values.top(); values.pop();
                char op = ops.top(); ops.pop();

                if (op == '+') values.push(val1 + val2);
                else if (op == '-') values.push(val1 - val2);
                else if (op == '*') values.push(val1 * val2);
                else if (op == '/') values.push(val1 / val2);
            }
            ops.pop(); // Remove '(' from stack
        } else {
            while (!ops.empty() && ops.top() != '(' &&
                   ((expr[i] == '*' || expr[i] == '/') ? (ops.top() == '*' || ops.top() == '/') : true)) {
                double val2 = values.top(); values.pop();
                double val1 = values.top(); values.pop();
                char op = ops.top(); ops.pop();

                if (op == '+') values.push(val1 + val2);
                else if (op == '-') values.push(val1 - val2);
                else if (op == '*') values.push(val1 * val2);
                else if (op == '/') values.push(val1 / val2);
            }
            ops.push(expr[i]);
        }
    }

    while (!ops.empty()) {
        double val2 = values.top(); values.pop();
        double val1 = values.top(); values.pop();
        char op = ops.top(); ops.pop();

        if (op == '+') values.push(val1 + val2);
        else if (op == '-') values.push(val1 - val2);
        else if (op == '*') values.push(val1 * val2);
        else if (op == '/') values.push(val1 / val2);
    }

    return values.top();
}

// Function to check if two expressions are equivalent
bool areExpressionsEquivalent(const string& expr1, const string& expr2) {
    // Extract unique variables from both expressions
    map<char, double> vars;
    for (char c : expr1) {
        if (isalpha(c)) vars[c] = 0;
    }
    for (char c : expr2) {
        if (isalpha(c)) vars[c] = 0;
    }

    // Test with different values for variables
    for (auto& var : vars) {
        var.second = rand() % 100 + 1; // Assign random values to variables
    }

    double result1 = evaluateExpression(expr1, vars);
    double result2 = evaluateExpression(expr2, vars);

    return fabs(result1 - result2) < 1e-6; // Check if results are approximately equal
}

int main() {
    int n;
    cin >> n;
    cin.ignore(); // Ignore the newline after the integer input

    for (int i = 0; i < n; i++) {
        string expr1, expr2;
        getline(cin, expr1);
        getline(cin, expr2);

        if (areExpressionsEquivalent(expr1, expr2)) {
            cout << "TRUE" << endl;
        } else {
            cout << "FALSE" << endl;
        }
    }

    return 0;
}
