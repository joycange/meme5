/**
 * Status defaults for durations.
 */

// properties of the duration.
enum duration_flags : uint32_t
{
    D_NO_FLAGS    = 0,

    // Whether to do automatic expiration colouring.
    D_EXPIRES     = 1<< 0,

    // Whether !cancellation (and the like) end the duration.
    D_DISPELLABLE = 1<< 1,
};

struct duration_def
{
    duration_type dur;
    int    light_colour; ///< Base colour for status light.
    const char *light_text; ///< Text for the status light.
    const char *short_text; ///< Text for @ line on the % screen and morgues.
                            ///< Usually an adjective.
    const char *name_text;  ///< Text used in wizmode &^D. If empty, use the
                            ///< short_text.
    const char *long_text;  ///< Text for the @ message.

    uint32_t flags;       ///< A bitfield for various flags a duration can have.

    /// Return the name of the duration (name_text or short_text). */
    const char *name() const
    {
        return name_text[0] ? name_text : short_text;
    }

    const bool duration_has_flag(uint64_t flag_wanted) const
    {
        return flags & flag_wanted;
    }

};

/**
 * "" for an entry means N/A, either because it is not shown in the
 * relevant place, or because it is shown in a more complicated way.
 * A "" for name_text indicates that the name is the same as the
 * short text.
 *
 * Examples:
 *
 * DUR_FORESTED has "" for the short_text entry, and therefore has no
 * entry on the "@:" line.
 *
 * DUR_QAZLAL_AC has "" for the light_text entry, and therefore has no
 * status light (instead showing the AC bonus by coloring the player's
 * AC blue).
 */

static const duration_def duration_data[] =
{
    { DUR_AGILITY,
      LIGHTBLUE, "Agi",
      "agile", "agility",
      "You are agile.", D_DISPELLABLE},
    { DUR_ANTIMAGIC,
      RED, "-Mag",
      "antimagic", "",
      "You have trouble accessing your magic.", D_DISPELLABLE | D_EXPIRES},
    { DUR_BERSERK,
      BLUE, "Berserk",
      "berserking", "berserker",
      "You are possessed by a berserker rage.", D_EXPIRES},
    { DUR_BREATH_WEAPON,
      YELLOW, "Breath",
      "short of breath", "breath weapon",
      "You are short of breath.", D_NO_FLAGS},
    { DUR_BRILLIANCE,
      LIGHTBLUE, "Brill",
      "brilliant", "brilliance",
      "You are brilliant.", D_DISPELLABLE},
    { DUR_CONF,
      RED, "Conf",
      "confused", "conf",
      "You are confused.", D_DISPELLABLE},
    { DUR_CONFUSING_TOUCH,
      BLUE, "Touch",
      "confusing touch", "",
      "" , D_DISPELLABLE | D_EXPIRES},
    { DUR_CONTROL_TELEPORT,
      MAGENTA, "cTele",
      "controlling teleports", "control teleport",
      "You can control teleportations.", D_DISPELLABLE | D_EXPIRES},
    { DUR_CORONA,
      YELLOW, "Corona",
      "", "corona",
      "", D_DISPELLABLE},
    { DUR_DEATH_CHANNEL,
      MAGENTA, "DChan",
      "death channel", "",
      "You are channeling the dead.", D_DISPELLABLE | D_EXPIRES},
    { DUR_DIVINE_STAMINA,
      WHITE, "Vit",
      "vitalised", "divine stamina",
      "You are divinely vitalised.", D_EXPIRES},
    { DUR_DIVINE_VIGOUR,
      0, "",
      "divinely vigorous", "divine vigour",
      "You are imbued with divine vigour.", D_NO_FLAGS},
    { DUR_EXHAUSTED,
      YELLOW, "Exh",
      "exhausted", "",
      "You are exhausted.", D_NO_FLAGS},
    { DUR_FIRE_SHIELD,
      BLUE, "RoF",
      "immune to fire clouds", "fire shield",
      "", D_DISPELLABLE | D_EXPIRES},
    { DUR_ICY_ARMOUR,
      0, "",
      "icy armour", "",
      "You are protected by a layer of icy armour.", D_DISPELLABLE | D_EXPIRES},
    { DUR_LIQUID_FLAMES,
      RED, "Fire",
      "liquid flames", "",
      "You are covered in liquid flames.", D_NO_FLAGS},
    { DUR_LOWERED_MR,
      RED, "-MR",
      "vulnerable", "lowered mr",
      "", D_NO_FLAGS},
    { DUR_MAGIC_SHIELD,
      0, "",
      "shielded", "magic shield",
      "", D_DISPELLABLE},
    { DUR_MIGHT,
      LIGHTBLUE, "Might",
      "mighty", "might",
      "You are mighty.", D_DISPELLABLE},
    { DUR_PARALYSIS,
      RED, "Para",
      "paralysed", "paralysis",
      "You are paralysed.", D_DISPELLABLE},
    { DUR_PETRIFIED,
      RED, "Stone",
      "petrified", "",
      "You are petrified.", D_DISPELLABLE},
    { DUR_PETRIFYING,
      LIGHTRED, "Petr",
      "petrifying", "",
      "You are turning to stone.", D_DISPELLABLE /*but special-cased*/ | D_EXPIRES},
    { DUR_RESISTANCE,
      BLUE, "Resist",
      "resistant", "resistance",
      "You resist elements.", D_DISPELLABLE | D_EXPIRES},
    { DUR_SLIMIFY,
      GREEN, "Slime",
      "slimy", "slimify",
      "", D_EXPIRES},
    { DUR_SLEEP,
      0, "",
      "sleeping", "sleep",
      "You are sleeping.", D_NO_FLAGS},
    { DUR_STONESKIN,
      0, "",
      "stone skin", "stoneskin",
      "Your skin is tough as stone.", D_DISPELLABLE},
    { DUR_SWIFTNESS,
      BLUE, "Swift",
      "swift", "swiftness",
      "You can move swiftly.", D_DISPELLABLE | D_EXPIRES},
    { DUR_TELEPATHY,
      LIGHTBLUE, "Emp",
      "empathic", "telepathy",
      "", D_NO_FLAGS},
    { DUR_TELEPORT,
      LIGHTBLUE, "Tele",
      "about to teleport", "teleport",
      "You are about to teleport.", D_DISPELLABLE /*but special-cased*/},
    { DUR_DEATHS_DOOR,
      LIGHTGREY, "DDoor",
      "death's door", "deaths door",
      "", D_EXPIRES},
    { DUR_PHASE_SHIFT,
      0, "",
      "phasing", "phase shift",
      "You are out of phase with the material plane.", D_DISPELLABLE | D_EXPIRES},
    { DUR_QUAD_DAMAGE,
      BLUE, "Quad",
      "quad damage", "",
      "", D_EXPIRES},
    { DUR_SILENCE,
      MAGENTA, "Sil",
      "silence", "",
      "You radiate silence.", D_DISPELLABLE | D_EXPIRES},
    { DUR_STEALTH,
      BLUE, "Stealth",
      "especially stealthy", "stealth",
      "", D_DISPELLABLE},
    { DUR_AFRAID,
      RED, "Fear",
      "afraid", "",
      "You are terrified.", D_DISPELLABLE | D_EXPIRES},
    { DUR_MIRROR_DAMAGE,
      WHITE, "Mirror",
      "injury mirror", "mirror damage",
      "You mirror injuries.", D_NO_FLAGS},
    { DUR_SCRYING,
      WHITE, "Scry",
      "scrying", "",
      "Your astral vision lets you see through walls.", D_NO_FLAGS},
    { DUR_TORNADO,
      LIGHTGREY, "Tornado",
      "tornado", "",
      "You are in the eye of a mighty hurricane.", D_EXPIRES},
    { DUR_LIQUEFYING,
      LIGHTBLUE, "Liquid",
      "liquefying", "",
      "The ground has become liquefied beneath your feet.", D_DISPELLABLE},
    { DUR_HEROISM,
      LIGHTBLUE, "Hero",
      "heroism", "",
      "You possess the skills of a mighty hero.", D_NO_FLAGS},
    { DUR_FINESSE,
      LIGHTBLUE, "Finesse",
      "finesse", "",
      "Your blows are lightning fast.", D_NO_FLAGS},
    { DUR_LIFESAVING,
      LIGHTGREY, "Prot",
      "protection", "lifesaving",
      "You are calling for your life to be saved.", D_EXPIRES},
    { DUR_DARKNESS,
      BLUE, "Dark",
      "darkness", "",
      "You emit darkness.", D_DISPELLABLE | D_EXPIRES},
    { DUR_SHROUD_OF_GOLUBRIA,
      BLUE, "Shroud",
      "shrouded", "",
      "You are protected by a distorting shroud.", D_DISPELLABLE | D_EXPIRES},
    { DUR_TORNADO_COOLDOWN,
      YELLOW, "Tornado",
      "", "tornado cooldown",
      "", D_NO_FLAGS},
    { DUR_DISJUNCTION,
      BLUE, "Disjoin",
      "disjoining", "disjunction",
      "You are disjoining your surroundings.", D_DISPELLABLE | D_EXPIRES},
    { DUR_SENTINEL_MARK,
      LIGHTRED, "Mark",
      "marked", "sentinel's mark",
      "A sentinel's mark is revealing your location to enemies.", D_DISPELLABLE | D_EXPIRES},
    { DUR_INFUSION,
      BLUE, "Infus",
      "infused", "",
      "Your attacks are magically infused.", D_DISPELLABLE | D_EXPIRES},
    { DUR_SONG_OF_SLAYING,
      BLUE, "Slay",
      "singing", "song of slaying",
      "Your melee attacks are strengthened by your song.", D_DISPELLABLE | D_EXPIRES},
    { DUR_FLAYED,
      RED, "Flay",
      "flayed", "",
      "You are covered in terrible wounds.", D_EXPIRES},
    { DUR_WEAK,
      RED, "Weak",
      "weakened", "weak",
      "Your attacks are enfeebled.", D_DISPELLABLE},
    { DUR_DIMENSION_ANCHOR,
      RED, "-Tele",
      "cannot translocate", "dimension anchor",
      "You are firmly anchored to this plane.", D_DISPELLABLE},
    { DUR_TOXIC_RADIANCE,
      MAGENTA, "Toxic",
      "radiating poison", "toxic radiance",
      "You are radiating toxic energy.", D_DISPELLABLE},
    { DUR_RECITE,
      WHITE, "Recite",
      "reciting", "",
      "You are reciting Zin's Axioms of Law.", D_NO_FLAGS},
    { DUR_GRASPING_ROOTS,
      BROWN, "Roots",
      "grasped by roots", "grasping roots",
      "Your movement is impeded by grasping roots.", D_NO_FLAGS},
    { DUR_FIRE_VULN,
      RED, "-rF",
      "fire vulnerable", "fire vulnerability",
      "You are more vulnerable to fire.", D_DISPELLABLE},
    { DUR_BARBS,
      RED, "Barbs",
      "manticore barbs", "",
      "Manticore spikes are embedded in your body.", D_NO_FLAGS},
    { DUR_POISON_VULN,
      RED, "-rP",
      "poison vulnerable", "poison vulnerability",
      "You are more vulnerable to poison.", D_DISPELLABLE},
    { DUR_FROZEN,
      RED, "Frozen",
      "frozen", "",
      "You are partly encased in ice.", D_NO_FLAGS},
    { DUR_SAP_MAGIC,
      RED, "Sap",
      "sap magic", "",
      "Casting spells hinders your spell success.", D_DISPELLABLE},
    { DUR_PORTAL_PROJECTILE,
      LIGHTBLUE, "PProj",
      "portal projectile", "",
      "You are teleporting projectiles to their destination.", D_DISPELLABLE},
    { DUR_FORESTED,
      GREEN, "Forest",
      "", "forested",
      "", D_NO_FLAGS},
    { DUR_DRAGON_CALL,
      WHITE, "Dragoncall",
      "dragon's call", "dragon call",
      "You are beckoning forth a horde of dragons.", D_NO_FLAGS},
    { DUR_DRAGON_CALL_COOLDOWN,
      YELLOW, "Dragoncall",
      "", "dragon call cooldown",
      "", D_NO_FLAGS},
    { DUR_ABJURATION_AURA,
      BLUE, "Abj",
      "aura of abjuration", "",
      "You are abjuring all hostile summons around you.", D_DISPELLABLE},
    { DUR_NO_POTIONS,
      RED, "-Potion",
      "no potions", "",
      "You cannot drink potions.", D_NO_FLAGS},
    { DUR_QAZLAL_FIRE_RES,
      LIGHTBLUE, "rF+",
      "protected from fire", "qazlal fire resistance",
      "Qazlal is protecting you from fire.", D_NO_FLAGS},
    { DUR_QAZLAL_COLD_RES,
      LIGHTBLUE, "rC+",
      "protected from cold", "qazlal cold resistance",
      "Qazlal is protecting you from cold.", D_NO_FLAGS},
    { DUR_QAZLAL_ELEC_RES,
      LIGHTBLUE, "rElec+",
      "protected from electricity", "qazlal elec resistance",
      "Qazlal is protecting you from electricity.", D_NO_FLAGS},
    { DUR_QAZLAL_AC,
      LIGHTBLUE, "",
      "protected from physical damage", "qazlal ac",
      "Qazlal is protecting you from physical damage.", D_NO_FLAGS},
    { DUR_CORROSION,
      RED, "Corr",
      "corroded equipment", "corrosion",
      "Your equipment is corroded.", D_NO_FLAGS},
    { DUR_FORTITUDE,
      LIGHTBLUE, "Fort",
      "immense fortitude", "",
      "You have immense fortitude and shrug off injury.", D_DISPELLABLE},
    { DUR_HORROR,
      RED, "Horr",
      "horrified", "",
      "You are horrified, weakening your attacks and spells.", D_NO_FLAGS},
    { DUR_NO_SCROLLS,
      RED, "-Scroll",
      "no scrolls", "",
      "You cannot read scrolls.", D_NO_FLAGS},
    { DUR_CONDENSATION_SHIELD,
      0, "",
      "icy shield", "",
      "You are shielded by a disc of ice.", D_DISPELLABLE},
    { DUR_DIVINE_SHIELD,
      0, "",
      "divine shield", "",
      "You are shielded by the power of the Shining One.", D_NO_FLAGS},
    { DUR_CLEAVE,
      LIGHTBLUE, "Cleave",
      "cleaving", "cleave",
      "You are cleaving through your foes.", D_DISPELLABLE },
    { DUR_AMBROSIA, GREEN, "Ambros", "", "ambrosia",
      "You are regenerating under the effects of ambrosia.", D_DISPELLABLE },

    // The following are visible in wizmode only, or are handled
    // specially in the status lights and/or the % or @ screens.

    { DUR_INVIS, 0, "", "", "invis", "", D_DISPELLABLE},
    { DUR_SLOW, 0, "", "", "slow", "", D_DISPELLABLE},
    { DUR_MESMERISED, 0, "", "", "mesmerised", "", D_DISPELLABLE},
    { DUR_MESMERISE_IMMUNE, 0, "", "", "mesmerisation immunity", "" },
    { DUR_HASTE, 0, "", "", "haste", "", D_DISPELLABLE},
    { DUR_FLIGHT, 0, "", "", "flight", "", D_DISPELLABLE /*but special-cased*/},
    { DUR_POISONING, 0, "", "", "poisoning", "", D_NO_FLAGS},
    { DUR_PIETY_POOL, 0, "", "", "piety pool", "", D_NO_FLAGS},
    { DUR_REGENERATION, 0, "", "", "regeneration", "", D_DISPELLABLE},
    { DUR_TRANSFORMATION, 0, "", "", "transformation", "", D_DISPELLABLE /*but special-cased*/},
    { DUR_WEAPON_BRAND, 0, "", "", "weapon brand", "", D_DISPELLABLE},
    { DUR_DEMONIC_GUARDIAN, 0, "", "", "demonic guardian", "", D_NO_FLAGS},
    { DUR_POWERED_BY_DEATH, 0, "", "", "pbd", "", D_NO_FLAGS},
    { DUR_GOURMAND, 0, "", "", "gourmand", "", D_NO_FLAGS},
    { DUR_REPEL_STAIRS_MOVE, 0, "", "", "repel stairs move", "", D_NO_FLAGS},
    { DUR_REPEL_STAIRS_CLIMB, 0, "", "", "repel stairs climb", "", D_NO_FLAGS},
    { DUR_COLOUR_SMOKE_TRAIL, 0, "", "", "coloured smoke trail", "", D_NO_FLAGS},
    { DUR_TIME_STEP, 0, "", "", "time step", "", D_NO_FLAGS},
    { DUR_ICEMAIL_DEPLETED, 0, "", "", "icemail depleted", "", D_NO_FLAGS},
    { DUR_PARALYSIS_IMMUNITY, 0, "", "", "paralysis immunity", "", D_NO_FLAGS},
    { DUR_VEHUMET_GIFT, 0, "", "", "vehumet gift", "", D_NO_FLAGS},
    { DUR_SICKENING, 0, "", "", "sickening", "", D_DISPELLABLE},
    { DUR_WATER_HOLD, 0, "", "", "drowning", "", D_NO_FLAGS},
    { DUR_WATER_HOLD_IMMUNITY, 0, "", "", "drowning immunity", "", D_NO_FLAGS},
    { DUR_SLEEP_IMMUNITY, 0, "", "", "sleep immunity", "", D_NO_FLAGS},
    { DUR_ELIXIR_HEALTH, 0, "", "", "elixir health", "", D_DISPELLABLE},
    { DUR_ELIXIR_MAGIC, 0, "", "", "elixir magic", "", D_DISPELLABLE},
    { DUR_TROGS_HAND, 0, "", "", "trogs hand", "", D_NO_FLAGS},
    { DUR_MAGIC_SAPPED, 0, "", "", "magic sapped", "", D_DISPELLABLE},

#if TAG_MAJOR_VERSION == 34
    // And removed ones
    { DUR_REPEL_MISSILES, 0, "", "", "old repel missiles", "", D_NO_FLAGS},
    { DUR_DEFLECT_MISSILES, 0, "", "", "old deflect missiles", "", D_NO_FLAGS},
    { DUR_JELLY_PRAYER, 0, "", "", "old jelly prayer", "", D_NO_FLAGS},
    { DUR_CONTROLLED_FLIGHT, 0, "", "", "old controlled flight", "", D_NO_FLAGS},
    { DUR_SEE_INVISIBLE, 0, "", "", "old see invisible", "", D_NO_FLAGS},
    { DUR_INSULATION, 0, "", "", "old insulation", "", D_NO_FLAGS},
    { DUR_BARGAIN, 0, "", "", "old bargain", "", D_NO_FLAGS},
    { DUR_SLAYING, 0, "", "", "old slaying", "", D_NO_FLAGS},
    { DUR_MISLED, 0, "", "", "old misled", "", D_NO_FLAGS},
    { DUR_NAUSEA, 0, "", "", "old nausea", "", D_NO_FLAGS},
    { DUR_TEMP_MUTATIONS, 0, "", "", "old temporary mutations", "", D_NO_FLAGS},
    { DUR_BATTLESPHERE, 0, "", "", "old battlesphere", "", D_NO_FLAGS},
    { DUR_RETCHING, 0, "", "", "old retching", "", D_NO_FLAGS},
    { DUR_SPIRIT_HOWL, 0, "", "", "old spirit howl", "", D_NO_FLAGS},
    { DUR_SONG_OF_SHIELDING, 0, "", "", "old song of shielding", "", D_NO_FLAGS},
    { DUR_ANTENNAE_EXTEND, 0, "", "", "old antennae extend", "", D_NO_FLAGS},
    { DUR_BUILDING_RAGE, 0, "", "", "old building rage", "", D_NO_FLAGS},
    { DUR_NEGATIVE_VULN, 0, "", "", "old negative vuln", "", D_NO_FLAGS},
    { DUR_SURE_BLADE, 0, "", "", "old sure blade", "", D_NO_FLAGS},
#endif
};
