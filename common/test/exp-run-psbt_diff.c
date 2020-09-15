#include "config.h"
#include <assert.h>
#include <bitcoin/chainparams.h>
#include <bitcoin/psbt.h>
#include <bitcoin/tx.h>
#include <common/setup.h>
#include <stdio.h>
#include <wire/wire.h>
#include "../amount.c"
#include "../psbt_open.c"

/* AUTOGENERATED MOCKS START */
/* Generated stub for fromwire */
const u8 *fromwire(const u8 **cursor UNNEEDED, size_t *max UNNEEDED, void *copy UNNEEDED, size_t n UNNEEDED)
{ fprintf(stderr, "fromwire called!\n"); abort(); }
/* Generated stub for fromwire_bool */
bool fromwire_bool(const u8 **cursor UNNEEDED, size_t *max UNNEEDED)
{ fprintf(stderr, "fromwire_bool called!\n"); abort(); }
/* Generated stub for fromwire_fail */
void *fromwire_fail(const u8 **cursor UNNEEDED, size_t *max UNNEEDED)
{ fprintf(stderr, "fromwire_fail called!\n"); abort(); }
/* Generated stub for fromwire_secp256k1_ecdsa_signature */
void fromwire_secp256k1_ecdsa_signature(const u8 **cursor UNNEEDED, size_t *max UNNEEDED,
					secp256k1_ecdsa_signature *signature UNNEEDED)
{ fprintf(stderr, "fromwire_secp256k1_ecdsa_signature called!\n"); abort(); }
/* Generated stub for fromwire_sha256 */
void fromwire_sha256(const u8 **cursor UNNEEDED, size_t *max UNNEEDED, struct sha256 *sha256 UNNEEDED)
{ fprintf(stderr, "fromwire_sha256 called!\n"); abort(); }
/* Generated stub for fromwire_tal_arrn */
u8 *fromwire_tal_arrn(const tal_t *ctx UNNEEDED,
		       const u8 **cursor UNNEEDED, size_t *max UNNEEDED, size_t num UNNEEDED)
{ fprintf(stderr, "fromwire_tal_arrn called!\n"); abort(); }
/* Generated stub for fromwire_u16 */
u16 fromwire_u16(const u8 **cursor UNNEEDED, size_t *max UNNEEDED)
{ fprintf(stderr, "fromwire_u16 called!\n"); abort(); }
/* Generated stub for fromwire_u32 */
u32 fromwire_u32(const u8 **cursor UNNEEDED, size_t *max UNNEEDED)
{ fprintf(stderr, "fromwire_u32 called!\n"); abort(); }
/* Generated stub for fromwire_u64 */
u64 fromwire_u64(const u8 **cursor UNNEEDED, size_t *max UNNEEDED)
{ fprintf(stderr, "fromwire_u64 called!\n"); abort(); }
/* Generated stub for fromwire_u8 */
u8 fromwire_u8(const u8 **cursor UNNEEDED, size_t *max UNNEEDED)
{ fprintf(stderr, "fromwire_u8 called!\n"); abort(); }
/* Generated stub for pseudorand */
uint64_t pseudorand(uint64_t max UNNEEDED)
{ fprintf(stderr, "pseudorand called!\n"); abort(); }
/* Generated stub for towire */
void towire(u8 **pptr UNNEEDED, const void *data UNNEEDED, size_t len UNNEEDED)
{ fprintf(stderr, "towire called!\n"); abort(); }
/* Generated stub for towire_bool */
void towire_bool(u8 **pptr UNNEEDED, bool v UNNEEDED)
{ fprintf(stderr, "towire_bool called!\n"); abort(); }
/* Generated stub for towire_secp256k1_ecdsa_signature */
void towire_secp256k1_ecdsa_signature(u8 **pptr UNNEEDED,
			      const secp256k1_ecdsa_signature *signature UNNEEDED)
{ fprintf(stderr, "towire_secp256k1_ecdsa_signature called!\n"); abort(); }
/* Generated stub for towire_sha256 */
void towire_sha256(u8 **pptr UNNEEDED, const struct sha256 *sha256 UNNEEDED)
{ fprintf(stderr, "towire_sha256 called!\n"); abort(); }
/* Generated stub for towire_tx_add_input */
u8 *towire_tx_add_input(const tal_t *ctx UNNEEDED, const struct channel_id *channel_id UNNEEDED, u16 serial_id UNNEEDED, const u8 *prevtx UNNEEDED, u32 prevtx_vout UNNEEDED, u32 sequence UNNEEDED, const u8 *script UNNEEDED, const struct tlv_tx_add_input_tlvs *tlvs UNNEEDED)
{ fprintf(stderr, "towire_tx_add_input called!\n"); abort(); }
/* Generated stub for towire_tx_add_output */
u8 *towire_tx_add_output(const tal_t *ctx UNNEEDED, const struct channel_id *channel_id UNNEEDED, u16 serial_id UNNEEDED, u64 sats UNNEEDED, const u8 *script UNNEEDED)
{ fprintf(stderr, "towire_tx_add_output called!\n"); abort(); }
/* Generated stub for towire_tx_remove_input */
u8 *towire_tx_remove_input(const tal_t *ctx UNNEEDED, const struct channel_id *channel_id UNNEEDED, u16 serial_id UNNEEDED)
{ fprintf(stderr, "towire_tx_remove_input called!\n"); abort(); }
/* Generated stub for towire_tx_remove_output */
u8 *towire_tx_remove_output(const tal_t *ctx UNNEEDED, const struct channel_id *channel_id UNNEEDED, u16 serial_id UNNEEDED)
{ fprintf(stderr, "towire_tx_remove_output called!\n"); abort(); }
/* Generated stub for towire_u16 */
void towire_u16(u8 **pptr UNNEEDED, u16 v UNNEEDED)
{ fprintf(stderr, "towire_u16 called!\n"); abort(); }
/* Generated stub for towire_u32 */
void towire_u32(u8 **pptr UNNEEDED, u32 v UNNEEDED)
{ fprintf(stderr, "towire_u32 called!\n"); abort(); }
/* Generated stub for towire_u64 */
void towire_u64(u8 **pptr UNNEEDED, u64 v UNNEEDED)
{ fprintf(stderr, "towire_u64 called!\n"); abort(); }
/* Generated stub for towire_u8 */
void towire_u8(u8 **pptr UNNEEDED, u8 v UNNEEDED)
{ fprintf(stderr, "towire_u8 called!\n"); abort(); }
/* Generated stub for towire_u8_array */
void towire_u8_array(u8 **pptr UNNEEDED, const u8 *arr UNNEEDED, size_t num UNNEEDED)
{ fprintf(stderr, "towire_u8_array called!\n"); abort(); }
/* AUTOGENERATED MOCKS END */

static void diff_count(struct wally_psbt *a,
		       struct wally_psbt *b,
		       size_t diff_added,
		       size_t diff_rm)
{
	struct psbt_changeset *set;

	set = psbt_get_changeset(tmpctx, a, b);

	assert(tal_count(set->added_ins) == diff_added);
	assert(tal_count(set->added_outs) == diff_added);
	assert(tal_count(set->rm_ins) == diff_rm);
	assert(tal_count(set->rm_outs) == diff_rm);
}

static void add_in_out_with_serial(struct wally_psbt *psbt,
				   size_t serial_id,
				   size_t default_value)
{
	struct bitcoin_txid txid;
	u8 *script;
	struct amount_sat sat;
	struct wally_psbt_input *in;
	struct wally_psbt_output *out;

	memset(&txid, default_value, sizeof(txid));
	in = psbt_append_input(psbt, &txid, default_value, default_value,
			       NULL, NULL, NULL);
	if (!in)
		abort();
	psbt_input_add_serial_id(psbt, in, serial_id);

	script = tal_arr(tmpctx, u8, 20);
	memset(script, default_value, 20);
	sat = amount_sat(default_value);
	out = psbt_append_output(psbt, script, sat);
	if (!out)
		abort();
	psbt_output_add_serial_id(psbt, out, serial_id);
}

int main(int argc, const char *argv[])
{
	common_setup(argv[0]);

	struct wally_psbt *start, *end;
	u32 flags = 0;

	chainparams = chainparams_for_network("bitcoin");

	/* Create two psbts! */
	end = create_psbt(tmpctx, 1, 1, 0);
	tal_wally_start();
	if (wally_psbt_clone_alloc(end, flags, &start) != WALLY_OK)
		abort();
	tal_wally_end(tmpctx);
	diff_count(start, end, 0, 0);
	diff_count(end, start, 0, 0);

	/* New input/output added */
	add_in_out_with_serial(end, 10, 1);
	diff_count(start, end, 1, 0);
	diff_count(end, start, 0, 1);

	/* Add another one, before previous */
	tal_wally_start();
	if (wally_psbt_clone_alloc(end, flags, &start) != WALLY_OK)
		abort();
	tal_wally_end(tmpctx);
	add_in_out_with_serial(end, 5, 2);
	diff_count(start, end, 1, 0);
	diff_count(end, start, 0, 1);

	/* Add another, at end */
	tal_wally_start();
	if (wally_psbt_clone_alloc(end, flags, &start) != WALLY_OK)
		abort();
	tal_wally_end(tmpctx);
	add_in_out_with_serial(end, 15, 3);
	diff_count(start, end, 1, 0);
	diff_count(end, start, 0, 1);

	/* Add another, in middle */
	tal_wally_start();
	if (wally_psbt_clone_alloc(end, flags, &start) != WALLY_OK)
		abort();
	tal_wally_end(tmpctx);
	add_in_out_with_serial(end, 11, 4);
	diff_count(start, end, 1, 0);
	diff_count(end, start, 0, 1);

	/* Change existing input/output info
	 * (we accomplish this by removing and then
	 * readding an input/output with the same serial_id
	 * but different value) */
	tal_wally_start();
	if (wally_psbt_clone_alloc(end, flags, &start) != WALLY_OK)
		abort();
	tal_wally_end(tmpctx);
	psbt_rm_output(end, 0);
	psbt_rm_input(end, 0);
	add_in_out_with_serial(end, 5, 5);
	diff_count(start, end, 1, 1);
	diff_count(end, start, 1, 1);

	/* Add some extra unknown info to a PSBT */
	u8 *key = psbt_make_key(tmpctx, 0x05, NULL);
	char *val = tal_fmt(tmpctx, "hello");
	psbt_input_add_unknown(end, &end->inputs[1], key, val, tal_bytelen(val));
	psbt_input_add_unknown(start, &start->inputs[1], key, val, tal_bytelen(val));

	/* Swap locations */
	struct wally_map_item tmp;
	tmp = end->inputs[1].unknowns.items[0];
	end->inputs[1].unknowns.items[0] = end->inputs[1].unknowns.items[1];
	end->inputs[1].unknowns.items[1] = tmp;

	/* We expect nothing to change ? */
	diff_count(start, end, 1, 1);
	diff_count(end, start, 1, 1);

	/* No memory leaks please */
	common_shutdown();
	return 0;
}
