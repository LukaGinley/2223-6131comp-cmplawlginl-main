// #include "Rotary.h"
// #include <iostream>

// using namespace std;

// // Initialize variables
// int min_temp = 5;
// int max_temp = 30;
// int min_humid = 0;
// int max_humid = 100;

// // Define pins for the rotary encoder
// int encoderPinA = 2;
// int encoderPinB = 3;
// Encoder encoder(encoderPinA, encoderPinB);

// // Function to handle rotary encoder input
// void handle_encoder() {
//     // Read the rotary encoder position
//     long newPosition = encoder.read();

//     // Determine whether the user is adjusting temperature or humidity
//     string control;
//     int current_value;
//     if (newPosition % 2 == 0) {
//         control = "temp";
//         current_value = min_temp;
//     }
//     else {
//         control = "humid";
//         current_value = min_humid;
//     }

//     // Determine whether the user is adjusting minimum or maximum value
//     string setting;
//     if (newPosition < 0) {
//         setting = "min";
//     }
//     else {
//         setting = "max";
//     }

//     // Adjust the appropriate value
//     int new_value = current_value + newPosition * 2; // Multiply by 2 to adjust more quickly
//     if (control == "temp") {
//         if (new_value < max_temp && new_value >= 5) {
//             if (setting == "min" && new_value < max_temp) {
//                 min_temp = new_value;
//             }
//             else if (setting == "max" && new_value > min_temp) {
//                 max_temp = new_value;
//             }
//             else {
//                 cout << "Error: Minimum temperature must be below maximum temperature." << endl;
//             }
//         }
//         else {
//             cout << "Error: Temperature range must be between 5-30 degrees Celsius." << endl;
//         }
//     }
//     else if (control == "humid") {
//         if (new_value < max_humid && new_value >= 0) {
//             if (setting == "min" && new_value < max_humid) {
//                 min_humid = new_value;
//             }
//             else if (setting == "max" && new_value > min_humid) {
//                 max_humid = new_value;
//             }
//             else {
//                 cout << "Error: Minimum humidity must be below maximum humidity." << endl;
//             }
//         }
//         else {
//             cout << "Error: Humidity range must be between 0-100%." << endl;
//         }
//     }

//     // Reset the encoder position to zero
//     encoder.write(0);

//     // Output the new values to the MCU's serial/debug port
//     cout << "New temperature range: " << min_temp << "-" << max_temp << " C" << endl;
//     cout << "New humidity range: " << min_humid << "-" << max_humid << "%" << endl;
// }

// int main() {
//     // Example usage: handle rotary encoder input continuously
//     while (true) {
//         handle_encoder();
//     }

//     return 0;
// }
