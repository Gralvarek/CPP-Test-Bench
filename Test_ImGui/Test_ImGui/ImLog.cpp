#include "ImLog.h"

ImLog::ImLog()
{
}

ImLog::~ImLog()
{
}

void ImLog::Draw(const char* title, bool* p_open)
{
	ImGui::Begin(title, p_open);

	ImGui::End();
}

void ImLog::ClearLog()
{
}

void ImLog::AddLog(const char* fmt, ...)
{
}
