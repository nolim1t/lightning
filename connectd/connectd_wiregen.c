/* This file was generated by generate-wire.py */
/* Do not modify this file! Modify the .csv file it was generated from. */
/* Original template can be found at tools/gen/impl_template */

#include <connectd/connectd_wiregen.h>
#include <assert.h>
#include <ccan/array_size/array_size.h>
#include <ccan/mem/mem.h>
#include <ccan/tal/str/str.h>
#include <common/utils.h>
#include <stdio.h>

#ifndef SUPERVERBOSE
#define SUPERVERBOSE(...)
#endif


const char *connectd_wire_name(int e)
{
	static char invalidbuf[sizeof("INVALID ") + STR_MAX_CHARS(e)];

	switch ((enum connectd_wire)e) {
	case WIRE_CONNECTD_INIT: return "WIRE_CONNECTD_INIT";
	case WIRE_CONNECTD_INIT_REPLY: return "WIRE_CONNECTD_INIT_REPLY";
	case WIRE_CONNECTD_ACTIVATE: return "WIRE_CONNECTD_ACTIVATE";
	case WIRE_CONNECTD_ACTIVATE_REPLY: return "WIRE_CONNECTD_ACTIVATE_REPLY";
	case WIRE_CONNECTD_RECONNECTED: return "WIRE_CONNECTD_RECONNECTED";
	case WIRE_CONNECTD_CONNECT_TO_PEER: return "WIRE_CONNECTD_CONNECT_TO_PEER";
	case WIRE_CONNECTD_CONNECT_FAILED: return "WIRE_CONNECTD_CONNECT_FAILED";
	case WIRE_CONNECTD_PEER_CONNECTED: return "WIRE_CONNECTD_PEER_CONNECTED";
	case WIRE_CONNECTD_PEER_DISCONNECTED: return "WIRE_CONNECTD_PEER_DISCONNECTED";
	case WIRE_CONNECTD_DEV_MEMLEAK: return "WIRE_CONNECTD_DEV_MEMLEAK";
	case WIRE_CONNECTD_DEV_MEMLEAK_REPLY: return "WIRE_CONNECTD_DEV_MEMLEAK_REPLY";
	}

	snprintf(invalidbuf, sizeof(invalidbuf), "INVALID %i", e);
	return invalidbuf;
}

bool connectd_wire_is_defined(u16 type)
{
	switch ((enum connectd_wire)type) {
	case WIRE_CONNECTD_INIT:;
	case WIRE_CONNECTD_INIT_REPLY:;
	case WIRE_CONNECTD_ACTIVATE:;
	case WIRE_CONNECTD_ACTIVATE_REPLY:;
	case WIRE_CONNECTD_RECONNECTED:;
	case WIRE_CONNECTD_CONNECT_TO_PEER:;
	case WIRE_CONNECTD_CONNECT_FAILED:;
	case WIRE_CONNECTD_PEER_CONNECTED:;
	case WIRE_CONNECTD_PEER_DISCONNECTED:;
	case WIRE_CONNECTD_DEV_MEMLEAK:;
	case WIRE_CONNECTD_DEV_MEMLEAK_REPLY:;
	      return true;
	}
	return false;
}





/* WIRE: CONNECTD_INIT */
u8 *towire_connectd_init(const tal_t *ctx, const struct chainparams *chainparams, const struct feature_set *our_features, const struct node_id *id, const struct wireaddr_internal *wireaddrs, const enum addr_listen_announce *listen_announce, const struct wireaddr *tor_proxyaddr, bool use_tor_proxy_always, bool dev_allow_localhost, bool use_dns, const wirestring *tor_password, bool use_v3_autotor)
{
	u16 num_wireaddrs = tal_count(listen_announce);
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_CONNECTD_INIT);
	towire_chainparams(&p, chainparams);
	towire_feature_set(&p, our_features);
	towire_node_id(&p, id);
	towire_u16(&p, num_wireaddrs);
	for (size_t i = 0; i < num_wireaddrs; i++)
		towire_wireaddr_internal(&p, wireaddrs + i);
	for (size_t i = 0; i < num_wireaddrs; i++)
		towire_addr_listen_announce(&p, listen_announce[i]);
	if (!tor_proxyaddr)
		towire_bool(&p, false);
	else {
		towire_bool(&p, true);
		towire_wireaddr(&p, tor_proxyaddr);
	}
	towire_bool(&p, use_tor_proxy_always);
	towire_bool(&p, dev_allow_localhost);
	towire_bool(&p, use_dns);
	towire_wirestring(&p, tor_password);
	towire_bool(&p, use_v3_autotor);

	return memcheck(p, tal_count(p));
}
bool fromwire_connectd_init(const tal_t *ctx, const void *p, const struct chainparams **chainparams, struct feature_set **our_features, struct node_id *id, struct wireaddr_internal **wireaddrs, enum addr_listen_announce **listen_announce, struct wireaddr **tor_proxyaddr, bool *use_tor_proxy_always, bool *dev_allow_localhost, bool *use_dns, wirestring **tor_password, bool *use_v3_autotor)
{
	u16 num_wireaddrs;

	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_CONNECTD_INIT)
		return false;
 	fromwire_chainparams(&cursor, &plen, chainparams);
 	*our_features = fromwire_feature_set(ctx, &cursor, &plen);
 	fromwire_node_id(&cursor, &plen, id);
 	num_wireaddrs = fromwire_u16(&cursor, &plen);
 	// 2nd case wireaddrs
	*wireaddrs = num_wireaddrs ? tal_arr(ctx, struct wireaddr_internal, num_wireaddrs) : NULL;
	for (size_t i = 0; i < num_wireaddrs; i++)
		fromwire_wireaddr_internal(&cursor, &plen, *wireaddrs + i);
 	// 2nd case listen_announce
	*listen_announce = num_wireaddrs ? tal_arr(ctx, enum addr_listen_announce, num_wireaddrs) : NULL;
	for (size_t i = 0; i < num_wireaddrs; i++)
		(*listen_announce)[i] = fromwire_addr_listen_announce(&cursor, &plen);
 	if (!fromwire_bool(&cursor, &plen))
		*tor_proxyaddr = NULL;
	else {
		*tor_proxyaddr = tal(ctx, struct wireaddr);
		fromwire_wireaddr(&cursor, &plen, *tor_proxyaddr);
	}
 	*use_tor_proxy_always = fromwire_bool(&cursor, &plen);
 	*dev_allow_localhost = fromwire_bool(&cursor, &plen);
 	*use_dns = fromwire_bool(&cursor, &plen);
 	*tor_password = fromwire_wirestring(ctx, &cursor, &plen);
 	*use_v3_autotor = fromwire_bool(&cursor, &plen);
	return cursor != NULL;
}

/* WIRE: CONNECTD_INIT_REPLY */
/* Connectd->master */
u8 *towire_connectd_init_reply(const tal_t *ctx, const struct wireaddr_internal *bindings, const struct wireaddr *announcable)
{
	u16 num_bindings = tal_count(bindings);
	u16 num_announcable = tal_count(announcable);
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_CONNECTD_INIT_REPLY);
	towire_u16(&p, num_bindings);
	for (size_t i = 0; i < num_bindings; i++)
		towire_wireaddr_internal(&p, bindings + i);
	towire_u16(&p, num_announcable);
	for (size_t i = 0; i < num_announcable; i++)
		towire_wireaddr(&p, announcable + i);

	return memcheck(p, tal_count(p));
}
bool fromwire_connectd_init_reply(const tal_t *ctx, const void *p, struct wireaddr_internal **bindings, struct wireaddr **announcable)
{
	u16 num_bindings;
	u16 num_announcable;

	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_CONNECTD_INIT_REPLY)
		return false;
 	num_bindings = fromwire_u16(&cursor, &plen);
 	// 2nd case bindings
	*bindings = num_bindings ? tal_arr(ctx, struct wireaddr_internal, num_bindings) : NULL;
	for (size_t i = 0; i < num_bindings; i++)
		fromwire_wireaddr_internal(&cursor, &plen, *bindings + i);
 	num_announcable = fromwire_u16(&cursor, &plen);
 	// 2nd case announcable
	*announcable = num_announcable ? tal_arr(ctx, struct wireaddr, num_announcable) : NULL;
	for (size_t i = 0; i < num_announcable; i++)
		fromwire_wireaddr(&cursor, &plen, *announcable + i);
	return cursor != NULL;
}

/* WIRE: CONNECTD_ACTIVATE */
/* Activate the connect daemon */
u8 *towire_connectd_activate(const tal_t *ctx, bool listen)
{
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_CONNECTD_ACTIVATE);
	/* Do we listen? */
	towire_bool(&p, listen);

	return memcheck(p, tal_count(p));
}
bool fromwire_connectd_activate(const void *p, bool *listen)
{
	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_CONNECTD_ACTIVATE)
		return false;
 	/* Do we listen? */
	*listen = fromwire_bool(&cursor, &plen);
	return cursor != NULL;
}

/* WIRE: CONNECTD_ACTIVATE_REPLY */
/* Connectd->master */
u8 *towire_connectd_activate_reply(const tal_t *ctx)
{
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_CONNECTD_ACTIVATE_REPLY);

	return memcheck(p, tal_count(p));
}
bool fromwire_connectd_activate_reply(const void *p)
{
	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_CONNECTD_ACTIVATE_REPLY)
		return false;
	return cursor != NULL;
}

/* WIRE: CONNECTD_RECONNECTED */
/* connectd->master: disconnect this peer please (due to reconnect). */
u8 *towire_connectd_reconnected(const tal_t *ctx, const struct node_id *id)
{
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_CONNECTD_RECONNECTED);
	towire_node_id(&p, id);

	return memcheck(p, tal_count(p));
}
bool fromwire_connectd_reconnected(const void *p, struct node_id *id)
{
	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_CONNECTD_RECONNECTED)
		return false;
 	fromwire_node_id(&cursor, &plen, id);
	return cursor != NULL;
}

/* WIRE: CONNECTD_CONNECT_TO_PEER */
/* Master -> connectd: connect to a peer. */
u8 *towire_connectd_connect_to_peer(const tal_t *ctx, const struct node_id *id, u32 seconds_waited, const struct wireaddr_internal *addrhint)
{
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_CONNECTD_CONNECT_TO_PEER);
	towire_node_id(&p, id);
	towire_u32(&p, seconds_waited);
	if (!addrhint)
		towire_bool(&p, false);
	else {
		towire_bool(&p, true);
		towire_wireaddr_internal(&p, addrhint);
	}

	return memcheck(p, tal_count(p));
}
bool fromwire_connectd_connect_to_peer(const tal_t *ctx, const void *p, struct node_id *id, u32 *seconds_waited, struct wireaddr_internal **addrhint)
{
	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_CONNECTD_CONNECT_TO_PEER)
		return false;
 	fromwire_node_id(&cursor, &plen, id);
 	*seconds_waited = fromwire_u32(&cursor, &plen);
 	if (!fromwire_bool(&cursor, &plen))
		*addrhint = NULL;
	else {
		*addrhint = tal(ctx, struct wireaddr_internal);
		fromwire_wireaddr_internal(&cursor, &plen, *addrhint);
	}
	return cursor != NULL;
}

/* WIRE: CONNECTD_CONNECT_FAILED */
/* Connectd->master: connect failed. */
u8 *towire_connectd_connect_failed(const tal_t *ctx, const struct node_id *id, errcode_t failcode, const wirestring *failreason, u32 seconds_to_delay, const struct wireaddr_internal *addrhint)
{
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_CONNECTD_CONNECT_FAILED);
	towire_node_id(&p, id);
	towire_errcode_t(&p, failcode);
	towire_wirestring(&p, failreason);
	towire_u32(&p, seconds_to_delay);
	if (!addrhint)
		towire_bool(&p, false);
	else {
		towire_bool(&p, true);
		towire_wireaddr_internal(&p, addrhint);
	}

	return memcheck(p, tal_count(p));
}
bool fromwire_connectd_connect_failed(const tal_t *ctx, const void *p, struct node_id *id, errcode_t *failcode, wirestring **failreason, u32 *seconds_to_delay, struct wireaddr_internal **addrhint)
{
	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_CONNECTD_CONNECT_FAILED)
		return false;
 	fromwire_node_id(&cursor, &plen, id);
 	*failcode = fromwire_errcode_t(&cursor, &plen);
 	*failreason = fromwire_wirestring(ctx, &cursor, &plen);
 	*seconds_to_delay = fromwire_u32(&cursor, &plen);
 	if (!fromwire_bool(&cursor, &plen))
		*addrhint = NULL;
	else {
		*addrhint = tal(ctx, struct wireaddr_internal);
		fromwire_wireaddr_internal(&cursor, &plen, *addrhint);
	}
	return cursor != NULL;
}

/* WIRE: CONNECTD_PEER_CONNECTED */
/* Connectd -> master: we got a peer. Three fds: peer */
u8 *towire_connectd_peer_connected(const tal_t *ctx, const struct node_id *id, const struct wireaddr_internal *addr, const struct per_peer_state *pps, const u8 *features)
{
	u16 flen = tal_count(features);
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_CONNECTD_PEER_CONNECTED);
	towire_node_id(&p, id);
	towire_wireaddr_internal(&p, addr);
	towire_per_peer_state(&p, pps);
	towire_u16(&p, flen);
	towire_u8_array(&p, features, flen);

	return memcheck(p, tal_count(p));
}
bool fromwire_connectd_peer_connected(const tal_t *ctx, const void *p, struct node_id *id, struct wireaddr_internal *addr, struct per_peer_state **pps, u8 **features)
{
	u16 flen;

	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_CONNECTD_PEER_CONNECTED)
		return false;
 	fromwire_node_id(&cursor, &plen, id);
 	fromwire_wireaddr_internal(&cursor, &plen, addr);
 	*pps = fromwire_per_peer_state(ctx, &cursor, &plen);
 	flen = fromwire_u16(&cursor, &plen);
 	// 2nd case features
	*features = flen ? tal_arr(ctx, u8, flen) : NULL;
	fromwire_u8_array(&cursor, &plen, *features, flen);
	return cursor != NULL;
}

/* WIRE: CONNECTD_PEER_DISCONNECTED */
/* master -> connectd: peer has disconnected. */
u8 *towire_connectd_peer_disconnected(const tal_t *ctx, const struct node_id *id)
{
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_CONNECTD_PEER_DISCONNECTED);
	towire_node_id(&p, id);

	return memcheck(p, tal_count(p));
}
bool fromwire_connectd_peer_disconnected(const void *p, struct node_id *id)
{
	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_CONNECTD_PEER_DISCONNECTED)
		return false;
 	fromwire_node_id(&cursor, &plen, id);
	return cursor != NULL;
}

/* WIRE: CONNECTD_DEV_MEMLEAK */
/* master -> connectd: do you have a memleak? */
u8 *towire_connectd_dev_memleak(const tal_t *ctx)
{
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_CONNECTD_DEV_MEMLEAK);

	return memcheck(p, tal_count(p));
}
bool fromwire_connectd_dev_memleak(const void *p)
{
	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_CONNECTD_DEV_MEMLEAK)
		return false;
	return cursor != NULL;
}

/* WIRE: CONNECTD_DEV_MEMLEAK_REPLY */
u8 *towire_connectd_dev_memleak_reply(const tal_t *ctx, bool leak)
{
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_CONNECTD_DEV_MEMLEAK_REPLY);
	towire_bool(&p, leak);

	return memcheck(p, tal_count(p));
}
bool fromwire_connectd_dev_memleak_reply(const void *p, bool *leak)
{
	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_CONNECTD_DEV_MEMLEAK_REPLY)
		return false;
 	*leak = fromwire_bool(&cursor, &plen);
	return cursor != NULL;
}

// SHA256STAMP:63529c4b1d95e8cb69c017829e3269e72c0d884545ae67b925f424b231c9633a
