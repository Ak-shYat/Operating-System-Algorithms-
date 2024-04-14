#include <iostream>
#include <unistd.h>

int main() {
    pid_t child_pid = fork(); // Create a child process

    if (child_pid == -1) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    } else if (child_pid == 0) {
        std::cout << "Child process: PID = " << getpid() << std::endl;
    } else {
        std::cout << "Parent process: PID = " << getpid() << std::endl;
    }

    return 0;
}
