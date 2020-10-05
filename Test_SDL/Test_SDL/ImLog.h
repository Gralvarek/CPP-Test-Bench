#ifndef IMLOG_H
#define IMLOG_H

#include "imgui.h"

class ImLog
{
private:
	ImGuiTextBuffer buf;
	ImGuiTextFilter filter;
	ImVector<int> line_offset;
	bool auto_scroll;

public:

	ImLog();
	~ImLog();

	void Draw(const char* title, bool* p_open = NULL);
	void ClearLog();
	void AddLog(const char* fmt, ...);

};

#endif // IMLOG_H