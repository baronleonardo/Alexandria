#pragma once

#include <stdio.h>

#define panic(msg) { fprintf(stderr, "File: %s\nLine: %d\nFunction: %s\nError: %s\n", __FILE__, __LINE__, __func__, msg); abort(); }