#pragma once

#ifdef tbs_whisper_api_EXPORTS
#define tbs_whisper_api extern "C" __declspec(dllexport)
#else
#define tbs_whisper_api extern "C" __declspec(dllimport)
#endif


tbs_whisper_api int tbs_whisper_init(int argc, char** argv);