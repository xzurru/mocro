#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define BUFFER_SIZE 1024

// Global pointer for the current position in the input expression
const char *input;

// Function prototypes
double parse_expression();
double parse_term();
double parse_factor();

// Parses a number (supports integers and decimals)
double parse_number() {
    double result = 0;
    while (isdigit(*input)) {
        result = result * 10 + (*input - '0');
        input++;
    }
    if (*input == '.') {
        input++;
        double factor = 0.1;
        while (isdigit(*input)) {
            result += (*input - '0') * factor;
            factor *= 0.1;
            input++;
        }
    }
    return result;
}

// Parses factors: numbers or parenthesized expressions
double parse_factor() {
    while (*input == ' ') input++;
    if (*input == '(') {
        input++; // Skip '('
        double result = parse_expression();
        if (*input == ')') {
            input++; // Skip ')'
        } else {
            fprintf(stderr, "Error: unmatched parenthesis\n");
            exit(1);
        }
        return result;
    } else if (isdigit(*input)) {
        return parse_number();
    } else {
        fprintf(stderr, "Error: unexpected character '%c'\n", *input);
        exit(1);
    }
    return 0;
}

// Parses terms: factors combined with * or /
double parse_term() {
    double result = parse_factor();
    while (1) {
        while (*input == ' ') input++;
        if (*input == '*') {
            input++;
            result *= parse_factor();
        } else if (*input == '/') {
            input++;
            double divisor = parse_factor();
            if (divisor != 0)
                result /= divisor;
            else {
                fprintf(stderr, "Error: division by zero\n");
                exit(1);
            }
        } else {
            break;
        }
    }
    return result;
}

// Parses expressions: terms combined with + or -
double parse_expression() {
    double result = parse_term();
    while (1) {
        while (*input == ' ') input++;
        if (*input == '+') {
            input++;
            result += parse_term();
        } else if (*input == '-') {
            input++;
            result -= parse_term();
        } else {
            break;
        }
    }
    return result;
}

int main() {
    char line[BUFFER_SIZE];

    printf("Welcome to mocro language interpreter\n");
    printf("Enter arithmetic expressions (or type 'exit' to quit):\n");

    while (1) {
        printf("> ");
        if (!fgets(line, sizeof(line), stdin))
            break;

        // Exit condition
        if (strncmp(line, "exit", 4) == 0)
            break;

        // Set the global input pointer to the current line and parse it
        input = line;
        double result = parse_expression();
        printf("Result: %lf\n", result);
    }

    return 0;
}
