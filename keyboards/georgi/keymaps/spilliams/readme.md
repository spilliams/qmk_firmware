# Georgi QWERTY/Steno firmware

This is spilliams' keymap for Georgi. current version 3.2

- It's based off "minimal"
- serial mode wasn't working though, so it has been built with `steno_set_mode(STENO_MODE_BOLT)` (in `keyboards/georgi/georgi.c`)
- the steno layer still uses Gemini keymaps though, because with TX Bolt keymaps the QWERTY mode was misbehaving (ST3 -> "t", ST3|ST4 -> "t", ST4 -> "t", LSU|LSD -> "q", LSD -> "q")
