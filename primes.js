/** PROBLEM 4 - PRIMES
 * Create a program that finds if a number is a prime number.
 * A prime number is a number that has only two factors: one and
 * itself.
 * 
 * Your program should print "prime" if the number is prime, or
 * "not a prime" if the number is not prime. Then, on a new line, your
 * program should print all of the factors, in ascending numerical
 * order, separated by a space.
 * 
 * You may assume:
 * - The input contains only the digits 0-9
 * - The input is a positive integer, less than the 2,147,483,647 (the
 *   largest signed 32 bit integer)
 * - The input ends in a newline
 * 
 * Your program should not prompt for input or print anything other
 * than specified above. A trailing newline is optional.
 * 
 * SAMPLE TESTS
 * (Sample 1)
 * 426381                               <-- Input
 * not a prime                          <-- Output
 * 1 3 311 457 933 1371 142127 426381   <-- Output
 * 
 * (Sample 2)
 * 17                                   <-- Input
 * prime                                <-- Output
 * 1 17                                 <-- Output
 * 
 */



// ----------------------
// Sample solution in JavaScript
// ----------------------



// Import the standard 'readline' module to get console input
// Unfortunately, getting input in node.js is somewhat convoluted
const readline = require('readline').createInterface({
    // Specify the console (process.stdin/out)
    // As the input and output
    input: process.stdin,
    output: process.stdout
});
  
// readline.question gets input from a prompt
// Use '' as prompt, because we don't want to prompt for input.
readline.question('', (value) => {
    // `value` is a string, make it a number
    const input = Number(value);

    const factors = [1];

    // No use checking anything more than half the number
    const max_factor = input / 2;
    for (let i = 2; i <= max_factor; i++) {
        if (input % i === 0) {
            factors.push(i);
        }
    }

    factors.push(input);

    if (factors.length === 2) {
        console.log("prime");
    } else {
        console.log("not a prime");
    }

    let out = '';
    for (const factor of factors) {
        out += factor + ' ';
    }
    console.log(out);

    // Clean up, Otherwise, the program won't end
    readline.close();
});