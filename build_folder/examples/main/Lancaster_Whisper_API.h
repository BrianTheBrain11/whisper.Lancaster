#pragma once

#include <thread>
#include <string>
#include <queue>

#if defined(LANCASTER_WHISPER_EXPORTS) // Inside DLL implementation
#define LANCASTER_WHISPER_API extern "C" __declspec(dllexport)
#else   // Outside DLL
#define LANCASTER_WHISPER_API extern "C" __declspec(dllimport)
#endif  // LANCASTER_WHISPER_API

enum CommandTypes
{
	IO,
	GAME_COMMAND,
	TEXT_TRANSFER,
};

struct WhisperCommand
{
	std::string message;
};

struct WhisperGameCommand : WhisperCommand
{
	std::string speaker;
	std::string recipient;
};

// Initialize the Lancaster Whisper runtime. Takes program flags like an executable
LANCASTER_WHISPER_API int lancaster_whisper_init(int argc, char** argv);

// Shutdown the whisper thread and free its resources
LANCASTER_WHISPER_API int lancaster_whisper_shutdown();

// Allocate a queue for commands to be shared with calling program
LANCASTER_WHISPER_API std::queue<WhisperCommand*>* lancaster_whisper_allocate_command_queue();

// delete top n queue items
LANCASTER_WHISPER_API void lancaster_whisper_clean_queue(int n_numToClean);

// Set the push to talk on or off. True for on, false for off
// Return bool reflects internal ptt state
LANCASTER_WHISPER_API bool lancaster_whisper_ptt_set(bool onoff);