#!/bin/bash
while true
do
	gsettings set org.mate.background picture-filename "`find ~/clips/images/explosion_wallpapers | grep '\.' | shuf | head -n 1`"
	mpv "`find ~/clips/sfx/explosion | grep -v '^/\.' | shuf | head -n 1 `"
	gsettings set org.mate.background picture-filename "`find ~/clips/images/calm_wallpapers | grep '\.' | shuf | head -n 1`"
	sleep `random 0 10`
done
