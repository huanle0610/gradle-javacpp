#ifndef HL_DEMO_HL_CONFIG_H
#define HL_DEMO_HL_CONFIG_H

#ifndef OF /* function prototypes */
#ifdef STDC
#define OF(args) args
#else
#define OF(args) ()
#endif
#endif

#if defined(WINDOWS) || defined(WIN32)
/* If building or using zlib as a DLL, define ZLIB_DLL.
 * This is not mandatory, but it offers a little performance increase.
 */
#ifdef ZLIB_DLL
#if defined(WIN32) && (!defined(__BORLANDC__) || (__BORLANDC__ >= 0x500))
#ifdef ZLIB_INTERNAL
#define ZEXTERN extern __declspec(dllexport)
#else
#define ZEXTERN extern __declspec(dllimport)
#endif
#endif
#endif /* ZLIB_DLL */
#endif

#ifndef ZEXTERN
#define ZEXTERN extern
#endif
#ifndef ZEXPORT
#define ZEXPORT
#endif
#ifndef ZEXPORTVA
#define ZEXPORTVA
#endif
//===============================================


#endif