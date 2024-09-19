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

	std::queue<std::string>* queue = lancaster_whisper_allocate_command_queue();

	printf("Queue Length: %i\n", (int)queue->size());

	while (true)
	{
		int i = 0;
		for (i = 0; i < queue->size(); i++)
		{
			printf("Whisper text: %s", queue->front().c_str());
		}
		for (int j = 0; j < i; j++)
		{
			queue->pop();
		}

	}
	/*
	while (true)
	{
		printf("%i", (queue->size());
	}*/
}