#! /bin/bash
echo $1
mogrify -resize 66% -quality 60 $1