// license:BSD-3-Clause
// copyright-holders:Nicola Salmoria
#ifndef MAME_INCLUDES_PACMAN_H
#define MAME_INCLUDES_PACMAN_H

#pragma once

#include "machine/74259.h"
#include "machine/gen_latch.h"
#include "machine/watchdog.h"
#include "sound/namco.h"
#include "emupal.h"
#include "tilemap.h"

/*************************************************************************

    Namco PuckMan

**************************************************************************/

class pacman_state : public driver_device
{
public:
	pacman_state(const machine_config &mconfig, device_type type, const char *tag)
		: driver_device(mconfig, type, tag)
		, m_maincpu(*this, "maincpu")
		, m_mainlatch(*this, "mainlatch")
		, m_namco_sound(*this, "namco")
		, m_watchdog(*this, "watchdog")
		, m_spriteram(*this, "spriteram")
		, m_spriteram2(*this, "spriteram2")
		, m_s2650_spriteram(*this, "s2650_spriteram")
		, m_videoram(*this, "videoram")
		, m_colorram(*this, "colorram")
		, m_s2650games_tileram(*this, "s2650_tileram")
		, m_rocktrv2_prot_data(*this, "rocktrv2_prot")
		, m_gfxdecode(*this, "gfxdecode")
		, m_palette(*this, "palette")
	{ }

protected:
	void _8bpm_portmap(address_map &map);
	void alibaba_map(address_map &map);
	void bigbucks_map(address_map &map);
	void bigbucks_portmap(address_map &map);
	void birdiy_map(address_map &map);
	void cannonbp_map(address_map &map);
	void crushs_map(address_map &map);
	void crushs_portmap(address_map &map);
	void dremshpr_map(address_map &map);
	void dremshpr_portmap(address_map &map);
	void drivfrcp_portmap(address_map &map);
	void mschamp_map(address_map &map);
	void mschamp_portmap(address_map &map);
	void mspacman_map(address_map &map);
	void nmouse_portmap(address_map &map);
	void numcrash_map(address_map &map);
	void pacman_map(address_map &map);
	void pengojpm_map(address_map &map);
	void piranha_portmap(address_map &map);
	void porky_portmap(address_map &map);
	void rocktrv2_map(address_map &map);
	void s2650games_dataport(address_map &map);
	void s2650games_map(address_map &map);
	void superabc_map(address_map &map);
	void vanvan_portmap(address_map &map);
	void woodpek_map(address_map &map);
	void writeport(address_map &map);

	required_device<cpu_device> m_maincpu;
	optional_device<ls259_device> m_mainlatch;
	optional_device<namco_device> m_namco_sound;
	required_device<watchdog_timer_device> m_watchdog;
	optional_shared_ptr<uint8_t> m_spriteram;
	optional_shared_ptr<uint8_t> m_spriteram2;
	optional_shared_ptr<uint8_t> m_s2650_spriteram;
	required_shared_ptr<uint8_t> m_videoram;
	optional_shared_ptr<uint8_t> m_colorram;
	optional_shared_ptr<uint8_t> m_s2650games_tileram;
	optional_shared_ptr<uint8_t> m_rocktrv2_prot_data;
	required_device<gfxdecode_device> m_gfxdecode;
	required_device<palette_device> m_palette;

	uint8_t m_cannonb_bit_to_read;
	int m_mystery;
	uint8_t m_counter;
	int m_bigbucks_bank;
	uint8_t m_rocktrv2_question_bank;
	tilemap_t *m_bg_tilemap;
	uint8_t m_charbank;
	uint8_t m_spritebank;
	uint8_t m_palettebank;
	uint8_t m_colortablebank;
	uint8_t m_flipscreen;
	uint8_t m_bgpriority;
	int m_xoffsethack;
	uint8_t m_inv_spr;
	uint8_t m_maketrax_counter;
	uint8_t m_maketrax_offset;
	int m_maketrax_disable_protection;

	uint8_t m_irq_mask;

	void pacman_interrupt_vector_w(uint8_t data);
	void piranha_interrupt_vector_w(uint8_t data);
	void nmouse_interrupt_vector_w(uint8_t data);
	DECLARE_WRITE_LINE_MEMBER(coin_counter_w);
	DECLARE_WRITE_LINE_MEMBER(coin_lockout_global_w);
	void alibaba_sound_w(offs_t offset, uint8_t data);
	uint8_t alibaba_mystery_1_r();
	uint8_t alibaba_mystery_2_r();
	void maketrax_protection_w(uint8_t data);
	uint8_t mbrush_prot_r(offs_t offset);
	uint8_t maketrax_special_port2_r(offs_t offset);
	uint8_t maketrax_special_port3_r(offs_t offset);
	uint8_t mschamp_kludge_r();
	void bigbucks_bank_w(uint8_t data);
	uint8_t bigbucks_question_r(offs_t offset);
	void porky_banking_w(uint8_t data);
	uint8_t drivfrcp_port1_r();
	uint8_t _8bpm_port1_r();
	uint8_t porky_port1_r();
	uint8_t rocktrv2_prot1_data_r();
	uint8_t rocktrv2_prot2_data_r();
	uint8_t rocktrv2_prot3_data_r();
	uint8_t rocktrv2_prot4_data_r();
	void rocktrv2_prot_data_w(offs_t offset, uint8_t data);
	void rocktrv2_question_bank_w(uint8_t data);
	uint8_t rocktrv2_question_r(offs_t offset);
	uint8_t pacman_read_nop();
	uint8_t mspacman_disable_decode_r_0x0038(offs_t offset);
	uint8_t mspacman_disable_decode_r_0x03b0(offs_t offset);
	uint8_t mspacman_disable_decode_r_0x1600(offs_t offset);
	uint8_t mspacman_disable_decode_r_0x2120(offs_t offset);
	uint8_t mspacman_disable_decode_r_0x3ff0(offs_t offset);
	uint8_t mspacman_disable_decode_r_0x8000(offs_t offset);
	uint8_t mspacman_disable_decode_r_0x97f0(offs_t offset);
	void mspacman_disable_decode_w(uint8_t data);
	uint8_t mspacman_enable_decode_r_0x3ff8(offs_t offset);
	void mspacman_enable_decode_w(uint8_t data);
	DECLARE_WRITE_LINE_MEMBER(irq_mask_w);
	uint8_t mspacii_protection_r(offs_t offset);
	uint8_t cannonbp_protection_r(offs_t offset);
	void pacman_videoram_w(offs_t offset, uint8_t data);
	void pacman_colorram_w(offs_t offset, uint8_t data);
	DECLARE_WRITE_LINE_MEMBER(flipscreen_w);
	DECLARE_WRITE_LINE_MEMBER(pengo_palettebank_w);
	DECLARE_WRITE_LINE_MEMBER(pengo_colortablebank_w);
	DECLARE_WRITE_LINE_MEMBER(pengo_gfxbank_w);
	void s2650games_videoram_w(offs_t offset, uint8_t data);
	void s2650games_colorram_w(offs_t offset, uint8_t data);
	void s2650games_scroll_w(offs_t offset, uint8_t data);
	void s2650games_tilesbank_w(offs_t offset, uint8_t data);
	void jrpacman_videoram_w(offs_t offset, uint8_t data);
	DECLARE_WRITE_LINE_MEMBER(jrpacman_charbank_w);
	DECLARE_WRITE_LINE_MEMBER(jrpacman_spritebank_w);
	void jrpacman_scroll_w(uint8_t data);
	DECLARE_WRITE_LINE_MEMBER(jrpacman_bgpriority_w);
	void superabc_bank_w(uint8_t data);

public:
	void init_maketrax();
	void init_drivfrcp();
	void init_mspacmbe();
	void init_ponpoko();
	void init_eyes();
	void init_woodpek();
	void init_jumpshot();
	void init_mspacii();
	void init_pacplus();
	void init_rocktrv2();
	void init_superabc();
	void init_8bpm();
	void init_porky();
	void init_mspacman();
	void init_mschamp();
	void init_mbrush();
	void init_pengomc1();

protected:
	TILEMAP_MAPPER_MEMBER(pacman_scan_rows);
	TILE_GET_INFO_MEMBER(pacman_get_tile_info);
	TILE_GET_INFO_MEMBER(s2650_get_tile_info);
	TILEMAP_MAPPER_MEMBER(jrpacman_scan_rows);
	TILE_GET_INFO_MEMBER(jrpacman_get_tile_info);
	DECLARE_VIDEO_START(pacman);
	void pacman_palette(palette_device &palette) const;
	DECLARE_VIDEO_START(birdiy);
	DECLARE_VIDEO_START(s2650games);
	DECLARE_MACHINE_RESET(mschamp);
	DECLARE_MACHINE_RESET(superabc);
	DECLARE_MACHINE_RESET(maketrax);
	DECLARE_VIDEO_START(pengo);
	DECLARE_VIDEO_START(jrpacman);
	uint32_t screen_update_pacman(screen_device &screen, bitmap_ind16 &bitmap, const rectangle &cliprect);
	uint32_t screen_update_s2650games(screen_device &screen, bitmap_ind16 &bitmap, const rectangle &cliprect);
	DECLARE_WRITE_LINE_MEMBER(vblank_irq);
	INTERRUPT_GEN_MEMBER(periodic_irq);
	DECLARE_WRITE_LINE_MEMBER(rocktrv2_vblank_irq);
	DECLARE_WRITE_LINE_MEMBER(vblank_nmi);
	DECLARE_WRITE_LINE_MEMBER(s2650_interrupt);

private:
	void init_save_state();
	void jrpacman_mark_tile_dirty( int offset );
	void eyes_decode(uint8_t *data);
	void mspacman_install_patches(uint8_t *ROM);

public:
	void birdiy(machine_config &config);
	void cannonbp(machine_config &config);
	void rocktrv2(machine_config &config);
	void mspacman(machine_config &config);
	void dremshpr(machine_config &config);
	void mschamp(machine_config &config);
	void nmouse(machine_config &config);
	void vanvan(machine_config &config);
	void s2650games(machine_config &config);
	void woodpek(machine_config &config);
	void crushs(machine_config &config);
	void superabc(machine_config &config);
	void numcrash(machine_config &config);
	void crush4(machine_config &config);
	void bigbucks(machine_config &config);
	void porky(machine_config &config);
	void pacman(machine_config &config, bool latch = true);
	void _8bpm(machine_config &config);
	void crush2(machine_config &config);
	void korosuke(machine_config &config);
	void alibaba(machine_config &config);
	void drivfrcp(machine_config &config);
	void pengojpm(machine_config &config);
	void piranha(machine_config &config);

private:
	// pacplus.c
	uint8_t pacplus_decrypt(int addr, uint8_t e);
	void pacplus_decode();

	// jumpshot.c
	uint8_t jumpshot_decrypt(int addr, uint8_t e);
	void jumpshot_decode();
};


class epospm_state : public pacman_state
{
public:
	using pacman_state::pacman_state;

	void acitya(machine_config &config);
	void theglobp(machine_config &config);
	void eeekkp(machine_config &config);

protected:
	uint8_t epos_decryption_w(offs_t offset);
	DECLARE_MACHINE_START(theglobp);
	DECLARE_MACHINE_RESET(theglobp);
	DECLARE_MACHINE_START(eeekkp);
	DECLARE_MACHINE_RESET(eeekkp);
	DECLARE_MACHINE_START(acitya);
	DECLARE_MACHINE_RESET(acitya);

	void epos_map(address_map &map);
	void epos_portmap(address_map &map);
};

class clubpacm_state : public pacman_state
{
public:
	clubpacm_state(const machine_config &mconfig, device_type type, const char *tag)
		: pacman_state(mconfig, type, tag)
		, m_sublatch(*this, "sublatch")
		, m_players(*this, "P%u", 1)
	{ }

	void clubpacm(machine_config &config);

	DECLARE_CUSTOM_INPUT_MEMBER(clubpacm_input_r);

	void init_clubpacma();

protected:
	void clubpacm_map(address_map &map);

	required_device<generic_latch_8_device> m_sublatch;
	required_ioport_array<2> m_players;
};

#endif // MAME_INCLUDES_PACMAN_H
