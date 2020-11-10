/* This file was generated by generate-wire.py */
/* Do not modify this file! Modify the .csv file it was generated from. */
/* Template located at tools/gen/print_header_template */
#ifndef LIGHTNING_WIRE_ONION_PRINTGEN_H
#define LIGHTNING_WIRE_ONION_PRINTGEN_H
#include <ccan/tal/tal.h>
#include <devtools/print_wire.h>
#include <wire/onion_defs.h>

void printonion_wire_message(const u8 *msg);

void printonion_wire_tlv_message(const char *tlv_name, const u8 *msg);

void printwire_invalid_realm(const char *fieldname, const u8 *cursor);

void printwire_temporary_node_failure(const char *fieldname, const u8 *cursor);

void printwire_permanent_node_failure(const char *fieldname, const u8 *cursor);

void printwire_required_node_feature_missing(const char *fieldname, const u8 *cursor);

void printwire_invalid_onion_version(const char *fieldname, const u8 *cursor);

void printwire_invalid_onion_hmac(const char *fieldname, const u8 *cursor);

void printwire_invalid_onion_key(const char *fieldname, const u8 *cursor);

void printwire_temporary_channel_failure(const char *fieldname, const u8 *cursor);

void printwire_permanent_channel_failure(const char *fieldname, const u8 *cursor);

void printwire_required_channel_feature_missing(const char *fieldname, const u8 *cursor);

void printwire_unknown_next_peer(const char *fieldname, const u8 *cursor);

void printwire_amount_below_minimum(const char *fieldname, const u8 *cursor);

void printwire_fee_insufficient(const char *fieldname, const u8 *cursor);

void printwire_incorrect_cltv_expiry(const char *fieldname, const u8 *cursor);

void printwire_expiry_too_soon(const char *fieldname, const u8 *cursor);

void printwire_incorrect_or_unknown_payment_details(const char *fieldname, const u8 *cursor);

void printwire_final_incorrect_cltv_expiry(const char *fieldname, const u8 *cursor);

void printwire_final_incorrect_htlc_amount(const char *fieldname, const u8 *cursor);

void printwire_channel_disabled(const char *fieldname, const u8 *cursor);

void printwire_expiry_too_far(const char *fieldname, const u8 *cursor);

void printwire_invalid_onion_payload(const char *fieldname, const u8 *cursor);

void printwire_mpp_timeout(const char *fieldname, const u8 *cursor);


#endif /* LIGHTNING_WIRE_ONION_PRINTGEN_H */
// SHA256STAMP:6f34c3287d2f8abec14ecd33fe8340b82298a34959e96a752f8dafc0762b8f65
