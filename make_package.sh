#!/usr/bin/sh

VERSION=$(cat package/platform.txt | grep "^version=" | cut -d \= -f2) || exit 1

if [ -e ./arndtm3-samd-$VERSION ]; then
	rm -R ./arndtm3-samd-$VERSION || exit 2
fi

cp -Ra package ./arndtm3-samd-$VERSION || exit 3

find ./arndtm3-samd-$VERSION -name '.git*' -exec rm -R '{}' \; || exit 4

ARCHIVE=arndtm3-samd-$VERSION.tar.bz2

if [ -e ./$ARCHIVE ]; then
	rm ./$ARCHIVE || exit 5
fi

tar -cvvj -f ./$ARCHIVE -C ./arndtm3-samd-$VERSION . || exit 6

rm -R ./arndtm3-samd-$VERSION || exit 7

SHA256=$(cat ./$ARCHIVE | sha256sum -b | cut -d \  -f1) || exit 8
SIZE=$(stat -c%s "$ARCHIVE") || exit 9

cp -a ./pattern_package_arndtm3_index.json ./package_arndtm3_index.json && \
sed -i "s/%VERSION%/$VERSION/g" ./package_arndtm3_index.json && \
sed -i "s/%ARCHIVE%/$ARCHIVE/g" ./package_arndtm3_index.json && \
sed -i "s/%SIZE%/$SIZE/g" ./package_arndtm3_index.json && \
sed -i "s/%SHA256%/$SHA256/g" ./package_arndtm3_index.json \
|| exit 10

echo ""
echo "Successful created package archive: arndtm3-samd-$VERSION.tar.bz2"
exit 0