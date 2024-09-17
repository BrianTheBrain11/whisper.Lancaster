#include "LancasterWhisperAPI.h"
#include <stdio.h>


int main(int argc, char** argv)
{
	printf("Starting up\n");
	LANC_WHISPER_API lancaster_whisper_api;
	printf("here have another\n");
	printf("Executing: %i", lancaster_whisper_api.lancaster_whisper_init(argc, argv));
}