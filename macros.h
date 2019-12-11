/* Copyright (C) Bartosz Mierzynski 2019
 * Rules
 * 0. All macro identifiers must be written in uppercase to indicate they are
 *    indeed macros.
 * 1. If some terminology for an operation exists in C++ it should be reflected
 *    in macro's identifier
 * */

#ifndef _MACROS_H_
#define _MACROS_H_
#ifdef __cplusplus
  #include <cstddef>
  #include <cstring>
#else
  #include <stddef.h>
  #include <string.h>
#endif /* __cplusplus */

/* bits */
#define BIT(x)           (1 << (x))
#define BIT_TEST(x,p) (!!((x) &  (1 << (p)))) 
#define BIT_SET(x,p)     ((x) |   (1 << (p)))
#define BIT_RESET(x,p)   ((x) & (~(1 << (p))))
#define BIT_FLIP(x,p)    ((x) ^   (1 << (p)))

/* bitmasks */
#define BITMASK_SET(x,m)     ((x) |   (m))
#define BITMASK_RESET(x,m)   ((x) & (~(m)))
#define BITMASK_FLIP(x,m)    ((x) ^   (m))

/* numbers */ 
#define UCLIP(x, max) (((x) > (max)) ? (max) : (x))
#define LCLIP(x, min) (((x) < (min)) ? (min) : (x))
#define ABS(x)        ((x) < 0 ? -(x) : (x))
#define DIFF(x, y)    ABS((x) - (y))
#define MIN(x, y)     ((x) < (y) ?  (x) : (y))
#define MAX(x, y)     ((x) < (y) ?  (y) : (x))
#define IS_FINITE(x)  ((x) * 0 == 0)
#define IS_NAN(x)     ((x) != (x))
#define IS_ODD(x)     ((x) & 1)
#define IS_EVEN(x)    (!(IS_ODD((x)))
#define IMPLIES(x, y) (!(x) || (y))

/* arrays */
#define ARRAY_SIZE(a) (sizeof(a) / sizeof((a)[0]))

/* structures */
/* instead of STRUCT_MEMBER_OFFSET() you should use offsetof()
 * from <stddef.h> in C or <cstddef> in C++ */
#define STRUCT_MEMBER_OFFSET(type, member) \
	((size_t)((void *)(&((type *)((void *)0))->member)))

/* digit characters; (int) in C, (char) in C++ */
#define IS_ODIGIT(c)     ((c) >= '0' && (c) <= '7')
#define ODIGIT_TO_BIN(c) ((c) - '0')
#define DIGIT_TO_BIN(c)  ((c) - '0')
#define XDIGIT_TO_BIN(c) ((c) >= 'a' && (c) <= 'f' ? (c) - 'a' + 10 : \
                          (c) >= 'A' && (c) <= 'F' ? (c) - 'A' + 10 : (c) - '0')

/* C strings (const char *) */
#ifdef __cplusplus
  #define STR_EQ(a, b)        (std::strcmp (a, b) == 0)
  #define STR_NE(a, b)        (std::strcmp (a, b) != 0)
  #define STR_EQ_LEN(a, b, n) (std::strncmp (a, b, n) == 0)
  #define STR_PREFIX(a, b)    (std::strncmp (a, b, std::strlen (b)) == 0)
#else
  #define STR_EQ(a, b)        (strcmp (a, b) == 0)
  #define STR_NE(a, b)        (strcmp (a, b) != 0)
  #define STR_EQ_LEN(a, b, n) (strncmp (a, b, n) == 0)
  #define STR_PREFIX(a, b)    (strncmp (a, b, strlen (b)) == 0)
#endif /* __cplusplus */

/* C code linkage for C++ */
#ifdef __cplusplus
  #define BEGIN_DECLS extern "C" {
  #define END_DECLS   }
#else
  #define BEGIN_DECLS
  #define END_DECLS
#endif /* __cplusplus */

#endif /* _MACROS_H_ */
