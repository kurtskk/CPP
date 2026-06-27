#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Usage: ./sed_pro <filename> <s1> <s2>" << std::endl;
        return 1;
    }
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    if (s1.empty())
    {
        std::cerr << "Error: s1 cannot be empty (prevents infinite loop)." << std::endl;
        return 1;
    }
    std::ifstream inputFile(filename.c_str());
    if (!inputFile.is_open())
    {
        std::cerr << "Error opening input file: " << filename << std::endl;
        return 1;
    }
    std::string outFilename = filename + ".replace";
    std::ofstream outputFile(outFilename.c_str());
    if (!outputFile.is_open())
    {
        std::cerr << "Error creating output file: " << outFilename << std::endl;
        inputFile.close();
        return 1;
    }
    std::string line;
    bool isFirstLine = true;
    while (std::getline(inputFile, line))
    {
        if (!isFirstLine)
            outputFile << std::endl;
        isFirstLine = false;
        size_t lastPos = 0;
        size_t pos;
        while ((pos = line.find(s1, lastPos)) != std::string::npos)
        {
            outputFile << line.substr(lastPos, pos - lastPos);
            outputFile << s2;
            lastPos = pos + s1.length();
        }
        outputFile << line.substr(lastPos);
    }
    inputFile.close();
    outputFile.close();
    return 0;
}