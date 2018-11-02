# Simple Media Gallery Generator 
> A fast and simple media gallery generator written in C

# Description
This code takes a directory of images/videos, generates thumbnails, and outputs an image gallery in HTML format to stdout

# Dependencies
libimagemagick ([https://imagemagick.org](https://imagemagick.org)) for generating thumbnails 

# Build
`$ git clone https://github.com/tazzaoui/smgg.git && cd smgg && Make`

# Usage 
`./smgg <path-to-media>`
- This will output HTML data to stdout. Usually you'd redirect this output to a file: `./smgg /some/path > output.html`
- Note: If no path is specified, smgg will look in the current directory for media.

# Screenshot
![](screenshot.jpg)

# Configuration
smgg comes with some sane defaults, however the layout can be customized by editing `style.css`. Furthermore, the size of the generated thumbnails can be configured by modifying the `HEIGHT` and `WIDTH` macros in `Gallery.h`.
