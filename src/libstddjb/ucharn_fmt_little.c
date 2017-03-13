/* ISC license. */

#include <skalibs/fmtscan.h>

size_t ucharn_fmt_little (char *s, char const *key, size_t n)
{
  size_t i = 0 ;
  for (; i < n ; i++)
  {
    s[i<<1] = fmtscan_asc((unsigned char)key[i] & 0xF) ;
    s[(i<<1)+1] = fmtscan_asc((unsigned char)key[i] >> 4) ;
  }
  return n << 1 ;
}
