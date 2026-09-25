# Environment for everything: loaded once at login, before mango starts,
# so apps launched from mango (fuzzel, Chrome's "Show in folder") inherit it too.
export PATH="$HOME/.local/bin:$PATH"

# Editor, tool paths and nnn file manager
export EDITOR=nvim VISUAL=nvim
export KERAS_HOME="$HOME/.config/keras"
export npm_config_cache="$HOME/.cache/npm"
export NNN_OPTS='de'   # d: detail view, e: open text files in $EDITOR in the same terminal
export NNN_TRASH=1     # delete moves to trash (trash-cli) instead of removing for good
# Catppuccin Mocha via foot's palette (exact), except socket (b7 = closest 256-color mauve)
# block char dir exec regular hardlink symlink details orphan fifo socket unknown
# peach yellow blue green text pink teal surface2 red yellow mauve red
export NNN_FCOLORS='10030402000506080103b701'
export NNN_COLORS='4526'  # tab colors: blue, pink, green, teal
export NNN_FIFO=/tmp/nnn.fifo                     # needed by preview-tui
export NNN_PLUG='p:preview-tui'                   # ; then p: toggle preview window
export NNN_TERMINAL='foot -a preview-tui'         # preview opens as its own foot window
export NNN_PREVIEWIMGPROG='chafa'                 # images via sixel (foot supports it)

# Start mango when logging in on tty1
if [ -z "$WAYLAND_DISPLAY" ] && [ "$(tty)" = "/dev/tty1" ]; then
    exec mango
fi
