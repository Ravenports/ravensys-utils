# ravensys
Consistent utilities for the Ravenports system root

For years, the following Ravenports existed separately:

| Standard Ravenport | provides
| :----------------- | :-----------------
| bsd-patch          | FreeBSD/DragonFly patch program 
| bsd-which          | FreeBSD/DragonFly which program 
| sha256             | FreeBSD/Dragonfly sha256 and md5 programs
| mtree              | DragonFly's mtree program (from NetBSD)
| ravensys-uname     | Custom program to emulate uname consistently
| ravensys-selector  | Linker deflector (switch between ld.bfd, gold, other).  Currently unused
| libdl              | Empty dl library to prevent breakage when linker receives -ldl on non-linux platform

The source for those files were embedded in the Ravenport.

This repository pulls all the source files in and provides a cmake
framework to build and install them.  This replaces seven ravenports-specific
ports with a single one.

The new port will be called "ravensys-utils"
