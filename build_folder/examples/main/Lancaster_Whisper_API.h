#pragma once

#include <thread>
#include <string>
#include <queue>

struct CommandOutput
{

};


#if defined(LANCASTER_WHISPER_EXPORTS) // Inside DLL implementation
#define LANCASTER_WHISPER_API extern "C" __declspec(dllexport)
#else   // Outside DLL
#define LANCASTER_WHISPER_API extern "C" __declspec(dllimport)
#endif  // LANCASTER_WHISPER_API


// Initialize the Lancaster Whisper runtime. Takes program flags like an executable
LANCASTER_WHISPER_API int lancaster_whisper_init(int argc, char** argv);

// Shutdown the whisper thread and free its resources
LANCASTER_WHISPER_API int lancaster_whisper_shutdown();

// Allocate a queue for commands to be shared with calling program
LANCASTER_WHISPER_API std::queue<std::string>* lancaster_whisper_allocate_command_queue();

// Give this function a pointer to a queue and it will push 
LANCASTER_WHISPER_API void lancaster_whisper_read_commands(std::queue<CommandOutput>*);