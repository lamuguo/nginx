#ifndef _NGX_STRING_H_INCLUDED_
#define _NGX_STRING_H_INCLUDED_


#include <ngx_config.h>


typedef struct {
    size_t  len;
    char   *data;
} ngx_str_t;


#define ngx_string(str)  { sizeof(str) - 1, str }


#if (WIN32)

#define ngx_memzero               ZeroMemory

#define strcasecmp                stricmp
#define ngx_strcmp                strcmp

#define ngx_snprintf              _snprintf
#define ngx_vsnprintf             _vsnprintf

#else

#define ngx_memzero               bzero

#define ngx_strcmp                strcmp

#define ngx_snprintf              snprintf
#define ngx_vsnprintf             vsnprintf

#endif

#define ngx_memcpy(dst, src, n)   memcpy(dst, src, n)
#define ngx_cpymem(dst, src, n)   memcpy(dst, src, n) + n

char *ngx_cpystrn(char *dst, char *src, size_t n);


#endif /* _NGX_STRING_H_INCLUDED_ */
