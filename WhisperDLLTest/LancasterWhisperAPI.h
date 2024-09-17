#pragma once
#include <Windows.h>

typedef int (*LANCASTER_WHISPER_INIT)(int argc, char** argv);

struct lancaster_whisper_api
{
	LANCASTER_WHISPER_INIT lancaster_whisper_init;
};

inline lancaster_whisper_api get_lancaster_api()
{
	HMODULE lancaster_whisper_dll = GetModuleHandleA("LancasterWhisper.dll");

	lancaster_whisper_api ret;
	ret.lancaster_whisper_init = (LANCASTER_WHISPER_INIT)GetProcAddress(lancaster_whisper_dll, "lancaster_whisper_init");
	return ret;
}

class LANC_WHISPER_API
{
public:
	lancaster_whisper_api lancaster_whisper_api;
	
	LANC_WHISPER_API()
	{
		this->lancaster_whisper_api = get_lancaster_api();
	}

	int lancaster_whisper_init(int argc, char** argv)
	{
		return lancaster_whisper_api.lancaster_whisper_init(argc, argv);
	}

};