#pragma once

#ifdef tbs_whisper_api_EXPORTS
#define tbs_whisper_api extern "C" __declspec(dllexport)
#else
#define tbs_whisper_api extern "C" __declspec(dllimport)
#endif

#include <string>
#include <queue>

// init whisper using cmd args
tbs_whisper_api int tbs_whisper_init(int argc, char** argv);

// init whisper using string args
tbs_whisper_api int tbs_whisper_init_with_string(std::string);

// shutdown the api
tbs_whisper_api void tbs_whisper_shutdown();

tbs_whisper_api bool tbs_whisper_is_running();

// allocate a queue and return its pointer
tbs_whisper_api std::queue<std::string*>* tbs_whisper_allocate_queue();