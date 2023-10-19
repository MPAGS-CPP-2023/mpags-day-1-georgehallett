#include <cctype>
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char* argv[])
{
    // Convert the command line arguments (CLA) into a more easily useable form
    const std::vector<std::string> cmdLineArgs{argv, argv + argc};
    const std::size_t nCmdLineArgs{cmdLineArgs.size()};

    // Set up booleans and empty strings to save input and output files to
    bool help{false};
    bool version{false};
    bool inputfile{false};
    bool outputfile{false};
    std::string input;
    std::string output;

    // Go through CLAs searching for the flags below
    for (std::size_t i{1}; i < nCmdLineArgs; ++i) { 
        if (cmdLineArgs[i] == "-h" || cmdLineArgs[i] == "--help") {
            help = true;
        }
        else if (cmdLineArgs[i] == "-v" || cmdLineArgs[i] == "--version") {
            version = true;
        }
        else if (cmdLineArgs[i] == "-i" || cmdLineArgs[i] == "--input_file") {
            if (i + 1 < nCmdLineArgs && cmdLineArgs[i+1].find("-")!=0 ){         
            //Check if this isn't the last CLA otherwise if left empty, e.g. -i it gives segementation error but also raise error if -i then -h etc after
            inputfile = true;     
            input = cmdLineArgs[i + 1];
            i++;        
            }
            else {
                std::cerr << "Error: Missing argument for -i or --input_file" << std::endl;
                return 1;
            }                      
        }
        else if (cmdLineArgs[i] == "-o" || cmdLineArgs[i] == "--output_file") {
            if (i + 1 < nCmdLineArgs && cmdLineArgs[i+1].find("-") != 0){
            outputfile = true;
            output = cmdLineArgs[i + 1];
            i++;
            }
            else {
                std::cerr << "Error: Missing argument for -o or --outout_file"
                          << std::endl;
                return 1;
            }
        }
        else {
            std::cerr << "Error: Unknown flag: " << cmdLineArgs[i] << std::endl;     //Print any unknown flags
            return 0;         // Break out program
        }
        }

    if (help) {
        std::cout
            << "\n\n"
            << "Encrypts or Decrypts numeric and alphabetic text using classical ciphers\n\n"
            << "-h / --help\n\n"
            << "-v / --version for version number\n\n"
            << "-i / --input_file for specifying input file location\n\n"
            << "-o / --output_file for specifying output file location\n\n"
            << std::endl;

    }
    if (version) {
        std::cout 
            << "\n\n"
            << "version : v1.0 \n\n" 
            << std::endl;

    }

    if (inputfile) {
        std::cout
            << "Input_file_location:\n\n"
            << input    //Saved variable input string as supplied in CLA
            << "\n\n"
            << std::endl;
    }
    

    if (outputfile) {
        std::cout 
            << "Output_file_location:\n\n"
            << output << "\n\n"
            << std::endl;
    }


    char in_char{'x'};
    std::string out_string{""};
    // Take each letter from user input and in each case:
    while (std::cin >> in_char) {
        // - Convert to upper case
        if (std::isalpha(in_char)) {
            out_string += std::toupper(in_char);
            continue;
        }

        switch (in_char) {
            case '1':
                out_string += "ONE";
                break;

            case '2':
                out_string += "TWO";
                break;

            case '3':
                out_string += "THREE";
                break;

            case '4':
                out_string += "FOUR";
                break;

            case '5':
                out_string += "FIVE";
                break;

            case '6':
                out_string += "SIX";
                break;

            case '7':
                out_string += "SEVEN";
                break;

            case '8':
                out_string += "EIGHT";
                break;

            case '9':
                out_string += "NINE";
                break;

            case '0':
                out_string += "ZERO";
                break;

            default:
                break;
        }
        // - Change numbers to words
        // - Ignore any other (non-alpha) characters
        // - In each case, add result to a string variable
    }
    // print out the new string
    std::cout << out_string << std::endl;
}
