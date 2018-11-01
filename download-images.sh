mkdir -p images
mkdir tmp && cd tmp
wget http://imagedatabase.cs.washington.edu/groundtruth/_tars.for.download/swissmountains.tar
tar -xvf swissmountains.tar
mv swissmountains/*.jpg ../images
cd ..
rm -rf tmp
