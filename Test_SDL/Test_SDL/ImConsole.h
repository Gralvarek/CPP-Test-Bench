#ifndef IMCONSOLE_H
#define IMCONSOLE_H

#include "imgui.h"
#include "ImLog.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <algorithm>


class ImConsole
{
private:
	char input_buffer[256];
	ImVector<char*> items;
	ImVector<const char*> commands;
	ImVector<char*> history;
	int history_position;
	ImGuiTextFilter filter;
	bool auto_scroll;
	bool scroll_to_bottom;


public:

	ImConsole();
	~ImConsole();

	void Draw(const char* title, bool* p_open = NULL);
	void ExecuteCommand(const char* command);
	void ClearLog();
	void AddLog(const char* fmt, ...);
	int TextEditCallback(ImGuiInputTextCallbackData* data);
};

#endif // IMCONSOLE_H