//                    -*- mode:c++; tab-width:4 -*-
// modified September 2016
// file: tools.hpp -----------------------------------------------------------
// header file for the tools library.
// ---------------------------------------------------------------------------
// Local definitions and portability code.
// Please enter your own system, name, class, and printer stream name.
// ---------------------------------------------------------------------------
#pragma once
#define NAME    "Invididual or both partners"
#define CLASS   "CS 6626"

// C++ header files  ---------------------------------------------------------
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <limits>

// Old C header files  -------------------------------------------------------
#include <cstddef>     // for NULL
#include <cstdlib>     // for malloc() and calloc()
#include <cstring>
#include <cerrno>
#include <cmath>
#include <ctime>
#include <cstdarg>     // for functions with variable # of arguments

using namespace std;

// ---------------------------------------------------------------------------
// Macros for debugging.
// ---------------------------------------------------------------------------
#define DUMPp(p) "\n" <<"    " #p " @ " <<&p <<"    value = " <<p <<"    " #p " --> " <<*p
#define DUMPv(k) "\n" <<"    " #k " @ " <<&k <<"    value = " <<k

// ---------------------------------------------------------------------------
// I/O Extension. ------------------------------------------------------------
// ---------------------------------------------------------------------------
istream& flush( istream& is );         // Use: cin >> x >> flush;

// ---------------------------------------------------------------------------
// Routine screen and process management.-------------------------------------
// ---------------------------------------------------------------------------
istream& flush(istream& is);
void     fbanner( ostream& fout );
void     banner();
void     bye( void );
void     hold( void );

// ---------------------------------------------------------------------------
// Error handling. -----------------------------------------------------------
// ---------------------------------------------------------------------------
void    fatal( const char* format, ... );

// ---------------------------------------------------------------------------
// time and date. -------------------------------------------------------------
// ---------------------------------------------------------------------------
void   when( char* date, char* hour );
char*  today( char* date );
char*  oclock( char* hour );
