#
# ~/.bashrc
#

# If not running interactively, don't do anything
[[ $- != *i* ]] && return

# aliases
alias ls='ls --color=auto --group-directories-first'
alias ll='ls -l -a --color=auto --group-directories-first'
alias grep='grep --color=auto'
alias rm='trash -v' # requires trash-cli
alias cp='cp -v'
alias mv='mv -v'

alias pac='pacman -Q | wc -l'
alias pacu='checkupdates | wc -l'

alias vim='nvim'
alias nf='neofetch'

alias odwm='cd ~/.config/dwm'
alias ost='cd ~/.config/st'
alias oblocks=' cd ~/.config/dwmblocks'
alias obin='cd ~/.local/bin'

alias dotfiles=’/usr/bin/git --git-dir=$HOME/.dotfiles/.git --work-tree=$HOME

# paths
export PATH="$PATH:$HOME/.local/bin/scripts"
export PATH="$PATH:$HOME/.local/bin/statusbar"

# prompt
PS1="\[\e[1;32m\]\W \[\e[1;32m\]➤  \[\e[0m\]"
