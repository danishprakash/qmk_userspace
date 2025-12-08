# Danish's QMK Userspace

Custom QMK keymaps for my keyboards, tracked separately from the main QMK firmware.

## Keyboards

### Kinesis Advantage 2 (kint41)

Custom keymap for Kinesis Advantage 2 with kint41 mod.

**Location:** `keyboards/kinesis/kint41/keymaps/danishprakash/`

**Key Features:**
- Layer 0: Base QWERTY layout with custom modifier positions
- Layer 1: Navigation layer with HJKL arrow keys on right hand
- Shift-when-held on curly brace keys
- Layer toggle on Tab and Escape keys

## Building

Compile all configured keymaps:
```bash
qmk userspace-compile
```

Compile specific keymap:
```bash
qmk compile -kb kinesis/kint41 -km danishprakash
```

## Flashing

```bash
qmk flash -kb kinesis/kint41 -km danishprakash
```

## Setup

This repository is configured as an external userspace for QMK:

```bash
qmk config user.overlay_dir="$(realpath ~/code/dotfiles/qmk_userspace)"
```

## Adding New Keymaps

```bash
qmk new-keymap -kb <keyboard> -km danishprakash
qmk userspace-add -kb <keyboard> -km danishprakash
```
