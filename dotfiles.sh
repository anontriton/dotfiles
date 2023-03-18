#!/bin/bash

# backup dotfiles into my github repo

# check to see is git command line installed in this machine
IS_GIT_AVAILABLE="$(git --version)"
if [[ $IS_GIT_AVAILABLE == *"version"* ]]; then
  echo "Git is Available"
else
  echo "Git is not installed"
  exit 1
fi

# copy other dot files 
cp  $HOME/{.bashrc,.xinitrc,.Xmodmap,.xbindkeysrc} .
cp  -r $HOME/.config/{dwm,st,dwmblocks,nvim,neofetch} .
cp  -r $HOME/.local/bin/{scripts,statusbar} .

# Check git status
gs="$(git status | grep -i "modified")"
# echo "${gs}"

# If there is a new change
if [[ $gs == *"modified"* ]]; then
  echo "push"
fi

# push to Github
git pull origin main
git commit -a -m "New backup `date +'%Y-%m-%d %H:%M:%S'`";
git push origin main
