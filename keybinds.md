# Keybinds

Directions use vim keys: `h` left · `j` down · `k` up · `l` right

## Mango (window manager)

Config: `~/.config/mango/config.conf`.

### Apps & System

| Keys | Action |
|---|---|
| `Alt + Space` | Launcher (fuzzel) |
| `Alt + Enter` | Terminal (foot) |
| `Alt + Shift + Enter` | Toggle scratchpad terminal |
| `Alt + q` | Close window |
| `Super + v` | Clipboard history |
| `Super + Esc` | Lock screen |
| `Super + r` | Reload config |
| `Super + Shift + m` | Quit mango |

### Focus

| Keys | Action |
|---|---|
| `Ctrl + Alt + h/j/k/l` | Focus window in direction |
| `Alt + Shift + Tab` | Focus next window in stack |
| `Alt + Tab` | Jump mode (pick a window by label) |
| `Ctrl + Alt + Shift + h/j/k/l` | Swap window with neighbor in direction |

### Window State

| Keys | Action |
|---|---|
| `Alt + \` | Toggle floating |
| `Alt + a` | Toggle maximize |
| `Alt + f` | Toggle fullscreen |
| `Alt + Shift + f` | Toggle fake fullscreen |
| `Alt + Shift + g` | Toggle global (show on all workspaces) |
| `Alt + Shift + o` | Toggle overlay (always on top) |
| `Alt + z` | Toggle scratchpad |
| `Alt + Shift + h/j/k/l` | Resize window |

### Workspaces

| Keys | Action |
|---|---|
| `Alt + 1–9` | Go to workspace |
| `Alt + Shift + 1–9` | Move window to workspace (and follow) |
| `Super + h` / `Super + l` | Previous / next workspace |

### Layout & Gaps

| Keys | Action |
|---|---|
| `Alt + Shift + n` | Switch layout |
| `Alt + Shift + x` | Increase gaps |
| `Alt + Shift + z` | Decrease gaps |
| `Alt + Shift + c` | Toggle gaps |

### Mouse

| Keys | Action |
|---|---|
| `Super + Left drag` | Move window |
| `Super + Right drag` | Resize window |

### Screenshots

Saved to `~/pictures/screenshots/` and copied to the clipboard.

| Keys | Action |
|---|---|
| `Print` | Full screen |
| `Shift + Print` | Select region |

### Wallpaper

Cycles through `~/wallpapers/`. The last one picked comes back on login.

| Keys | Action |
|---|---|
| `Super + w` | Next wallpaper |
| `Super + Shift + w` | Previous wallpaper |

### Media Keys

| Keys | Action |
|---|---|
| `Brightness Up / Down` | Brightness ±2% |
| `Shift + Brightness Up` | Brightness 100% |
| `Shift + Brightness Down` | Brightness 1% |
| `Volume Up / Down` | Volume ±5% |
| `Mute` | Toggle speaker mute |
| `Shift + Mute` | Toggle mic mute |

### Disabled (commented out in `config.conf`)

Scroller binds (`Alt + e`, `Alt + x`, `Ctrl + Alt + Super + h/j/k/l`), `Ctrl + ←/→` (skip-empty workspace switch), `Ctrl + Super + h/l` (send window to adjacent workspace), `Super + Alt + h/l` (send window to monitor), `Ctrl + Shift + h/j/k/l` (move floating window), `Alt + Shift + Enter` as a dwindle split toggle (that key is the scratchpad instead).

## Fuzzel (launcher)

Open with `Alt + Space`. Config: `~/.config/fuzzel/fuzzel.ini`.

### Keys

| Keys | Action |
|---|---|
| `Ctrl + j` / `Ctrl + k` | Next / previous result |
| `Ctrl + n` / `Ctrl + p`, `↓` / `↑` | Next / previous result |
| `Ctrl + d` / `Ctrl + u` | Page down / up |
| `Tab` | Launch selected, or cycle to next |
| `Enter` | Launch selected |
| `Shift + Enter` | Run exactly what you typed |
| `Ctrl + h` / `Ctrl + w` | Delete character / word |
| `Esc` | Close |

## Foot (terminal)

Config: `~/.config/foot/foot.ini`.

### Keys

| Keys | Action |
|---|---|
| `Ctrl + Shift + c` / `v` | Copy / paste |
| `Shift + Insert` | Paste middle-click selection |
| `Ctrl + Shift + j` / `k` | Scroll down / up one line |
| `Ctrl + Shift + d` / `u` | Scroll down / up half a page |
| `Shift + PgDn` / `PgUp` | Scroll down / up a page |
| `Ctrl + Shift + r` | Search scrollback |
| `Ctrl + Shift + o` | Label links on screen, then press a label to open |
| `Ctrl + Shift + z` / `x` | Jump to previous / next shell prompt (needs shell integration) |
| `Ctrl + Shift + n` | New terminal window |
| `Ctrl + Shift + i` | Unicode character input |
| `Ctrl + +` / `-` / `0` | Font bigger / smaller / reset |

### Search mode (after `Ctrl + Shift + r`)

| Keys | Action |
|---|---|
| `Ctrl + r` / `Ctrl + s` | Previous / next match |
| `Enter` | Finish and keep the selection |
| `Esc` | Cancel |

Scrolling keys do nothing in Neovim and other full-screen apps, which have no scrollback.

## zsh (shell)

Config: `~/.zshrc`. fzf and fzf-tab use Catppuccin Mocha colors.

### Keys

| Keys | Action |
|---|---|
| `Tab` | Fuzzy completion menu (fzf-tab); folders show a preview |
| `<` / `>` | In the completion menu: switch between groups |
| `Ctrl + Space` | In the completion menu: select several items |
| `Ctrl + r` | Fuzzy search command history |
| `Ctrl + t` | Fuzzy pick a file and paste its path |
| `Alt + c` | Fuzzy pick a subfolder and cd into it |
| `→` / `End` | Accept the grey autosuggestion |

Inside any fzf list: `Ctrl + j` / `Ctrl + k` move, `Enter` picks, `Esc` cancels.

### Handy commands

| Command | Action |
|---|---|
| `n` | nnn, staying in the folder you quit in |
| `lock` | Lock the screen (same as `Super + Esc`) |
| `fh` | Fuzzy search history (prints the match) |
| `fcd` | Fuzzy pick a folder and cd into it |
| `ll` / `lt` | Detailed list / tree view (eza) |
| `ff` | fastfetch |
| `lazygit` | Git interface (`?` for keys) |
| `btop` | System monitor (vim keys on) |

## nnn (file manager)

Open with `n` in the terminal (stays in the folder you quit in), or search **nnn** in fuzzel. Folders opened from other apps (like Chrome's "Show in folder") also open here. Settings live in `~/.zshrc`. Press `?` inside nnn for every key.

### Moving around

| Keys | Action |
|---|---|
| `j` / `k` | Down / up |
| `l` / `Enter` | Open file or folder |
| `h` | Parent folder |
| `g` / `G` | Top / bottom of list |
| `~` | Home folder |
| `-` | Previous folder |
| `/` | Filter the list as you type |
| `.` | Show / hide hidden files |
| `b` | Jump to a bookmark |

### Files

| Keys | Action |
|---|---|
| `Space` | Select / unselect file |
| `a` / `A` | Select all / invert selection |
| `p` | Copy selected files here |
| `v` | Move selected files here |
| `x` | Delete (moves to trash) |
| `Ctrl + r` | Rename |
| `n` | New file or folder |
| `e` | Edit in Neovim |
| `o` | Open with a chosen program |

### View & tabs

| Keys | Action |
|---|---|
| `d` | Toggle detail view |
| `t` | Sort options |
| `1`–`8` | Switch to tab 1–8 |
| `Tab` | Next tab |
| `!` | Open a shell in this folder (`exit` to return) |
| `;` or `Alt + ;` | Run a plugin |
| `;` then `p` | Toggle preview window (preview-tui) |
| `q` | Quit |

### Trash

Deleted files go to `~/.local/share/Trash/`, also reachable as `~/trash`. Manage them from the terminal:

| Command | Action |
|---|---|
| `trash-list` | List trashed files |
| `trash-restore` | Pick a file to restore |
| `trash-empty` | Empty the trash for good |
