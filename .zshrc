autoload -Uz compinit && compinit
setopt autocd

# fzf-tab: fuzzy tab completion (must load after compinit, before autosuggestions/highlighting)
source ~/.local/share/zsh/fzf-tab/fzf-tab.plugin.zsh
zstyle ':completion:*' matcher-list 'm:{a-z}={A-Za-z}'  # case-insensitive
zstyle ':completion:*' list-colors ${(s.:.)LS_COLORS}
zstyle ':completion:*:descriptions' format '[%d]'
zstyle ':completion:*' menu no
zstyle ':fzf-tab:complete:(cd|z|__zoxide_z):*' fzf-preview 'eza -1 --icons --color=always $realpath'
zstyle ':fzf-tab:*' switch-group '<' '>'

HISTFILE=~/.zsh_history
HISTSIZE=5000
SAVEHIST=5000
setopt share_history hist_ignore_all_dups

eval "$(starship init zsh)"
eval "$(zoxide init zsh)"

source /usr/share/zsh/plugins/zsh-syntax-highlighting/zsh-syntax-highlighting.zsh

# Valid commands: Catppuccin Mocha green. Unknown commands: Catppuccin Mocha red.
for style in command builtin alias suffix-alias global-alias function precommand reserved-word hashed-command; do
  ZSH_HIGHLIGHT_STYLES[$style]='fg=#a6e3a1'
done
ZSH_HIGHLIGHT_STYLES[unknown-token]='fg=#f38ba8'
source /usr/share/zsh/plugins/zsh-autosuggestions/zsh-autosuggestions.zsh
source /usr/share/zsh/plugins/zsh-history-substring-search/zsh-history-substring-search.zsh

source /usr/share/fzf/completion.zsh
source /usr/share/fzf/key-bindings.zsh
# Catppuccin Mocha for fzf (bg:-1 keeps foot's own background)
export FZF_DEFAULT_OPTS=" \
--color=bg+:#313244,bg:-1,spinner:#f5e0dc,hl:#f38ba8 \
--color=fg:#cdd6f4,header:#f38ba8,info:#cba6f7,pointer:#f5e0dc \
--color=marker:#b4befe,fg+:#cdd6f4,prompt:#cba6f7,hl+:#f38ba8 \
--color=selected-bg:#45475a,border:#6c7086,label:#cdd6f4"
zstyle ':fzf-tab:*' use-fzf-default-opts yes  # fzf-tab uses the colors above too

alias ff='fastfetch'

alias ls='eza --icons'
alias ll='eza --icons -la'
alias lt='eza --icons --tree'

alias cat='bat'

alias cd='z'

alias fh='history | fzf'                 # fuzzy search command history
alias fcd='cd "$(fd --type d | fzf)"'    # fuzzy search and cd into a directory

alias ask='ollama run quickdev'

alias dotfiles='git --git-dir=$HOME/.dotfiles --work-tree=$HOME'

wifi-list() {
	nmcli device wifi list
}
wifi-connect() {
	nmcli device wifi connect "$1" --ask
}
orphans() {
	pacman -Qdtq
}

# nnn file manager (its settings live in ~/.zprofile so apps launched from mango get them too)
source /usr/share/nnn/quitcd/quitcd.bash_sh_zsh  # `n`: like nnn, but stays in the folder you quit in

# Make foot opaque while claude is running
claude() {
  if [[ $TERM == foot* ]]; then
    printf '\e]11;[100]#1a1b26\e\\'   # opaque, foot's tokyo night bg
    command claude "$@"
    local ret=$?
    printf '\e]111\e\\'               # reset bg (and alpha) to foot.ini values
    return $ret
  fi
  command claude "$@"
}

# Secrets (API keys, tokens) go in ~/.zshrc.local, which the dotfiles repo never tracks
[[ -f ~/.zshrc.local ]] && source ~/.zshrc.local
