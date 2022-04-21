#! /bin/bash

for i in *.jpg; do convert $i -resize 50% -quality 30% $i-50p.jpg; done;