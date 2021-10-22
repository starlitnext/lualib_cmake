#pragma once

#if defined(_WIN32)
#  define EXPORT_API __declspec(dllexport)
#else // non windows
#  define EXPORT_API
#endif