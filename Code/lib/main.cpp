/**
 * Here is implemented the main file
 * In this file is defined all the program declarations and dinamic libraries implementation
 *
 * @author Johan Rodriguez, Aaron Gonzalez, Gabriel Alfaro
 * @version 2.1
 *
 * last modification: 07/10/2022
 */

#include <cstdio>
#include <filesystem>
#include <program.hh>
#include <string.h>

/// Define the extension of the dinamic library depends on the OS
#if defined(_WIN32)
#define DL ".dll"
#include <windows.h>
#define dlopen LoadLibrary
#define dlsym GetProcAddress
#else
#define DL ".so"
#include <dlfcn.h>
#endif

/// Define the SetupHandler type, syntactic sugar
typedef void (*SetupHandler)(Program *);

/// Main function of the program
int main() {
  // Instantiate the program
  Program *program = new Program();

  /// Charge the dinamic libraries
  for (const std::filesystem::directory_entry &entry :
       std::filesystem::directory_iterator("./bin/")) {
#if defined(_WIN32)
    std::string fileName = entry.path().string();
#else
    std::string fileName = entry.path();
#endif
    // store the position of last '.' in the file name
    int position = fileName.find_last_of(".");

    // store the characters after the '.' from the file_name string
    std::string result = fileName.substr(position);

    /// Check the extension of the file
    if (result.compare(DL) == 0) {
#if defined(_WIN32)
      HMODULE menuhandle = dlopen(fileName.c_str());
#else
      void *menuhandle = dlopen(fileName.c_str(), RTLD_LAZY);
#endif

      SetupHandler setup = (SetupHandler)dlsym(menuhandle, "setup");

      /// Manage errors
      if (setup == nullptr) {
        fprintf(stderr, "Couldn't load %s\n", fileName.c_str());
        continue;
      }
      /// Setup the actual program with the dinamic libraries
      setup(program);
    }
  }

  /// Run the charged program
  program->run();
}
