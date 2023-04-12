/** PROBLEM 2 - ROMAN NUMERALS
 * Create a program that converts a roman numeral to arabic numerals.
 * Roman numerals are written with the following characters
 * Symbol   Arabic numeral value
 * I        1
 * V        5
 * X        10
 * L        50
 * C        100
 * D        500
 * M        1000
 * 
 * When two characters are written together you add them, to make
 * eg II = 2 and VI = 6.
 * However, if a smaller value comes before a large one, you instead
 * subtract the smaller value so IV = (5 - 1) = 4,
 * and XLIV = (50 - 10) + (5 - 1) = (40 + 4) = 44.
 * 
 * Subtraction is only used for:
 * - IV and IX to make 5 and 9
 * - XL and XC to make 40 and 90
 * - CD and CM to make 400 and 900
 * - Any other subtraction, for the purpose of this problem, is
 *    considered an invalid numeral (eg VIL is not valid)
 * 
 * You may assume:
 * - The input is a valid roman numeral (according to the definition
 *   above) which is less than 3,999
 * - The input is all uppercase and includes no characters other than the
 *   roman numeral
 * - The input will end with a newline
 * 
 * Your program should calculate the value of the given roman numeral
 * and print it in arabic numerals (decimal)
 * 
 * Your program should not prompt for input or print anything other
 * than specified above. A trailing newline is optional.
 * 
 * SAMPLE TESTS
 * (Sample 1)
 * V
 * 5
 * 
 * (Sample 2)
 * MMCMXCI
 * 2991
 * 
 * (Sample 3)
 * LIX
 * 59
*/



// ----------------------
// Sample solution in c++
// ----------------------



#include <iostream>
#include <string>

// returns the integer value of a numeral
int valueOf(char numeral) {
    switch (numeral) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default:
            // This should never happen, according to the prompt
            // So you wouldn't have to include this part.
            throw "Invalid Input " + numeral;
    }
}

// NOTE: This program does not check that your numeral is valid
// It will often return unusual results for invalid numerals.
// But, it's okay since the problem allows us to assume the input
// is a valid numeral

int main() {
    // Get user input
    std::string input{ };
    std::cin >> input;

    // Store the total value
    int value{ };

    for (int index{ }; index < input.size(); index += 1) {

        char current{ input.at(index) };
        // Don't check the next char if at the end of the string
        if (index < input.size() - 1) {
            int next{ input.at(index + 1) };
            // If current < next, use subtraction.
            // In a valid roman numeral, this should not cause problems
            if (valueOf(current) < valueOf(next)) {
                value += valueOf(next) - valueOf(current);
                // Skip the next character, it's accounted for right here
                index += 1;
                continue;

            } // else, fall through to below
        }

        // No subtraction? Just add the value
        value += valueOf(current);
        
    }

    std::cout << value << '\n';
}