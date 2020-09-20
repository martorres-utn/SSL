#pragma once

#include <stdio.h>
#include <stdbool.h>
#include "Scanner2.h"

#define TOKEN_BUFFER_SIZE 1000
#define PARSER_LOOP_LIMIT 50

void Parser_Start();
void Parser_CleanBuffer(Token buffer[], size_t max);
bool Parser_IsExpression(Token buffer[], size_t max, size_t start, size_t end);
bool Parser_IsTerm(Token buffer[], size_t max, size_t start, size_t end);
bool Parser_IsFactor(Token buffer[], size_t max, size_t start, size_t end);