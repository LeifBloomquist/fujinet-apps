# Makefile for iss-tracker - #FujiNet client
# for tracking the International Space Station (ISS)
# and seeing who is in space right now.
#
# Pulls data from "Open Notify" http://open-notify.org/
# (an open source project to provide a simple programming interface for
# some of NASA's awesome data)
#
# Bill Kendrick <bill@newbreedsoftware.com>
# 2021-05-17 - 2022-05-29

CC65BIN=/usr/bin
CC65=${CC65BIN}/cc65
CA65=${CC65BIN}/ca65
LD65=${CC65BIN}/ld65
CC65_HOME=/usr/share/cc65/
CC65_INC=${CC65_HOME}/include/
CC65_ASMINC=${CC65_HOME}/asminc/
CC65_LIB=${CC65_HOME}/lib/
CC65_CFG=${CC65_HOME}/cfg/
CC65_FLAGS=-Osir --add-source

# FIXME: Use this in "iss.c" as well
VERSION=2022-05-29

all:	iss.xex

run:	iss.xex
	atari800 -nobasic iss.xex

clean:
	-rm iss.xex
	-rm iss.map
	# O files from S source
	-rm segments.o
	-rm sio.o
	# S assembly from C source, and corresponding O files
	-rm iss.o
	-rm iss.s
	-rm nsio.o
	-rm nsio.s
	-rm app_key.o
	-rm app_key.s
	-rm colors.o
	-rm colors.s

release:	clean releaseclean
	mkdir release
	mkdir release/iss-tracker-atari-${VERSION}-src
	mkdir release/iss-tracker-atari-${VERSION}-src/img
	cp *.* release/iss-tracker-atari-${VERSION}-src/
	cp img/* release/iss-tracker-atari-${VERSION}-src/img/
	tar -czf release/iss-tracker-atari-${VERSION}-src.tar.gz release/iss-tracker-atari-${VERSION}-src/

releaseclean:
	-rm -rf release

iss.xex:	iss.o nsio.o sio.o app_key.o colors.o segments.o atari.cfg
	${LD65} --lib-path "${CC65_LIB}" \
		-o iss.xex \
		-t atari \
		-m iss.map \
		iss.o nsio.o sio.o app_key.o colors.o segments.o atari.lib

iss.o:	iss.s
	${CA65} -I "${CC65_ASMINC}" -t atari iss.s -o iss.o

iss.s:	iss.c nsio.h app_key.h colors.h
	${CC65} ${CC65_FLAGS} -I "${CC65_INC}" \
		-t atari \
		iss.c \
		-o iss.s

nsio.o:	nsio.s
	${CA65} -I "${CC65_ASMINC}" -t atari nsio.s -o nsio.o

nsio.s:	nsio.c nsio.h sio.h
	${CC65} ${CC65_FLAGS} -I "${CC65_INC}" \
		-t atari \
		nsio.c \
		-o nsio.s

app_key.o:	app_key.s
	${CA65} -I "${CC65_ASMINC}" -t atari app_key.s -o app_key.o

app_key.s:	app_key.c app_key.h colors.h
	${CC65} ${CC65_FLAGS} -I "${CC65_INC}" \
		-t atari \
		app_key.c \
		-o app_key.s

colors.o:	colors.s
	${CA65} -I "${CC65_ASMINC}" -t atari colors.s -o colors.o

colors.s:	colors.c colors.h
	${CC65} ${CC65_FLAGS} -I "${CC65_INC}" \
		-t atari \
		colors.c \
		-o colors.s

sio.o:	sio.s
	${CA65} -I "${CC65_ASMINC}" -t atari sio.s -o sio.o

segments.o:     segments.s img/map.gr7
	${CA65} -I "${CC65_ASMINC}" -t atari segments.s -o segments.o

