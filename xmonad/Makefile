# $NetBSD$
DISTNAME=	xmonad-${VERSION}
PKGNAME=	xmonad-${VERSION}
VERSION=	0.11
CATEGORIES=	wm

MAINTAINER=	esg@sdf.lonestar.org
HOMEPAGE=	http://xmonad.org/
COMMENT=	Tiling window manager

LICENSE=	modified-bsd

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/xmonad.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../x11/libX11/buildlink3.mk"
.include "../../wip/mk/haskell.mk"
.include "../../wip/hs-extensible-exceptions/buildlink3.mk"
.include "../../wip/hs-mtl/buildlink3.mk"
.include "../../wip/hs-utf8-string/buildlink3.mk"
.include "../../wip/hs-x11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
