TEMPLATE = app
CONFIG  += console
CONFIG  -= app_bundle
CONFIG  -= qt

INCLUDEPATH += include include/uno
DEFINES     += MPU=atmega328p F_CPU=16000000UL
DISTFILES   += .clang-format .clang-tidy .editorconfig .gitattributes .gitignore CMakeLists.txt LICENSE \
				Makefile README.md toolchain.cmake
HEADERS     += include/rw.hpp include/ports/uno.h
SOURCES     += src/rw.cpp