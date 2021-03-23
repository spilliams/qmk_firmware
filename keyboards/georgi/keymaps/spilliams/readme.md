# Georgi QWERTY/Steno firmware

This is spilliams' keymap for Georgi. current version 4.0.1

- It's based off "minimal"
- serial mode wasn't working though, so it has been built with `steno_set_mode(STENO_MODE_BOLT)` (in `keyboards/georgi/georgi.c`)
- the steno layer still uses Gemini keymaps though, because with TX Bolt keymaps the QWERTY mode was misbehaving (ST3 -> "t", ST3|ST4 -> "t", ST4 -> "t", LSU|LSD -> "q", LSD -> "q")
- I disabled qwerty mode (by unmapping `STN_FN`), so I could have an
escape key again.
- I also unmapped `STN_PWR`, so I could use it for my own layers.

# Changelog

- 4.0.1: changed the symbol layers to overlap less with the Single Stroke Commands dictionary, and to have more keyboard shortcuts up front.
Also the top left key turns into a `TO(L0)` in case you need to manually return to the base layer.
- 4.0.0: Adds two symbol layers in place of the `STN_PWR` button in lower left. Also turns `STN_FN` into Esc, because I wasn't using qwerty mode anyway.
