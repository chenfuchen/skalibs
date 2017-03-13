/* ISC license. */

#include <skalibs/nonposix.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <skalibs/uint16.h>
#include <skalibs/ip46.h>
#include <skalibs/socket.h>

#ifdef SKALIBS_IPV6_ENABLED

int socket_remote6 (int s, char *ip, uint16_t *port)
{
  struct sockaddr_in6 sa ;
  socklen_t dummy = sizeof sa ;
  if (getpeername(s, (struct sockaddr *)&sa, &dummy) == -1)
    return -1 ;
  memcpy(ip, sa.sin6_addr.s6_addr, 16) ;
  uint16_unpack_big((char *)&sa.sin6_port, port) ;
  return 0 ;
}

#else

int socket_remote6 (int s, char *ip, uint16_t *port)
{
  (void)s ;
  (void)ip ;
  (void)port ;
  return (errno = ENOSYS, -1) ;
}

#endif
