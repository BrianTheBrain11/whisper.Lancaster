#include "Lancaster_Whisper_API.h"

#include "whisper.h"

#include <thread>
#include <string>
#include <queue>
#include <iostream>
#include <stdio.h>
#include <Windows.h>

int main(int argc, char** argv)
{

	lancaster_whisper_init(argc, argv);

	std::queue<WhisperCommand*>* queue = lancaster_whisper_allocate_command_queue();

	printf("Queue Length: %i\n", (int)queue->size());

	while (true)
	{
		int i = 0;
		int size = queue->size();
		for (i = 0; i < size; i++)
		{
			printf("Whisper text: %s", queue->front()->message.c_str());
		}

		lancaster_whisper_clean_queue(size);

	}
	/*
	while (true)
	{
		printf("%i", (queue->size());
	}*/
}