/* This file was generated by generate-wire.py */
/* Do not modify this file! Modify the .csv file it was generated from. */
/* Original template can be found at tools/gen/impl_template */

#include <gossipd/gossipd_peerd_wiregen.h>
#include <assert.h>
#include <ccan/array_size/array_size.h>
#include <ccan/mem/mem.h>
#include <ccan/tal/str/str.h>
#include <common/utils.h>
#include <stdio.h>

#ifndef SUPERVERBOSE
#define SUPERVERBOSE(...)
#endif

/* These must be distinct from WIRE_CHANNEL_ANNOUNCEMENT etc. gossip msgs! */

const char *gossipd_peerd_wire_name(int e)
{
	static char invalidbuf[sizeof("INVALID ") + STR_MAX_CHARS(e)];

	switch ((enum gossipd_peerd_wire)e) {
	case WIRE_GOSSIPD_GET_UPDATE: return "WIRE_GOSSIPD_GET_UPDATE";
	case WIRE_GOSSIPD_GET_UPDATE_REPLY: return "WIRE_GOSSIPD_GET_UPDATE_REPLY";
	case WIRE_GOSSIPD_LOCAL_ADD_CHANNEL: return "WIRE_GOSSIPD_LOCAL_ADD_CHANNEL";
	case WIRE_GOSSIPD_LOCAL_CHANNEL_UPDATE: return "WIRE_GOSSIPD_LOCAL_CHANNEL_UPDATE";
	case WIRE_GOSSIPD_NEW_STORE_FD: return "WIRE_GOSSIPD_NEW_STORE_FD";
	case WIRE_GOSSIPD_LOCAL_CHANNEL_ANNOUNCEMENT: return "WIRE_GOSSIPD_LOCAL_CHANNEL_ANNOUNCEMENT";
	}

	snprintf(invalidbuf, sizeof(invalidbuf), "INVALID %i", e);
	return invalidbuf;
}

bool gossipd_peerd_wire_is_defined(u16 type)
{
	switch ((enum gossipd_peerd_wire)type) {
	case WIRE_GOSSIPD_GET_UPDATE:;
	case WIRE_GOSSIPD_GET_UPDATE_REPLY:;
	case WIRE_GOSSIPD_LOCAL_ADD_CHANNEL:;
	case WIRE_GOSSIPD_LOCAL_CHANNEL_UPDATE:;
	case WIRE_GOSSIPD_NEW_STORE_FD:;
	case WIRE_GOSSIPD_LOCAL_CHANNEL_ANNOUNCEMENT:;
	      return true;
	}
	return false;
}





/* WIRE: GOSSIPD_GET_UPDATE */
/* Channel daemon can ask for updates for a specific channel */
/* errors. */
u8 *towire_gossipd_get_update(const tal_t *ctx, const struct short_channel_id *short_channel_id)
{
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_GOSSIPD_GET_UPDATE);
	towire_short_channel_id(&p, short_channel_id);

	return memcheck(p, tal_count(p));
}
bool fromwire_gossipd_get_update(const void *p, struct short_channel_id *short_channel_id)
{
	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_GOSSIPD_GET_UPDATE)
		return false;
 	fromwire_short_channel_id(&cursor, &plen, short_channel_id);
	return cursor != NULL;
}

/* WIRE: GOSSIPD_GET_UPDATE_REPLY */
/* If channel isn't known */
u8 *towire_gossipd_get_update_reply(const tal_t *ctx, const u8 *update)
{
	u16 len = tal_count(update);
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_GOSSIPD_GET_UPDATE_REPLY);
	towire_u16(&p, len);
	towire_u8_array(&p, update, len);

	return memcheck(p, tal_count(p));
}
bool fromwire_gossipd_get_update_reply(const tal_t *ctx, const void *p, u8 **update)
{
	u16 len;

	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_GOSSIPD_GET_UPDATE_REPLY)
		return false;
 	len = fromwire_u16(&cursor, &plen);
 	// 2nd case update
	*update = len ? tal_arr(ctx, u8, len) : NULL;
	fromwire_u8_array(&cursor, &plen, *update, len);
	return cursor != NULL;
}

/* WIRE: GOSSIPD_LOCAL_ADD_CHANNEL */
/* Both sides have seen the funding tx being locked */
/* yet reached the announcement depth. So we add the channel locally so */
/* we (and peer) can update it already. */
u8 *towire_gossipd_local_add_channel(const tal_t *ctx, const struct short_channel_id *short_channel_id, const struct node_id *remote_node_id, struct amount_sat satoshis, const u8 *features)
{
	u16 flen = tal_count(features);
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_GOSSIPD_LOCAL_ADD_CHANNEL);
	towire_short_channel_id(&p, short_channel_id);
	towire_node_id(&p, remote_node_id);
	towire_amount_sat(&p, satoshis);
	towire_u16(&p, flen);
	towire_u8_array(&p, features, flen);

	return memcheck(p, tal_count(p));
}
bool fromwire_gossipd_local_add_channel(const tal_t *ctx, const void *p, struct short_channel_id *short_channel_id, struct node_id *remote_node_id, struct amount_sat *satoshis, u8 **features)
{
	u16 flen;

	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_GOSSIPD_LOCAL_ADD_CHANNEL)
		return false;
 	fromwire_short_channel_id(&cursor, &plen, short_channel_id);
 	fromwire_node_id(&cursor, &plen, remote_node_id);
 	*satoshis = fromwire_amount_sat(&cursor, &plen);
 	flen = fromwire_u16(&cursor, &plen);
 	// 2nd case features
	*features = flen ? tal_arr(ctx, u8, flen) : NULL;
	fromwire_u8_array(&cursor, &plen, *features, flen);
	return cursor != NULL;
}

/* WIRE: GOSSIPD_LOCAL_CHANNEL_UPDATE */
/* Send this channel_update. */
u8 *towire_gossipd_local_channel_update(const tal_t *ctx, const struct short_channel_id *short_channel_id, bool disable, u16 cltv_expiry_delta, struct amount_msat htlc_minimum_msat, u32 fee_base_msat, u32 fee_proportional_millionths, struct amount_msat htlc_maximum_msat)
{
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_GOSSIPD_LOCAL_CHANNEL_UPDATE);
	towire_short_channel_id(&p, short_channel_id);
	towire_bool(&p, disable);
	towire_u16(&p, cltv_expiry_delta);
	towire_amount_msat(&p, htlc_minimum_msat);
	towire_u32(&p, fee_base_msat);
	towire_u32(&p, fee_proportional_millionths);
	towire_amount_msat(&p, htlc_maximum_msat);

	return memcheck(p, tal_count(p));
}
bool fromwire_gossipd_local_channel_update(const void *p, struct short_channel_id *short_channel_id, bool *disable, u16 *cltv_expiry_delta, struct amount_msat *htlc_minimum_msat, u32 *fee_base_msat, u32 *fee_proportional_millionths, struct amount_msat *htlc_maximum_msat)
{
	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_GOSSIPD_LOCAL_CHANNEL_UPDATE)
		return false;
 	fromwire_short_channel_id(&cursor, &plen, short_channel_id);
 	*disable = fromwire_bool(&cursor, &plen);
 	*cltv_expiry_delta = fromwire_u16(&cursor, &plen);
 	*htlc_minimum_msat = fromwire_amount_msat(&cursor, &plen);
 	*fee_base_msat = fromwire_u32(&cursor, &plen);
 	*fee_proportional_millionths = fromwire_u32(&cursor, &plen);
 	*htlc_maximum_msat = fromwire_amount_msat(&cursor, &plen);
	return cursor != NULL;
}

/* WIRE: GOSSIPD_NEW_STORE_FD */
/* Update your gossip_store fd: + gossip_store_fd */
u8 *towire_gossipd_new_store_fd(const tal_t *ctx, u64 offset_shorter)
{
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_GOSSIPD_NEW_STORE_FD);
	/* How much shorter the new store is */
	towire_u64(&p, offset_shorter);

	return memcheck(p, tal_count(p));
}
bool fromwire_gossipd_new_store_fd(const void *p, u64 *offset_shorter)
{
	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_GOSSIPD_NEW_STORE_FD)
		return false;
 	/* How much shorter the new store is */
	*offset_shorter = fromwire_u64(&cursor, &plen);
	return cursor != NULL;
}

/* WIRE: GOSSIPD_LOCAL_CHANNEL_ANNOUNCEMENT */
/* Send this channel_announcement */
u8 *towire_gossipd_local_channel_announcement(const tal_t *ctx, const u8 *cannount)
{
	u16 len = tal_count(cannount);
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_GOSSIPD_LOCAL_CHANNEL_ANNOUNCEMENT);
	towire_u16(&p, len);
	towire_u8_array(&p, cannount, len);

	return memcheck(p, tal_count(p));
}
bool fromwire_gossipd_local_channel_announcement(const tal_t *ctx, const void *p, u8 **cannount)
{
	u16 len;

	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_GOSSIPD_LOCAL_CHANNEL_ANNOUNCEMENT)
		return false;
 	len = fromwire_u16(&cursor, &plen);
 	// 2nd case cannount
	*cannount = len ? tal_arr(ctx, u8, len) : NULL;
	fromwire_u8_array(&cursor, &plen, *cannount, len);
	return cursor != NULL;
}

// SHA256STAMP:8d8786f111a7dea8a44e064e382adf00265494b06cdf4cef1c6466bd03878b73
