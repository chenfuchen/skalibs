/* ISC license. */

#include <stdint.h>
#include <string.h>
#include <skalibs/uint32.h>

void uint32_unpack (char const *s, uint32_t *u)
{
  uint32_t x ;
  memcpy(&x, s, sizeof(uint32_t)) ;
  *u = uint32_little(x) ;
}
