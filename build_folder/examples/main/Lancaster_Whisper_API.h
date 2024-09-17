#pragma once

#if defined(LANCASTER_WHISPER_EXPORTS) // Inside DLL implementation
#define LANCASTER_WHISPER_API extern "C" __declspec(dllexport)
#else   // Outside DLL
#define LANCASTER_WHISPER_API extern "C" __declspec(dllimport)
#endif  // LANCASTER_WHISPER_API


// Initialize the Lancaster Whisper runtime. Takes program flags like an executable
LANCASTER_WHISPER_API int lancaster_whisper_init(int argc, char** argv);