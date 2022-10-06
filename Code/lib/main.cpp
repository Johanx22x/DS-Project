#include <cstdio>
#include <filesystem>
#include <program.hh>
#include <string.h>

#if defined(_WIN32)
#define DL ".dll"
#include <windows.h>
#define dlopen LoadLibrary
#define dlsym GetProcAddress
#else
#define DL ".so"
#include <dlfcn.h>
#endif

typedef void (*setupHandler)(Program *);

int main() {
  Program *program = new Program();

  for (const std::filesystem::directory_entry &entry :
       std::filesystem::directory_iterator("./bin/")) {
#if defined(_WIN32)
    std::string fileName = entry.path().string();

    // store the position of last '.' in the file name
    int position = fileName.find_last_of(".");

    // store the characters after the '.' from the file_name string
    std::string result = fileName.substr(position);

    if (result.compare(DL) == 0) {
      HMODULE menuhandle = dlopen(fileName.c_str());

      setupHandler setup = (setupHandler)dlsym(menuhandle, "setup");

      if (setup == nullptr) {
        fprintf(stderr, "Couldn't load %s\n", fileName.c_str());
        continue;
      }
#else
    std::string fileName = entry.path();

    // store the position of last '.' in the file name
    int position = fileName.find_last_of(".");

    // store the characters after the '.' from the file_name string
    std::string result = fileName.substr(position);

    if (result.compare(DL) == 0) {
      void *menuhandle = dlopen(fileName.c_str(), RTLD_LAZY);

      setupHandler setup = (setupHandler)dlsym(menuhandle, "setup");

      if (setup == nullptr) {
        fprintf(stderr, "Couldn't load %s\n", fileName.c_str());
        continue;
      }

#endif
      setup(program);
    }
  }

  program->run();
}
