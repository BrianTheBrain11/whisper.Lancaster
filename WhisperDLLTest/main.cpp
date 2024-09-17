#include "Lancaster_Whisper_API.h"
#include <stdio.h>

int main(int argc, char** argv)
{
	printf("Starting up\n");
	printf("here have another\n");
	printf("Executing: %i", lancaster_whisper_init(argc, argv));
}