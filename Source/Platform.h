#pragma once

/**
 * @brief Determineing which platform is being used
 * 
 */
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
    #define PLATFORM_WINDOWS 1
#elif __linux__
    #define PLATFORM_LINUX 1
#else
    #error "Unknown compiler"
#endif