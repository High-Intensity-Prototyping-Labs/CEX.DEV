#!/bin/bash

# Get the newest version from user 
read -p "Version number (x.y.z): " version 

# Do the thing 
cp ~/Documents/CEX/CEX\ –\ The\ Standard\ v${version}.pdf downloads
cp ~/Documents/Obsidian/Main/HIPL/CEX\ –\ The\ Standard\ v${version}.md readme.md
vim index.html
git add .
git commit -m "Updated to (v$(version))"
git push

ssh linode 'cd /var/www/cex && git pull'
