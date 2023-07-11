#pragma once

// If there are several keys assigned to the same command, the last one
// will be the one displayed on the command help screen. Keys assigned
// via keybindings will take precedence. (jpeg)
#ifdef USE_TILE
{'-', CMD_EDIT_PLAYER_TILE},
#endif
// movement keys
{'s', CMD_WAIT},
{CK_CLEAR, CMD_WAIT},
{CK_NUMPAD_DECIMAL, CMD_WAIT},
{CK_DELETE, CMD_WAIT},
{'.', CMD_WAIT},
{CK_END, CMD_MOVE_DOWN_LEFT},
{CK_LEFT, CMD_MOVE_LEFT},
{CK_DOWN, CMD_MOVE_DOWN},
{CK_UP, CMD_MOVE_UP},
{CK_RIGHT, CMD_MOVE_RIGHT},
{CK_PGDN, CMD_MOVE_DOWN_RIGHT},
{CK_PGUP, CMD_MOVE_UP_RIGHT},
{CK_HOME, CMD_MOVE_UP_LEFT},
{CK_NUMPAD_1, CMD_MOVE_DOWN_LEFT},
{CK_NUMPAD_4, CMD_MOVE_LEFT},
{CK_NUMPAD_2, CMD_MOVE_DOWN},
{CK_NUMPAD_8, CMD_MOVE_UP},
{CK_NUMPAD_6, CMD_MOVE_RIGHT},
{CK_NUMPAD_3, CMD_MOVE_DOWN_RIGHT},
{CK_NUMPAD_9, CMD_MOVE_UP_RIGHT},
{CK_NUMPAD_7, CMD_MOVE_UP_LEFT},
{CK_NUMPAD_5, CMD_REST},
{'b', CMD_MOVE_DOWN_LEFT},
{'h', CMD_MOVE_LEFT},
{'j', CMD_MOVE_DOWN},
{'k', CMD_MOVE_UP},
{'l', CMD_MOVE_RIGHT},
{'n', CMD_MOVE_DOWN_RIGHT},
{'u', CMD_MOVE_UP_RIGHT},
{'y', CMD_MOVE_UP_LEFT},
// other commands
{'a', CMD_USE_ABILITY},
{'c', CMD_UNEQUIP}, // not a very good letter for this
{'d', CMD_DROP},
{'e', CMD_EQUIP},
{'f', CMD_FIRE},
{'g', CMD_PICKUP},
{'i', CMD_DISPLAY_INVENTORY},
{'m', CMD_DISPLAY_SKILLS},
{'p', CMD_AUTOFIRE}, // also shift-tab
{'o', CMD_EXPLORE},
{'q', CMD_QUAFF},
{'r', CMD_READ},
{'t', CMD_SHOUT},
{'V', CMD_EVOKE},
{'v', CMD_PRIMARY_ATTACK},
{'w', CMD_WIELD_WEAPON},
{'x', CMD_LOOK_AROUND},
{'z', CMD_CAST_SPELL},
{'Z', CMD_FORCE_CAST_SPELL},
{CK_SHIFT_END, CMD_RUN_DOWN_LEFT},
{CK_SHIFT_LEFT, CMD_RUN_LEFT},
{CK_SHIFT_DOWN, CMD_RUN_DOWN},
{CK_SHIFT_UP, CMD_RUN_UP},
{CK_SHIFT_RIGHT, CMD_RUN_RIGHT},
{CK_SHIFT_PGDN, CMD_RUN_DOWN_RIGHT},
{CK_SHIFT_PGUP, CMD_RUN_UP_RIGHT},
{CK_SHIFT_HOME, CMD_RUN_UP_LEFT},
{'B', CMD_RUN_DOWN_LEFT},
{'H', CMD_RUN_LEFT},
{'J', CMD_RUN_DOWN},
{'K', CMD_RUN_UP},
{'L', CMD_RUN_RIGHT},
{'N', CMD_RUN_DOWN_RIGHT},
{'U', CMD_RUN_UP_RIGHT},
{'Y', CMD_RUN_UP_LEFT},
{'A', CMD_DISPLAY_MUTATIONS},
{'C', CMD_CLOSE_DOOR},
{'D', CMD_DROP_LAST},
{'E', CMD_EXPERIENCE_CHECK},
{'F', CMD_FIRE_ITEM_NO_QUIVER},
{CONTROL('G'), CMD_INTERLEVEL_TRAVEL},
{'G', CMD_INTERLEVEL_TRAVEL},
{'I', CMD_DISPLAY_SPELLS},
{'M', CMD_MEMORISE_SPELL},
{'O', CMD_OPEN_DOOR},
{'P', CMD_WEAR_JEWELLERY},
{'Q', CMD_QUIVER_ITEM},
{'R', CMD_REMOVE_JEWELLERY},
{'S', CMD_SAVE_GAME},
{CONTROL('S'), CMD_SAVE_GAME_NOW},
{'T', CMD_REMOVE_ARMOUR},
{'W', CMD_WEAR_ARMOUR},
{'X', CMD_DISPLAY_MAP},
{'<', CMD_GO_UPSTAIRS},
{'>', CMD_GO_DOWNSTAIRS},
{'@', CMD_DISPLAY_CHARACTER_STATUS},
{'%', CMD_RESISTS_SCREEN},
{',', CMD_PICKUP},
{':', CMD_MAKE_NOTE},
#ifndef USE_TILE_LOCAL
{'_', CMD_READ_MESSAGES},
#endif
{'|', CMD_SHOW_TERRAIN},
{';', CMD_INSPECT_FLOOR},
{'^', CMD_DISPLAY_RELIGION},
{'#', CMD_CHARACTER_DUMP},
{'=', CMD_ADJUST_INVENTORY},
{'?', CMD_DISPLAY_COMMANDS},
{'!', CMD_ANNOTATE_LEVEL},
{u'€', CMD_LIST_GOLD},
{u'£', CMD_LIST_GOLD},
{u'¥', CMD_LIST_GOLD},
{u'₩', CMD_LIST_GOLD},
{'$', CMD_LIST_GOLD},
{CONTROL('D'), CMD_MACRO_MENU},
{CONTROL('E'), CMD_MACRO_ADD},
{'~', CMD_GAME_MENU},
{CK_F1, CMD_GAME_MENU},
#ifdef __ANDROID__
{CK_F11, CMD_TOGGLE_TAB_ICONS},
{CK_F12, CMD_TOGGLE_KEYBOARD},
#endif
#ifdef WIZARD
{'&', CMD_WIZARD},
{'+', CMD_EXPLORE_MODE},
#endif
{'"', CMD_LIST_JEWELLERY},
{'{', CMD_INSCRIBE_ITEM},
{'[', CMD_LIST_ARMOUR},
{']', CMD_SWAP_QUIVER_RECENT},
{'(', CMD_CYCLE_QUIVER_BACKWARD},
{')', CMD_CYCLE_QUIVER_FORWARD},
{'\\', CMD_DISPLAY_KNOWN_OBJECTS},
{'}', CMD_DISPLAY_RUNES},
{'\'', CMD_WEAPON_SWAP},
{'`', CMD_PREV_CMD_AGAIN},
{'0', CMD_REPEAT_CMD},
{CK_INSERT, CMD_REPEAT_CMD},
{CK_SHIFT_CLEAR, CMD_REST},
{CK_CTRL_CLEAR, CMD_REST},
{'5', CMD_REST},
{CONTROL('B'), CMD_ATTACK_DOWN_LEFT},
{CONTROL('H'), CMD_ATTACK_LEFT}, // n.b. this is backspace...
{CONTROL('J'), CMD_ATTACK_DOWN},
{CONTROL('K'), CMD_ATTACK_UP},
{CONTROL('L'), CMD_ATTACK_RIGHT},
{CONTROL('N'), CMD_ATTACK_DOWN_RIGHT},
{CONTROL('U'), CMD_ATTACK_UP_RIGHT},
{CONTROL('Y'), CMD_ATTACK_UP_LEFT},
{CK_CTRL_END, CMD_ATTACK_DOWN_LEFT},
{CK_CTRL_LEFT, CMD_ATTACK_LEFT},
{CK_CTRL_DOWN, CMD_ATTACK_DOWN},
{CK_CTRL_UP, CMD_ATTACK_UP},
{CK_CTRL_RIGHT, CMD_ATTACK_RIGHT},
{CK_CTRL_PGDN, CMD_ATTACK_DOWN_RIGHT},
{CK_CTRL_PGUP, CMD_ATTACK_UP_RIGHT},
{CK_CTRL_HOME, CMD_ATTACK_UP_LEFT},
{CONTROL('A'), CMD_TOGGLE_AUTOPICKUP},
{CONTROL('C'), CMD_CLEAR_MAP},
{CONTROL('T'), CMD_TOGGLE_TRAVEL_SPEED},
{CONTROL('F'), CMD_SEARCH_STASHES},
{CONTROL('O'), CMD_DISPLAY_OVERMAP},
{CONTROL('P'), CMD_REPLAY_MESSAGES},
{CONTROL('Q'), CMD_QUIT},
{CONTROL('R'), CMD_REDRAW_SCREEN},
{CONTROL('W'), CMD_FIX_WAYPOINT},
{CONTROL('X'), CMD_FULL_VIEW},
{CONTROL('Z'), CMD_SUSPEND_GAME},
{ESCAPE, CMD_TARGET_CANCEL},
{CONTROL('G'), CMD_TARGET_CANCEL},
{'x', CMD_TARGET_CANCEL},
#ifdef WIZARD
{'F', CMD_TARGET_WIZARD_MAKE_FRIENDLY},
{'P', CMD_TARGET_WIZARD_BLESS_MONSTER},
{'s', CMD_TARGET_WIZARD_MAKE_SHOUT},
{'o', CMD_TARGET_WIZARD_GIVE_ITEM},
{'m', CMD_TARGET_WIZARD_MOVE},
{'w', CMD_TARGET_WIZARD_PATHFIND},
{'G', CMD_TARGET_WIZARD_GAIN_LEVEL},
{'M', CMD_TARGET_WIZARD_MISCAST},
{'S', CMD_TARGET_WIZARD_MAKE_SUMMONED},
{'~', CMD_TARGET_WIZARD_POLYMORPH},
{'D', CMD_TARGET_WIZARD_DEBUG_MONSTER},
{CONTROL('H'), CMD_TARGET_WIZARD_HEAL_MONSTER},
{',', CMD_TARGET_WIZARD_HURT_MONSTER},
{'"', CMD_TARGET_WIZARD_DEBUG_PORTAL},
{CONTROL('B'), CMD_TARGET_WIZARD_BANISH_MONSTER},
{CONTROL('K'), CMD_TARGET_WIZARD_KILL_MONSTER},
{CONTROL('('), CMD_TARGET_WIZARD_CREATE_MIMIC},
#endif
{'v', CMD_TARGET_DESCRIBE},
{CONTROL('X'), CMD_TARGET_FULL_DESCRIBE},
{'?', CMD_TARGET_HELP},
{' ', CMD_TARGET_SELECT}, // XXX hack: can also be CMD_TARGET_CANCEL
{CONTROL('P'), CMD_TARGET_SHOW_PROMPT},
{CONTROL('C'), CMD_TARGET_CYCLE_BEAM},
{':', CMD_TARGET_TOGGLE_BEAM},
{'!', CMD_TARGET_SELECT_FORCE},
{'@', CMD_TARGET_SELECT_FORCE_ENDPOINT},
{CK_ENTER, CMD_TARGET_SELECT},
{'5', CMD_TARGET_SELECT},
{CK_NUMPAD_DECIMAL, CMD_TARGET_SELECT_ENDPOINT}, // numpad .
{'.', CMD_TARGET_SELECT_ENDPOINT},
{'e', CMD_TARGET_EXCLUDE},
{'\t', CMD_TARGET_FIND_PORTAL},
{'\\', CMD_TARGET_FIND_PORTAL},
{'^', CMD_TARGET_FIND_TRAP},
{'_', CMD_TARGET_FIND_ALTAR},
{'<', CMD_TARGET_FIND_UPSTAIR},
{'>', CMD_TARGET_FIND_DOWNSTAIR},
{'r', CMD_TARGET_FIND_YOU},
{'p', CMD_TARGET_PREV_TARGET},
//{'f', CMD_TARGET_SELECT}, // HACK: Moved to be the downmost for tutorial key
                            // look-up.
{'g', CMD_TARGET_GET},
{CK_NUMPAD_SUBTRACT, CMD_TARGET_CYCLE_BACK}, // numpad -
{CK_NUMPAD_SUBTRACT2, CMD_TARGET_CYCLE_BACK}, // numpad -, maybe?
{'-', CMD_TARGET_CYCLE_BACK},
{'=', CMD_TARGET_CYCLE_FORWARD},
{CK_NUMPAD_ADD, CMD_TARGET_CYCLE_FORWARD}, // numpad +
{CK_NUMPAD_ADD2, CMD_TARGET_CYCLE_FORWARD}, // numpad +, maybe?
{'+', CMD_TARGET_CYCLE_FORWARD},
{CK_NUMPAD_DIVIDE, CMD_TARGET_OBJ_CYCLE_BACK}, // numpad /, sometimes
{'/', CMD_TARGET_OBJ_CYCLE_BACK},
{';', CMD_TARGET_OBJ_CYCLE_BACK},
{CK_NUMPAD_MULTIPLY, CMD_TARGET_OBJ_CYCLE_FORWARD}, // numpad *, sometimes
{'*', CMD_TARGET_OBJ_CYCLE_FORWARD},
{'\'', CMD_TARGET_OBJ_CYCLE_FORWARD},
{'b', CMD_TARGET_DOWN_LEFT},
{'h', CMD_TARGET_LEFT},
{'j', CMD_TARGET_DOWN},
{'k', CMD_TARGET_UP},
{'l', CMD_TARGET_RIGHT},
{'n', CMD_TARGET_DOWN_RIGHT},
{'u', CMD_TARGET_UP_RIGHT},
{'y', CMD_TARGET_UP_LEFT},
{')', CMD_TARGET_CYCLE_QUIVER_FORWARD},
{'(', CMD_TARGET_CYCLE_QUIVER_BACKWARD},
{'Q', CMD_TARGET_SELECT_ACTION},
{CK_CLEAR, CMD_TARGET_SELECT},
{CK_END, CMD_TARGET_DOWN_LEFT},
{CK_LEFT, CMD_TARGET_LEFT},
{CK_DOWN, CMD_TARGET_DOWN},
{CK_UP, CMD_TARGET_UP},
{CK_RIGHT, CMD_TARGET_RIGHT},
{CK_PGDN, CMD_TARGET_DOWN_RIGHT},
{CK_PGUP, CMD_TARGET_UP_RIGHT},
{CK_HOME, CMD_TARGET_UP_LEFT},
{CK_NUMPAD_1, CMD_TARGET_DOWN_LEFT},
{CK_NUMPAD_4, CMD_TARGET_LEFT},
{CK_NUMPAD_2, CMD_TARGET_DOWN},
{CK_NUMPAD_8, CMD_TARGET_UP},
{CK_NUMPAD_6, CMD_TARGET_RIGHT},
{CK_NUMPAD_3, CMD_TARGET_DOWN_RIGHT},
{CK_NUMPAD_9, CMD_TARGET_UP_RIGHT},
{CK_NUMPAD_7, CMD_TARGET_UP_LEFT},
{CK_NUMPAD_5, CMD_TARGET_SELECT},
{CK_NUMPAD_ENTER, CMD_TARGET_SELECT},
{'f', CMD_TARGET_SELECT}, // HACK: Down here for tutorial key look-up, see above
{'B', CMD_TARGET_DIR_DOWN_LEFT},
{'H', CMD_TARGET_DIR_LEFT},
{'J', CMD_TARGET_DIR_DOWN},
{'K', CMD_TARGET_DIR_UP},
{'L', CMD_TARGET_DIR_RIGHT},
{'N', CMD_TARGET_DIR_DOWN_RIGHT},
{'U', CMD_TARGET_DIR_UP_RIGHT},
{'Y', CMD_TARGET_DIR_UP_LEFT},
{CK_SHIFT_END, CMD_TARGET_DIR_DOWN_LEFT},
{CK_SHIFT_LEFT, CMD_TARGET_DIR_LEFT},
{CK_SHIFT_DOWN, CMD_TARGET_DIR_DOWN},
{CK_SHIFT_UP, CMD_TARGET_DIR_UP},
{CK_SHIFT_RIGHT, CMD_TARGET_DIR_RIGHT},
{CK_SHIFT_PGDN, CMD_TARGET_DIR_DOWN_RIGHT},
{CK_SHIFT_PGUP, CMD_TARGET_DIR_UP_RIGHT},
{CK_SHIFT_HOME, CMD_TARGET_DIR_UP_LEFT},

{CK_MOUSE_MOVE,  CMD_MOUSE_MOVE},
{CK_MOUSE_CLICK, CMD_MOUSE_CLICK},
{CK_MOUSE_MOVE,  CMD_TARGET_MOUSE_MOVE},
{CK_MOUSE_CLICK, CMD_TARGET_MOUSE_SELECT},

{'?', CMD_MAP_HELP},
{CONTROL('C'), CMD_MAP_CLEAR_MAP},
{CONTROL('F'), CMD_MAP_FORGET},
{CONTROL('U'), CMD_MAP_UNFORGET},
{CONTROL('W'), CMD_MAP_ADD_WAYPOINT},
{'w', CMD_MAP_ADD_WAYPOINT},
{'e', CMD_MAP_EXCLUDE_AREA},
{CONTROL('E'), CMD_MAP_CLEAR_EXCLUDES},
{'R', CMD_MAP_EXCLUDE_RADIUS},
{'b', CMD_MAP_MOVE_DOWN_LEFT},
{'h', CMD_MAP_MOVE_LEFT},
{'j', CMD_MAP_MOVE_DOWN},
{'k', CMD_MAP_MOVE_UP},
{'l', CMD_MAP_MOVE_RIGHT},
{'n', CMD_MAP_MOVE_DOWN_RIGHT},
{'u', CMD_MAP_MOVE_UP_RIGHT},
{'y', CMD_MAP_MOVE_UP_LEFT},
{CK_END, CMD_MAP_MOVE_DOWN_LEFT},
{CK_LEFT, CMD_MAP_MOVE_LEFT},
{CK_DOWN, CMD_MAP_MOVE_DOWN},
{CK_UP, CMD_MAP_MOVE_UP},
{CK_RIGHT, CMD_MAP_MOVE_RIGHT},
{CK_PGDN, CMD_MAP_MOVE_DOWN_RIGHT},
{CK_PGUP, CMD_MAP_MOVE_UP_RIGHT},
{CK_HOME, CMD_MAP_MOVE_UP_LEFT},
{CK_NUMPAD_1, CMD_MAP_MOVE_DOWN_LEFT},
{CK_NUMPAD_4, CMD_MAP_MOVE_LEFT},
{CK_NUMPAD_2, CMD_MAP_MOVE_DOWN},
{CK_NUMPAD_8, CMD_MAP_MOVE_UP},
{CK_NUMPAD_6, CMD_MAP_MOVE_RIGHT},
{CK_NUMPAD_3, CMD_MAP_MOVE_DOWN_RIGHT},
{CK_NUMPAD_9, CMD_MAP_MOVE_UP_RIGHT},
{CK_NUMPAD_7, CMD_MAP_MOVE_UP_LEFT},
{'B', CMD_MAP_JUMP_DOWN_LEFT},
{'H', CMD_MAP_JUMP_LEFT},
{'J', CMD_MAP_JUMP_DOWN},
{'K', CMD_MAP_JUMP_UP},
{'L', CMD_MAP_JUMP_RIGHT},
{'N', CMD_MAP_JUMP_DOWN_RIGHT},
{'U', CMD_MAP_JUMP_UP_RIGHT},
{'Y', CMD_MAP_JUMP_UP_LEFT},
{CK_SHIFT_END, CMD_MAP_JUMP_DOWN_LEFT},
{CK_SHIFT_LEFT, CMD_MAP_JUMP_LEFT},
{CK_SHIFT_DOWN, CMD_MAP_JUMP_DOWN},
{CK_SHIFT_UP, CMD_MAP_JUMP_UP},
{CK_SHIFT_RIGHT, CMD_MAP_JUMP_RIGHT},
{CK_SHIFT_PGDN, CMD_MAP_JUMP_DOWN_RIGHT},
{CK_SHIFT_PGUP, CMD_MAP_JUMP_UP_RIGHT},
{CK_SHIFT_HOME, CMD_MAP_JUMP_UP_LEFT},
{'[', CMD_MAP_PREV_LEVEL},
{']', CMD_MAP_NEXT_LEVEL},
{'G', CMD_MAP_GOTO_LEVEL},
{CK_NUMPAD_ADD, CMD_MAP_SCROLL_DOWN}, // numpad +
{CK_NUMPAD_ADD2, CMD_MAP_SCROLL_DOWN}, // numpad +, maybe
{'+', CMD_MAP_SCROLL_DOWN},
{CK_MOUSE_B5, CMD_MAP_SCROLL_DOWN},
{CK_NUMPAD_SUBTRACT, CMD_MAP_SCROLL_UP},
{CK_NUMPAD_SUBTRACT2, CMD_MAP_SCROLL_UP},
{'-', CMD_MAP_SCROLL_UP},
{CK_MOUSE_B4, CMD_MAP_SCROLL_UP},
{'<', CMD_MAP_FIND_UPSTAIR},
{'>', CMD_MAP_FIND_DOWNSTAIR},
{'@', CMD_MAP_FIND_YOU},
{'\t', CMD_MAP_FIND_PORTAL},
{'\\', CMD_MAP_FIND_PORTAL},
{'^', CMD_MAP_FIND_TRAP},
{'_', CMD_MAP_FIND_ALTAR},
{'E', CMD_MAP_FIND_EXCLUDED},
{'F', CMD_MAP_FIND_WAYPOINT},
{'W', CMD_MAP_FIND_WAYPOINT},
{'I', CMD_MAP_FIND_STASH},
{'O', CMD_MAP_FIND_STASH_REVERSE},
{'\'', CMD_MAP_FIND_STASH},
{CK_NUMPAD_DECIMAL, CMD_MAP_GOTO_TARGET}, // numpad .
{'.', CMD_MAP_GOTO_TARGET},
{CK_NUMPAD_ENTER, CMD_MAP_GOTO_TARGET},
{CK_ENTER, CMD_MAP_GOTO_TARGET},
{'S', CMD_MAP_GOTO_TARGET},
{',', CMD_MAP_GOTO_TARGET},
{';', CMD_MAP_GOTO_TARGET},
{'!', CMD_MAP_ANNOTATE_LEVEL},
{'o', CMD_MAP_EXPLORE},
{'v', CMD_MAP_DESCRIBE},
{ESCAPE, CMD_MAP_EXIT_MAP},
{CONTROL('I'), CMD_AUTOFIGHT}, // tab
{CK_SHIFT_TAB, CMD_AUTOFIRE}, // also 'p'

#ifdef WIZARD
{'T', CMD_MAP_WIZARD_TELEPORT},
{CONTROL('X'), CMD_MAP_WIZARD_FORGET},
#endif

// N.b. these cannot be rebound on webtiles
// numpad mappings are handled (by default) in Menu via numpad_to_regular
{CK_UP, CMD_MENU_UP},
{CK_DOWN, CMD_MENU_DOWN},
{CK_SHIFT_UP, CMD_MENU_LINE_UP},
{CK_RIGHT, CMD_MENU_RIGHT},
{CK_LEFT, CMD_MENU_LEFT},
{CK_SHIFT_DOWN, CMD_MENU_LINE_DOWN},
{CK_SHIFT_LEFT, CMD_MENU_LINE_UP}, // some terms don't have shift-up/down available by default
{CK_SHIFT_RIGHT, CMD_MENU_LINE_DOWN},
{'<', CMD_MENU_PAGE_UP},
{'-', CMD_MENU_PAGE_UP}, // manually overridden by many menus
{CK_PGUP, CMD_MENU_PAGE_UP},
{' ', CMD_MENU_PAGE_DOWN}, // currently still can be overridden with hacks
{'>', CMD_MENU_PAGE_DOWN},
{'+', CMD_MENU_PAGE_DOWN},
{CK_PGDN, CMD_MENU_PAGE_DOWN},
{CK_HOME, CMD_MENU_SCROLL_TO_TOP},
{CK_END, CMD_MENU_SCROLL_TO_END},
{CONTROL('F'), CMD_MENU_SEARCH},
{'!', CMD_MENU_CYCLE_MODE},
{',', CMD_MENU_CYCLE_HEADERS},
{'_', CMD_MENU_HELP},
{'?', CMD_MENU_HELP}, // overridden in item menus
{CK_ENTER, CMD_MENU_SELECT},
{'\\', CMD_MENU_EXAMINE},
{'\'', CMD_MENU_EXAMINE},
{CK_MOUSE_B2, CMD_MENU_EXIT},
{CK_MOUSE_CMD, CMD_MENU_EXIT},
{CONTROL('G'), CMD_MENU_EXIT},
{ESCAPE, CMD_MENU_EXIT},

// multiselect-specific:
{CK_ENTER, CMD_MENU_ACCEPT_SELECTION},
{',', CMD_MENU_SELECT_ALL},
{'*', CMD_MENU_INVERT_SELECTION},
{'-', CMD_MENU_CLEAR_SELECTION},
{'.', CMD_MENU_TOGGLE_SELECTED}, // TODO: ' '

#ifdef USE_TILE
{CONTROL('R'), CMD_DOLL_RANDOMIZE},
{'H', CMD_DOLL_SELECT_PREV_DOLL},
{'L', CMD_DOLL_SELECT_NEXT_DOLL},
{CK_SHIFT_LEFT, CMD_DOLL_SELECT_PREV_DOLL},
{CK_SHIFT_RIGHT, CMD_DOLL_SELECT_NEXT_DOLL},
{'k', CMD_DOLL_SELECT_PREV_PART},
{'j', CMD_DOLL_SELECT_NEXT_PART},
{'h', CMD_DOLL_CHANGE_PART_PREV},
{'l', CMD_DOLL_CHANGE_PART_NEXT},
{CK_UP, CMD_DOLL_SELECT_PREV_PART},
{CK_DOWN, CMD_DOLL_SELECT_NEXT_PART},
{CK_LEFT, CMD_DOLL_CHANGE_PART_PREV},
{CK_RIGHT, CMD_DOLL_CHANGE_PART_NEXT},
{CK_NUMPAD_8, CMD_DOLL_SELECT_PREV_PART},
{CK_NUMPAD_2, CMD_DOLL_SELECT_NEXT_PART},
{CK_NUMPAD_4, CMD_DOLL_CHANGE_PART_PREV},
{CK_NUMPAD_6, CMD_DOLL_CHANGE_PART_NEXT},
{CK_NUMPAD_ENTER, CMD_DOLL_CONFIRM_CHOICE},
{CK_ENTER, CMD_DOLL_CONFIRM_CHOICE},
{CONTROL('C'), CMD_DOLL_COPY},
{CONTROL('V'), CMD_DOLL_PASTE},
{'t', CMD_DOLL_TAKE_OFF},
{CONTROL('T'), CMD_DOLL_TAKE_OFF_ALL},
{'*', CMD_DOLL_TOGGLE_EQUIP},
{CONTROL('E'), CMD_DOLL_TOGGLE_EQUIP_ALL},
{CONTROL('D'), CMD_DOLL_JOB_DEFAULT},
{'m', CMD_DOLL_CHANGE_MODE},
{ESCAPE, CMD_DOLL_SAVE},
{CONTROL('S'), CMD_DOLL_SAVE},
{'q', CMD_DOLL_QUIT},
{CONTROL('Q'), CMD_DOLL_QUIT},
#endif

#if defined(USE_TILE_LOCAL)
// no good webtiles keys available for the main view case, and browser zoom
// already more or less accomplishes this.
{LC_CONTROL('='), CMD_ZOOM_IN},
{LC_CONTROL('+'), CMD_ZOOM_IN},
{LC_CONTROL('-'), CMD_ZOOM_OUT},
{LC_CONTROL('='), CMD_MAP_ZOOM_IN},
{LC_CONTROL('+'), CMD_MAP_ZOOM_IN},
{LC_CONTROL('-'), CMD_MAP_ZOOM_OUT},
#endif

#ifdef USE_TILE
{'}', CMD_MAP_ZOOM_IN},
{'{', CMD_MAP_ZOOM_OUT},
#endif

{'\0', CMD_NO_CMD}
