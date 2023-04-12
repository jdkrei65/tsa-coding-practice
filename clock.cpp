/** PROBLEM 3 - CLOCK HANDS
 * Create a program that finds the angle between the hour hands
 * of two 12 hour analog clocks. For the purpose of this problem you
 * should ignore the minute hands, and only use the angle of the hour
 * hands, but keep in mind that the hour hand still depends on the
 * minutes - Eg at 11:30, the hour hand is halfway between 11 and 12.
 *
 * The input to your program will be two times, as follows:
 *
 * HH:MMTT HH:MMTT
 *
 * Where HH is the hours, MM is the minutes (00 < HH <= 12) and
 * (00 < MM < 60), and TT is either AM or PM
 * 
 * Your program should print the largest (latest in the day) of the two
 * times. Your program should print the time in the form HH:MMTT, or
 * "equal" if the two times are equal.
 * 
 * On a new line, your program should print the smallest positive angle,
 * in degrees, made from the hour hands of the two clocks. Your program
 * should round the answer to the nearest degree.
 * 
 * You may assume:
 * - The input is formatted as specified above, and will not contain
 *   any characters other than 0-9, space, and : (colon)
 * - If an input number, for example HH is less two digits, it will be
 *   left-zero-padded to be two digits.
 * - The input will end with a newline
 * 
 * Your program should not prompt for input or print anything other
 * than specified above. A trailing newline is optional.
 * 
 * SAMPLE TESTS
 * (Sample 1)
 * 12:00AM 11:59PM      <-- Input
 * 11:59PM              <-- Output
 * 1                    <-- Output
 * 
 * (Sample 2)
 * 04:30PM 05:30PM      <-- Input
 * equal                <-- Output
 * 0                    <-- Output
 * 
 * (Sample 3)
 * 01:00AM 09:47PM      <-- Input
 * 09:47PM              <-- Output
 * 117                  <-- Output
 * 
 * (Sample 4)
 * 12:00AM 06:00PM      <-- Input
 * 06:00PM              <-- Output
 * 180                  <-- Output
 * 
*/



// ----------------------
// Sample solution in c++
// ----------------------



#include <iostream>
#include <string>
#include <cmath>

int hoursToDeg(int hours) {
    const int degPerHour{ 30 }; // 360 deg / 12 hrs = 30deg/hr
    return hours * degPerHour;
}
double minutesToDeg(int minutes) {
    const double degPerMin{ 0.5 }; // 30deg/hr / 60 min = 0.5deg/min
    return minutes * degPerMin;
}

int main() {
    std::string time1{ };
    std::string time2{ };
    std::cin >> time1;
    std::cin >> time2;

    // No bounds-checking is needed, because it won't throw as long
    // as the input is as specified in the problem.
    // But it can be useful for fixing bugs, so i'm including it

    if (time1.size() < 7 || time2.size() < 7) {
        std::cout << "Input is too short!\n";
        return -1;
    }

    // Grab each section of the input and convert it to an integer
    int hours1{ std::stoi(time1.substr(0, 2)) };
    int minutes1{ std::stoi(time1.substr(3, 2)) };
    std::string half1{ time1.substr(5, 2) };

    int hours2{ std::stoi(time2.substr(0, 2)) };
    int minutes2{ std::stoi(time2.substr(3, 2)) };
    std::string half2{ time2.substr(5, 2) };

    // 12:00 is really 0:00
    if (hours1 == 12) hours1 = 0;
    if (hours2 == 12) hours2 = 0;

    // Get the angle of each time
    double firstAngle{ hoursToDeg(hours1) + minutesToDeg(minutes1) };
    double secondAngle{ hoursToDeg(hours2) + minutesToDeg(minutes2) };

    double difference{ firstAngle - secondAngle };

    // When given a valid time, -360 < difference < 360
    // Again, not a necesary check for this problem, but useful
    // while creating the program
    if (difference <= -360 || difference >= 360) {
        std::cout << "Invalid time!\n";
        return -1;
    }

    // The problem wants the positive, smaller angle
    if (difference < 0) difference *= -1;
    if (difference > 180) difference = 180 - (difference - 180);

    // Print the latest time
    if (half1 == half2) {
        // If the times are the same half of the day,
        // later times will have a greater angle
        if (firstAngle > secondAngle) {
            std::cout << time1 << '\n';
        } else if (secondAngle > firstAngle) {
            std::cout << time2 << '\n';
        } else {
            std::cout << "equal\n";
        }

    // If one time is PM, it's later
    } else if (half2 == "PM") {
        std::cout << time2 << '\n';
    } else {
        std::cout << time1 << '\n';
    }

    std::cout << std::round(difference) << '\n';
}

