/*
 * Copyright (C) 1998, 1999  Internet Software Consortium.
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

#ifndef DNS_RESULT_H
#define DNS_RESULT_H 1

#include <isc/lang.h>
#include <isc/result.h>
#include <isc/resultclass.h>

ISC_LANG_BEGINDECLS

typedef isc_result_t dns_result_t;	/* XXXRTH for legacy use only */

#define DNS_R_SUCCESS			(ISC_RESULTCLASS_DNS + 0)
#define DNS_R_NOMEMORY			(ISC_RESULTCLASS_DNS + 1)
#define DNS_R_NOSPACE			(ISC_RESULTCLASS_DNS + 2)
#define DNS_R_LABELTOOLONG		(ISC_RESULTCLASS_DNS + 3)
#define DNS_R_BADESCAPE			(ISC_RESULTCLASS_DNS + 4)
#define DNS_R_BADBITSTRING		(ISC_RESULTCLASS_DNS + 5)
#define DNS_R_BITSTRINGTOOLONG		(ISC_RESULTCLASS_DNS + 6)
#define DNS_R_EMPTYLABEL		(ISC_RESULTCLASS_DNS + 7)
#define DNS_R_BADDOTTEDQUAD		(ISC_RESULTCLASS_DNS + 8)
#define DNS_R_UNEXPECTEDEND		(ISC_RESULTCLASS_DNS + 9)
#define DNS_R_NOTIMPLEMENTED		(ISC_RESULTCLASS_DNS + 10)
#define DNS_R_UNKNOWN			(ISC_RESULTCLASS_DNS + 11)
#define DNS_R_BADLABELTYPE		(ISC_RESULTCLASS_DNS + 12)
#define DNS_R_BADPOINTER		(ISC_RESULTCLASS_DNS + 13)
#define DNS_R_TOOMANYHOPS		(ISC_RESULTCLASS_DNS + 14)
#define DNS_R_DISALLOWED		(ISC_RESULTCLASS_DNS + 15)
#define DNS_R_NOMORE			(ISC_RESULTCLASS_DNS + 16)
#define DNS_R_EXTRATOKEN		(ISC_RESULTCLASS_DNS + 17)
#define DNS_R_EXTRADATA			(ISC_RESULTCLASS_DNS + 18)
#define DNS_R_TEXTTOLONG		(ISC_RESULTCLASS_DNS + 19)
#define DNS_R_RANGE			(ISC_RESULTCLASS_DNS + 20)
#define DNS_R_EXISTS			(ISC_RESULTCLASS_DNS + 21)
#define DNS_R_NOTFOUND			(ISC_RESULTCLASS_DNS + 22)
#define DNS_R_SYNTAX			(ISC_RESULTCLASS_DNS + 23)
#define DNS_R_BADCKSUM			(ISC_RESULTCLASS_DNS + 24)
#define DNS_R_BADAAAA			(ISC_RESULTCLASS_DNS + 25)
#define DNS_R_NOOWNER			(ISC_RESULTCLASS_DNS + 26)
#define DNS_R_NOTTL			(ISC_RESULTCLASS_DNS + 27)
#define DNS_R_BADCLASS			(ISC_RESULTCLASS_DNS + 28)
#define DNS_R_UNEXPECTEDTOKEN		(ISC_RESULTCLASS_DNS + 29)
#define DNS_R_BADBASE64			(ISC_RESULTCLASS_DNS + 30)
#define DNS_R_PARTIALMATCH		(ISC_RESULTCLASS_DNS + 31)
#define DNS_R_NEWORIGIN			(ISC_RESULTCLASS_DNS + 32)
#define DNS_R_UNCHANGED			(ISC_RESULTCLASS_DNS + 33)
#define DNS_R_BADTTL			(ISC_RESULTCLASS_DNS + 34)
#define DNS_R_NOREDATA			(ISC_RESULTCLASS_DNS + 35)
#define DNS_R_CONTINUE			(ISC_RESULTCLASS_DNS + 36)
#define DNS_R_DELEGATION		(ISC_RESULTCLASS_DNS + 37)
#define DNS_R_GLUE			(ISC_RESULTCLASS_DNS + 38)
#define DNS_R_DNAME			(ISC_RESULTCLASS_DNS + 39)
#define DNS_R_CNAME			(ISC_RESULTCLASS_DNS + 40)
#define DNS_R_NXDOMAIN			(ISC_RESULTCLASS_DNS + 41)
#define DNS_R_NXRDATASET		(ISC_RESULTCLASS_DNS + 42)
#define DNS_R_BADDB			(ISC_RESULTCLASS_DNS + 43)
#define DNS_R_ZONECUT			(ISC_RESULTCLASS_DNS + 44)
#define DNS_R_FORMERR			(ISC_RESULTCLASS_DNS + 45)
#define DNS_R_BADZONE			(ISC_RESULTCLASS_DNS + 46) /* XXX MPA*/
#define DNS_R_TIMEDOUT			(ISC_RESULTCLASS_DNS + 47)
#define DNS_R_CANCELED			(ISC_RESULTCLASS_DNS + 48)
#define DNS_R_UNEXPECTED		(ISC_RESULTCLASS_DNS + 49)
#define DNS_R_MOREDATA			(ISC_RESULTCLASS_DNS + 50)

#define DNS_R_NRESULTS			51	/* Number of results */

char *					dns_result_totext(dns_result_t);
void					dns_result_register(void);

ISC_LANG_ENDDECLS

#endif /* DNS_RESULT_H */
