
/** PROMPT 1 - PANGRAM
 * Create a program that checks if a given input is a pangram.
 * A pangram is a phrase that contains all letters of the alphabet
 * (ingnoring punctuation and spaces) eg "The quick brown fox jumps
 * over the lazy dog".
 * 
 * Your program should print "pangram" if the input is a pangram,
 * or "not a pangram" if the input is not a pangram.
 * On a new line, your program should print all the duplicate
 * letters (in lowercase) if the input is a pangram, or all the missing
 * letters if (in lowercase) the input is not a pangram. The letters
 * should be printed in alphabetical order, separated by spaces.
 * If the program is a pangram and there are no duplicate charcaters,
 * the program should print an empty line.
 * 
 * You may assume:
 * - The input will only include capital and lowercase letters
 *   (a-z, A-Z), spaces, and punctuation.
 * - The input will be less than 100 characters long
 * - The input will end with a newline
 * 
 * Your program should not prompt for input or print anything other
 * than specified above. A trailing newline is optional.
 * 
 * SAMPLE TESTS
 * (Sample 1)
 * Hello, world!                                <-- Input
 * not a pangram                                <-- Output
 * a b c f g i j k m n p q s t u v x y z        <-- Output
 * 
 * (Sample 2)
 * The quick brown fox jumps over the lazy dog  <-- Input
 * pangram                                      <-- Output
 * e h o r t u                                  <-- Output
 * 
 * (Sample 3)
 * abcdefghiklmnopqrstuv                        <-- Input
 * not a pangram                                <-- Output
 * j w x y z                                    <-- Output
 * 
 * (Sample 4)
 * abcdefghijklmnopqrstuvwxzy                   <-- Input
 * pangram                                      <-- Output
 *                                              <-- Output (Empty Line)
*/



/** JESSE'S NOTE
 * Only use standard (default) libraries.
 * If you have to "npm install ___" something, that's not a standard
 * library and not allowed.
 * 
 * You'll want to know how to read console input in node.js, that's a
 * crucial part of most problems.
 * 
 * And keep in mind, node.js is different than browser JavaScript, so
 * you can't just use prompt();
 * 
 * SOME TIPS
 * - Do what you know how to do, and what is easiest for you to code.
 *   Just writing out the alphabet is usually simpler and easier than
 *   finding a clever way to automate it. (See sample program)
 * 
 * - Think out the problem. If you need, write out the steps.
 * 
 * - Follow the prompt to the letter. Your program should do no less
 *   than the prompt, and in most cases it shouldn't do any more than
 *   the prompt.
 * 
 * - Use the sample cases. When you run the program, does the input
 *   and output look exactly like the example?
 * 
 * - If there's an easy way to optimize it, do it. (See primes.js)
 *   But, you're timed. So get a working solution, then optimize.
 * 
*/



// ----------------------
// Below is an example of what I would consider a good
// solution (in JavaScript). This is not the only solution,
// and not necessarily the best.
//
// Try making your own solution before looking at this.
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
  // Make the input lowercase for easier checking
  // For pangrams, in this problem, the case doesn't matter
  const input = value.toLowerCase();

  // There's probably a better way to do this, but this is much easier
  // and perfectly reasonable for this problem
  const allLetters = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
    'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
    'y', 'z'];

  const hasLetters = []; // Count the occurence of letters
  const missingLetters = []; // keep track of missing letters

  // Fill both arrays with the default state
  for (const index in allLetters) {
    // Start assuming all letters are missing
    hasLetters[index] = 0;
    missingLetters[index] = true;
  }

  // Go through each character of the input
  for (const char of input) {
    const index = allLetters.indexOf(char);
    // Add to the letters count, and mark the letter as not missing
    hasLetters[index] += 1;
    missingLetters[index] = false;
  }

  // If any letters are still marked as true, they don't appear in the string,
  // and the input is not a pangram
  if (missingLetters.includes(true)) {
    // console.log prints a newline, so store the letters as a string first
    let out = '';
    for (const index in missingLetters) {
      // Only print missing letters
      if (missingLetters[index]) {
        out += allLetters[index] + ' ';
      }
    }
    console.log('not a pangram');
    console.log(out);

  // Otherwise all the letters are marked false, and the input is a pangram
  } else {
    // console.log prints a newline, so store the letters as a string first
    let out = '';
    for (const index in hasLetters) {
      // Only print duplicate letters
      if (hasLetters[index] >= 2) {
        out += allLetters[index] + ' ';
      }
    }
    console.log('pangram');
    console.log(out);
  }

  // Clean up, Otherwise, the program won't end
  readline.close();
});

// Anything out here would be run **before** you get the console input