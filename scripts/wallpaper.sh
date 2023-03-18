#!/bin/sh

# uses feh to change wallpaper

read -p "Enter wallpaper file name: " filename

feh --bg-fill /home/iverson/media/pictures/wallpapers/$filename
