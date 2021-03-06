# $NetBSD: Makefile,v 1.18 2012/10/03 12:55:17 asau Exp $
#
DISTNAME=		simulavr-1.0.0
CATEGORIES=		emulators
MASTER_SITES=		http://download.savannah.gnu.org/releases/simulavr/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.nongnu.org/simulavr/
COMMENT=		Simulator for Atmel AVR microcontrollers
LICENSE=		gnu-gpl-v2

BUILD_DEPENDS+=		doxygen-[0-9]*:../../devel/doxygen
BUILD_DEPENDS+=		avr-libc-[0-9]*:../../wip/avr-libc

GIT_REPOSITORIES=	master
GIT_MODULE.master=	simulavr
GIT_REPO.master=	git://git.savannah.nongnu.org/simulavr.git
GIT_FLAGS?=		--depth 1

USE_LANGUAGES+=		c c++
USE_TOOLS+=		makeinfo gmake automake autoconf
USE_LIBTOOL=		yes

GNU_CONFIGURE=		yes
INFO_FILES=		yes
USE_PKGLOCALEDIR=	yes
WRKSRC=			${WRKDIR}/${PKGBASE}

CONFIGURE_ARGS+=	--enable-python=python${PYVERSSUFFIX}
CONFIGURE_ARGS+=	--with-bfd=${PREFIX}/avr
# looking for include/gtest/gtest.h and src/gtest.cc
CONFIGURE_ARGS+=	--with-gtest=
# Following line does not affect anything yet
CONFIGURE_ENV+=		GTEST_USE_FALSE=yes
CONFIGURE_ENV+=		GTEST_USE=no

# Interim fix
SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	post-patch
SUBST_MESSAGE.prefix=	Fix include path finding Python.h
SUBST_FILES.prefix=	src/Makefile.am
SUBST_VARS.prefix=	PREFIX

SUBST_CLASSES+=		makeinfo
SUBST_STAGE.makeinfo=	post-configure
SUBST_MESSAGE.makeinfo=	set MAKEINFO path (to avoid work-directory references included)
SUBST_FILES.makeinfo=	examples/anacomp/Makefile.in
SUBST_FILES.makeinfo+=	examples/python/Makefile.in
SUBST_SED.makeinfo=	-e 's,@MAKEINFO@,${PREFIX}/bin/makeinfo,g'

SUBST_CLASSES+=		build-dir
SUBST_STAGE.build-dir=	post-configure
SUBST_MESSAGE.build-dir= Deleting option not to get -o output only asks for single arg.
SUBST_FILES.build-dir=	doc/Makefile.in doc/Makefile
SUBST_SED.build-dir=	-e 's,--build-dir.*-o,-o,g'

## gcc 2.95 gives warnings that it cannot inline all functions.
#BUILDLINK_TRANSFORM+=	rm:-Werror

pre-configure:
	(cd ${WRKSRC}; ./bootstrap)

.include "../../wip/mk/git-package.mk"

.include "../../cross/avr-binutils/buildlink3.mk"
.include "../../cross/avr-gcc/buildlink3.mk"
#.include "../../devel/googletest/buildlink3.mk"
.include "../../devel/swig/buildlink3.mk"
#.include "../../wip/avr-libc/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../lang/python/pyversion.mk"
.include "../../lang/${PYPACKAGE}/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
