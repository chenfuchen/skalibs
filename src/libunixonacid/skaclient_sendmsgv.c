/* ISC license. */

#include <skalibs/skaclient.h>

int skaclient_sendmsgv_and_close (skaclient_t *a, unixmessage_v_t const *m, unsigned char const *bits, unixmessage_handler_func_t_ref cb, void *result, tain_t const *deadline, tain_t *stamp)
{
  return skaclient_putmsgv_and_close(a, m, bits, cb, result)
    && skaclient_syncify(a, deadline, stamp) ;
}
