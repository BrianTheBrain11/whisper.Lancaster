#pragma once

#if defined(LANCASTER_WHISPER_EXPORTS) // Inside DLL implementation
#define LANCASTER_WHISPER_API __declspec(dllexport)
#else   // Outside DLL
#define LANCASTER_WHISPER_API __declspec(dllimport)
#endif  // LANCASTER_WHISPER_API