#include <iostream>
#include <fstream>

//Help from Udacity GPT
class File {
private:
    std::ofstream file;

public:
File(const std::string& filename) : file(filename) {
    if (!file) {
        throw std::runtime_error("Failed to open file");
    }
}

    ~File() {
        file.close();
        std::cout << "File closed successfully!\n";
    }

    void write(const int& score, const int& size, std::string player) {
        std::string t = "Score for " + player + " is now: " + std::to_string(score) + " and size is " + std::to_string(size) + "\n";
        file << t;
    }
};