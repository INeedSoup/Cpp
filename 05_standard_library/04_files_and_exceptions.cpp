/* Learn: file streams use the same stream model as console I/O; exceptions report failures to a caller.
Why: a program must detect when an external resource such as a file is unavailable.
Use: check an opened stream before reading or writing it.
Watch out: this relative file name is created in the program's working directory; opening ofstream truncates an existing file.
Try next: Ask the user for a file name and handle an unreadable file. */
#include <exception>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

int main()
{
    try
    {
        const std::string fileName = "lesson_notes.txt";
        std::ofstream output(fileName);
        if (!output)
        {
            throw std::runtime_error("Could not open the output file.");
        }
        output << "Files are streams.\nAlways check that a file opened successfully.\n";
        output.close();

        std::ifstream input(fileName);
        if (!input)
        {
            throw std::runtime_error("Could not reopen the output file.");
        }

        std::string line;
        while (std::getline(input, line))
        {
            std::cout << line << '\n';
        }
    }
    catch (const std::exception& error)
    {
        std::cerr << "File operation failed: " << error.what() << '\n';
        return 1;
    }
}
