# $NetBSD$
#

DISTNAME=	terminfo-0.3.2.6
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Haskell bindings to the terminfo library
LICENSE=	modified-bsd

CONFIGURE_ARGS+= --configure-option=--with-curses-includes=${PREFIX:Q}/include/ncurses
CONFIGURE_ARGS+= --configure-option=--with-curses-libraries=${PREFIX:Q}/lib

USE_NCURSES=    yes
.include "../../wip/mk/haskell.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
