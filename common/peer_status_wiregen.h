/* This file was generated by generate-wire.py */
/* Do not modify this file! Modify the _csv file it was generated from. */
/* Original template can be found at tools/gen/header_template */

#ifndef LIGHTNING_COMMON_PEER_STATUS_WIREGEN_H
#define LIGHTNING_COMMON_PEER_STATUS_WIREGEN_H
#include <ccan/tal/tal.h>
#include <wire/tlvstream.h>
#include <wire/wire.h>
#include <common/channel_id.h>
#include <common/per_peer_state.h>

enum peer_status_wire {
        /*  An error occurred: if error_for_them */
        WIRE_STATUS_PEER_ERROR = 0xFFF4,
};

const char *peer_status_wire_name(int e);

/**
 * Determine whether a given message type is defined as a message.
 *
 * Returns true if the message type is part of the message definitions we have
 * generated parsers for, false if it is a custom message that cannot be
 * handled internally.
 */
bool peer_status_wire_is_defined(u16 type);


/* WIRE: STATUS_PEER_ERROR */
/*  An error occurred: if error_for_them */
u8 *towire_status_peer_error(const tal_t *ctx, const struct channel_id *channel, const wirestring *desc, bool soft_error, const struct per_peer_state *pps, const u8 *error_for_them);
bool fromwire_status_peer_error(const tal_t *ctx, const void *p, struct channel_id *channel, wirestring **desc, bool *soft_error, struct per_peer_state **pps, u8 **error_for_them);


#endif /* LIGHTNING_COMMON_PEER_STATUS_WIREGEN_H */

// SHA256STAMP:e956fdfdddc89d050229153e3db7a9539795b35b23d4c132f0f65eb0cc339d97
