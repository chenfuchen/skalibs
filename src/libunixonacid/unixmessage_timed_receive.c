/* ISC license. */

#include <sys/types.h>
#include <skalibs/functypes.h>
#include <skalibs/unix-timed.h>
#include <skalibs/unixmessage.h>

typedef struct unixmessage_get_s unixmessage_get_t, *unixmessage_get_t_ref ;
struct unixmessage_get_s
{
  unixmessage_receiver_t *b ;
  unixmessage_t *m ;
} ;

static int getfd (unixmessage_get_t *g)
{
  return unixmessage_receiver_fd(g->b) ;
}

static ssize_t get (unixmessage_get_t *g)
{
  return unixmessage_receive(g->b, g->m) ;
}

int unixmessage_timed_receive (unixmessage_receiver_t *b, unixmessage_t *m, tain_t const *deadline, tain_t *stamp)
{
  unixmessage_get_t g = { .b = b, .m = m } ;
  return timed_get(&g, (initfunc_t_ref)&getfd, (getfunc_t_ref)&get, deadline, stamp) ;
}
