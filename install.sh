curl --output Blitz2k18Environment.zip "https://s3.amazonaws.com/blitz2k18-public/Blitz2k18Environment.zip"
unzip Blitz2k18Environment.zip -d Blitz2k18Environment-Source
rm Blitz2k18Environment.zip
cd Blitz2k18Environment-Source
make
mv blitz2k18 ../
cd ../
rm -r Blitz2k18Environment-Source 