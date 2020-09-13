#pragma once

#include <stdio.h>
#include <stdbool.h>
#include "Scanner.h"

#define TOKEN_BUFFER_SIZE 1000
#define PARSER_LOOP_LIMIT 50

void Parser_Start();
bool Parser_IsExpression(Token array[], size_t max, size_t start, size_t end);
bool Parser_IsTerm(Token array[], size_t max, size_t start, size_t end);
bool Parser_IsFactor(Token array[], size_t max, size_t start, size_t end);