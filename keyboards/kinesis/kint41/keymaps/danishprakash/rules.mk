COMBO_ENABLE = yes
CAPS_WORD_ENABLE = yes
AUTO_SHIFT_ENABLE = yes
WPM_ENABLE = yes

# Teensy will reboot to halfkay without this
# This would mean reinserting the keyboard everytime
# you flash the firmware, which is annoying.
# https://github.com/kinx-project/kint/issues/77#issuecomment-1837631133
OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=FALSE
