/*
 * Copyright (C) 2000  Internet Software Consortium.
 * 
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS" AND INTERNET SOFTWARE CONSORTIUM DISCLAIMS
 * ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL INTERNET SOFTWARE
 * CONSORTIUM BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
 * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS
 * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS
 * SOFTWARE.
 */

#ifndef DNS_BYADDR_H
#define DNS_BYADDR_H 1

/*****
 ***** Module Info
 *****/

/*
 * DNS ByAddr
 *
 * The byaddr module provides reverse lookup services for IPv4 and IPv6
 * addresses.
 *
 * MP:
 *	The module ensures appropriate synchronization of data structures it
 *	creates and manipulates.
 *
 * Reliability:
 *	No anticipated impact.
 *
 * Resources:
 *	<TBS>
 *
 * Security:
 *	No anticipated impact.
 *
 * Standards:
 *	RFCs:	1034, 1035, 2181, <TBS>
 *	Drafts:	<TBS>
 */

#include <isc/types.h>
#include <isc/lang.h>
#include <isc/event.h>
#include <isc/netaddr.h>

#include <dns/types.h>
#include <dns/result.h>

ISC_LANG_BEGINDECLS

typedef struct dns_byaddrevent {
	ISC_EVENT_COMMON(struct dns_byaddrevent);
	dns_byaddr_t *			byaddr;
	isc_result_t			result;
	dns_namelist_t			names;
} dns_byaddrevent_t;

isc_result_t
dns_byaddr_create(isc_mem_t *mctx, isc_netaddr_t *address, dns_view_t *view,
		  unsigned int options, isc_task_t *task,
		  isc_taskaction_t action, void *arg, dns_byaddr_t **byaddrp);
/*
 * Find the domain name of 'address'.
 *
 * Requires:
 *
 *	'mctx' is a valid mctx.
 *
 *	'address' is a valid IPv4 or IPv6 address.
 *
 *	'view' is a valid view which has a resolver.
 *
 *	'task' is a valid task.
 *
 *	byaddrp != NULL && *byaddrp == NULL
 *
 * Returns:
 *
 *	ISC_R_SUCCESS
 *	ISC_R_NOMEMORY
 *
 *	Any resolver-related error (e.g. ISC_R_SHUTTINGDOWN) may also be
 *	returned.
 */

void
dns_byaddr_cancel(dns_byaddr_t *byaddr);
/*
 * Cancel 'byaddr'.
 *
 * Notes:
 *
 *	If 'byaddr' has not completed, post its BYADDRDONE event with a
 *	result code of ISC_R_CANCELED.
 *
 * Requires:
 *
 *	'byaddr' is a valid byaddr.
 */

void
dns_byaddr_destroy(dns_byaddr_t **byaddrp);
/*
 * Destroy 'byaddr'.
 *
 * Requires:
 *
 *	'*byaddrp' is a valid byaddr.
 *
 *	The caller has received the BYADDRDONE event (either because the
 *	byaddr completed or because dns_byaddr_cancel() was called).
 *
 * Ensures:
 *
 *	*byaddrp == NULL.
 */

ISC_LANG_ENDDECLS

#endif /* DNS_BYADDR_H */
