#include <iostream>
#include <cstdlib>
#include <string>

// Check OS for path delimeter
#ifdef _WIN32
  std::string pathDel = ";";
  std::string dirDel = "\\";
#elif __linux__
  std::string pathDel = ":";
  std::string dirDel = "/";
#endif

//TODO
// Define static variables for command strings maybe?

std::string readCommand(const std::string input){
  std::string del = " ";
  int pos = input.find(del);
  std::string command = input.substr(0, pos); 
  return command;
}

bool isCommand(const std::string input){
  std::string command = readCommand(input);
  if(command == "echo"){
    return true;
  } else if(command == "type"){
    return true;
  }
  return false;
}

std::string stripInput(const std::string input){
  std::string del = " ";
  int pos = input.find(del);
  std::string param = input.substr(pos + 1);
  return param;
}

/*
 * A path variable will be assigned, and we will parse as
 * a string
 */

/*std::string*/ void getPATH(const std::string input){
  std::string path = getenv("PATH");
  int pos_path = input.find(pathDel);
  int pos_dir = input.find(dirDel);
  std::string foo = "";

  //while(pos_path != std::string::npos){
     foo = pathDel;//input.substr(pos_path+1).substr(0, pos_dir);
     std::cout << foo << std::endl;
  //}

  //return path;
}

void typeCommand(const std::string input){
  std::string command = stripInput(input);
  getPATH(command);
  //std::string commandPath = getPATH(command);
  if(command == "echo"){
    std::cout << "echo is a shell builtin" << std::endl;
  } else if(command == "ls"){
    std::cout << "ls is "<< "built in"/*commandPath*/ << std::endl;
  } else if(command == "type"){
    std::cout << "type is " << "built in"/*commandPath*/ << std::endl;
  } else if(command == "exit"){
    std::cout << "exit is " << "built in"/*commandPath*/ << std::endl;
  }else{
    std::cout << command << ": not found" << std::endl;
  }
}

std::string echoCommand(const std::string input){
  std::string del = " ";
  int pos = input.find(del);
  std::string echoIn = input.substr(pos + 1);
  return echoIn;
}

void executeCommand(const std::string input){
  std::string command = readCommand(input);
  if(command == "echo"){
    std::cout << echoCommand(input) << std::endl;
  } else if (command == "type"){
    typeCommand(input);
  } else {
    std::cout << "idk" << std::endl;
  }
}

int main() {
  // Main loop for shell
  bool exit = false;

  // TODO
  // Check if inputs valid/invalid
  while(!exit){
    // Flush after every std::cout / std::cerr
    std::cout << std::unitbuf;
    std::cerr << std::unitbuf;

    // Print prompt
    std::cout << "$ ";

    // Get user input
    std::string input;
    std::getline(std::cin, input);

    // Input checking for specific commands
    if(input == "exit 0"){
      // TODO
      // Establish exit codes
      exit = true;
    } else if(isCommand(input)){
      executeCommand(input);
    } else{
      // Impement command not found method
      std::cout << input << ": command not found" << "\n";
    }
  }
  return 0;
}
