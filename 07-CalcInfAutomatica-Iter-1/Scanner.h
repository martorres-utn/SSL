#pragma once

#include <stdio.h>
#include <stdbool.h>
#include "ScannerTypes.h"

//Scanner - Public functions
Token Scanner_GetNextToken();
void Scanner_UngetLastToken();
void Scanner_BufferGetContent(char output[]);