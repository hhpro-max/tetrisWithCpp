#include <iostream>
#include "Space.cpp"
#include <cstdlib>
#include <thread>
#include <chrono>
#include <sys/select.h>
#include <termios.h>
#include <unistd.h>
int main()
{
    // Set terminal to non-blocking mode to read user input
    struct termios old_tio, new_tio;
    tcgetattr(STDIN_FILENO, &old_tio);
    new_tio = old_tio;
    new_tio.c_lflag &= (~ICANON & ~ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_tio);
    Space gameSpace;

    char userInput = NULL;
    std::thread inputThread([&userInput]() {
        while(true){
            fd_set fds;
            FD_ZERO(&fds);
            FD_SET(STDIN_FILENO, &fds);
            struct timeval timeout;
            timeout.tv_sec = 5; // Set the timeout to 0 seconds (non-blocking)
            timeout.tv_usec = 0;
            int ready = select(STDIN_FILENO + 1, &fds, nullptr, nullptr, &timeout);
            if (ready == -1) {
                std::cout << "Error occurred while waiting for input." << std::endl;
                break;
            } else if (ready == 1) {
                char input;
                std::cin.get(input); // Read the user input character
                
                userInput = input;
                std::cout << "User input received: " << userInput << std::endl;
            }
        }

        
        
    });
    
    while(true){
        if(userInput!=NULL){

        }

        std::this_thread::sleep_for(std::chrono::seconds(1));
        system("clear");
        gameSpace.moveDown(1);
        gameSpace.printSpace();
        
    }
    // Restore terminal settings to normal
    tcsetattr(STDIN_FILENO, TCSANOW, &old_tio);
    return 0;
}
