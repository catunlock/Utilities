#pragma once

#if defined( FOR_BUILDING )
	#include "testlib/version.hpp"
	#define testlib_VERSION_MAJOR _testlib_VERSION_MAJOR
	#define testlib_VERSION_MINOR _testlib_VERSION_MINOR
#endif

#if defined( _WIN32 ) || defined( __WIN32__ )
	#if defined( TESTLIB_EXPORTS )
		#define TESTLIB_API __declspec( dllexport )
	#else
		#define TESTLIB_API __declspec( dllimport )
	#endif
#else
	#define TESTLIB_API
#endif


// Constants for Box2D.
const float TO_BOX2D = 1.0f / 32.0f;
const float TO_SFML = 32.0f;