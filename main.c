#include <stdio.h>
#include <stdlib.h>

#include "eviction.h"
#include "libflush.h"
#include "internal.h"


int main() {

    struct libflush_session_t **lst;
    lst = malloc(sizeof(struct libflush_session_t **));
    struct libflush_session_args_t *sess_args;
    sess_args = malloc(sizeof(struct libflush_session_args_t));

    printf("%d", libflush_init(lst, sess_args));
    struct libflush_session_t *ls = *lst;
#if HAVE_PAGEMAP_ACCESS == 1
    printf("%d", (ls->memory).pagemap);
#endif
    libflush_terminate(*lst);

    return 0;
}
