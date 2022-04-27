#! /bin/xonsh

for fpath in pg`*.jpg`:
  # convert @(fpath) -resize 50% -quality 30% @(str(fpath).replace(".jpg", ""))-50p.jpg
  convert @(fpath) -quality 30% @(fpath)
