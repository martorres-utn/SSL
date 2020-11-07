#pragma once
#include <stdbool.h>

bool VariableManager_GetValue(const char * varName, int *varValue);
void VariableManager_SetValue(const char * varName, int  varValue);
void VariableManager_RemoveAll();