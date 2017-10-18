/* ISC license. */

#include <stdint.h>
#include <string.h>
#include <skalibs/uint16.h>

void uint16_pack_big (char *s, uint16_t u)
{
  u = uint16_big(u) ;
  memcpy(s, &u, sizeof(uint16_t)) ;
}
