#!/bin/bash
#
# This script downloads all exam files (.pdf) from the website:
# 	https://www.ais.mw.tum.de/lehre/grundlagen-und-vertiefungsfaecher/informationstechnik-ii/
# to current directory.
#
PREFIX='http://www.ais.mw.tum.de'
# 1. Get the whole webpage content with <curl -L>.
# 2. Direct the downloaded content to <grep> to search for lines with ".pdf".
# 3. <Grep> then redirects (stdout, 1>) the found strings to file <tmp.txt>.
#    Attention: In Windows, the whole content in <tmp.txt> is handled as ONE line.
curl -L https://www.ais.mw.tum.de/lehre/grundlagen-und-vertiefungsfaecher/informationstechnik-ii/ | grep '.pdf' 1> tmp.txt
# Since the content in <tmp.txt> is only ONE line, we will read string by string (separated by white-space) and save only strings
# that represent a download link in <links.txt>.
while read str; do
	# Cut the string into many substrings/fields that are separated by double-quotes ("). Get the second substring/field (-f 2).
	# If a string <str> doesn't include double-quotes (") and cannot be cut, the error messages (stderr, 2>) will be ignored
	# (2>/dev/null), i.e. they are directed to a not-existing null device and discarded. 
	str=$(cut -d'"' -f 2 $str 2>/dev/null)
	# Redirect download link to file <links.txt>
	echo -e "$str\n" >> links.txt  # With option -e of <echo>, we insert a line-feed (new-line) after every string <str>.
	#fi		
done < tmp.txt
# Delete <tmp.txt>
rm -f tmp.txt
# Now we can read file <links.txt> line by line
while read line; do
	if [[ ! $line = *${PREFIX}* ]]; then
		line="${PREFIX}$line"
	fi
	# Option -O indicates that <curl> downloads and saves the file with the same name as in remote-server.
	# Without -O, <curl> will only dump the file content in <stdout> and does not really save/download it.  
	curl -O $line
done < links.txt
# Delete <tmp.txt>
rm -f links.txt


