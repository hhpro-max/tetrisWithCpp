/*#include <iostream>
#include <thread>
#include <chrono>
int main() {
    for (int i = 0; i <= 100; i++) {
        std::cout << "Progress: " << i << "%\r";
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::seconds(1));
        // Simulate some work being done
        // In a real-world scenario, you might replace this with actual computation or tasks.
        // For example: Sleep(100);
    }

    std::cout << std::endl << "Task complete!" << std::endl;

    return 0;
}*/
/*#include <iostream>
#include <thread>
#include <chrono>

int main() {
    std::cout << "Press any key within 1 second to continue..." << std::endl;

    // Start a separate thread for user input
    char userInput = NULL;
    std::thread inputThread([&userInput]() {
        char input = std::getchar();
        userInput = input;
    });

    // Wait for 1 second for user input
    std::this_thread::sleep_for(std::chrono::seconds(5));

    // Check if user input has been received
    if (userInput!=NULL) {
        std::cout << "User input received! Continuing..." << std::endl;
    } else {
        std::cout << "No user input received. Continuing..." << std::endl;
    }

    // Join the input thread to avoid potential issues
    inputThread.join();

    return 0;
}*/
/*
#include <iostream>
#include <sys/select.h>
#include <termios.h>
#include <unistd.h>

int main() {
    std::cout << "Type anything within 5 seconds to continue..." << std::endl;

    // Set terminal to non-blocking mode to read user input
    struct termios old_tio, new_tio;
    tcgetattr(STDIN_FILENO, &old_tio);  // Get the current terminal settings
    new_tio = old_tio;
    new_tio.c_lflag &= (~ICANON & ~ECHO); // Disable canonical mode and local echo
    tcsetattr(STDIN_FILENO, TCSANOW, &new_tio); // Apply the new terminal settings

    // Wait for 5 seconds for user input
    fd_set fds;
    FD_ZERO(&fds); // Clear the set
    FD_SET(STDIN_FILENO, &fds); // Add STDIN_FILENO (0) to the set

    struct timeval timeout;
    timeout.tv_sec = 5; // Set the timeout to 5 seconds
    timeout.tv_usec = 0;

    int ready = select(STDIN_FILENO + 1, &fds, nullptr, nullptr, &timeout);
    // Use select() to check if input is available on STDIN_FILENO (0) within the timeout

    // Restore terminal settings to normal
    tcsetattr(STDIN_FILENO, TCSANOW, &old_tio); // Revert to the original terminal settings

    if (ready == -1) {
        std::cout << "Error occurred while waiting for input." << std::endl;
    } else if (ready == 0) {
        std::cout << "No input received within 5 seconds. Continuing..." << std::endl;
    } else {
        char input;
        std::cin.get(input); // Read the user input character
        std::cout << "User input received: " << input << std::endl;
    }

    return 0;
}
*/
/*
#include <iostream>
#include <sys/select.h>
#include <termios.h>
#include <unistd.h>

int main() {
    std::cout << "Type anything and press Enter to continue..." << std::endl;

    // Set terminal to non-blocking mode to read user input
    struct termios old_tio, new_tio;
    tcgetattr(STDIN_FILENO, &old_tio);
    new_tio = old_tio;
    new_tio.c_lflag &= (~ICANON & ~ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_tio);

    // Use non-blocking I/O to continuously check for user input
    while (true) {
        fd_set fds;
        FD_ZERO(&fds);
        FD_SET(STDIN_FILENO, &fds);

        struct timeval timeout;
        timeout.tv_sec = 0; // Set the timeout to 0 seconds (non-blocking)
        timeout.tv_usec = 0;

        int ready = select(STDIN_FILENO + 1, &fds, nullptr, nullptr, &timeout);

        if (ready == -1) {
            std::cout << "Error occurred while waiting for input." << std::endl;
            break;
        } else if (ready == 1) {
            char input;
            std::cin.get(input); // Read the user input character
            std::cout << "User input received: " << input << std::endl;
            break;
        }

        // Do other processing or tasks here while waiting for input
        // For example, you can perform some computations, update the display, etc.
    }

    // Restore terminal settings to normal
    tcsetattr(STDIN_FILENO, TCSANOW, &old_tio);

    return 0;
}
*/
/*template <size_t pRows, size_t pCols>
void spawnNewItem(Place (&arr)[pRows][pCols]) {
        };
*/

// C++ program to demonstrate
// the use of rand()
/*
#include <iostream>
#include <random>

int main() {
    // Create a random number engine (Mersenne Twister engine)
    std::random_device rd; // Used to obtain a random seed
    std::mt19937 gen(rd()); // Mersenne Twister engine

    // Define the range for the random number
    int minNum = 1;
    int maxNum = 100;

    // Create a uniform distribution for integers in the specified range
    std::uniform_int_distribution<int> dist(minNum, maxNum);

    // Generate a random number within the specified range
    int randomNumber = dist(gen);

    // Print the generated random number
    std::cout << "Random number: " << randomNumber << std::endl;

    return 0;
}
*/
/*
#include<iostream>
#include<cstdlib>
using namespace std;

int main(){

	// Providing a seed value
	srand((unsigned) time(NULL));

	// Loop to get 5 random numbers
	for(int i=1; i<=5; i++){
		
		// Retrieve a random number between 100 and 200
		// Offset = 100
		// Range = 101
		int random = 100 + (rand() % 101);

		// Print the random number
		cout<<random<<endl;
	}

	return 1;
}
*/
#include <iostream>

int main() {
    bool shouldBreak = false;

    for (int i = 1; i <= 3 && !shouldBreak; i++) {
        std::cout << "Outer Loop: Iteration " << i << std::endl;

        for (int j = 1; j <= 3; j++) {
            if(j == 2){
                break;
            }
            std::cout << j << "\n";
            std::cout << i << "\n";
            
            
        }
    }

    std::cout << "Continuing with the code after the outer loop." << std::endl;

    return 0;
}


