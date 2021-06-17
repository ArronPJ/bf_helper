#pragma once

#ifdef WIN32
#define bf_helper_EXPORT __declspec(dllexport)
#else
#define bf_helper_EXPORT
#endif

bf_helper_EXPORT void bf_helper_version();

// V1.0.0 : create this library
// V1.1.0 : provide version function
